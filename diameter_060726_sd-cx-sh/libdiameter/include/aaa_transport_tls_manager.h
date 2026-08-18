// DiameterTLSManager.h
#ifndef DIAMETER_TLS_MANAGER_H
#define DIAMETER_TLS_MANAGER_H

#include <ace/SSL/SSL_Context.h>
#include <ace/Singleton.h>
#include <ace/Synch.h>
#include <map>
#include <string>

// Simple Manager to hold Certificates per Host Identity
class DiameterTLSManager {
public:
    struct HostTLSConfig {
        std::string identity;
        std::string certFile;
        std::string keyFile;
        std::string caFile;
        std::string keyPassphrase;
        std::string cipherList;
        bool verifyPeer;
    };

    int LoadHostIdentity(const HostTLSConfig& config) {
        ACE_Guard<ACE_Thread_Mutex> guard(m_lock);
        if (m_contexts.find(config.identity) != m_contexts.end()) return 0;

        ACE_SSL_Context* ctx = new ACE_SSL_Context();
        ctx->set_mode(ACE_SSL_Context::TLSv1_2);
        
        // Critical: Load Trust Store
        if (ctx->load_trusted_ca(config.caFile.c_str()) != 0) { delete ctx; return -1; }
        
        // Critical: Load Identity
        if (ctx->load_certificate(config.certFile.c_str(), config.keyFile.c_str(), config.keyPassphrase.c_str()) != 0) { delete ctx; return -1; }
        
        // Critical: Set Ciphers
        if (ctx->set_cipher_list(config.cipherList.c_str()) != 0) { delete ctx; return -1; }

        if (config.verifyPeer) 
            ctx->set_verify_mode(ACE_SSL_Context::VERIFY_PEER | ACE_SSL_Context::FAIL_IF_NO_PEER_CERT | ACE_SSL_Context::CLIENT_ONCE);
        else 
            ctx->set_verify_mode(ACE_SSL_Context::VERIFY_NONE);

        m_contexts[config.identity] = ctx;
        return 0;
    }

    ACE_SSL_Context* GetContext(const std::string& identity) {
        ACE_Guard<ACE_Thread_Mutex> guard(m_lock);
        auto it = m_contexts.find(identity);
        return (it != m_contexts.end()) ? it->second : nullptr;
    }

private:
    friend class ACE_Singleton<DiameterTLSManager, ACE_Null_Mutex>;
    DiameterTLSManager() {}
    std::map<std::string, ACE_SSL_Context*> m_contexts;
    ACE_Thread_Mutex m_lock;
};

typedef ACE_Singleton<DiameterTLSManager, ACE_Null_Mutex> TLS_MANAGER;
#endif