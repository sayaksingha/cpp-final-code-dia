// @(#) $Id: aaa_rbtree_dbase.h,v 1.1.4.1.2.1 2018/02/21 23:00:44 anandhv Exp $
//---------------------------------------------------------------
// NAME : aaa_rbtree_dbase.h
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
#ifndef __OD_UTL_RBTREE_DBASE_H__
#define __OD_UTL_RBTREE_DBASE_H__

#include "aaa_rbtree.h"

template<class TYPE, class ARG>
class OD_Utl_DbaseTree : public OD_Utl_RbTreeTree
{
   public:
     typedef enum {
         ENTRY_ALLOC_FAILURE,
         ENTRY_INSERTION_FAILURE,
         ENTRY_NOT_FOUND
     } DB_ERROR;

   protected:
     class OD_Utl_DbEntry : public OD_Utl_RbTreeData {
         public:
            OD_Utl_DbEntry(TYPE &index) : m_Index(index) { 
	    }
            int operator<(OD_Utl_RbTreeData &cmp) {
               OD_Utl_DbEntry &compare = reinterpret_cast<OD_Utl_DbEntry&>(cmp);
               return (m_Index < compare.Index());
            }
            int operator==(OD_Utl_RbTreeData &cmp) {
               OD_Utl_DbEntry &compare = reinterpret_cast<OD_Utl_DbEntry&>(cmp);
               return (m_Index == compare.Index());
            }
            void clear(void *userData = 0) { 
	    }
            TYPE &Index() { 
	       return m_Index; 
	    }
         protected:
            TYPE m_Index;
     };

   public:
      OD_Utl_DbaseTree() { 
      }
      virtual ~OD_Utl_DbaseTree() { 
      }
      void Add(TYPE &index, ARG &arg) {
         OD_Utl_DbEntry *newEntry = new OD_Utl_DbEntry(index);
         if (newEntry) {
            newEntry->payload = reinterpret_cast<void*>(&arg);
            if (Insert(newEntry)) {
               return;
            }
            throw (ENTRY_INSERTION_FAILURE);
         }
         throw (ENTRY_ALLOC_FAILURE);
      }
      void Remove(TYPE &index, ARG **arg = NULL) {
         OD_Utl_DbEntry lookupEntry(index), *searchEntry;
         searchEntry = static_cast<OD_Utl_DbEntry*>
             (OD_Utl_RbTreeTree::Remove(&lookupEntry));
         if (searchEntry) {
            if (arg) {
               *arg = reinterpret_cast<ARG*>(searchEntry->payload);
            }
            return;
         }
         throw (ENTRY_NOT_FOUND);
      }
      ARG *Search(TYPE &index) {
         OD_Utl_DbEntry lookupEntry(index), *searchEntry;
         searchEntry = static_cast<OD_Utl_DbEntry*>
             (OD_Utl_RbTreeTree::Find(&lookupEntry));
         if (searchEntry) {
            return reinterpret_cast<ARG*>(searchEntry->payload);
         }
         throw (ENTRY_NOT_FOUND);
      }
};

#endif // __OD_UTL_RBTREE_DBASE_H__
