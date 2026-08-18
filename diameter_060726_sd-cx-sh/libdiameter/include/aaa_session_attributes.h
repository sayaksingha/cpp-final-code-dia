// @(#) $Id: aaa_session_attributes.h,v 1.1.4.1.2.1 2018/02/21 23:00:47 anandhv Exp $
//---------------------------------------------------------------
// NAME : aaa_session_attributes.h
//
// COPYRIGHT
// TSS : - Copyright (C) 2001 Tayana Software Solution Pvt Ltd.,
//         All rights reserved. No part of this computer program
//         may be used or reproduced in any form by any
//         means without prior written permission of
//         Tayana Software Solution Pvt Ltd.
//
// DESCRIPTION
//
// Originated:
//----------------------------------------------------------------
#ifndef __AAA_SESSION_ATTRIBUTES_H__
#define __AAA_SESSION_ATTRIBUTES_H__

#include "diameter_parser.h"
#include "aaa_parser_defs.h"

class DIAMETERBASEPROTOCOL_EXPORT DiameterSessionCounter {
     public:
        DiameterSessionCounter(diameter_unsigned32_t h = 0,
                           diameter_unsigned32_t l = 0) :
            m_High(h),
            m_Low(l) {
        }        
        diameter_unsigned32_t &High() {
            return m_High;
        }
        diameter_unsigned32_t &Low()  {
            return m_Low;
        }
        int operator=(DiameterSessionCounter &cntr) {
            High() = cntr.High();
            Low() = cntr.Low();
            return (true);
        }
        int operator==(DiameterSessionCounter &cntr) {
            return ((m_High == cntr.High()) &&
                    (m_Low == cntr.Low()));
        }
        int operator<(DiameterSessionCounter &cntr) {
           if (m_High < cntr.High()) {
              return (true);
           }
           else if ((m_High == cntr.High()) &&
                    (m_Low < cntr.Low())) {
              return (true);
           }
           return (false);
        }
        int operator++() {
           m_Low ++;
           if (m_Low == 0xffffffff) {
              m_Low = 0x0;
              m_High ++;
           }
           if (m_High == 0xffffffff) {
              m_High = 0;
           }
           return (true);
        }

     protected:
        diameter_unsigned32_t m_High;
        diameter_unsigned32_t m_Low;
};

class DIAMETERBASEPROTOCOL_EXPORT DiameterSessionId : 
    public DiameterSessionCounter 
{
    public:
        DiameterSessionId() {
        }
        virtual ~DiameterSessionId() {
        }
        bool operator==(DiameterSessionId &id) {
            if ((DiameterSessionCounter&)(*this) ==
                (DiameterSessionCounter&)id) {
                if (DiameterId() == id.DiameterId()) {
                    if (OptionalValue().length() > 0) {
                        if (OptionalValue() == 
                            id.OptionalValue()) {
                            return true;
                        }
                    }
                    else {
                        return true;
                    }
                }
            }
            return false;
        }
        bool operator=(DiameterSessionId &id) {
            High() = id.High();
            Low() = id.Low();
            DiameterId() = id.DiameterId();
            OptionalValue() = id.OptionalValue();
            return true;
        }
        std::string &DiameterId() {
            return m_DiameterId;
        }
        std::string &OptionalValue() {
            return m_OptionalVal;
        }
        bool IsEmpty() {
            return (m_DiameterId.length() == 0) ? true : false;
        }
        AAAReturnCode Get(DiameterMsg &msg);
        AAAReturnCode Set(DiameterMsg &msg);
        void Dump();
        void Dump(std::string &dump);
    private:
        std::string m_DiameterId;
        std::string m_OptionalVal;
};

class DIAMETERBASEPROTOCOL_EXPORT DiameterSessionAttributes :
    public AAA_JobData
{
	public:

        std::string &DestinationHost() {
            return m_DestinationHost;
        }
        std::string &DestinationRealm() {
            return m_DestinationRealm;
        }
        std::string &Username() {
            return m_Username;
        }
        diameter_unsigned32_t &SessionTimeout() {
            return m_SessionTimeout;
        }

        DiameterSessionId &SessionId() {
            return m_SessionId;
        }
        diameter_unsigned32_t &LastTxHopId() {
            return m_LastTxHopId;
        }
        diameter_unsigned32_t &LastTxEndId() {
            return m_LastTxEndId;
        }
        diameter_unsigned32_t &LastRxHopId() {
            return m_LastRxHopId;
        }
        diameter_unsigned32_t &LastRxEndId() {
            return m_LastRxEndId;
        }
        diameter_unsigned32_t &ApplicationId() {
            return m_ApplicationId;
        }
        void MsgIdTxMessage(DiameterMsg &msg);
        bool MsgIdRxMessage(DiameterMsg &msg);

    private:
        DiameterSessionId m_SessionId;            // session id (RTM)
        diameter_unsigned32_t m_LastTxHopId;
        diameter_unsigned32_t m_LastTxEndId;
        diameter_unsigned32_t m_LastRxHopId;
        diameter_unsigned32_t m_LastRxEndId;
        diameter_unsigned32_t m_ApplicationId;
        std::string m_DestinationHost;
        std::string m_DestinationRealm;
        std::string m_Username;
        diameter_unsigned32_t m_SessionTimeout;
};


class DiameterAuthSessionAttributes :
    public DiameterSessionAttributes
{
    public:
        DiameterReAuthValue &ReAuthRequestValue() {
            return m_ReAuthRequestValue;
        }
        diameter_unsigned32_t &AuthSessionState() {
            return m_AuthSessionState;
        }
        diameter_unsigned32_t &AuthLifetime() {
            return m_AuthLifetime;
        }
        diameter_unsigned32_t &AuthGrace() {
            return m_AuthGrace;
        }

    private:
        DiameterReAuthValue   m_ReAuthRequestValue;
        diameter_unsigned32_t m_AuthSessionState;
        diameter_unsigned32_t m_AuthLifetime;
        diameter_unsigned32_t m_AuthGrace;
};

#endif
