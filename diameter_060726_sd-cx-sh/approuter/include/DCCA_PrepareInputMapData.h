// @(#) $Id: DCCA_PrepareInputMapData.h,v 1.1.2.1 2018/08/20 20:29:36 shijuc Exp $
//--------------------------------------------------------------------------------
// NAME           : BreRuleApi.h
//
// COPYRIGHT      : TSS -- Copyright (C) 2012 Tayana Software Solutions Pvt Ltd.,
//                  All rights reserved. No part of this computer program
//                  may be used or reproduced in any form by any
//                  means without prior written permission of
//                  Tayana Software Solutions Pvt Ltd.
//
// Originated     : Nandagopi 
//-------------------------------------------------------------------------------
#ifndef  DCCA_PREPARE_ROUTE_INPUT_H
#define  DCCA_PREPARE_ROUTE_INPUT_H 

#include "DiameterBaseInterface.h"
template < class T_DIA_MSG >
class DCCA_PrepareInputMapData
{
   public  :
      bool DecodeRequest(T_DIA_MSG &DiaMsgObj, list<int> &InputList, 
            multimap< int, boost::any>  &InputMapData, string &lSessionId);

      bool DisplayMapData( multimap< INT32, boost::any >  &InputMapData );
};

#endif
