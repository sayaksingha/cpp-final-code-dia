static const char *id = " @(#) $Id: aaa_transport_collector.cc,v 1.1.4.1.2.1.2.16 2024/05/15 13:12:15 mram Exp $";
//----------------------------------------------------------------------
// NAME
// aaa_transport_collector.cc
//
// COPYRIGHT
// Tayana Software Solutions Pvt Ltd -- Copyright(C) 2007
// All rights reserved. No part of this computer program
// may be used or reproduced in any form by any
// means without prior written permission of
// Tayana Software Solutions Pvt Ltd
//
// DESCRIPTION
//
// Originated :                                     Date:
//----------------------------------------------------------------------
#include "aaa_transport_collector.h"
#include "aaa_peer_table.h"
//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
DiameterRxMsgCollector::DiameterRxMsgCollector() :
    m_Buffer(NULL),
    m_Offset(0),
    m_BufSize(0),
    m_MsgLength(0),
    m_Handler(NULL)
{
   m_Buffer = (char*)ACE_OS::malloc(DIAMETER_HEADER_SIZE + DIAMETER_CFG_TRANSPORT()->rx_buffer_size);

   if (m_Buffer != NULL) 
	{
      m_BufSize = DIAMETER_HEADER_SIZE + DIAMETER_CFG_TRANSPORT()->rx_buffer_size;
      ACE_OS::memset(m_Buffer, 0, m_BufSize);
      m_PersistentError.Reset(0, 0,(m_BufSize * MSG_COLLECTOR_MAX_MSG_BLOCK)/sizeof(ACE_UINT32));
   }
	else
	{
		// Error Log - 
		AAA_LOG((LM_CRITICAL, "%T |TRANSPORT| Rx Buffer memory allocation failed\n"));
	}
}
//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------

DiameterRxMsgCollector::~DiameterRxMsgCollector()
{
   if (m_Buffer) 
	{
      ACE_OS::free(m_Buffer);
   }
}

//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
void DiameterRxMsgCollector::ReceiveMessage(void *data, size_t length)
{
   if (m_Buffer == NULL || m_Handler == NULL) 
   {
		// Log 
		AAA_LOG((LM_CRITICAL, "%T |TRANSPORT| Rx Buffer is NULL\n"));
      return;
   }

   int r_bytes 			= 0;
   int lTotalMsglength  = length;
   bool bHasHeaderError = false;
   std::string eDesc;
	
   while (length > 0) 
   {
		r_bytes = (length > size_t(m_BufSize - m_Offset)) ? m_BufSize - m_Offset : length;

	   ACE_OS::memcpy(m_Buffer + m_Offset, data, r_bytes);

		length   -= r_bytes;
	   data      = (char*)data + r_bytes;
	   m_Offset += (r_bytes > 0) ? r_bytes : 0;

	   while (m_Offset > DIAMETER_HEADER_SIZE) 
	   {
			//DiameterMsgHeader hdr;
		   //memset(&hdr		 , 0x0, sizeof(hdr));
		
		std::unique_ptr<DiameterMsg> 		lDiameterMsg(new DiameterMsg);
		std::unique_ptr<DiameterBase>      lDiameterBase(new DiameterBase);

        // std::unique_ptr<DiameterMsg>     lDiameterMsg(new DiameterMsg);
        // std::unique_ptr<DiameterBase>    lDiameterBase(new DiameterBase);

			DiameterMsgHeader *lDiameterMsgHeader = 0;
			memset(&lDiameterMsg->rawbyteArray, 0,  sizeof(lDiameterMsg->rawbyteArray));
			ACE_OS::memcpy(&lDiameterMsg->rawbyteArray.byte, m_Buffer, DIAMETER_HEADER_SIZE);
			lDiameterMsg->rawbyteArray.size = r_bytes;
			
		   if (m_MsgLength == 0) 
		   {
				try 
			   {
					lDiameterMsgHeader = lDiameterBase->decodeDiameterMsgHeader(&lDiameterMsg->rawbyteArray);

					if(lDiameterMsgHeader == NULL)
					{
						AAA_LOG((LM_CRITICAL, "%T |TRANSPORT| Unable to Decode Diameter Message Header\n"));
						return ;
					}
					else
					{						AAA_LOG((LM_CRITICAL,"%T |TRANSPORT| Received TCP Len: %d m_Offset: %d r_bytes: %d Decode header Len: %d AppId: %d CmdCode:%d HH:%u EE:%u\n", lTotalMsglength , m_Offset , r_bytes, lDiameterMsgHeader->mMsgLen , lDiameterMsgHeader->mApplId, lDiameterMsgHeader->mCmdCode,lDiameterMsgHeader->mHopByHopId ,lDiameterMsgHeader->mEndToEndId));
					}

				}
				catch (TssDiameterMsgException &msgException) 
				{
					m_MsgLength = 0;
					AAA_LOG((LM_ERROR, "%T |TRANSPORT| Failed to decode Msg Header\n"));
					return ;

				}

				m_MsgLength = lDiameterMsgHeader->mMsgLen;
			} // Header Decode.

			/*AAA_LOG((LM_INFO, "%T TDS_Rx HH:%X EE:%X CC:%d R:%d MsgLen:%d Header Decode Success\n", 
			  lDiameterMsgHeader->mHopByHopId, lDiameterMsgHeader->mEndToEndId, lDiameterMsgHeader->mCmdCode, 
			  lDiameterMsgHeader->mCmdFlg.rBit, lDiameterMsgHeader->mMsgLen));*/

			if (m_MsgLength > m_Offset) 
			{
				if (m_MsgLength > m_BufSize) 
				{
					m_Buffer = (char*)ACE_OS::realloc(m_Buffer,m_MsgLength + 1);

					if (m_Buffer) 
					{
						ACE_OS::memset(m_Buffer + m_BufSize, 0, m_MsgLength - m_BufSize + 1);
						m_BufSize = m_MsgLength + 1;
					}
					else 
					{
						m_BufSize = 0;
						m_Offset = 0;
						m_MsgLength = 0;

						eDesc = "Byte buffer too small but failed to re-alloc";
						m_Handler->Error (DiameterRxMsgCollectorHandler::MEMORY_ALLOC_ERROR, eDesc);

						AAA_LOG((LM_CRITICAL, "%T |TRANSPORT| Byte buffer too small but failed to re-alloc\n"));
						return; 
					}
				}
				else 
				{
					break;
				}
			}
			else 
			{
				if (! bHasHeaderError) 
				{
					std::unique_ptr<DiameterMsg> lDiameterMsg(new DiameterMsg);
               //std::unique_ptr<DiameterMsg> lDiameterMsg(new DiameterMsg);

					try 
					{
						if (lDiameterMsg.get() == NULL) 
						{
							// Log 
							AAA_LOG((LM_CRITICAL, "%T |TRANSPORT| DiameterMsg is NULL\n"));
						   throw (0);
					   }
							
						if ( lDiameterMsgHeader == 0 || lDiameterMsgHeader == NULL )
						{
							memset(&lDiameterMsg->rawbyteArray, 0, sizeof(lDiameterMsg->rawbyteArray)); 

							if(m_MsgLength > sizeof(lDiameterMsg->rawbyteArray.byte))
							{
								eDesc = "Msg len exceeds capacity, capacity:"+to_string(sizeof(lDiameterMsg->rawbyteArray.byte))+" Msg len:"+to_string(m_MsgLength);
								m_Handler->Error (DiameterRxMsgCollectorHandler::MEMORY_ALLOC_ERROR, eDesc);
								AAA_LOG((LM_CRITICAL, "%T |TRANSPORT| Msg len exceeds capacity\n"));
								return;
							}

							ACE_OS::memcpy(&lDiameterMsg->rawbyteArray.byte, m_Buffer, m_MsgLength);
							lDiameterMsg->rawbyteArray.size = m_MsgLength;

							lDiameterMsgHeader = lDiameterBase->decodeDiameterMsgHeader(&lDiameterMsg->rawbyteArray);
							memcpy(&lDiameterMsg->hdr, lDiameterMsgHeader, sizeof(DiameterMsgHeader));

							/*m_BufSize   = 0;
							m_Offset    = 0;
							m_MsgLength = 0;

							AAA_LOG((LM_INFO, "%T TBRRRRRRRRR Byte buffer too small but failed to re-alloc\n"));
							exit(0);

							eDesc = "Byte buffer too small but failed to re-alloc";
							m_Handler->Error
								(DiameterRxMsgCollectorHandler::MEMORY_ALLOC_ERROR, eDesc);
							return;*/

						}
						else
						{
							memcpy(&lDiameterMsg->hdr, lDiameterMsgHeader, sizeof(DiameterMsgHeader));

							memset(&lDiameterMsg->rawbyteArray, 0, sizeof(lDiameterMsg->rawbyteArray)); 

							if(m_MsgLength > sizeof(lDiameterMsg->rawbyteArray.byte))
							{
								eDesc = "Msg len exceeds capacity, capacity:"+to_string(sizeof(lDiameterMsg->rawbyteArray.byte))+" Msg len:"+to_string(m_MsgLength);
								m_Handler->Error (DiameterRxMsgCollectorHandler::MEMORY_ALLOC_ERROR, eDesc);
								return;
							}

							ACE_OS::memcpy(&lDiameterMsg->rawbyteArray.byte, m_Buffer, m_MsgLength);
							lDiameterMsg->rawbyteArray.size = m_MsgLength;
						}

					}
					catch (DiameterErrorCode &st) 
					{
						/*
							int eCode;
							AAA_PARSE_ERROR_TYPE eType;

							st.get(eType, eCode, eDesc);

							if (eType == AAA_PARSE_ERROR_TYPE_NORMAL) 
							{

							SendFailedAvp(st);

							m_Offset -= m_MsgLength;
							ACE_OS::memcpy(m_Buffer, m_Buffer + m_Offset,	m_MsgLength);

							eDesc = "Payload error encounted in newly arrived message";
							m_Handler->Error	(DiameterRxMsgCollectorHandler::PARSING_ERROR, eDesc);
							continue;
							}
							else 
							{
							eDesc = "Bug present in the parsing code !!!!";
							m_Handler->Error
							(DiameterRxMsgCollectorHandler::BUG_IN_PARSING_CODE, eDesc);
							return;
							}*/
						AAA_LOG((LM_CRITICAL, "%T |TRANSPORT| DiameterErrorCode Exception \n"));
					} 
					catch (...) 
					{
						if ((lDiameterMsg.get() == NULL )) 
						{
							m_BufSize   = 0;
							m_Offset    = 0;
							m_MsgLength = 0;

							eDesc = "Byte buffer too small but failed to re-alloc";
							m_Handler->Error
								(DiameterRxMsgCollectorHandler::MEMORY_ALLOC_ERROR, eDesc);

							AAA_LOG((LM_CRITICAL, "%T |TRANSPORT| Byte buffer too small but failed to re-alloc\n"));
							return;
						}
						AAA_LOG((LM_CRITICAL, "%T |TRANSPORT| DiameterErrorCode Exception \n"));
					}
	AAA_LOG((LM_INFO,"%T |TRANSPORT| Decode header Len:%d Flag:%s %s %s %s AppId:%d CmdCode:%d HH:%u EE:%u \n",lDiameterMsgHeader->mMsgLen ,lDiameterMsgHeader->mCmdFlg.rBit?" REQ":"", lDiameterMsgHeader->mCmdFlg.pBit?" PXY":"",
								lDiameterMsgHeader->mCmdFlg.eBit?" ERR":"", lDiameterMsgHeader->mCmdFlg.tBit?" TRX":"",
								lDiameterMsgHeader->mApplId, lDiameterMsgHeader->mCmdCode,
								lDiameterMsgHeader->mHopByHopId ,lDiameterMsgHeader->mEndToEndId));

	
					m_Handler->HandleMessage(std::move(lDiameterMsg));

					m_PersistentError.Reset(0, 0,(m_BufSize *	MSG_COLLECTOR_MAX_MSG_BLOCK)/sizeof(ACE_UINT32));

				}
				else 
				{
					eDesc = "Header error encounted in newly arrived message";
					m_Handler->Error
						(DiameterRxMsgCollectorHandler::PARSING_ERROR, eDesc);
				}

				if (m_MsgLength < m_Offset) 
				{
					//ACE_OS::memcpy(m_Buffer, m_Buffer + m_MsgLength, m_Offset - m_MsgLength);
					memmove(m_Buffer, m_Buffer + m_MsgLength, m_Offset - m_MsgLength);
					m_Offset -= m_MsgLength;
				}
				else 
				{
					m_Offset = 0;
				}

				ACE_OS::memset(m_Buffer + m_Offset, 0, m_BufSize - m_Offset);
				m_MsgLength = 0;
			}
		} // m_Offset > DIAMETER_HEADER_SIZE)
	}  // length > 0)
}

//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
void DiameterRxMsgCollector::SendFailedAvp(DiameterErrorCode &st)
{
	// AAA_OUT_OF_SPACE
	// AAA_INVALID_AVP_VALUE
	// AAA_AVP_UNSUPPORTED
	// AAA_MISSING_AVP
	// AAA_INVALID_AVP_BITS
	// AAA_AVP_OCCURS_TOO_MANY_TIMES

	// TBD:
	// std::unique_ptr<DiameterMsg> answerMsg = DiameterErrorMsg::Generate(lDiameterMsg, eCode);
	// m_Handler->SendErrorAnswer(answerMsg);
}


//-------------------------------------------------------------------------------
// METHOD      :
// DESCRIPTION :
// PARAMETER   :
// RETURN      :
// THROWS      :
//-------------------------------------------------------------------------------
int DiameterTxMsgCollector::SafeSend(DiameterMsg *lDiameterMsg,
		Diameter_IO_Base *io)
{
	BOOLEAN retVal = true;
	byteArray lRawByte;	
	
	string lDH = lDiameterMsg->destinationHost;
	string lDR = lDiameterMsg->destinationRealm;
	std::string lLogText = LOG_DIAMETER_AVPS_L(*lDiameterMsg);
	
	if(lDiameterMsg == NULL)
	{
		AAA_LOG((LM_ERROR,
       "%T |TRANSPORT| PeerName:%s Message is NULL\n",mPeerName.c_str()));

		return false;
	}

	if(io == NULL || io->isRunning() == false)
	{
#if 0
		DiameterPeerEntry *lPeerPtr = DIAMETER_PEER_TABLE()->Lookup(PeerName());

		if(query.IsBaseProtocol())
		{
			io = lPeerPtr->getIOObject();
			if ( io == NULL)
			{
				AAA_LOG((LM_ERROR, "%T |TRANSPORT| Send failed\n"));
				return false;
			}
		}
		else
		{
			AAA_LOG((LM_ERROR, "%T |TRANSPORT| TBR Send failed------------------2\n"));
		}
		if (lPeerPtr != NULL && lPeerPtr->IsOpen())
		{
			io = lPeerPtr->getIOObject();
			if ( io == NULL)
			{
				AAA_LOG((LM_ERROR, "%T |TRANSPORT| %s IO is null, Dropping Message,DH:%s\n",
							lLogText.c_str(), lDH.c_str()));
				return false;
			}
			AAA_LOG((LM_ERROR, "%T |TRANSPORT| %s TBR Got Peer,DH:%s\n",
						lLogText.c_str(), lDH.c_str()));
		}
		else
		{
			AAA_LOG((LM_ERROR, "%T |TRANSPORT| %s TBR Peer Not Open,DH:%s,PeerName:%s\n",
						lLogText.c_str(), lDH.c_str(),PeerName().c_str()));
			return false;
		}
#endif

		AAA_LOG((LM_ERROR, "%T |TRANSPORT| %s Peer Not Open,DH:%s,PeerName:%s\n",
					lLogText.c_str(), 
					lDH.c_str(),
					PeerName().c_str()));
		return false;
	}

	DiameterMsgQuery query(*lDiameterMsg);

	if(!query.IsBaseProtocol())
	{
		retVal = false;
		retVal = DiaHandleMsg::EncodeMsg(*lDiameterMsg,lRawByte);
	}

	//for ASR
	if(0 != lDiameterMsg->hdr.mApplId && query.IsBaseProtocol()) 
	{
		retVal = false;
		retVal = DiaHandleMsg::EncodeMsg(*lDiameterMsg,lRawByte);
	}

	//(DiameterPeerData)this.m_peg->GeneratePeg(E_CER_MSG);

	//	return retVal==true?io->SendData(&lDiameterMsg->rawbyteArray):false;

	//try{
	//std::string lLogText = LOG_DIAMETER_AVPS(*lDiameterMsg);
	//std::string lLogText = "::= <CC:"+to_string(lDiameterMsg->hdr.mCmdCode)+(lDiameterMsg->hdr.mCmdFlg.rBit?" REQ":"")+(lDiameterMsg->hdr.mCmdFlg.pBit?" PXY":"")+(lDiameterMsg->hdr.mCmdFlg.eBit?" ERR":"")+(lDiameterMsg->hdr.mCmdFlg.tBit?" TRX":"")+" HH:"+to_string(lDiameterMsg->hdr.mHopByHopId)+" EE:"+to_string(lDiameterMsg->hdr.mEndToEndId)+" APPID:"+to_string(lDiameterMsg->hdr.mApplId)+"> " + "<Session-Id:"+lDiameterMsg->sessionId+"> "+"{Origin-Host:"+lDiameterMsg->originationHost+"} {Origin-Realm:"+lDiameterMsg->originationRealm+"}";

	if(retVal == true)
	{
		//int bytes = io->SendData(&lDiameterMsg->rawbyteArray);
		int bytes = 0;
		bool status = true;

		if(!query.IsBaseProtocol()||(0 != lDiameterMsg->hdr.mApplId && query.IsBaseProtocol()))
		{
			bytes = io->SendData(&lRawByte);
			if(bytes != lRawByte.size)
				status = false;
		}
		else
		{
			bytes = io->SendData(&lDiameterMsg->rawbyteArray);
			if(bytes != lDiameterMsg->rawbyteArray.size)
				status = false;
		}
		
		//if(bytes != lDiameterMsg->rawbyteArray.size)
		if(!status)
		{
			AAA_LOG((LM_ERROR, "%T |TRANSPORT| %s DestHost:%s Message send failed\n",
						lLogText.c_str() , lDiameterMsg->destinationHost.c_str()));	
			
			return false;
		}
		else
		{
			AAA_LOG((LM_CRITICAL, "%T |TRANSPORT| %s DH:%s DR:%s Message send success\n",
						lLogText.c_str(),lDH.c_str(), lDR.c_str() )); 
			return true;
		}
	}
	AAA_LOG((LM_ERROR, "%T |TRANSPORT| Message encode failed\n"));

	//AAA_LOG((LM_ERROR, "%T |TRANSPORT| %s ,Message encode failed\n",
	//			lLogText.c_str()));

	/*}
	catch(std::bad_alloc& e)
	{
		cout<<"Memory allocation bug : "<<e.what()<<endl;
		std::terminate();
	}*/
	return false;

#if 0
	do 
	{
		//..lDiameterMsg->acl.reset();
		m_Buffer->reset();

		msg.rawbyteArray

			DiameterMsgHeaderParser hp;
		hp.setRawData(m_Buffer);
		hp.setAppData(&lDiameterMsg->hdr);

		try 
		{
			hp.parseAppToRaw();
		}
		catch (DiameterErrorCode &st) 
		{
			ACE_UNUSED_ARG(st);
			return (-1);
		}


		DiameterMsgPayloadParser pp;
		pp.setRawData(m_Buffer);
		pp.setAppData(&lDiameterMsg->acl);
		pp.setDictData(lDiameterMsg->hdr.getDictHandle());

		try 
		{ 
			pp.parseAppToRaw();
		}
		catch (DiameterErrorCode &st) 
		{
			AAA_PARSE_ERROR_TYPE type;
			int code;
			st.get(type, code);
			if ((type == AAA_PARSE_ERROR_TYPE_NORMAL) && (code == AAA_OUT_OF_SPACE)) 
			{
			if (m_BlockCount < MSG_COLLECTOR_MAX_MSG_BLOCK) 
			{
			m_BlockCount ++;
			m_Buffer->Release();
			m_Buffer = AAAMessageBlock::Acquire
			(DIAMETER_CFG_TRANSPORT()->rx_buffer_size * m_BlockCount);
			continue;
			}
			AAA_LOG((LM_ERROR, "(%P|%t) Not enough block space for transmission\n"));
			}
			return (-1);
			}
			*/

		lDiameterMsg->hdr.length = m_Buffer->wr_ptr() - m_Buffer->base();
		try 
		{
			hp.parseAppToRaw();
		}
		catch (DiameterErrorCode &st) 
		{
			return (-1);
		}
		break;
	}
	while (true);

	m_Buffer->length(lDiameterMsg->hdr.length);
	return io->Send(m_Buffer);
#endif

}
