#include "tss_rbtree.h"

TSS_RbTreeNode &TSS_RbTreeNode::operator=
          (TSS_RbTreeNode &source)
{
   left = source.left;
   right = source.right;
   parent = source.parent;
   color = source.color;
   data = source.data;
   return (*this);
}

TSS_RbTreeNode::TSS_RbTreeNode()
{
   left = right = this;
   parent = (0);
   color = TSS_RBTREE_CLR_BLACK;
   data = (0);
}

void TSS_RbTreeTree::RotateLeft(TSS_RbTreeNode *x)
{
    TSS_RbTreeNode *y = x->right;

    // establish x->right link 
    x->right = y->left;
    if (y->left != &nil) {
        y->left->parent = x;
    }

    // establish y->parent link 
    if (y != &nil) {
        y->parent = x->parent;
    }
    if (x->parent) {
        if (x == x->parent->left)
            x->parent->left = y;
        else
            x->parent->right = y;
    } else {
        root = y;
    }

    // link x and y 
    y->left = x;
    if (x != &nil) {
        x->parent = y;
    }
}

void TSS_RbTreeTree::RotateRight(TSS_RbTreeNode *x)
{
    TSS_RbTreeNode *y = x->left;

    // establish x->left link
    x->left = y->right;
    if (y->right != &nil) {
        y->right->parent = x;
    }

    // establish y->parent link 
    if (y != &nil) {
        y->parent = x->parent;
    }
    if (x->parent) {
        if (x == x->parent->right)
            x->parent->right = y;
        else
            x->parent->left = y;
    } else {
        root = y;
    }

    // link x and y 
    y->right = x;
    if (x != &nil) {
        x->parent = y;
    }
}

void TSS_RbTreeTree::FixupRemove(TSS_RbTreeNode *x)
{
    while (x != root && x->color == TSS_RBTREE_CLR_BLACK) {
        if (x == x->parent->left) {
            TSS_RbTreeNode *w = x->parent->right;
            if (w->color == TSS_RBTREE_CLR_RED) {
                w->color = TSS_RBTREE_CLR_BLACK;
                x->parent->color = TSS_RBTREE_CLR_RED;
                RotateLeft (x->parent);
                w = x->parent->right;
            }
            if (w->left->color == TSS_RBTREE_CLR_BLACK && 
                w->right->color == TSS_RBTREE_CLR_BLACK) {
                w->color = TSS_RBTREE_CLR_RED;
                x = x->parent;
            } else {
                if (w->right->color == TSS_RBTREE_CLR_BLACK) {
                    w->left->color = TSS_RBTREE_CLR_BLACK;
                    w->color = TSS_RBTREE_CLR_RED;
                    RotateRight (w);
                    w = x->parent->right;
                }
                w->color = x->parent->color;
                x->parent->color = TSS_RBTREE_CLR_BLACK;
                w->right->color = TSS_RBTREE_CLR_BLACK;
                RotateLeft (x->parent);
                x = root;
            }
        } else {
            TSS_RbTreeNode *w = x->parent->left;
            if (w->color == TSS_RBTREE_CLR_RED) {
                w->color = TSS_RBTREE_CLR_BLACK;
                x->parent->color = TSS_RBTREE_CLR_RED;
                RotateRight (x->parent);
                w = x->parent->left;
            }
            if (w->right->color == TSS_RBTREE_CLR_BLACK && 
                w->left->color == TSS_RBTREE_CLR_BLACK) {
                w->color = TSS_RBTREE_CLR_RED;
                x = x->parent;
            } else {
                if (w->left->color == TSS_RBTREE_CLR_BLACK) {
                    w->right->color = TSS_RBTREE_CLR_BLACK;
                    w->color = TSS_RBTREE_CLR_RED;
                    RotateLeft (w);
                    w = x->parent->left;
                }
                w->color = x->parent->color;
                x->parent->color = TSS_RBTREE_CLR_BLACK;
                w->left->color = TSS_RBTREE_CLR_BLACK;
                RotateRight (x->parent);
                x = root;
            }
        }
    }
    x->color = TSS_RBTREE_CLR_BLACK;
}

void TSS_RbTreeTree::FixupInsert(TSS_RbTreeNode *x)
{
    // check Red-Black properties
    while (x != root && x->parent->color == TSS_RBTREE_CLR_RED) {
        // violation
        if (x->parent == x->parent->parent->left) {
            TSS_RbTreeNode *y = x->parent->parent->right;
            if (y->color == TSS_RBTREE_CLR_RED) {

                // uncle is TSS_RBTREE_CLR_RED
                x->parent->color = TSS_RBTREE_CLR_BLACK;
                y->color = TSS_RBTREE_CLR_BLACK;
                x->parent->parent->color = TSS_RBTREE_CLR_RED;
                x = x->parent->parent;
            } else {

                // uncle is TSS_RBTREE_CLR_BLACK
                if (x == x->parent->right) {
                    // make x a left child
                    x = x->parent;
                    RotateLeft(x);
                }

                // recolor and rotate 
                x->parent->color = TSS_RBTREE_CLR_BLACK;
                x->parent->parent->color = TSS_RBTREE_CLR_RED;
                RotateRight(x->parent->parent);
            }
        } else {

            // mirror image of above code 
            TSS_RbTreeNode *y = x->parent->parent->left;
            if (y->color == TSS_RBTREE_CLR_RED) {

                // uncle is TSS_RBTREE_CLR_RED
                x->parent->color = TSS_RBTREE_CLR_BLACK;
                y->color = TSS_RBTREE_CLR_BLACK;
                x->parent->parent->color = TSS_RBTREE_CLR_RED;
                x = x->parent->parent;
            } else {

                // uncle is TSS_RBTREE_CLR_BLACK 
                if (x == x->parent->left) {
                    x = x->parent;
                    RotateRight(x);
                }
                x->parent->color = TSS_RBTREE_CLR_BLACK;
                x->parent->parent->color = TSS_RBTREE_CLR_RED;
                RotateLeft(x->parent->parent);
            }
        }
    }
    root->color = TSS_RBTREE_CLR_BLACK;
}

TSS_RbTreeData *TSS_RbTreeTree::Insert(TSS_RbTreeData *data, TSS_RbTreeNode *par)
{
//	AAA_MutexScopeLock guard(mutex);
	TSS_RbTreeNode *parent = par, *current = root;

	//If application passes parent node, then skipping this while loop to identifying parent
	//Application shall be carefull while passing parent node
	if(!par)
	while (current != &nil) {
		if (*(current->data) == (*data)) {
			return (current->data);
		}
		parent = current;
		current = ((*data) < (*(current->data))) ?
			current->left : current->right;
	}

	current = new TSS_RbTreeNode;
	if (! current) {
		return (0);
	}

	current->left = current->right = &nil;
	current->parent = parent;
	current->color = TSS_RBTREE_CLR_RED;
	current->data = data;

	if (parent) {
		if ((*data) < (*(parent->data))) {
			parent->left = current;
		}
		else {
			parent->right = current;
		}
	}
	else {      
		root = current;
	}

	FixupInsert(current);
	numOfNodes++;
	return (current->data);
}

TSS_RbTreeNode *TSS_RbTreeTree::_Find(TSS_RbTreeData *data, TSS_RbTreeNode **parent)
{
//	AAA_MutexScopeLock guard(mutex);
	TSS_RbTreeNode *current = root;

	while (current != &nil) {
		if (*(current->data) == (*data)) {
			return current;
		}
		*parent = current;
		current = ((*data) < (*(current->data))) ?
			current->left : current->right;
	}

	return (0);
}

TSS_RbTreeData *TSS_RbTreeTree::Find(TSS_RbTreeData *data)
{
//	AAA_MutexScopeLock guard(mutex);
	TSS_RbTreeNode *current = root;
	while (current != &nil) {
		if (*(current->data) == (*data)) {
			return (current->data);
		}
		current = ((*data) < (*(current->data))) ?
			current->left : current->right;
	}

	return (0);
}


TSS_RbTreeData *TSS_RbTreeTree::Delete(TSS_RbTreeData *data)
{
//	AAA_MutexScopeLock guard(mutex);
	TSS_RbTreeData *val;
	TSS_RbTreeNode *x, *y, *z = root;

	while (z != &nil) {
		if (*(z->data) == (*data)) {
			break;
		}
		z = ((*data) < (*(z->data))) ? z->left : z->right;
	}

	if (!z || z == &nil) {
		return (0);
	}

	if (z->left == &nil || z->right == &nil) {
		// y has a nil node as a child 
		y = z;
	} else {
		// find tree successor with a nil node as a child 
		y = z->right;
		while (y->left != &nil) {
			y = y->left;
		}
	}

	// x is y's only child
	if (y->left != &nil) {
		x = y->left;
	} else {
		x = y->right;
	}

	// remove y from the parent chain
	x->parent = y->parent;
	if (y->parent) {
		if (y == y->parent->left) {
			y->parent->left = x;
		} else {
			y->parent->right = x;
		}
	} else {
		root = x;
	}

	if (y != z) {
		val = z->data;
		z->data = y->data;
	}
	else {
		val = y->data;
	}

	if (y->color == TSS_RBTREE_CLR_BLACK) {
		FixupRemove(x);
	}

	delete y;
	numOfNodes--;
	return (val);
}

TSS_RbTreeData *TSS_RbTreeTree::Delete(TSS_RbTreeNode *node)
{
	//AAA_MutexScopeLock guard(mutex);
	TSS_RbTreeNode *x, *y, *z = node;
	TSS_RbTreeData *val;

	if (!z || z == &nil) {
		return (0);
	}

	if (z->left == &nil || z->right == &nil) {
		// y has a nil node as a child 
		y = z;
	} else {
		// find tree successor with a nil node as a child 
		y = z->right;
		while (y->left != &nil) {
			y = y->left;
		}
	}

	// x is y's only child
	if (y->left != &nil) {
		x = y->left;
	} else {
		x = y->right;
	}

	// remove y from the parent chain
	x->parent = y->parent;
	if (y->parent) {
		if (y == y->parent->left) {
			y->parent->left = x;
		} else {
			y->parent->right = x;
		}
	} else {
		root = x;
	}

	if (y != z) {
		val = z->data;
		z->data = y->data;
	}
	else {
		val = y->data;
	}

	if (y->color == TSS_RBTREE_CLR_BLACK) {
		FixupRemove(x);
	}

	delete y;
	numOfNodes--;
	return (val);
}
void TSS_RbTreeTree::Clear(void *userData)
{
	TSS_RbTreeData *val;
	while (root != &nil) {
		val = TSS_RbTreeTree::Delete(root->data);
		val->clear(userData);
		delete val;
	}
}

void TSS_RbTreeTree::Dump(TSS_RbTreeNode *x, 
		void *userData)
{
	if (x == 0) {
		x = root;
	}
	if (x == &nil) {
		return;
	}
	if (x->left != &nil) {
		Dump(x->left, userData);
	}
	if (x->data) {
		x->data->Dump(userData);
	} else {
	}
	if (x->right != &nil) {
		Dump(x->right, userData);
	}
}
