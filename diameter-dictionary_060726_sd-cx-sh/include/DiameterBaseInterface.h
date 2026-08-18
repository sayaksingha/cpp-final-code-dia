#ifndef DIAMETERBASEINTERFACE_H
#define DIAMETERBASEINTERFACE_H
#include "DiameterStruct.h"
#include "TssDiameterMsgException.h"

class DiameterBaseInterface
{
	public:
// virtual ~DiameterBaseInterface() = default;  
	virtual int								Decode(byteArray *array,  INT16 lMLen = 0, UINT16 *parsedBytes = NULL) = 0;
	virtual int								Encode(byteArray *array) = 0;
	virtual void							Display(UINT32 tab) = 0;
	virtual DiameterBaseInterface*	Find(byteArray *array, UINT32 avpCode) = 0;
	virtual BOOLEAN   FindAll(byteArray *array, UINT32 avpCode, list<DiameterBaseInterface*>& pBaseInterface, BOOLEAN deepInspect = false) = 0;
	
	void SetDataType(DiameterDataType type){mType = type;}
	
	DiameterDataType GetDataType(){return mType;}

	protected:
		DiameterDataType  				mType;
};
#endif
