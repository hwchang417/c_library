
/*
 * struct TreeNode for embedded system
 *
 *
 *
 */

#define _DEBUG
#include "../common/debug.h"
#include "tree.h"
#define SIZE 7

int main(){
	int arr[SIZE] = {1, 2, 3, 4, 5, 6, 7};
	TreeNode* root, *succ, *pre;
	
    root = constructBST(arr, SIZE);
	inorder(root);
    tDeletion(&root, 3);
    tDeletion(&root, 1);
    tDeletion(&root, 2);
    tDeletion(&root, 4);
    tDeletion(&root, 5);
    tDeletion(&root, 6);
    tDeletion(&root, 7);
	tInsert(&root, 2);
	inorder(root);
	
    // succ = successor(root->right);
    // pre = predecessor(root->left);
    // printf("%d %d\n", succ->val, pre->val);
	
	return 0;
}


