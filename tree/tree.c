
#define _DEBUG
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "../common/debug.h"
#include "tree.h"

TreeNode* initTree(TREE_TYPE val){
	TreeNode* root = (TreeNode *)malloc(sizeof(TreeNode));
	assert(root != NULL);
	root->val = val;
	root->left = root->right = root->parent = NULL;
	return root;
}

TreeNode* makeTree(int *arr, int start, int end){
	TreeNode* root;
	if(start > end) return NULL;

	root = initTree(0);
	if(root == NULL) return root;

	int mid = (start + end) >> 1;
	root->val = arr[mid];
	root->left = makeTree(arr, start, mid - 1);
	root->right = makeTree(arr, mid + 1, end);
    if(root->left != NULL) root->left->parent = root;
    if(root->right != NULL) root->right->parent = root;

	return root;
}

TreeNode* constructBST(int *arr, int size){
	return makeTree(arr, 0, size - 1);
}

TreeNode* isExistTree(TreeNode *root, TREE_TYPE val){
	while(root != NULL){
		if(root->val > val)
			root = root->left;
		else if(root->val < val)
			root = root->right;
		else
			return root;
	}
	return NULL;
}

//preorder()
void preorder(TreeNode *root){
	if(root == NULL) return;
	DEBUG("%d,", root->val);
	preorder(root->left);
	preorder(root->right);
}

//inorder()
void inorder(TreeNode *root){
	if(root == NULL) return;
	inorder(root->left);
	DEBUG("%d,", root->val);
	inorder(root->right);
}

//postorder()
void postorder(TreeNode *root){
	if(root == NULL) return;
	postorder(root->left);
	postorder(root->right);
	DEBUG("%d,", root->val);
}

//successor()
TreeNode* successor(TreeNode *root){
    TreeNode* prev;
	if(root == NULL) return NULL;
	root = root->right;
    while(root != NULL){
        prev = root;
        root = root->left;
    }
    return prev;
}

//predecessor()
TreeNode* predecessor(TreeNode *root){
    TreeNode* prev;
	if(root == NULL) return NULL;
	root = root->left;
    while(root != NULL){
        prev = root;
        root = root->right;
    }
    return prev;
}

void tDeletion(TreeNode **root, TREE_TYPE val){
    TreeNode *y, *tmp; 
    TreeNode *delete_node = isExistTree(*root, val);
    if(delete_node == NULL) return;
    
    if(delete_node->left == NULL || delete_node->right == NULL){
        if(delete_node->left == NULL)
            tmp = delete_node->right;
        else// if(delete_node->right == NULL)
            tmp = delete_node->left;
        
		if(delete_node->parent == NULL){ // root node
			(*root) = tmp;
		}else{
			if(delete_node->parent->left == delete_node)
				delete_node->parent->left = tmp;
			else //(delete_node->parent->right == delete_node)
				delete_node->parent->right = tmp;
		}
		if(tmp != NULL)
            tmp->parent = delete_node->parent;
	}else{
		y = successor(delete_node);
		delete_node->val = y->val;

		if(y->parent->left == y)
			y->parent->left = y->right;
		else
			y->parent->right = y->right;
		delete_node = y;
	}
	free(delete_node);
}

void tInsert(TreeNode **root, TREE_TYPE val){
	TreeNode *parent, *child;
	if((*root) == NULL){
		(*root) = initTree(val);
		return;
	}
	child = (*root);
	while(child != NULL){
		parent = child;
		child = (child->val <= val ? child->right : child->left);
	}

	if(parent->val <= val){
		parent->right = initTree(val);
		parent->right->parent = parent;
	}else{
		parent->left = initTree(val);
		parent->left->parent = parent;
	}
}

void tGetDepth(TreeNode *root, int depth, int* max){
	if(root == NULL) return;
	tGetDepth(root->right, depth + 1, max);
	tGetDepth(root->left, depth + 1, max);
	if(*max < depth) *max = depth;
}

void printTree(TreeNode *root){
	int max = 0;
	tGetDepth(root, 0, &max);
	printf("depth of the tree = %d\n", max);
}

void releaseTree(TreeNode *root){
	TreeNode *left, *right;
	if(root == NULL) return;
	
	left = root->left;
	right = root->right;
	
	free(root);
	releaseTree(left);
	releaseTree(right);
}
