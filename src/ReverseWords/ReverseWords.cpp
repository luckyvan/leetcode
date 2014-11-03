// Source : https://oj.leetcode.com/problems/reverse-words-in-a-string/
// Author : Fan Chou
// Date   : 2014-11-03

/**********************************************************************************
*
* Given an input string, reverse the string word by word.
*
* For example,
* Given s = "the sky is blue",
* return "blue is sky the".
*
***********************************************************************************/
#include "../Solution.h"

static void reverse(string& s, int start, int end){
	while (start < --end)
	{
		char temp = s[start];
		s[start] = s[end];
		s[end] = temp;
		start++;
	}
}

string Solution::reverseWords(string& str) {
	reverse(str, 0, str.length());

	int start = 0;
	int end = 0;
	int length = str.length();
	while(start < length)
	{
		/* find sub string */
		while (isspace(str[start])) { start++; }
		end = start;
		while ((end < length) && !isspace(str[end])) end++;

		/* reverse sub string */
		reverse(str, start, end);
		start = end;
	}

	return string(str);
}

