// Source : https://oj.leetcode.com/problems/binary-tree-postorder-traversal/
// Author : Fan Chou
// Date   : 2014-11-16

/**********************************************************************************
*
* Given a binary tree, return the postorder traversal of its nodes' values.
*
* For example:
* Given binary tree {1,#,2,3},
*
*    1
*     \
*      2
*     /
*    3
*
* return [3,2,1].
*
* Note: Recursive solution is trivial, could you do it iteratively?
*
**********************************************************************************/
#include "../Solution.h"

// using the stack to simulate the recursive function stack.
vector<int> Solution::postorderTraversal(TreeNode *root) {
	vector<int> v;
	vector<TreeNode*> stack;
	TreeNode *node = root;
	TreeNode *lastVisitNode = NULL;

	while (
		!stack.empty() || //not in the top of calling stack
		node != NULL //not start yet
		)
	{
		if (node != NULL){
			//go left
			stack.push_back(node);
			node = node->left;
		}
		else{
			TreeNode* parent = stack.back();
			if (parent->right != NULL && parent->right != lastVisitNode){
				//go right
				node = parent->right;
			}
			else{
				v.push_back(parent->val);
				lastVisitNode = parent;
				stack.pop_back();
			}
		}
	}
	return v;
}

/**********************************************************************************
*
* Given a binary tree, return the preorder traversal of its nodes' values.
*
* For example:
* Given binary tree {1,#,2,3},
*
*    1
*     \
*      2
*     /
*    3
*
* return [1,2,3].
*
* Note: Recursive solution is trivial, could you do it iteratively?
*
**********************************************************************************/
// using the stack to simulate the recursive function stack.
vector<int> Solution::preorderTraversal(TreeNode *root) {
	vector<int> v;
	vector<TreeNode*> stack;
	TreeNode *node = root;
	TreeNode *lastVisitNode = NULL;

	while (
		!stack.empty() || //not in the top of calling stack
		node != NULL //not start yet
		)
	{
		if (node != NULL){
			v.push_back(node->val);

			//go left
			stack.push_back(node);
			node = node->left;
		}
		else{
			TreeNode* parent = stack.back();
			if (parent->right != NULL && parent->right != lastVisitNode){
				//go right
				node = parent->right;
			}
			else{
				lastVisitNode = parent;
				stack.pop_back();
			}
		}
	}
	return v; return v;
}

