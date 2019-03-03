
/*
 * struct TreeNode for embedded system
 *
 *
 *
 */
#ifndef _TREE_H
#define _TREE_H

#define _DEBUG
#include "../common/debug.h"

#define TREE_TYPE int

typedef struct treeNode{
    struct treeNode* parent;
	struct treeNode* left;
	struct treeNode* right;
	TREE_TYPE val;
}TreeNode;

TreeNode* initTree(TREE_TYPE val);
TreeNode* makeTree(int* arr, int start, int end);
TreeNode* constructBST(int *arr, int size);
TreeNode* isExistTree(TreeNode *root, TREE_TYPE val);
void preorder(TreeNode* root);
void inorder(TreeNode* root);
void postorder(TreeNode* root);
TreeNode* successor(TreeNode* root);
TreeNode* predecessor(TreeNode* root);
void tDeletion(TreeNode** root, TREE_TYPE val);
void tInsert(TreeNode** root, TREE_TYPE val);
void tGetDepth(TreeNode* root, int depth, int* max);
void printTree(TreeNode* root);
void releaseTree(TreeNode *root);

#endif