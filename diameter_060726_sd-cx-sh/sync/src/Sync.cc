#include<bits/stdc++.h>

using namespace std;

class MsgRecvInterface
{
	public:
		MsgRecvInterface() {}
};

class MsgSendInterface
{
	public:
		MsgSendInterface(){}
};

class SyncIoHandler;

class SyncHandler;

// Interface Type
typedef enum {
	IP_INTERFACE
} EnumSyncInterfaceType;

// Interface Service
typedef struct {
	EnumSyncInterfaceType  interfaceType;
	std::string            ip;
	int                    port;
	int                    priority;
	SyncIoHandler*         ioHandler;
} SyncServiceInterface;

typedef std::list<SyncServiceInterface> InterfaceList;

// Service
typedef struct {
	std::string		name;
	unsigned       refNum;
	int            state; // 1 Established
	InterfaceList  interfaceList;
} SyncService;

// Service List
typedef std::list<SyncService> syncServiceList;

// IO Handler
class SyncIoHandler
{
	public:
		int lookup(std::string ip, int port)
		{
			if(ip == serviceInterface.ip && port == serviceInterface.port)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}

	private:
		SyncServiceInterface  serviceInterface;
		int                   status;
		std::list<unsigned>   refNumList;
		MsgSendInterface*     m_sendInterface;
};

// Unique List Of Transport
typedef std::list<SyncIoHandler> transportList;

// Interface Base Class
class SyncDataAccess
{
	public:
		virtual std::pair<void*, size_t> SerializeData(SyncDataAccess* dataPtr) = 0;
		virtual SyncDataAccess* DeSerializeData(void* data, size_t len) = 0;
};

// Application Interface
class SyncInterface
{
	public:
		int SendSyncData(void* data, size_t len);
		virtual void RecvSyncData(void* data, size_t len) = 0;

	private:
		SyncService m_service;
};

// Management class
class SyncManager
{
	private:
		std::map<std::string, unsigned> nameRefMap;
		std::map<unsigned, SyncInterface*> refObjPtrMap;
		syncServiceList m_serviceList;
		transportList   m_transportList;

		friend SyncHandler;
};

// Handler Class
class SyncHandler
{
	public:
		SyncHandler()
		{
			bool matchFound = false;

			syncServiceList::iterator i = m_Manager.m_serviceList.begin();
			for (; i != m_Manager.m_serviceList.end(); i++)
			{
				InterfaceList::iterator k = (*i).interfaceList.begin();
				for (; k != (*i).interfaceList.end(); k++)
				{
					transportList::iterator j = m_Manager.m_transportList.begin();
					for (; j != m_Manager.m_transportList.end(); j++)
					{
						if((*j).lookup((*k).ip, (*k).port))
						{
							matchFound = true;
							break;
						}
					}

					if(!matchFound)
					{
						// Allocate & add to transport list
						matchFound = false;
					}
				}
			}
		}

		int RegisterSyncDataHandler(std::string name, SyncInterface* dataPtr);
		int DeRegisterSyncDataHandler(std::string name);

	private:
		SyncManager m_Manager;
};

// Hash Function (Bézout's identity)
#define A 54059 // prime No.
#define B 76963 // prime No.
#define C 86969 // prime No.
#define FIRST 37 // prime No. 
unsigned hash(const char* s)
{
	unsigned h = FIRST;
	while (*s) {
		h = (h * A) ^ (s[0] * B);
		s++;
	}
	return h % C;
}
// End of Hash Function
