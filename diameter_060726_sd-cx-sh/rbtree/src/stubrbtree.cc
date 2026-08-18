#include "aaa_session_storage.h"

class abc : public TSS_RbTreeData
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

   void clear(void *userData)	
	{
		return;
	}
};

class clear : public ACE_Task<ACE_MT_SYNCH>
{
	private:
		aaa_session_storage *storageObj;

	public:
		clear(aaa_session_storage *obj) : storageObj(obj)
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
				for(int low = 1; low < 10000; low++)
				{
					string sessionId("www.tayanasoft.com" + std::to_string(low%1000) + ";" + std::to_string(low%100) +  ";" + std::to_string(low) + ";" +"mohan" + std::to_string(low));
					data = new abc(temp, sessionId);
					data1 = (abc*)storageObj->Find(sessionId);
					if(data1 != NULL)
						printf("Inside Thread id is %d and sessionID is %s\n", data1->a, data1->sid);

					data1 = (abc*)storageObj->Remove(sessionId, data);
					if(data1 != NULL)
						printf("Deleting id is %d and sessionID is %s\n", data1->a, data1->sid);
					delete data1;
				}
					usleep(20);
			}
		}
};

int main()
{
	aaa_session_storage storageObj;

	TSS_RbTreeData *data = new abc(1, "www.tayana.com;12345;87654;mohan");

	abc* data1;
	clear clearObj(&storageObj);
	clearObj.Start(1);

	//while(1)
	{
		for(int temp = 1; temp < 2; temp++)
			for(int low = 1; low < 10000; low++)
			{
				string sessionId("www.tayanasoft.com" + std::to_string(low%1000) + ";" + std::to_string(low%100) +  ";" + std::to_string(low) + ";" +"mohan" + std::to_string(low));
				data = new abc(temp, sessionId);
				storageObj.Insert(sessionId, data);
				data1 = (abc*)storageObj.Find(sessionId);
				if(data1 != NULL)
					printf("id is %d and sessionID is %s\n", data1->a, data1->sid);
			}
	}
	
	sleep(30);
	
	data1 = (abc*)storageObj.Find("www.tayana.com;23;7654;mohan");
	if(data1 != NULL)
		printf("id is %d and sessionID is %s\n", data1->a, data1->sid);

	return 0;

}
