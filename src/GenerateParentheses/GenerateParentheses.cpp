// Source : https://oj.leetcode.com/problems/implement-strstr/
// Author : Fan Chou
// Date   : 2014-11-03

/**********************************************************************************
*
* Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
*
* For example, given n = 3, a solution set is:
*
* "((()))", "(()())", "(())()", "()(())", "()()()"
*
*
**********************************************************************************/
#include "../Solution.h"
#include <algorithm>

vector<string> Solution::generateParentheses(int n) {
	vector<string> parentheses;
	if (n == 0){ // termination condition with zero parentheses.
		parentheses.push_back("");
	}

	// divide the n parentheses into two parts
	// 1. left i parentheses in which the left-most '(' and right-most ')' are a pair.
	//    That is, '(' n - 1 parentheses ')'
	// 2. right n - i parentheses
	for (size_t i = 1; i <= n; i++)
	{
		vector<string> right_parentheses = generateParentheses(n - i);
		vector<string> left_parentheses = generateParentheses(i - 1);
		for (size_t i = 0; i < left_parentheses.size(); i++){
			for (size_t j = 0; j < right_parentheses.size(); j++)
			{
				parentheses.push_back("(" + left_parentheses[i] + ")" + right_parentheses[j]);
			}
		}
	}
	return parentheses;
}
