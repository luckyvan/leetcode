// Source : https://oj.leetcode.com/problems/valid-parentheses/
// Author : Fan Chou
// Date   : 2014-10-27

/********************************************************************************** 
*
* Given a string containing just the characters '(', ')', '{', '}', '[' and ']',
* determine if the input string is valid.
*
* The brackets must close in the correct order, "()" and "()[]{}" are all valid
* but "(]" and "([)]" are not.
*
*
**********************************************************************************/

#include "../Solution.h"

bool Solution::isValid(string s) {

  vector<char> stack;

  int i=0;
  for (; i<s.length(); i++)
  {
    char c = s[i];

    if (c == '(' || c == '{' || c == '[')
      stack.push_back(c);
    else
    {
      if (stack.empty()) break;

      char lch = stack.back();
      if ( (c == ')' && lch == '(') 
          || (c == '}' && lch == '{')
          || (c == ']' && lch == '[') ) //match
        stack.pop_back();
      else
        break;
    }

  }

  return stack.empty() && (i == s.length());
}

