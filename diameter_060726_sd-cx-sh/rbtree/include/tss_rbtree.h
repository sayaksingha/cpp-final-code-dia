
#ifndef __TSS_RBTREE_H__
#define __TSS_RBTREE_H__

#include "aaa_exports.h"
#include "framework.h"

typedef enum {
   TSS_RBTREE_CLR_BLACK,
   TSS_RBTREE_CLR_RED
} TSS_RbTreeNodeColor;

class OD_UTL_EXPORT TSS_RbTreeData 
{
   public:
      // constructor
      TSS_RbTreeData() { payload = this;};
      virtual ~TSS_RbTreeData() {};
  
      // exposed functions
      void *payload;
  
      // methods
      virtual int operator < (TSS_RbTreeData &cmp) = 0;
      virtual int operator == (TSS_RbTreeData &cmp) = 0;
      virtual void clear(void *userData = 0) = 0;

      // debugging only
      virtual void Dump(void *userData) {};
};

class OD_UTL_EXPORT TSS_RbTreeNode {
   public:
      // constructor
      TSS_RbTreeNode();
  
      // exposed members
      TSS_RbTreeNode *left;
      TSS_RbTreeNode *right;
      TSS_RbTreeNode *parent;
      TSS_RbTreeNodeColor color;
      TSS_RbTreeData *data;

      // methods
      TSS_RbTreeNode &operator=(TSS_RbTreeNode &source);
};

class OD_UTL_EXPORT TSS_RbTreeTree {
   public:
      // constructor
      TSS_RbTreeTree() { root = &nil; numOfNodes = 0;}

      // methods
      TSS_RbTreeData *Insert(TSS_RbTreeData *data, TSS_RbTreeNode *parent=NULL);
      TSS_RbTreeData *Find(TSS_RbTreeData *data);
      TSS_RbTreeNode *_Find(TSS_RbTreeData *data, TSS_RbTreeNode **parent);
      TSS_RbTreeData *Delete(TSS_RbTreeData *data);
      TSS_RbTreeData *Delete(TSS_RbTreeNode *data);
      void Clear(void *userData = 0);
		unsigned getNumOfNodes() { return numOfNodes;};

		inline void clear(void *data) {}

      // debugging only
      void Dump(TSS_RbTreeNode *x = 0, void *userData = 0);

   private:
      TSS_RbTreeNode *root;
      TSS_RbTreeNode nil;
		unsigned numOfNodes;
  		ACE_Mutex mutex;

      void FixupInsert(TSS_RbTreeNode *x);
      void FixupRemove(TSS_RbTreeNode *x);
      void RotateLeft(TSS_RbTreeNode *x);
      void RotateRight(TSS_RbTreeNode *x);
};

#endif /* __TSS_RBTREE_H__ */
