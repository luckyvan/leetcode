// Source : https://oj.leetcode.com/problems/scramble-string/
// Author : Fan Chou
// Date   : 2014-11-09

/**********************************************************************************
*
* Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.
*
* Below is one possible representation of s1 = "great":
*
*     great
*    /    \
*   gr    eat
*  / \    /  \
* g   r  e   at
*            / \
*           a   t
*
* To scramble the string, we may choose any non-leaf node and swap its two children.
*
* For example, if we choose the node "gr" and swap its two children, it produces a scrambled string "rgeat".
*
*     rgeat
*    /    \
*   rg    eat
*  / \    /  \
* r   g  e   at
*            / \
*           a   t
*
* We say that "rgeat" is a scrambled string of "great".
*
* Similarly, if we continue to swap the children of nodes "eat" and "at", it produces a scrambled string "rgtae".
*
*     rgtae
*    /    \
*   rg    tae
*  / \    /  \
* r   g  ta  e
*        / \
*       t   a
*
* We say that "rgtae" is a scrambled string of "great".
*
* Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1.
*
*
**********************************************************************************/

#include "../Solution.h"

//Dynamic Programming
//Recursive Optimal Structure:
//  Divide s1 into [0, j) and [j, n), then
//		isScramble£¨s1, s2) = For any possible j, If
//			isScramble( s1[0, j), s2[0, j)) && isScramble( s1[j, n), s2[j, n) )
//			Or isScramble( s1[0, j), s2[n-j, n)) && isScramble( s1[j, n), s2[0, n-j) )
//          Returns true.
//Overlapping subproblem:
//	For any substring of s1 with length i, start from position j,
//		can be used to compare with a substring in s2 from position [0, n-i)
bool Solution::isScramble(string s1, string s2) {
	int length = s1.size();
	//initialization for len 1
	//cube[len][pos1][pos2] 
	vector<vector<vector<bool> > > cube;
	vector<vector<bool> > table;
	cube.push_back(table); //push a stub table for len 0
	for (size_t i = 0; i < length; i++)
	{
		vector<bool> line;
		for (size_t j = 0; j < length; j++) //s2 element
		{
			line.push_back(s1[i] == s2[j]);
		}
		table.push_back(line);
	}
	cube.push_back(table);


	for (size_t len = 2; len <= length; len++) //substring length
	{
		vector<vector<bool> > table;
		for (size_t pos1 = 0; pos1 < length - len + 1; pos1++) //substring start position
		{
			vector<bool> line;
			for (size_t pos2 = 0; pos2 < length - len + 1; pos2++)
			{
				bool temp = false;
				for (size_t i = 1; i < len; i++)
				{
					bool forward = (cube[i][pos1][pos2] 
						&& cube[len - i][pos1 + i][pos2 + i]);
					bool backward = (cube[i][pos1][pos2 + len - i]
						&& cube[len - i][pos1 + i][pos2]);
					temp = temp || (forward || backward);
				}
				line.push_back(temp);
			}
			table.push_back(line);
		}
		cube.push_back(table);
	}

	return cube[length][0][0];
}

