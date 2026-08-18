// @(#) $Id: aaa_transport_collector.h,v 1.1.4.1.2.1.2.5 2024/05/15 13:11:22 mram Exp $
//---------------------------------------------------------------
// NAME : aaa_transport_collector.h
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
#ifndef __AAA_TRANSPORT_COLLECTOR_H__
#define __AAA_TRANSPORT_COLLECTOR_H__

#include <atomic>
#include "diameter_parser.h"
#include "aaa_transport_interface.h"

typedef enum maxCollector_s{
    MSG_COLLECTOR_MAX_MSG_LENGTH  = 2048,
    MSG_COLLECTOR_MAX_MSG_BLOCK   = 10
}maxCollector_t;

class DiameterRxMsgCollectorHandler
{
    public:
        typedef enum 
		  {
           PARSING_ERROR          = 3000,
           BUG_IN_PARSING_CODE    = 3001,
           MEMORY_ALLOC_ERROR     = 3002,
           CORRUPTED_BYTE_STREAM  = 3003,
           INVALID_MSG            = 3004,
           TRANSPORT_ERROR        = 3005
        } COLLECTOR_ERROR;
    public:    
        virtual void HandleMessage(std::unique_ptr<DiameterMsg> msg) = 0;
        virtual void Error(COLLECTOR_ERROR error,
                           std::string &io_name) = 0;
        virtual int SendErrorAnswer(std::unique_ptr<DiameterMsg> &msg) = 0;
        virtual ~DiameterRxMsgCollectorHandler() { }
};

class DiameterRxMsgCollector : public Diameter_IO_RxHandler
{
    public:
        void RegisterHandler(DiameterRxMsgCollectorHandler &h) {
            m_Handler = &h;
        }
        void RemoveHandler() {
            m_Handler = NULL;
        }

        DiameterRxMsgCollector();
        virtual ~DiameterRxMsgCollector();

        void ReceiveMessage(void *data, size_t length);

        void Error(int error, const Diameter_IO_Base *io) 
		  {
            m_Handler->Error(DiameterRxMsgCollectorHandler::TRANSPORT_ERROR,
                    const_cast<Diameter_IO_Base*>(io)->Name());
        }

    protected:
        void SendFailedAvp(DiameterErrorCode &st);

    private:
        char *m_Buffer; // buffer of unprocessed received data
        int   m_Offset; // current read offset from buffer
        int   m_BufSize; // allocated size of rdBuffer
        int   m_MsgLength; // current message length

        DiameterRxMsgCollectorHandler *m_Handler;

        AAA_RangedValue m_PersistentError;
};

class DiameterTxMsgCollector : public ACE_Task<ACE_MT_SYNCH>
{
    private:
        class TransmitDatum 
		  {
            public:
                TransmitDatum(DiameterMsg *msg,
                              Diameter_IO_Base *io,
                              bool consume) :
                     m_Msg(msg),
                     m_IO(io),
                     m_Consume(consume) {
                }

                virtual ~TransmitDatum() 
					 {
                    if (m_Consume && m_Msg) 
						  {
                       if(m_Msg->baseClass.use_count() > 1)
                       {
                          m_Msg->baseClass.reset();
                       }
                       delete m_Msg;
                    }
                }

                DiameterMsg *GetMsg() 
                {
                   return m_Msg;
                }

                Diameter_IO_Base *GetIO() 
                {
                   return m_IO;
                }

                bool IsConsumed() 
                {
                   return m_Consume;
                }

            private:
                DiameterMsg      *m_Msg;
                Diameter_IO_Base *m_IO;
                bool              m_Consume;
        };

    public:
        DiameterTxMsgCollector() :
           m_Active(false),
           m_Condition(*(new ACE_Mutex)),
           m_Buffer(NULL),
           m_BlockCount(1) {
              mPendingMessages.store(0);
           }
        virtual ~DiameterTxMsgCollector() {
           Stop(); 
           delete &(m_Condition.mutex());
        }

        bool Start() {
           //if (! m_Active && (activate() == 0)) {
           if (! m_Active && (activate(THR_NEW_LWP|THR_DETACHED) == 0)) {
              m_Active = true;
           }
           return m_Active;
        }

        void Stop() 
        {
           m_Active = false;
           m_Condition.signal();
           // wait for thread to exit
           AAA_MutexScopeLock guard(m_ExitMutex);
        }

        int Send(std::unique_ptr<DiameterMsg> &msg,
              Diameter_IO_Base *io, bool consume) 
        {
           DiameterMsg *ptr = (consume) ? msg.release() : msg.get();

           if(io == NULL)
           {
              AAA_LOG((LM_ERROR,"%T |TRANSPORT| PeerName:%s IO object is null:Unable to send\n",mPeerName.c_str()));

              return -1;
           }

           if(ptr == NULL)
           {
              AAA_LOG((LM_ERROR,"%T |TRANSPORT| PeerName:%s Message is NULL\n",mPeerName.c_str()));
              return -1;
           }

           m_SendQueue.Enqueue(new TransmitDatum(ptr, io, consume));
           //AAA_MutexScopeLock guard(m_Condition.mutex());
           ++mPendingMessages;
           AAA_LOG((LM_ERROR, "%T |TRANSPORT| PeerName:%s Enqueue:Messages Pending status in Trasnmit Queue %d \n",
                    mPeerName.c_str(),  mPendingMessages.load() ));

           m_Condition.signal();
           return (0);
        }

        int SendMsg(std::shared_ptr<DiameterMsg> &msg,
              Diameter_IO_Base *io,   bool consume) 
        {
           DiameterMsg *ptr = msg.get();

           if(io == NULL)
           {
              AAA_LOG((LM_ERROR,"%T |TRANSPORT| PeerName:%s IO object is null:Unable to send\n",mPeerName.c_str()));

              return -1;
           }

           if(ptr == NULL)
           {
				  AAA_LOG((LM_ERROR,
							  "%T |TRANSPORT| PeerName:%s Message is NULL\n",mPeerName.c_str()));
				  return -1;
			  }

			  m_SendQueue.Enqueue(new TransmitDatum(ptr, io, consume));
			  //AAA_MutexScopeLock guard(m_Condition.mutex());
			  ++mPendingMessages;
			  AAA_LOG((LM_ERROR, "%T |TRANSPORT|  PeerName:%s Enqueue:Messages Pending status in Trasnmit Queue %d \n",
						   mPeerName.c_str(),  mPendingMessages.load() ));

			  m_Condition.signal();
			  return (0);
		  }

		  std::string  &PeerName() {
			  return mPeerName;
		  }

	 private:
		  //
		  // Variables for transmitter thread
		  //
		  bool 										 m_Active;
		  ACE_Mutex 								 m_ExitMutex;
		  ACE_Condition<ACE_Mutex>				 m_Condition;
		  AAA_ProtectedQueue<TransmitDatum*> m_SendQueue;
		  std::atomic<int>                   mPendingMessages;
		  std::string                        mPeerName;


		  //
		  // Variables for buffer pool
		  //
		  AAAMessageBlock *m_Buffer;
		  short m_BlockCount;

	 private:
		  int SafeSend(DiameterMsg *msg,  Diameter_IO_Base *io);

		  int svc() 
		  {
			  AAA_MutexScopeLock guard(m_ExitMutex);
			  //m_Buffer = AAAMessageBlock::Acquire(DIAMETER_CFG_TRANSPORT()->rx_buffer_size); HV 
			  do 
			  {
				  AAA_MutexScopeLock guard(m_Condition.mutex());
				  m_Condition.wait();
				  while (! m_SendQueue.IsEmpty()) 
				  {
					  std::unique_ptr<TransmitDatum> datum(m_SendQueue.Dequeue());
					  SafeSend(datum->GetMsg(), datum->GetIO());
					  --mPendingMessages;
					  //sleep(5);//TBC-Added for testing purpose
					  AAA_LOG((LM_INFO, "%T |TRANSPORT|  PeerName:%s Messages Pending in Trasnmit Queue %d \n",
								  mPeerName.c_str(),  mPendingMessages.load() ));

				  }
			  } while (m_Active);

			  //m_Buffer->Release();
			  return (0);
		  }
};

#endif
