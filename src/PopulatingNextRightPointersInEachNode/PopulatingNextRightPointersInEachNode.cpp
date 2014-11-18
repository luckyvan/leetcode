// Source : https://oj.leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/
// Author : Fan Chou
// Date   : 2014-11-18

/********************************************************************************** 
* 
* Follow up for problem "Populating Next Right Pointers in Each Node".
* What if the given tree could be any binary tree? Would your previous solution still work?
* 
* Note:
* You may only use constant extra space.
* 
* For example,
* Given the following binary tree,
* 
*          1
*        /  \
*       2    3
*      / \    \
*     4   5    7
* 
* After calling your function, the tree should look like:
* 
*          1 -> NULL
*        /  \
*       2 -> 3 -> NULL
*      / \    \
*     4-> 5 -> 7 -> NULL
* 
*               
**********************************************************************************/

#include "../Solution.h"

void insertNode(TreeLinkNode* node, TreeLinkNode** p_head, TreeLinkNode** p_tail)
{
	if (node == NULL)
		return;

	if (*p_head == NULL){
		*p_head = node;
		*p_tail = node;
	}
	else{
		(*p_tail)->next = node;
		(*p_tail) = node;
	}
}

void Solution::connect(TreeLinkNode *root) {
	TreeLinkNode* head = root; //head of linked list in certain level
	TreeLinkNode* tail = root;
	TreeLinkNode* node;

	while (head != NULL) //current level linked list exist
	{
		node = head;
		head = NULL; //next level linked list uninitialed
		tail = NULL;
		while (node != NULL)
		{
			insertNode(node->left, &head, &tail);
			insertNode(node->right, &head, &tail);
			node = node->next;
		}
	}
}