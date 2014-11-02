// Source : https://oj.leetcode.com/problems/longest-common-prefix/
// Author : Fan Chou
// Date   : 2014-10-27

/********************************************************************************** 
*
* Write a function to find the longest common prefix string amongst an array of strings.
*
*
**********************************************************************************/
#include "../Solution.h"

string Solution::longestCommonPrefix(vector<string> &strs) {
  string word;
  if (strs.size()<=0) return word;

  int length = strs[0].length();
  int str_number = strs.size();
  //1. find the shortest string
  for (int i = 1; i<str_number; i++) 
    if(length > strs[i].length()) length = strs[i].length();

  //2. compare each charater across all strings at a time to reduce comparison number
  for (int i = 0; i < length; i++)
  {
    bool match = true;
    char character = strs[0][i];
    int index = 1;
    for (; index<str_number; index++)
    {
      if (strs[index][i] != character) break;
    }

    if (index != str_number) 
      break;
    else
      word += character;
  }

  return word;
}

