#include <stdio.h>
#include <stdlib.h>
#include "mbst.h"
#include "tree.h"

static tree_root* _recDelete(tree_root* root, int key) {

	bstNode* node;

	if (!root)
		return root;

	node = tree_node(root, bstNode, treeNode);

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
			bstNode* succ = tree_node(tmp, bstNode, treeNode);

			node->key = succ->key;
			node->val = succ->val;
			
			return _recDelete(root->right, key);
		}
	}

	return root;
}

void del1(bst* bt, int key) {

	tree_add(_recDelete((bt->root).left, key), &bt->root);
}

static tree_root* _recSearch(tree_root* root, int key) {

	bstNode* node;

	if (!root)
		return NULL;

	node = tree_node(root, bstNode, treeNode);

	if (node->key > key)
		return _recSearch(root->left, key);

	else if (node->key < key)
		return _recSearch(root->right, key);

	else
		return root;
}

static void* search1(bst* bt, int key) {

	tree_root* root = _recSearch((bt->root).left, key);

	return !root ? NULL : tree_node(root, bstNode, treeNode)->val;
}

static tree_root* _recInsert(tree_root* root, int key, void* val) {

	bstNode* node;

	if (!root) {

		bstNode* node = malloc(sizeof(bstNode));
		node->height = 0;
		node->key = key;
		node->val = !val ? NULL: val;

		INIT_TREE_ROOT(&node->treeNode);

		return &node->treeNode;
	} 

	node = tree_node(root, bstNode, treeNode);

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

void _recInorder(tree_root* root) {

	if (!root)
		return;

	_recInorder(root->left);
	printf("%d ", tree_node(root, bstNode, treeNode)->key);
	_recInorder(root->right);
}

void printInorder(bst* bt) {

	if(tree_empty(&bt->root))
		return;

	_recInorder((bt->root).left);
	printf("\n\n");
}

bst* initBST() {

	bst* bt  	= malloc(sizeof(bst));

	INIT_TREE_ROOT(&bt->root);
	bt->insertT = insert1;
	bt->searchT  = search1;
	bt->delT	= del1;

	return bt;
}

void destroyBST(bst* bt) {

	while (!tree_empty(&bt->root)) {

		bstNode* node = tree_node((bt->root).left, bstNode, treeNode);
		bt->delT(bt, node->key);
	}

	free(bt);
}
