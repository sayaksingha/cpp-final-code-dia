------------------
|    Method I    |
------------------

---------------   --------------------
  Application      Data Access Object  
---------------   --------------------
   |                    |
   |  Sync Method call  | 
	|------------------->|
	|							|  Network Request
   |                    |--------------------->
   |                    |
   |                    |
   |                    |   Network Request
   |                    |<---------------------
   |  Sync Method call  |
   |<-------------------|
   |                    |
   |                    |
   |                    |


------------------
|    Method II   |
------------------

---------------   --------------------
  Application      Data Access Object  
---------------   --------------------
   |                    |
   |  Sync Method call  |
   |------------------->|
   |                    |  Network Request
   |                    |--------------------->
   |                    |
   |                    |
   |                    |   Network Response
   |                    |<---------------------
   | Sync Return Method | 
   |       call  	      |
   |<-------------------|
   |                    |
   |                    |
   |                    |  Network Request
   |                    |<---------------------
   |                    |
   |  Sync Method call  |
   |<-------------------|
   |                    |
   |                    |
   | Sync Return Method |
   |       call         |
   |------------------->|
   |                    |
   |                    |   Network Response
   |                    |--------------------->
   |                    |
   |                    |



Data State Machine 

1) Non-Sync State
2) Synchronizing
3) Synchronized


class Application : public SyncHandler
{
	serializeData();
	deSerializeData();
};

template<class C_DATA, struct S_DATA>
class SyncHandler : public SyncFsm
{
	void Connected() {}
	void Error(int resultCode) {}
	void Disconnected(int cause) {}

	void ReceiveMessage(void *data, size_t length) {}
	void SendMessage(void *data, size_t length) {}

	void HandleMessage() {}
	// 1) Register
	// 2) Connected
	// 3) ReceiveMsg
	// 4) SendMsg
	TransportManager mTransportMgr;
	Notify();
};

class SyncFsm : public AAA_StateMachine<SyncFsm>
{
	//state
	//Event
	//Action
};

class TransportManager
{
	RegisterHandler();
};
