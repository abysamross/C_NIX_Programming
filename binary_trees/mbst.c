#include <stdio.h>
#include <stdlib.h>
#include "mbst.h"
#include "tree.h"

static tree_root* _recDelete(tree_root* root, int key) {

	bstNode* node;

	if (tree_empty(root))
		return root;

	node = tree_node(root, struct bstNode, treeNode);

	if (node->key > key)
		tree_add_left(_recDelete(root->left, key), root);

	else if (node->key < key)
		tree_add_right(_recDelete(root->right, key), root);

	else {

		tree_root* tmp = NULL;
		if (tree_empty(root)) {

			delete_node(root);
			return tmp;

		} else if (tree_empty_left(root) || tree_empty_right(root)) {

			tmp = tree_empty_left(root) ? root->right : root->left;

			delete_node(root);
			return tmp;

		} else {

			tmp = tree_node_succ(root);
			bstNode* succ = tree_node(tmp, struct bstNode, treeNode);

			node->key = succ->key;
			node->val = succ->val;
			
			return _recDelete(root->right, key);
		}
	}

	return root;
}

void del1(bst* bt, int key) {

	_recDelete((bt->root).left, key);
}

static tree_root* _recSearch(tree_root* root, int key) {

	bstNode* node;

	if (tree_empty(root))
		return NULL;

	node = tree_node(root, struct bstNode, treeNode);

	if (node->key > key)
		return _recSearch(root->left, key);

	else if (node->key < key)
		return _recSearch(root->right, key);

	else
		return root;
}

static void* search1(bst* bt, int key) {

	tree_root* root = _recSearch((bt->root).left, key);
	return !root ? NULL : tree_node(root, struct bstNode, treeNode)->val;
}

static tree_root* _recInsert(tree_root* root, int key, void* val) {

	bstNode* node;

	if (tree_empty(root)) {

		bstNode* node = malloc(sizeof(bstNode));
		node->height = 0;
		node->key = key;
		node->val = !val ? NULL: val;

		INIT_TREE_ROOT(&node->treeNode);

		return &node->treeNode;
	} 

	node = tree_node(root, struct bstNode, treeNode);

	if (node->key > key)
		tree_add_left(_recInsert(root->left, key, val), root); 

	else if (node->key < key)
		tree_add_right(_recInsert(root->right, key, val), root);

	else
		printf("Key: %d already present in tree!\n", key);

 	return root;
}

static void insert1(bst* bt, int key, void* val) {

	tree_add(_recInsert((bt->root).left, key, val), &bt->root);
}

bst* initBST() {

	bst* bt  	= malloc(sizeof(bst));

	INIT_TREE_ROOT(&bt->root);
	bt->insertT = insert1;
	bt->searchT  = search1;
	bt->delT	= del1;

	return bt;
}
