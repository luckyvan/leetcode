// Source : https://oj.leetcode.com/problems/longest-valid-parentheses/
// Author : Fan Chou
// Date   : 2014-11-04

/********************************************************************************** 
* 
* Given a string containing just the characters '(' and ')', 
* find the length of the longest valid (well-formed) parentheses substring.
* 
* For "(()", the longest valid parentheses substring is "()", which has length = 2.
* 
* Another example is ")()())", where the longest valid parentheses substring is "()()", 
* which has length = 4.
* 
*               
**********************************************************************************/
#include "../Solution.h"

int Solution::longestValidParentheses(string s)
{
	int maxLength = 0;
	
	vector<int> invalid_left;
	int lastInvalidRight = -1;
	for (size_t i = 0; i < s.size(); i++)
	{
		if (s[i] == '('){
			invalid_left.push_back(i);
		}
		else{ //')'
			if (!invalid_left.empty()){
				invalid_left.pop_back();
				int currentLength = (invalid_left.empty()) ? i - lastInvalidRight : i - invalid_left.back();
				maxLength = (maxLength > currentLength) ? maxLength : currentLength;
			}
			else{
				lastInvalidRight = i;
			}
		}
	}
	return maxLength;
}

