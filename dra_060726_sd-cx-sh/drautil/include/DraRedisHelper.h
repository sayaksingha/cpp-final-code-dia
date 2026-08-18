// @(#) $Id: DraRedisHelper.h,v 1.1.2.2.2.3 2021/11/26 04:23:01 anandhv Exp $";
//-----------------------------------------------------------------------------
// NAME           :  DraRedisHelper.h
//
// COPYRIGHT      :  TSS - Copyright (C) 2009 Tayana Software Solution Pvt Ltd.,
//                   All rights reserved. No part of this computer program
//                   may be used or reproduced in any form by any
//                   means without prior written permission of
//                   Tayana Software Solution Pvt Ltd.
//
// DESCRIPTION
//
// Originated By  : Abhishek Chhabra                      Date: 23-12-2025
//---------------------------------------------------------------------------
#pragma once

#include "TdraStructs.h"
#include <vector>
#include <mutex>
#include <condition_variable>
#include <atomic>

class HashUtils {
private:
    // ROTL32: Circular shift left
    static inline uint32_t rotl32(uint32_t x, int8_t r) {
        return (x << r) | (x >> (32 - r));
    }

public:
    // -------------------------------------------------------------------------
    // MurmurHash3_x86_32
    // Optimized for x86/x64 but safe for all architectures (ARM/PowerPC)
    // -------------------------------------------------------------------------
    static uint32_t MurmurHash3(const void* key, int len, uint32_t seed = 5381) {
        const uint8_t* data = (const uint8_t*)key;
        const int nblocks = len / 4;

        uint32_t h1 = seed;

        // Constants mixed into the hash to ensure distribution
        const uint32_t c1 = 0xcc9e2d51;
        const uint32_t c2 = 0x1b873593;

        // body: process 4 bytes at a time
        // We track the pointer to the blocks region
        const uint8_t* blocks = data + (nblocks * 4);

        for (int i = -nblocks; i; i++) {
            uint32_t k1;
            
            // SAFE LOAD: Read 4 bytes from unaligned memory
            // 'blocks' points to end, 'i' is negative. indexing works backwards-ish.
            // Actually simpler: let's use standard pointer arithmetic logic
            // Murmur3 standard implementation often uses this negative indexing trick
            // equivalent to: const uint32_t* blk = (const uint32_t*)(data + i*4);
            
            // Let's stick to the cleanest pointer arithmetic:
            std::memcpy(&k1, data + (nblocks + i) * 4, sizeof(uint32_t));

            k1 *= c1;
            k1 = rotl32(k1, 15);
            k1 *= c2;

            h1 ^= k1;
            h1 = rotl32(h1, 13);
            h1 = h1 * 5 + 0xe6546b64;
        }

        // tail: process remaining 0-3 bytes
        const uint8_t* tail = data + (nblocks * 4);
        uint32_t k1 = 0;

        switch (len & 3) {
            case 3: k1 ^= tail[2] << 16; [[fallthrough]];
            case 2: k1 ^= tail[1] << 8;  [[fallthrough]];
            case 1: k1 ^= tail[0];
                    k1 *= c1; k1 = rotl32(k1, 15); k1 *= c2; h1 ^= k1;
        };

        // finalization: avalanche
        h1 ^= len;
        h1 ^= h1 >> 16;
        h1 *= 0x85ebca6b;
        h1 ^= h1 >> 13;
        h1 *= 0xc2b2ae35;
        h1 ^= h1 >> 16;

        return h1;
    }

    // -------------------------------------------------------------------------
    // GetBucketId
    // Usage: uint16_t bid = HashUtils::GetBucketId(sessionId);
    // -------------------------------------------------------------------------
    static uint16_t GetBucketId(std::string_view key) 
    {        
        uint32_t hash = MurmurHash3(key.data(), static_cast<int>(key.size()));
        return static_cast<uint16_t>(hash & BUCKET_MASK);
    }
    // -------------------------------------------------------------------------
    // RedisKeys Struct
    // Usage: Used to hold preformatted Redis keys for efficiency
    // -------------------------------------------------------------------------
    static void GenerateKeys(uint16_t bid, int app_id, RedisKeys& keys) 
    {
        // 1. Format Tag (Bucket ID) once
        auto res = std::to_chars(keys.tagBuf, keys.tagBuf + sizeof(keys.tagBuf), bid);
        keys.tagLen = res.ptr - keys.tagBuf;
        std::string_view bidStr(keys.tagBuf, keys.tagLen);

        // 2. Format App ID once
        char appBuf[16];
        auto appRes = std::to_chars(appBuf, appBuf + sizeof(appBuf), app_id);
        std::string_view appStr(appBuf, appRes.ptr - appBuf);

        // 3. Construct hKey: "APP:HA:{BID}"
        char* ptr = keys.hKeyBuf;
        std::memcpy(ptr, appStr.data(), appStr.size()); ptr += appStr.size();
        std::memcpy(ptr, ":HA:{", 5); ptr += 5;
        std::memcpy(ptr, bidStr.data(), bidStr.size()); ptr += bidStr.size();
        *ptr++ = '}';
        keys.hLen = ptr - keys.hKeyBuf;

        // 4. Construct zKey: "APP:TTL:{BID}"
        ptr = keys.zKeyBuf;
        std::memcpy(ptr, appStr.data(), appStr.size()); ptr += appStr.size();
        std::memcpy(ptr, ":TTL:{", 6); ptr += 6;
        std::memcpy(ptr, bidStr.data(), bidStr.size()); ptr += bidStr.size();
        *ptr++ = '}';
        keys.zLen = ptr - keys.zKeyBuf;
    }
};

class RedisHASerializer {
public:
    // Buffer needs to be large enough for the worst case (full struct + length headers)
    static constexpr size_t MAX_BUFFER_SIZE = sizeof(SyncDccaProxySessionData) + 16; 

    // ----------------------------------------------------------------
    // SERIALIZE: Strips Padding Zeros
    // ----------------------------------------------------------------
    static std::string_view Serialize(const SyncDccaProxySessionData& data, char* buffer, size_t bufferSize) 
    {
        char* ptr = buffer;
        const char* end = buffer + bufferSize;

        // 1. Write Integers/Enum (4 bytes each)
        // We write them as raw memory to handle endianness consistently on the same machine
        auto write_int = [&](int val) {
            if (ptr + sizeof(int) > end) return false;
            std::memcpy(ptr, &val, sizeof(int));
            ptr += sizeof(int);
            return true;
        };

        if (!write_int(data.appId)) return {};
        if (!write_int(data.event)) return {};
        if (!write_int(data.mModuleId)) return {};
        if (!write_int(static_cast<int>(data.op))) return {}; // Cast Enum to int

        // 2. Write Strings (Length-Prefixed)
        // Format: [1-byte Length][Data...]
        auto write_string = [&](const char* str, size_t maxArrLen) {
            // Find actual length (up to 150)
            // strnlen is safer than strlen for non-null-terminated garbage
            size_t actualLen = 0;
            while (actualLen < maxArrLen && str[actualLen] != '\0') {
                actualLen++;
            }
            
            // Check buffer space: 1 byte for len + data bytes
            if (ptr + 1 + actualLen > end) return false;

            // Write Length (safe cast since 150 < 255)
            *ptr = static_cast<char>(static_cast<uint8_t>(actualLen)); 
            ptr++;

            // Write Data (Only if len > 0)
            if (actualLen > 0) {
                std::memcpy(ptr, str, actualLen);
                ptr += actualLen;
            }
            return true;
        };

        if (!write_string(data.sessionId, sizeof(data.sessionId))) return {};
        if (!write_string(data.sourceName, sizeof(data.sourceName))) return {};
        if (!write_string(data.destName, sizeof(data.destName))) return {};

        // Return view of ONLY used bytes
        return std::string_view(buffer, ptr - buffer);
    }

    // ----------------------------------------------------------------
    // DESERIALIZE: Restores Padding Zeros
    // ----------------------------------------------------------------
    static bool Deserialize(std::string_view input, SyncDccaProxySessionData& data) 
    {
        const char* ptr = input.data();
        const char* end = input.data() + input.size();

        // 0. Zero out the struct first (Crucial for recreating the padding)
        std::memset(&data, 0, sizeof(SyncDccaProxySessionData));

        // 1. Read Integers
        auto read_int = [&](int& val) {
            if (ptr + sizeof(int) > end) return false;
            std::memcpy(&val, ptr, sizeof(int));
            ptr += sizeof(int);
            return true;
        };

        if (!read_int(data.appId)) return false;
        if (!read_int(data.event)) return false;
        if (!read_int(data.mModuleId)) return false;
        
        int opTemp = 0;
        if (!read_int(opTemp)) return false;
        data.op = static_cast<SyncOperation>(opTemp);

        // 2. Read Strings
        auto read_string = [&](char* destArr, size_t maxArrLen) {
            if (ptr + 1 > end) return false; // Need at least len byte

            // Read Length
            uint8_t len = static_cast<uint8_t>(*ptr);
            ptr++;

            // Safety: Ensure packet length matches declared string length
            if (ptr + len > end) return false;
            // Safety: Ensure we don't overflow the destination array
            if (len >= maxArrLen) return false; // >= to leave room for \0

            if (len > 0) {
                std::memcpy(destArr, ptr, len);
                ptr += len;
            }
            // Explicit null termination
            destArr[len] = '\0';
            return true;
        };

        if (!read_string(data.sessionId, sizeof(data.sessionId))) return false;
        if (!read_string(data.sourceName, sizeof(data.sourceName))) return false;
        if (!read_string(data.destName, sizeof(data.destName))) return false;

        return true;
    }
};



class RedisAsyncBridge {
public:
    static RedisAsyncBridge& instance() {
        static RedisAsyncBridge inst;
        return inst;
    }

    // Called by Calculation Threads (Producers)
    void Enqueue(const SyncDccaProxySessionData& data) {
        std::lock_guard<std::mutex> lock(m_mutex);
        m_pendingBuffer.push_back(data);
        
        // Notify Redis thread if we have work
        m_cv.notify_one();
    }

    // Called by Redis Processing Threads (Consumers)
    // Returns: A vector of data to process
    std::vector<SyncDccaProxySessionData> DequeueAll() 
    {
        std::vector<SyncDccaProxySessionData> workBuffer;
        {
            std::unique_lock<std::mutex> lock(m_mutex);
            
            // Wait until there is data (optional timeout to prevent blocking forever)
            m_cv.wait_for(lock, std::chrono::milliseconds(100), [this] { 
                return !m_pendingBuffer.empty(); 
            });

            if (m_pendingBuffer.empty()) return workBuffer;

            // THE SWAP TRICK:
            // Instead of copying data, we just swap the vectors.
            // This is O(1) and holds the lock for nanoseconds.
            workBuffer.swap(m_pendingBuffer);
        }
        return workBuffer;
    }

private:
    std::mutex m_mutex;
    std::condition_variable m_cv;
    std::vector<SyncDccaProxySessionData> m_pendingBuffer;
};


/*

/*
* Significantly faster for strings longer than ~16 bytes and provides mathematically superior distribution (fewer collisions).

inline uint32_t MurmurHash3_x86_32(const void* key, int len, uint32_t seed = 5381) {
    const uint8_t* data = (const uint8_t*)key;
    const int nblocks = len / 4;

    uint32_t h1 = seed;
    const uint32_t c1 = 0xcc9e2d51;
    const uint32_t c2 = 0x1b873593;

    // 1. Body: Process 4 bytes at a time (Much faster than 1 byte)
    const uint32_t* blocks = (const uint32_t*)(data + nblocks * 4);
    for (int i = -nblocks; i; i++) {
        uint32_t k1 = blocks[i]; // Fetch 32-bits at once

        k1 *= c1;
        k1 = (k1 << 15) | (k1 >> 17); // ROTL32
        k1 *= c2;

        h1 ^= k1;
        h1 = (h1 << 13) | (h1 >> 19); // ROTL32
        h1 = h1 * 5 + 0xe6546b64;
    }

    // 2. Tail: Handle remaining bytes (0-3 bytes)
    const uint8_t* tail = (const uint8_t*)(data + nblocks * 4);
    uint32_t k1 = 0;

    switch (len & 3) {
        case 3: k1 ^= tail[2] << 16;
        case 2: k1 ^= tail[1] << 8;
        case 1: k1 ^= tail[0];
            k1 *= c1; k1 = (k1 << 15) | (k1 >> 17); k1 *= c2; h1 ^= k1;
    };

    // 3. Finalization (Avalanche: ensures every input bit affects every output bit)
    h1 ^= len;
    h1 ^= h1 >> 16;
    h1 *= 0x85ebca6b;
    h1 ^= h1 >> 13;
    h1 *= 0xc2b2ae35;
    h1 ^= h1 >> 16;

    return h1;
}

// Updated Helper
inline uint16_t GetBucketId_Fast(const std::string& session_id) {
    // Use the faster hash, verify mask matches your total buckets
    uint32_t hash = MurmurHash3_x86_32(session_id.data(), session_id.length());
    return hash & 1023;
}

/*
* CPU has a specific instruction (_mm_crc32_u64) built into the silicon
    

#include <nmmintrin.h> // Intel SSE4.2
inline uint16_t GetBucketId_HW(const std::string& session_id) {
    uint64_t hash = 0;
    const char* data = session_id.data();
    size_t len = session_id.length();

    // Process 8 bytes at a time directly in Hardware
    size_t i = 0;
    for (; i + 8 <= len; i += 8) {
        // _mm_crc32_u64 is a single CPU instruction
        hash = _mm_crc32_u64(hash, *(const uint64_t*)(data + i));
    }

    // Process remaining bytes
    for (; i < len; ++i) {
        hash = _mm_crc32_u8(hash, data[i]);
    }

    return hash & 1023;
}

// Helper: Format Keys


*/