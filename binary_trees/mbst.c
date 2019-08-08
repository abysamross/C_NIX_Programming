#include <stdio.h>
#include <stdlib.h>
#include "mbst.h"
#include "tree.h"

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

static inline int getLeftHeight(tree_root* root) {

	if (tree_empty_left(root))
		return 0;

	return tree_node_left(root, bstNode, treeNode)->height;
}

static inline int getRightHeight(tree_root* root) {

	if (tree_empty_right(root))
		return 0;

	return tree_node_right(root, bstNode, treeNode)->height;
}

static inline int getHeight(tree_root* root) {

	if (!root)
		return 0;

	return tree_node(root, bstNode, treeNode)->height;
}

static inline int getBalance(tree_root* root) {

	return (getLeftHeight(root) - getRightHeight(root));
}

static inline void updateHeight(tree_root* root) {

	if (!root)
		return;

	tree_node(root, bstNode, treeNode)->height =
		1 + max(getLeftHeight(root), getRightHeight(root));
}

static inline tree_root* updateHAndRef(tree_root* new, tree_root* old) {

	updateHeight(old);
	updateHeight(new);
	old = new;
	return old;
}

static inline tree_root* leftRotate(tree_root* root) {

	tree_root* new_root = tree_left_rotate(root);
	return updateHAndRef(new_root, root);
}

static inline tree_root* rightRotate(tree_root* root) {

	tree_root* new_root = tree_right_rotate(root);
	return updateHAndRef(new_root, root);
}

static tree_root* balanceTree(tree_root* root, int key) {

	int balance = getBalance(root);

	if (balance < -1 && 
			key > tree_node_right(root, bstNode, treeNode)->key) {

		return leftRotate(root);

	} else if (balance < -1 &&
				key < tree_node_right(root, bstNode, treeNode)->key) {

		root->right = rightRotate(root->right);
		return leftRotate(root);

	} else if (balance > 1 &&
				key < tree_node_left(root, bstNode, treeNode)->key) {

		return rightRotate(root);

	} else if (balance > 1 &&
				key > tree_node_left(root, bstNode, treeNode)->key) {

		root->left = leftRotate(root->left);
		return rightRotate(root);
	}

	return root;
}

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
		node->height = 1;
		node->key = key;
		node->val = !val ? NULL : val;

		INIT_TREE_ROOT(&node->treeNode);

		return &node->treeNode;
	} 

	node = tree_node(root, bstNode, treeNode);

	if (node->key > key)
		tree_add_left(_recInsert(root->left, key, val), root); 

	else if (node->key < key)
		tree_add_right(_recInsert(root->right, key, val), root);

	else {

		printf("Key: %d already present in tree!\n", key);
		return root;
	}

	updateHeight(root);
	return balanceTree(root, key);
}

static void insert1(bst* bt, int key, void* val) {

	tree_add(_recInsert((bt->root).left, key, val), &bt->root);
	//printInorder(bt);
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
