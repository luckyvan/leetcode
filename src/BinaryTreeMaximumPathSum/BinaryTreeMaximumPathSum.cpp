// Source : https://oj.leetcode.com/problems/binary-tree-maximum-path-sum/
// Author : Fan Chou
// Date   : 2014-11-19

/********************************************************************************** 
* 
* Given a binary tree, find the maximum path sum.
* 
* The path may start and end at any node in the tree.
* 
* For example:
* Given the below binary tree,
* 
*        1
*       / \
*      2   3
* 
* Return 6.
* 
*               
**********************************************************************************/

#include <algorithm>
#include <stdlib.h>
#include "../Solution.h"

int maxPathSumByBranch(TreeNode *root, int& maxSum ) {

    if (NULL == root) return 0;

    //get the maxBranchSum for both left and right branch
	int left_branch_sum = maxPathSumByBranch(root->left, maxSum);
	int right_branch_sum = maxPathSumByBranch(root->right, maxSum);

    //assume all val positive.
	int val = root->val;
	int m = val + left_branch_sum + right_branch_sum;
	int maxBranch = left_branch_sum > right_branch_sum ? val + left_branch_sum : val + right_branch_sum;
   
    maxSum = max(maxSum, m);

    return maxBranch;
}

int Solution::maxPathSum(TreeNode *root) {
    int maxSum = 0;
    maxPathSumByBranch(root, maxSum);
    return maxSum;
}

