// Source : https://oj.leetcode.com/problems/implement-strstr/
// Author : Fan Chou
// Date   : 2014-11-02

/**********************************************************************************
*
* Implement strStr().
*
* Returns a pointer to the first occurrence of needle in haystack, or null if needle is not part of haystack.
*
* Implementation:
*    1. naive string matcher and kmp string matcher
*    2. a strStr.pdf for algorithms
**********************************************************************************/
#include "../Solution.h"

// naive string matcher
char* Solution::strStr(char *haystack, char *needle) {
	int n = strlen(haystack);
	int m = strlen(needle);

	for (int i = 0; i < (n - m); i++)
	{
		char *q = needle;
		char *p = haystack + i;
		while (*q && *p && *p == *q){
			p++; q++;
		}
		if (!*q){
			return haystack;
		}
	}

	return NULL;
}

vector<int> Solution::computePrefixFunction(char* pattern){
	int m = strlen(pattern);
	vector<int> prefix_function(m);
	prefix_function[0] = 0;
	int prefix = 0;

	for (size_t pos = 1; pos < m; pos++)
	{
		while (prefix > 0 && (pattern[prefix] != pattern[pos]))
		{
			prefix = prefix_function[prefix-1];
		}
		if (pattern[prefix] == pattern[pos])
			prefix += 1;
		prefix_function[pos] = prefix;
	}

	return prefix_function;
}

//KMP
char* Solution::strStr_kmp(char *haystack, char *needle) {
	int n = strlen(haystack);
	int m = strlen(needle);
	vector<int> prefix_func = computePrefixFunction(needle);

	int match = 0;

	for (size_t i = 0; i < n; i++){
		while (match > 0 && (needle[match] != haystack[i])) // next character does not match
		{
			match = prefix_func[match - 1];
		}
		if (needle[match] == haystack[i])//next character match
		{
			match += 1;
		}
		if (match == m)//i is the last matched character
		{
			return haystack + i + 1 - m;
		}
	}

	return NULL;
}


