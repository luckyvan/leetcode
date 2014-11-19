// Source : https://oj.leetcode.com/problems/recover-binary-search-tree/
// Author : Fan Chou
// Date   : 2014-11-19

/**********************************************************************************
*
* Two elements of a binary search tree (BST) are swapped by mistake.
*
* Recover the tree without changing its structure.
*
* Note:
* A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?
*
* confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.
*
* OJ's Binary Tree Serialization:
*
* The serialization of a binary tree follows a level order traversal, where '#' signifies
* a path terminator where no node exists below.
*
* Here's an example:
*
*    1
*   / \
*  2   3
*     /
*    4
*     \
*      5
*
* The above binary tree is serialized as "{1,2,3,#,#,4,#,#,5}".
*
*
**********************************************************************************/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include "../Solution.h"

TreeNode* inorder_tree_walk(TreeNode* node, TreeNode* prev, TreeNode** a1, TreeNode** a2)
{
	if (node != NULL){
		TreeNode* left_max = inorder_tree_walk(node->left, NULL, a1, a2);

		if (prev == NULL)
			prev = left_max;

		if (prev != NULL){
			if (prev->val > node->val){
				if (*a1 == NULL){
					*a1 = prev;
				}
				*a2 = node;
			}
		}
		
		TreeNode* right_max = inorder_tree_walk(node->right, node, a1, a2);
		return (right_max == NULL) ? node : right_max;
	}
	return NULL;
}

/* inorder walk the tree, the 1st and last node disobey the compare relation is the anomalies.*/
void Solution::recoverTree(TreeNode *root) {
	TreeNode* anormaly1 = NULL;
	TreeNode* anormaly2 = NULL;

	inorder_tree_walk(root, NULL, &anormaly1, &anormaly2);

	if (anormaly1 != NULL &&
		anormaly2 != NULL)
	{
		int val = anormaly1->val;
		anormaly1->val = anormaly2->val;
		anormaly2->val = val;
	}
}
