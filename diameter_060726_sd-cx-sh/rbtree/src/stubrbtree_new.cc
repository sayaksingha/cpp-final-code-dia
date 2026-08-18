#include "aaa_session_storage.h"
#include <chrono>

class abc  : public AAA_JobData 
{
	public:
	abc(){}
	abc(int index, string data)
	{
		a = index;
		strcpy(sid, data.c_str());
	}
	int a = 0 ;
	char sid[100];

		
/*
	int operator < (TSS_RbTreeData &cmp)
	{
		abc *data = (abc*)cmp.payload;
		return a < data->a;
	}

	int operator == (TSS_RbTreeData &cmp)
	{
		abc *data = (abc*)cmp.payload;
		return a == data->a;
	}
*/
   void clear(void *userData)	
	{
		return;
	}
};

class clear : public ACE_Task<ACE_MT_SYNCH>
{
	private:

	public:

		clear()
		{
		}

		void Start(int n)
		{
			activate(THR_NEW_LWP|THR_JOINABLE, 1);
		}

		int svc()
		{
	     //abc* data;
			abc* data1;
			sleep(17);
			for(int temp = 1; temp <= 2; temp++)
			{
			//	for(int low = 1; low < 1000000; low++)
//				for(int low = 1; low < 1000000; low++)
 				//cout<<"----------- TBR --------------------" << temp<<"\n";
			for(int low = 1; low < 10; low++)
//				for(int low = 1; low < 2; low++)
				{
//ggsn2;6666660422;1000001
//					string sessionId("www.tayanasoft.com;" + std::to_string(temp) +  ";" + std::to_string(low) + ";" +"mohan" + std::to_string(low));
				//	string sessionId("ggsn2;" + std::to_string(low) + ";" + std::to_string(low));
				string sessionId("ggsn"+std::to_string(temp)+";" + std::to_string(low) + ";" + std::to_string(low));
				cout << "sessionId : ----- > " << sessionId << endl;
					//data = new abc(temp, sessionId);
				//	DiameterSessionId sid;
					abc* job;
				//	sid.Get(sessionId);
					chrono::time_point<chrono::high_resolution_clock> lCurrentTime1 = chrono::high_resolution_clock::now();
					bool ret = DIAMETER_NEW_SESSION_DB().Lookup(sessionId , (void**)&job);
					chrono::time_point<chrono::high_resolution_clock> lCurrentTime2 = chrono::high_resolution_clock::now();
					std::chrono::duration<float> fs = lCurrentTime2 - lCurrentTime1;
					std::chrono::nanoseconds ms = std::chrono::duration_cast<std::chrono::nanoseconds>(fs);
					cout<<"session " << sessionId << " lookup time: "<<ms.count()<<"ns\n";

					if(ret)
					{
						data1 = (abc*)job;
						if(data1 != NULL)
							printf("Inside Thread id is %d and sessionID is ->> %s\n", data1->a, data1->sid);
						void *data = NULL;
						DIAMETER_NEW_SESSION_DB().Remove(sessionId);
						printf("Inside Thread Deleting sessionID is %s\n", sessionId.c_str());
					}
					else
						cout << " Lookup failed !! " << sessionId << endl; 
//					if ( data1 )
//						delete data1;
				}
					usleep(20);
			}
		}
};

int main()
{
	abc* data = new abc(1, "www.tayana.com;12345;87654;mohan");
	abc* data1;
	clear *clearObj = new clear();
	//clearObj->Start(1);

	//while(1)
	{
		for(int temp = 1; temp <= 20; temp++)
		{
	//		for(int low = 1; low < 1000000; low++)
//			for(int low = 1; low < 1000000; low++)
			//cout << "----------- main TBR --------------------" << temp << endl;
			for(int low = 1; low < 5; low++)
			//for(int low = 1; low < 2; low++)
			{
//				string sessionId("www.tayanasoft.com;" + std::to_string(temp) +  ";" + std::to_string(low) + ";" +"mohan" + std::to_string(low));
				string sessionId("ggsn"+std::to_string(temp)+";" + std::to_string(low) + ";" + std::to_string(low));
				cout << "main sessionId : ----- > " << sessionId << endl;
				data = new abc(temp, sessionId);
    			//DiameterSessionId sid;
				//sid.Get(sessionId);
				//DIAMETER_NEW_SESSION_DB().Add(sessionId , (AAA_JobData&)*data);
				abc *job;

				chrono::time_point<chrono::high_resolution_clock> lCurrentTime1 = chrono::high_resolution_clock::now();
				//bool ret = DIAMETER_NEW_SESSION_DB().Lookup(msg.sessionId , data);

				if ( false == DIAMETER_NEW_SESSION_DB().Add(sessionId , (void*)data) )
					cout << " Main ADD failed !! " << sessionId << endl; 
				

				chrono::time_point<chrono::high_resolution_clock> lCurrentTime2 = chrono::high_resolution_clock::now();
				std::chrono::duration<float> fs = lCurrentTime2 - lCurrentTime1;
				std::chrono::nanoseconds ms = std::chrono::duration_cast<std::chrono::nanoseconds>(fs);
				cout<<" session "<< sessionId << "  Add time: "<<ms.count()<<"ns\n";

				lCurrentTime1 = chrono::high_resolution_clock::now();
				if(DIAMETER_NEW_SESSION_DB().Lookup(sessionId , (void**)&job))
				{
					lCurrentTime2 = chrono::high_resolution_clock::now();
					std::chrono::duration<float> fs = lCurrentTime2 - lCurrentTime1;
					std::chrono::nanoseconds ms = std::chrono::duration_cast<std::chrono::nanoseconds>(fs);
					cout<<"session " << sessionId << " Look Up time: "<<ms.count()<<"ns\n";
					data1 = reinterpret_cast<abc*>(job);

					if(data1 != NULL)
					{
						cout << " Lookup Success !! " << sessionId << endl; 
						printf("Stored Data is Value ->  Id:%d SID : %s\n", data1->a, data1->sid);
					}
				}
				else
					cout << " Main Lookup failed !! " << sessionId << endl; 
			}
		}

	}

	sleep(30);

	return 0;

}
