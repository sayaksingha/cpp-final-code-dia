#include "aaa_session_db.h"

class abc : public OD_Utl_RbTreeData 
{
	public:
	abc(){}
	abc(int index, string data)
	{
		a = index;
		strcpy(sid, data.c_str());
	}
	int a;
	char sid[100];

	int operator < (OD_Utl_RbTreeData &cmp)
	{
		abc *data = (abc*)cmp.payload;
		return a < data->a;
	}

	int operator == (OD_Utl_RbTreeData &cmp)
	{
		abc *data = (abc*)cmp.payload;
		return a == data->a;
	}

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
			abc* data;
			abc* data1;
			sleep(7);
			for(int temp = 1; temp < 2; temp++)
			{
				for(int low = 1; low < 1000000; low++)
				{
					string sessionId("www.tayanasoft.com;" + std::to_string(temp) +  ";" + std::to_string(low) + ";" +"mohan" + std::to_string(low));
					data = new abc(temp, sessionId);
					DiameterSessionId sid;
					AAA_JobData* job = NULL;
					sid.Get(sessionId);
					if(DIAMETER_SESSION_DB().Lookup(sid, job))
					{
						data1 = (abc*)job;
						if(data1 != NULL)
							printf("Inside Thread id is %d and sessionID is %s\n", data1->a, data1->sid);
						DIAMETER_SESSION_DB().Remove(sid);
						printf("Inside Thread Deleting sessionID is %s\n", sessionId.c_str());
					}

					delete data1;
				}
					usleep(20);
			}
		}
};

int main()
{
	OD_Utl_RbTreeData *data = new abc(1, "www.tayana.com;12345;87654;mohan");
	abc* data1;
	clear *clearObj = new clear();
	clearObj->Start(1);

	//while(1)
	{
		for(int temp = 1; temp < 2; temp++)
			for(int low = 1; low < 1000000; low++)
			{
				string sessionId("www.tayanasoft.com;" + std::to_string(temp) +  ";" + std::to_string(low) + ";" +"mohan" + std::to_string(low));
				data = new abc(temp, sessionId);
    			DiameterSessionId sid;
				sid.Get(sessionId);
				DIAMETER_SESSION_DB().Add(sid, (AAA_JobData&)*data);
				AAA_JobData *job = NULL;
				if(DIAMETER_SESSION_DB().Lookup(sid, job))
				{
					data1 = (abc*)job;
					if(data1 != NULL)
						printf("id is %d and sessionID is %s\n", data1->a, data1->sid);
				}
			}
	}
	
	sleep(30);
	
	return 0;

}
