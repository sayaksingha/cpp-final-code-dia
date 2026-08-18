#ifndef DIAMETERBASICTEMPLATE
#define DIAMETERBASICTEMPLATE

#include "DiameterTLVUtil.h"
#include "DiameterBasicDecEnc.h"
#include "TssDiameterMsgException.h"
#include "base/include/DiameterMsgHeader.h"

#define ROUTE_RECORD_AVP_CODE 282

namespace DiameterTemplateDecoder
{

   typedef tuple < int, int, int> AVPIdentity;
   typedef multimap<int,AVPIdentity> AVPMap;

   UINT32 FindAVP(byteArray *array, UINT32 avpCode)
   {
      array->offset = 0;
      UINT32   lMsgLen = 0;
      UINT32   lIndex = 0;

      if(array->size < DIA_HEADER_LEN)
      {
         TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE, "Invalid Msg Len");
         throw lTssDiaMsgException;
      }

      array->offset++;
      if(false == DiameterTLVUtil::decodeMessageLength(array,lMsgLen))
      {
         TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE);
         throw lTssDiaMsgException;
      }
      lMsgLen -= DIA_HEADER_LEN;
      array->offset = DIA_HEADER_LEN; 

      while( lMsgLen > 0)
      {
         UINT32  lAvpCode;
         UINT8   lAvpFlag = 0;
         UINT32  lAvpLen = 0;
         UINT32  lAvpHeaderLen = 8;
         UINT32  lAvpDataLen = 0;

         lIndex = array->offset;
         if(false == DiameterTLVUtil::decodeIntegerValue(array, lAvpCode, DIA_AVP_CODE_SIZE))
         {
            TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding AVP");
            throw lTssDiaMsgException;
         }
         memcpy( &lAvpFlag, &array->byte[array->offset++],sizeof(UINT8));
         if(false == DiameterTLVUtil::decodeIntegerValue(array, lAvpLen, DIA_AVP_LEN_SIZE))
         {
            TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding AVP");
            throw lTssDiaMsgException;
         }
         if( true == DiameterTLVUtil::isVenderSpecific(lAvpFlag))
         {
            lAvpHeaderLen  = 12;
            array->offset += DIA_VENDER_SPEC_APPLN_ID_SIZE;
         }
         lAvpDataLen = lAvpLen-lAvpHeaderLen;
         if(lAvpCode == avpCode)
         {
            return lIndex;
         }
         array->offset+=lAvpDataLen;

         if( (lAvpLen % 4) == 0 )
         {
            lMsgLen = lMsgLen -lAvpLen;
         }
         else
         {
            lMsgLen = lMsgLen -( lAvpLen + ( 4-(lAvpLen%4)));
            array->offset+= ( 4-(lAvpLen%4));
         }
      }
      return 0;
   } 

   AVPMap FindAllAVP(byteArray *array, vector<UINT32>&& avpCodes)
   {
      array->offset = 0;
      UINT32   lMsgLen = 0;
      UINT32   lIndex = 0;
      AVPMap	avpMap;

      if(array->size < DIA_HEADER_LEN)
      {
         TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE, "Invalid Msg Len");
         throw lTssDiaMsgException;
      }

      array->offset++;
      if(false == DiameterTLVUtil::decodeMessageLength(array,lMsgLen))
      {
         TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE);
         throw lTssDiaMsgException;
      }
      lMsgLen -= DIA_HEADER_LEN;
      array->offset = DIA_HEADER_LEN; 

      while( lMsgLen > 0)
      {
         UINT32  lAvpCode;
         UINT8   lAvpFlag = 0;
         UINT32  lAvpLen = 0;
         UINT32  lAvpHeaderLen = 8;
         UINT32  lAvpDataLen = 0;

         lIndex = array->offset;
         if(false == DiameterTLVUtil::decodeIntegerValue(array, lAvpCode, DIA_AVP_CODE_SIZE))
         {
            TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding AVP");
            throw lTssDiaMsgException;
         }
         memcpy( &lAvpFlag, &array->byte[array->offset++],sizeof(UINT8));
         if(false == DiameterTLVUtil::decodeIntegerValue(array, lAvpLen, DIA_AVP_LEN_SIZE))
         {
            TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding AVP");
            throw lTssDiaMsgException;
         }
         if( true == DiameterTLVUtil::isVenderSpecific(lAvpFlag))
         {
            lAvpHeaderLen  = 12;
            array->offset += DIA_VENDER_SPEC_APPLN_ID_SIZE;
         }
         lAvpDataLen = lAvpLen-lAvpHeaderLen;

         auto it = std::find(std::begin(avpCodes), std::end(avpCodes), lAvpCode);

         if ( it != std::end(avpCodes)) {
            avpMap.insert(pair<int,AVPIdentity>(lAvpCode,make_tuple(lIndex,lAvpLen,lAvpFlag)));	
            //avpMap[lAvpCode] = make_tuple(lIndex,lAvpLen,lAvpFlag);	
         } 
         array->offset+=lAvpDataLen;

         if( (lAvpLen % 4) == 0 )
         {
            lMsgLen = lMsgLen -lAvpLen;
         }
         else
         {
            lMsgLen = lMsgLen -( lAvpLen + ( 4-(lAvpLen%4)));
            array->offset+= ( 4-(lAvpLen%4));
         }
      }
      return avpMap;
   }

   BOOLEAN CheckVersion(byteArray *array, vector<UINT32>&& avpCodes)
   {
      AVPMap lAVPMap = FindAllAVP(array, move(avpCodes));
      for (auto it = avpCodes.begin() ; it != avpCodes.end(); ++it)		
      {
         if ( lAVPMap.find(*it) == lAVPMap.end() ) {
            return false;
         }
      }
      return true;
   }

   void RemoveAVP(byteArray *array, UINT32 avpCode)
   {
      UINT32 lIndex  = 0;
      UINT32 lAvpLen = 0;


      if(!(lIndex = FindAVP(array, avpCode)))
      {
         TEXT lMessage[100] = "";
         snprintf(lMessage, sizeof(lMessage), "AVP %d not present", avpCode);
         TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE, lMessage);
         throw lTssDiaMsgException;
      }
      array->offset = lIndex + 5;
      if(false == DiameterTLVUtil::decodeIntegerValue(array, lAvpLen, DIA_AVP_LEN_SIZE))
      {
         TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding AVP");
         throw lTssDiaMsgException;
      }

      //memset(array->byte + lIndex, 0, (array->size - lIndex - lAvpLen));
      memmove(array->byte + lIndex, array->byte + (lIndex + lAvpLen), (array->size - lIndex - lAvpLen)); 
      array->offset=array->size;
      array->size-=lAvpLen;
      array->offset-=lAvpLen;
      memset(array->byte + array->size, 0, ( MAX_DIAMETER_PACKET_SIZE - array->size ));

      if(DiameterTLVUtil::avp_msg_length_encode(1, array) == false){
         TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE);
         throw lTssDiaMsgException;
      }	
   }

   template<class AVPType>
      void AddAVP(byteArray *array, UINT32 avpCode, UINT8 flags, UINT32 vendorId, 
            AVPType& avpType)
      {
         UINT32 lIndex = 0;

         if(avpCode != ROUTE_RECORD_AVP_CODE)
         {
            if(!(lIndex = FindAVP(array, ROUTE_RECORD_AVP_CODE)))
               lIndex = array->size;	
         }
         else
            lIndex = array->size;

         byteArray   lArray;
         memset(&lArray, 0, sizeof(byteArray));
         INT32 lHtonlVar = 0;
         lArray.size+=4;
         lHtonlVar =  htonl(avpCode);
         memcpy(lArray.byte, &lHtonlVar, DIA_AVP_CODE_SIZE);
         lArray.offset+=DIA_AVP_CODE_SIZE;
         lArray.size++;
         lArray.byte[lArray.offset++] = flags;
         unsigned lengthOffset = lArray.offset;
         lArray.size   += 3;
         lArray.offset += 3;

         if( true == DiameterTLVUtil::isVenderSpecific(flags))
         {
            lArray.size   += 4;
            lHtonlVar =  htonl(vendorId);
            memcpy(lArray.byte+lArray.offset, &lHtonlVar, DIA_VENDER_SPEC_APPLN_ID_SIZE);
            lArray.offset += DIA_VENDER_SPEC_APPLN_ID_SIZE;
         }

         if(avpType.Encode(&lArray) < 0 ||
               (DiameterTLVUtil::avp_length_encode(lengthOffset, &lArray) == false))
         {
            TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Encoding Error");
            throw lTssDiaMsgException;
         }

         if((array->size + lArray.size) > MAX_DIAMETER_PACKET_SIZE)
         {
            TEXT lMessage[100] = "";
            snprintf(lMessage, sizeof(lMessage), "Max Packet Size Exceeded size[%d]", 
                  (array->size + lArray.size));
            TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE, lMessage);
            throw lTssDiaMsgException;
         }

         memmove(array->byte + ( lIndex + lArray.size), array->byte+lIndex, (array->size - lIndex));
         memset(array->byte + lIndex, 0, lArray.size);
         memcpy(array->byte + lIndex, lArray.byte, lArray.size);
         array->offset=array->size;
         array->size+=lArray.size;
         array->offset+=lArray.offset;

         if(DiameterTLVUtil::avp_msg_length_encode(1, array) == false){
            TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE);
            throw lTssDiaMsgException;
         }
      }

   template<>
      void AddAVP<OctetString>(byteArray *array, UINT32 avpCode, UINT8 flags, UINT32 vendorId, 
            OctetString& avpType)
      {
         UINT32 lIndex = 0;

         if(avpCode != ROUTE_RECORD_AVP_CODE)
         {
            if(!(lIndex = FindAVP(array, ROUTE_RECORD_AVP_CODE)))
               lIndex = array->size;	
         }
         else
            lIndex = array->size;

         byteArray   lArray;
         memset(&lArray, 0, sizeof(byteArray));
         INT32 lHtonlVar = 0;
         lArray.size+=4;
         lHtonlVar =  htonl(avpCode);
         memcpy(lArray.byte, &lHtonlVar, DIA_AVP_CODE_SIZE);
         lArray.offset+=DIA_AVP_CODE_SIZE;
         lArray.size++;
         lArray.byte[lArray.offset++] = flags;
         unsigned lengthOffset = lArray.offset;
         lArray.size   += 3;
         lArray.offset += 3;

         if( true == DiameterTLVUtil::isVenderSpecific(flags))
         {
            lArray.size   += 4;
            lHtonlVar =  htonl(vendorId);
            memcpy(lArray.byte+lArray.offset, &lHtonlVar, DIA_VENDER_SPEC_APPLN_ID_SIZE);
            lArray.offset += DIA_VENDER_SPEC_APPLN_ID_SIZE;
         }

         if(avpType.Encode(&lArray) < 0 ||
               (DiameterTLVUtil::avp_length_encode(lengthOffset, &lArray, avpType.getLength()) == false))
         {
            TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,"Encode Error");
            throw lTssDiaMsgException;
         }

         if((array->size + lArray.size) > MAX_DIAMETER_PACKET_SIZE)
         {
            TEXT lMessage[100] = "";
            snprintf(lMessage, sizeof(lMessage), "Max Packet Size Exceeded size[%d]", 
                  (array->size + lArray.size));
            TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE,lMessage);
            throw lTssDiaMsgException;
         }

         memmove(array->byte + (lIndex + lArray.size), array->byte+lIndex, (array->size - lIndex));
         memset(array->byte + lIndex, 0, lArray.size);
         memcpy(array->byte + lIndex, lArray.byte, lArray.size);
         array->offset=array->size;
         array->size+=lArray.size;
         array->offset+=lArray.offset;

         if(DiameterTLVUtil::avp_msg_length_encode(1, array) == false){
            TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_ENCODE);
            throw lTssDiaMsgException;
         }
      }

   template<class AVPType>
      AVPType GetAVP(byteArray *array, UINT32 avpCode, BOOLEAN checkHeader = false)
      {
         array->offset = 0;
         UINT32   lMsgLen = 0;
         UINT16   lBytesDecoded = 0;
         BOOLEAN  lFound = false;
         AVPType  lAVPType ;

         if(checkHeader)
         {
            UINT8    lCmdFlag= 0;
            DiameterMsgHeader *lDiameterMsgHeader = new DiameterMsgHeader();
            if(lDiameterMsgHeader == NULL){
               TssDiameterMsgException lTssDiaMsgException(DIAMETER_NULL_HEADER_ERR);
               throw lTssDiaMsgException;
            }

            memcpy( &lDiameterMsgHeader->mVersion, &array->byte[0],sizeof(UINT8));
            if( lDiameterMsgHeader->mVersion != 1){
               TssDiameterMsgException lTssDiaMsgException(DIAMETER_VERSION_ERR, "Version");
               throw lTssDiaMsgException;
            }

            array->offset++;
            if(false == DiameterTLVUtil::decodeMessageLength(array, lDiameterMsgHeader->mMsgLen))
            {
               TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE);
               throw lTssDiaMsgException;
            }

            memcpy( &lCmdFlag, &array->byte[array->offset++],sizeof(UINT8));
            if(false == DiameterTLVUtil::decodeIntegerValue(array, lDiameterMsgHeader->mCmdCode, DIA_CMD_CODE_SIZE))
            {
               TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE);
               throw lTssDiaMsgException;
            }

            if(false == DiameterTLVUtil::decodeIntegerValue(array, lDiameterMsgHeader->mApplId, DIA_APPLN_ID_SIZE))
            {
               TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE);
               throw lTssDiaMsgException;
            }

            if(false == DiameterTLVUtil::decodeIntegerValue(array, lDiameterMsgHeader->mHopByHopId, DIA_HOP_BY_HOP_ID_SIZE))
            {
               TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE);
               throw lTssDiaMsgException;
            }

            if(false == DiameterTLVUtil::decodeIntegerValue(array, lDiameterMsgHeader->mEndToEndId, DIA_END_TO_END_ID_SIZE))
            {
               TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE);
               throw lTssDiaMsgException;
            }


            lMsgLen = (lDiameterMsgHeader->mMsgLen-array->offset);
            if( lDiameterMsgHeader->mMsgLen != array->size){
               TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE, "Invalid Msg Len");
               throw lTssDiaMsgException;
            }
         }
         else
         {
            if(array->size < DIA_HEADER_LEN)
            {
               TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE, "Invalid Msg Len");
               throw lTssDiaMsgException;
            }
            ++array->offset;
            if(false == DiameterTLVUtil::decodeMessageLength(array,lMsgLen))
            {
               TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE);
               throw lTssDiaMsgException;
            }
            lMsgLen -= DIA_HEADER_LEN;
            array->offset = DIA_HEADER_LEN; 
         }

         while( lMsgLen > 0)
         {
            UINT32  lAvpCode;
            UINT8   lAvpFlag = 0;
            UINT32  lAvpLen = 0;
            UINT32  lVenderId = 0;
            UINT32  lAvpHeaderLen = 8;
            UINT32  lAvpDataLen = 0;
            lBytesDecoded = 0;
            if(false == DiameterTLVUtil::decodeIntegerValue(array, lAvpCode, DIA_AVP_CODE_SIZE))
            {
               TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding AVP");
               throw lTssDiaMsgException;
            }
            memcpy( &lAvpFlag, &array->byte[array->offset++],sizeof(UINT8));
            if(false == DiameterTLVUtil::decodeIntegerValue(array, lAvpLen, DIA_AVP_LEN_SIZE))
            {
               TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding AVP");
               throw lTssDiaMsgException;
            }
            if( true == DiameterTLVUtil::isVenderSpecific(lAvpFlag))
            {
               lAvpHeaderLen = 12;
               if(false == DiameterTLVUtil::decodeIntegerValue(array, lVenderId, DIA_VENDER_SPEC_APPLN_ID_SIZE))
               {
                  TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding AVP");
                  throw lTssDiaMsgException;
               }

            }
            lAvpDataLen = lAvpLen-lAvpHeaderLen;
            if(lAvpCode == avpCode)
            {
               lFound = true;
               lAVPType.setAvpCode(avpCode);
               lAVPType.setAvpVendorId(lVenderId);
               lAVPType.mspByteArray = make_shared<byteArray>(*array);
               if(lAVPType.Decode(array, lAvpDataLen, &lBytesDecoded) < 0)
               {
                  TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding AVP");
                  throw lTssDiaMsgException;
               }
               break;
            }
            array->offset+=lAvpDataLen;

            if( (lAvpLen % 4) == 0 )
            {
               lMsgLen = lMsgLen -lAvpLen;
            }
            else
            {
               lMsgLen = lMsgLen -( lAvpLen + ( 4-(lAvpLen%4)));
               array->offset+= ( 4-(lAvpLen%4));
            }
         }
         if(!lFound)
         {
            TEXT lMessage[100] = "";
            snprintf(lMessage, sizeof(lMessage), "AVP %d not present", avpCode);
            TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,lMessage);
            throw lTssDiaMsgException;
         }
         return lAVPType;
      }

   template<class AVPType>
      list<AVPType> GetAVPList(byteArray *array, UINT32 avpCode, BOOLEAN checkHeader = false)
      {
         list<AVPType> avpList;
         AVPMap avpMap = FindAllAVP(array, move(vector<UINT32>({avpCode})));

         if ( avpMap.find(avpCode) != avpMap.end() )
         {
            auto avpMapItr = avpMap.equal_range(avpCode);
            auto itr = avpMapItr.first;
            for ( ; itr != avpMapItr.second; ++itr)
            {
               AVPIdentity lAVPIdentity = itr->second;
               UINT32 lAvpDataLen   = 0;
               UINT32 lAvpHeaderLen = 8;
               UINT16 lBytesDecoded = 0;

               array->offset = get<0>(lAVPIdentity);

               if( true == DiameterTLVUtil::isVenderSpecific(get<2>(lAVPIdentity)))
               {
                  lAvpHeaderLen  = 12;
                  array->offset += DIA_VENDER_SPEC_APPLN_ID_SIZE;
               }

               array->offset += (DIA_AVP_CODE_SIZE + 1 + DIA_AVP_LEN_SIZE);
               lAvpDataLen = get<1>(lAVPIdentity)-lAvpHeaderLen;

               AVPType avpType;
               avpList.push_back(avpType);
               avpList.back().setAvpCode(avpCode);
               avpList.back().mspByteArray = make_shared<byteArray>(*array);         
               if(avpList.back().Decode(array, lAvpDataLen, &lBytesDecoded) < 0)
               {
                  avpList.pop_back();
                  TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding AVP");
                  throw lTssDiaMsgException;
               }
            }
         }
         return avpList;
      }

   template<unsigned count>
      class DiameterDecoder
      {
         private:
            int avpCount = count;
            int avp_code[count];

            template<class ...AVPCodes>
               void set_avp_code(int s, AVPCodes...codes){
                  avp_code[avpCount-sizeof...(AVPCodes)-1] = std::move(s);
                  set_avp_code(std::forward<AVPCodes>(codes)...);
               }

            void set_avp_code(){}

            template<class T, class ...AVPTypes>
               void parse_AvpCodes(byteArray *array,AVPMap& avpMap, std::size_t r, T& t, AVPTypes&...types){

                  if ( avpMap.find(avp_code[r]) != avpMap.end() )
                  {
                     auto avpMapItr = avpMap.equal_range(avp_code[r]);
                     auto itr = avpMapItr.first;
                     if(avpMap.count(avp_code[r]) != 1)
                     {
                        TEXT lMessage[100] = "";
                        snprintf(lMessage, sizeof(lMessage), "Multiple occurence detected AVP: %d", avp_code[r]);
                        TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE, lMessage);
                        throw lTssDiaMsgException;
                     }
                     AVPIdentity lAVPIdentity = itr->second;	
                     UINT32 lAvpDataLen   = 0;
                     UINT32 lAvpHeaderLen = 8;
                     UINT16 lBytesDecoded = 0;

                     array->offset = get<0>(lAVPIdentity);
                     if( true == DiameterTLVUtil::isVenderSpecific(get<2>(lAVPIdentity)))
                     {
                        lAvpHeaderLen  = 12;
                        array->offset += DIA_VENDER_SPEC_APPLN_ID_SIZE;
                     }

                     array->offset += (DIA_AVP_CODE_SIZE + 1 + DIA_AVP_LEN_SIZE);
                     lAvpDataLen = get<1>(lAVPIdentity)-lAvpHeaderLen;

                     t.mspByteArray = make_shared<byteArray>(*array);
                     t.setAvpCode(avp_code[r]);
                     if(t.Decode(array, lAvpDataLen, &lBytesDecoded) < 0)
                     {
                        TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding AVP");
                        throw lTssDiaMsgException;
                     }
                     t.setAvpCode(avp_code[r]);
                     parse_AvpCodes(array, avpMap,r+1, types...);
                  }
                  else
                  {
                     TEXT lMessage[100] = "";
                     snprintf(lMessage, sizeof(lMessage), "Missing AVP: %d", avp_code[r]);
                     TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE, lMessage);
                     throw lTssDiaMsgException;
                  }
               }

            template<class T, class ...AVPTypes>
               void parse_AvpCodes(byteArray *array,AVPMap& avpMap, std::size_t r, list<T>& avpTypeList, AVPTypes&...types){

                  if ( avpMap.find(avp_code[r]) != avpMap.end() )
                  {
                     auto avpMapItr = avpMap.equal_range(avp_code[r]);
                     auto itr = avpMapItr.first;
                     for ( ; itr != avpMapItr.second; ++itr)
                     {
                        AVPIdentity lAVPIdentity = itr->second;
                        UINT32 lAvpDataLen   = 0;
                        UINT32 lAvpHeaderLen = 8;
                        UINT16 lBytesDecoded = 0;

                        array->offset = get<0>(lAVPIdentity);
   
                        if( true == DiameterTLVUtil::isVenderSpecific(get<2>(lAVPIdentity)))
                        {
                           lAvpHeaderLen  = 12;
                           array->offset += DIA_VENDER_SPEC_APPLN_ID_SIZE;
                        }

                        array->offset += (DIA_AVP_CODE_SIZE + 1 + DIA_AVP_LEN_SIZE);
                        lAvpDataLen = get<1>(lAVPIdentity)-lAvpHeaderLen;

                        T avpType;	
                        avpTypeList.push_back(avpType);
                        avpTypeList.back().setAvpCode(avp_code[r]);
                        avpTypeList.back().mspByteArray = make_shared<byteArray>(*array); 
                        if(avpTypeList.back().Decode(array, lAvpDataLen, &lBytesDecoded) < 0)
                        {
                           avpTypeList.pop_back();
                           TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding AVP");
                           throw lTssDiaMsgException;
                        }
                     }
                     parse_AvpCodes(array, avpMap,r+1, types...);
                  }
                  else
                  {
                     TEXT lMessage[100] = "";
                     snprintf(lMessage, sizeof(lMessage), "Missing AVP: %d", avp_code[r]);
                     TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE, lMessage);
                     throw lTssDiaMsgException;
                  }
               }

            void parse_AvpCodes(byteArray *array,AVPMap& avpMap,std::size_t r){}

         public:
            template<class ...AVPCodes>
               void set_AvpCode(AVPCodes...codes){
                  static_assert(sizeof...(AVPCodes)>=count,
                        "set_AvpCode::not enough avps specified");
                  static_assert(sizeof...(AVPCodes)<=count,
                        "set_AvpCode::too many avps specified");
                  set_avp_code(std::forward<AVPCodes>(codes)...);
               }

            template<class ...AVPTypes>
               bool read_Avps(byteArray *array,AVPTypes& ...types){
                  static_assert(sizeof...(AVPTypes)>=count,
                        "read_Avps::not enough avps specified");
                  static_assert(sizeof...(AVPTypes)<=count,
                        "read_Avps::too many avps specified");

                  array->offset = 0;
                  UINT32   lMsgLen = 0;
                  UINT32   lIndex = 0;

                  if(array->size < DIA_HEADER_LEN)
                  {
                     TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE, "Invalid Msg Len");
                     throw lTssDiaMsgException;
                  }

                  array->offset++;
                  if(false == DiameterTLVUtil::decodeMessageLength(array,lMsgLen))
                  {
                     TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE);
                     throw lTssDiaMsgException;
                  }
                  lMsgLen -= DIA_HEADER_LEN;
                  array->offset = DIA_HEADER_LEN;

                  AVPMap lAVPMap = FindAllAVP(array, 
                        move(vector<UINT32>(avp_code, avp_code + count)));

                  parse_AvpCodes(array, lAVPMap, 0, types...);
               }
      };

   // =========================================================================================
   // =========================================================================================

   string GetAVPString(byteArray *array, UINT32 avpCode, string avpType, BOOLEAN checkHeader = false) 
      {
         array->offset = 0;
         UINT32   lMsgLen = 0;
         UINT16   lBytesDecoded = 0;
         BOOLEAN  lFound = false;

         if(checkHeader)
         {
            UINT8    lCmdFlag= 0;
            DiameterMsgHeader *lDiameterMsgHeader = new DiameterMsgHeader();
            if(lDiameterMsgHeader == NULL){
               TssDiameterMsgException lTssDiaMsgException(DIAMETER_NULL_HEADER_ERR);
               throw lTssDiaMsgException;
            }

            memcpy( &lDiameterMsgHeader->mVersion, &array->byte[0],sizeof(UINT8));
            if( lDiameterMsgHeader->mVersion != 1){
               TssDiameterMsgException lTssDiaMsgException(DIAMETER_VERSION_ERR, "Version");
               throw lTssDiaMsgException;
            }

            array->offset++;
            if(false == DiameterTLVUtil::decodeMessageLength(array, lDiameterMsgHeader->mMsgLen))
            {
               TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE);
               throw lTssDiaMsgException;
            }

            memcpy( &lCmdFlag, &array->byte[array->offset++],sizeof(UINT8));
            if(false == DiameterTLVUtil::decodeIntegerValue(array, lDiameterMsgHeader->mCmdCode, DIA_CMD_CODE_SIZE))
            {
               TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE);
               throw lTssDiaMsgException;
            }

            if(false == DiameterTLVUtil::decodeIntegerValue(array, lDiameterMsgHeader->mApplId, DIA_APPLN_ID_SIZE))
            {
               TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE);
               throw lTssDiaMsgException;
            }

            if(false == DiameterTLVUtil::decodeIntegerValue(array, lDiameterMsgHeader->mHopByHopId, DIA_HOP_BY_HOP_ID_SIZE))
            {
               TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE);
               throw lTssDiaMsgException;
            }

            if(false == DiameterTLVUtil::decodeIntegerValue(array, lDiameterMsgHeader->mEndToEndId, DIA_END_TO_END_ID_SIZE))
            {
               TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE);
               throw lTssDiaMsgException;
            }


            lMsgLen = (lDiameterMsgHeader->mMsgLen-array->offset);
            if( lDiameterMsgHeader->mMsgLen != array->size){
               TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE, "Invalid Msg Len");
               throw lTssDiaMsgException;
            }
         }
         else
         {
            if(array->size < DIA_HEADER_LEN)
            {
               TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE, "Invalid Msg Len");
               throw lTssDiaMsgException;
            }
            ++array->offset;
            if(false == DiameterTLVUtil::decodeMessageLength(array,lMsgLen))
            {
               TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE);
               throw lTssDiaMsgException;
            }
            lMsgLen -= DIA_HEADER_LEN;
            array->offset = DIA_HEADER_LEN; 
         }

         while( lMsgLen > 0)
         {
            UINT32  lAvpCode;
            UINT8   lAvpFlag = 0;
            UINT32  lAvpLen = 0;
            UINT32  lVenderId = 0;
            UINT32  lAvpHeaderLen = 8;
            UINT32  lAvpDataLen = 0;
            lBytesDecoded = 0;
            if(false == DiameterTLVUtil::decodeIntegerValue(array, lAvpCode, DIA_AVP_CODE_SIZE))
            {
               TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding AVP");
               throw lTssDiaMsgException;
            }
            memcpy( &lAvpFlag, &array->byte[array->offset++],sizeof(UINT8));
            if(false == DiameterTLVUtil::decodeIntegerValue(array, lAvpLen, DIA_AVP_LEN_SIZE))
            {
               TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding AVP");
               throw lTssDiaMsgException;
            }
            if( true == DiameterTLVUtil::isVenderSpecific(lAvpFlag))
            {
               lAvpHeaderLen = 12;
               if(false == DiameterTLVUtil::decodeIntegerValue(array, lVenderId, DIA_VENDER_SPEC_APPLN_ID_SIZE))
               {
                  TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding AVP");
                  throw lTssDiaMsgException;
               }

            }
            lAvpDataLen = lAvpLen-lAvpHeaderLen;
            if(lAvpCode == avpCode)
            {
               lFound = true;
               if(avpType.compare("Unsigned32") == 0)
               {
                  Unsigned32 lAVPType;
                  if(lAVPType.Decode(array, lAvpDataLen, &lBytesDecoded) < 0)
                  {
                     TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding AVP");
                     throw lTssDiaMsgException;
                  }
                  return lAVPType.ToString();
               }	
               else if(avpType.compare("Unsigned64") == 0)
               {
                  Unsigned64 lAVPType;
                  if(lAVPType.Decode(array, lAvpDataLen, &lBytesDecoded) < 0)
                  {
                     TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding AVP");
                     throw lTssDiaMsgException;
                  }
                  return lAVPType.ToString();
               }
               else if(avpType.compare("Integer32") == 0)
               {
                  Integer32 lAVPType;
                  if(lAVPType.Decode(array, lAvpDataLen, &lBytesDecoded) < 0)
                  {
                     TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding AVP");
                     throw lTssDiaMsgException;
                  }
                  return lAVPType.ToString();
               }
               else if(avpType.compare("Integer64") == 0)
               {
                  Integer64 lAVPType;
                  if(lAVPType.Decode(array, lAvpDataLen, &lBytesDecoded) < 0)
                  {
                     TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding AVP");
                     throw lTssDiaMsgException;
                  }
                  return lAVPType.ToString();
               }
               else if(avpType.compare("OctetString") == 0)
               {
                  OctetString lAVPType;
                  if(lAVPType.Decode(array, lAvpDataLen, &lBytesDecoded) < 0)
                  {
                     TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding AVP");
                     throw lTssDiaMsgException;
                  }
                  return lAVPType.ToString();;
               }
               else
               {
                  TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding AVP [Unknown Type]");
                  throw lTssDiaMsgException;
               }
            }
            array->offset+=lAvpDataLen;

            if( (lAvpLen % 4) == 0 )
            {
               lMsgLen = lMsgLen -lAvpLen;
            }
            else
            {
               lMsgLen = lMsgLen -( lAvpLen + ( 4-(lAvpLen%4)));
               array->offset+= ( 4-(lAvpLen%4));
            }
         }
         if(!lFound)
         {
            TEXT lMessage[100] = "";
            snprintf(lMessage, sizeof(lMessage), "AVP %d not present", avpCode);
            TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,lMessage);
            throw lTssDiaMsgException;
         }
         return "";
      }


   list<string> GetAVPStringList(byteArray *array, UINT32 avpCode, string avpType, BOOLEAN checkHeader = false)
   {
      list<string> avpList;
      AVPMap avpMap = FindAllAVP(array, move(vector<UINT32>({avpCode})));

      if ( avpMap.find(avpCode) != avpMap.end() )
      {
         auto avpMapItr = avpMap.equal_range(avpCode);
         auto itr = avpMapItr.first;
         for ( ; itr != avpMapItr.second; ++itr)
         {
            AVPIdentity lAVPIdentity = itr->second;
            byteArray arrayTemp;
            UINT32 lAvpDataLen   = 0;
            UINT32 lAvpHeaderLen = 8;
            UINT16 lBytesDecoded = 0;

            memset(&arrayTemp, 0, sizeof(arrayTemp));

            memcpy(arrayTemp.byte, array->byte + get<0>(lAVPIdentity), get<1>(lAVPIdentity));

            if( true == DiameterTLVUtil::isVenderSpecific(get<2>(lAVPIdentity)))
            {
               lAvpHeaderLen  = 12;
               arrayTemp.offset += DIA_VENDER_SPEC_APPLN_ID_SIZE;
               arrayTemp.size += DIA_VENDER_SPEC_APPLN_ID_SIZE;
            }

            arrayTemp.offset += (DIA_AVP_CODE_SIZE + 1 + DIA_AVP_LEN_SIZE);
            arrayTemp.size += get<1>(lAVPIdentity);
            lAvpDataLen = get<1>(lAVPIdentity)-lAvpHeaderLen;

            if(avpType.compare("Unsigned32") == 0)
            {
               Unsigned32 lAVPType;
               if(lAVPType.Decode(&arrayTemp, lAvpDataLen, &lBytesDecoded) < 0)
               {
                  TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding AVP");
                  throw lTssDiaMsgException;
               }
               avpList.push_back(lAVPType.ToString());
            }
            else if(avpType.compare("Unsigned64") == 0)
            {
               Unsigned64 lAVPType;
               if(lAVPType.Decode(&arrayTemp, lAvpDataLen, &lBytesDecoded) < 0)
               {
                  TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding AVP");
                  throw lTssDiaMsgException;
               }
               avpList.push_back(lAVPType.ToString());
            }
            else if(avpType.compare("Integer32") == 0)
            {
               Integer32 lAVPType;
               if(lAVPType.Decode(&arrayTemp, lAvpDataLen, &lBytesDecoded) < 0)
               {
                  TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding AVP");
                  throw lTssDiaMsgException;
               }
               avpList.push_back(lAVPType.ToString());
            }
            else if(avpType.compare("Integer64") == 0)
            {
               Integer64 lAVPType;
               if(lAVPType.Decode(&arrayTemp, lAvpDataLen, &lBytesDecoded) < 0)
               {
                  TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding AVP");
                  throw lTssDiaMsgException;
               }
               avpList.push_back(lAVPType.ToString());
            }
            else if(avpType.compare("OctetString") == 0)
            {
               OctetString lAVPType;
               if(lAVPType.Decode(&arrayTemp, lAvpDataLen, &lBytesDecoded) < 0)
               {
                  TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding AVP");
                  throw lTssDiaMsgException;
               }
               avpList.push_back(lAVPType.ToString());
            }
            else
            {
               TssDiameterMsgException lTssDiaMsgException(DIAMETER_ERR_DECODE,"Error decoding AVP [Unknown Type]");
               throw lTssDiaMsgException;
            }
         }
      }
      return avpList;
   }

}

#endif
