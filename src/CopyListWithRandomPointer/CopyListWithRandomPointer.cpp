// Source : https://oj.leetcode.com/problems/copy-list-with-random-pointer/
// Author : Fan Chou
// Date   : 2014-12-01

/**********************************************************************************
*
* A linked list is given such that each node contains an additional random pointer
* which could point to any node in the list or null.
*
* Return a deep copy of the list.
*
*
**********************************************************************************/



/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */


/*
 *
 *  The idea as below:
 *
 *  Consider we have a linked list as below:
 *
 *    node1->random = node2;
 *    node2->random = node1;
 *    node3->random = node1;
 *
 *       +-------------+
 *       |             v
 *    +-------+    +-------+    +-------+
 *    | node1 |----> node2 |----> node3 |--->NULL
 *    +-------+    +-------+    +-------+
 *      ^  ^           |           |
 *      |  +-----------+           |
 *      +--------------------------+
 *
 *
 *  To copy the list,
 *
 *    1) We insert a new node for each node's next position
 *
 *
 *       +-------------------------+
 *       |                         v
 *    +--+----+     +-----+    +-------+     +-----+    +-------+
 *    | node1 |---> | NEW |----> node2 |---> | NEW |----> node3 |--->NULL
 *    +-------+     +-----+    +---+---+     +-----+    +--+----+
 *      ^  ^                       |                       |
 *      |  +-----------------------+                       |
 *      +--------------------------------------------------+
 *
 *    2) Then, we can construt the new node's random pointer:
 *
 *        (node1->next) -> random  = (node1->random) -> next;
 *
 *    3) After we take out all of the "NEW" node to finish the copy.
 *
 */
#include "../Solution.h"
#include <map>
RandomListNode* Solution::copyRandomList(RandomListNode *head) 
{
	//1. generate the whole list
	RandomListNode* node = head;
	RandomListNode* new_head = NULL;
	RandomListNode* new_prev = NULL;

	map<RandomListNode*, RandomListNode*> map;
	while (node != NULL)
	{
		RandomListNode* new_node = new RandomListNode(node->label);
		map[node] = new_node;
		if (new_head == NULL)
		{
			new_head = new_node;
		}
		else
		{
			new_prev->next = new_node;
		}
		new_prev = new_node;
		node = node->next;
	}

	//2. form the random pointer
	node = head;
	while (node != NULL)
	{
		if (node->random != NULL)
		{
			map[node]->random = map[node->random];
		}

		node = node->next;
	}

	return new_head;
}



