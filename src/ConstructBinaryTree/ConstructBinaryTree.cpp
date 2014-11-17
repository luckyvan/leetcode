// Source : https://oj.leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
// Author : Fan Chou
// Date   : 2014-11-17

/********************************************************************************** 
* 
* Given inorder and postorder traversal of a tree, construct the binary tree.
* 
* Note:
* You may assume that duplicates do not exist in the tree.
* 
*               
**********************************************************************************/

#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;


/**********************************************************************************
*
* Given preorder and inorder traversal of a tree, construct the binary tree.
*
* Note:
* You may assume that duplicates do not exist in the tree.
*
*
**********************************************************************************/
#include "../Solution.h"
#include <algorithm>

TreeNode* Solution::buildTreePI(vector<int> pre, vector<int> in)
{
	if (pre.empty())
		return NULL;

	int val = *pre.begin();
	TreeNode* node = new TreeNode(val);
	vector<int>::iterator it = std::find(in.begin(), in.end(), val);
	size_t left_subtree_node_num = it - in.begin();
	
	vector<int> in_left(in.begin(), it), in_right(it + 1, in.end());
	vector<int> pre_left(pre.begin() + 1, pre.begin() + 1 + left_subtree_node_num);
	vector<int> pre_right(pre.begin() + 1 + left_subtree_node_num, pre.end());
    
	node->left = buildTreePI(pre_left, in_left);
	node->right = buildTreePI(pre_right, in_right);
	return node;
}

TreeNode* Solution::buildTreeIP(vector<int> in, vector<int> post)
{
	if (post.empty())
		return NULL;

	int val = post.back();
	TreeNode* node = new TreeNode(val);
	vector<int>::iterator it = std::find(in.begin(), in.end(), val);
	size_t left_subtree_node_num = it - in.begin();

	vector<int> in_left(in.begin(), it), in_right(it + 1, in.end());
	vector<int> post_left(post.begin(), post.begin() + left_subtree_node_num);
	vector<int> post_right(post.begin() + left_subtree_node_num, post.end() - 1);

	node->left = buildTreeIP(in_left, post_left);
	node->right = buildTreeIP(in_right, post_right);
	return node;
}