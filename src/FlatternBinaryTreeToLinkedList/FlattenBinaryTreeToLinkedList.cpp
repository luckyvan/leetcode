// Source : https://oj.leetcode.com/problems/flatten-binary-tree-to-linked-list/
// Author : Fan Chou
// Date   : 2014-11-18

/********************************************************************************** 
* 
* Given a binary tree, flatten it to a linked list in-place.
* 
* For example,
* Given
* 
*          1
*         / \
*        2   5
*       / \   \
*      3   4   6
* 
* The flattened tree should look like:
* 
*    1
*     \
*      2
*       \
*        3
*         \
*          4
*           \
*            5
*             \
*              6
* 
* 
* Hints:
* If you notice carefully in the flattened tree, each node's right child points to 
* the next node of a pre-order traversal.
*               
**********************************************************************************/

#include "../Solution.h"

void Solution::flatten(TreeNode *root) {
	if (root == NULL)
		return;

	TreeNode* node = root;
	TreeNode* left = root->left;
	TreeNode* right = root->right;
	flatten(left);
	flatten(right);

	node->right = left;

	while (node->right != NULL)
	{
		node = node->right;
	}

	node->right = right;
}
