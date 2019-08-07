#ifndef _MBST_H_
#define _MBST_H_

#include "tree.h"

typedef struct bstNode {

	int key;
	void* val;
	int height;
	tree_root treeNode;

} bstNode;

typedef struct bst {

	tree_root root;
	void (*insertT) (struct bst*, int, void*);
	void* (*searchT) (struct bst*, int);
	void (*delT) (struct bst*, int);

} bst;

#define delete_node(root) do {								\
			tree_del(root);									\
			free(tree_node(root, bstNode, treeNode)->val);	\
			free(tree_node(root, bstNode, treeNode));		\
		} while (0)

#endif //_MBST_H_
