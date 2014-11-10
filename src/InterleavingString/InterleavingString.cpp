// Source : https://oj.leetcode.com/problems/interleaving-string/
// Author : Fan Chou
// Date   : 2014-11-04

/********************************************************************************** 
* 
* Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.
* 
* For example,
* Given:
* s1 = "aabcc",
* s2 = "dbbca",
* 
* When s3 = "aadbbcbcac", return true.
* When s3 = "aadbbbaccc", return false.
* 
*               
**********************************************************************************/
#include "../Solution.h"

//Recursive Problem:
//Let's say s1 has length m, and s2 has length n.
//Provided s3[0, m + n) is interleaved string by s1[0, m), s2[0, n), then  
//If s3[m+n-1] == s1[m - 1], 
//    then, s3[0, m+n-1) is interleaved string by s1[0, m-1), s2[0, n), and
//If s3[m + n - 1] == s2[n - 1],
//	  then, s3[0, m + n - 1) is interleaved string by s1[0, m), s2[0, n-1)
//Buttom-Up Overlapping Optimal Subproblem:
//use match[i][j] to document the match result of s1[0 .. i), s2[0 .. j) to s3[0 .. i + j)
bool Solution::isInterleave(string s1, string s2, string s3) {
	int m = s1.size();
	int n = s2.size();
	vector<bool> match_line(n+1, true); //use a line to represent a table
	//initialize by s2
	for (size_t j = 0; j < n; j++)
	{
		match_line[j + 1] = (s3[j] == s2[j]) && match_line[j];
	}

	for (size_t i = 0; i < m; i++)
	{
		match_line[0] = (s3[i] == s1[i]) && match_line[0];
		for (size_t j = 0; j < n; j++)
		{
			size_t pos = i + j + 1;
			if (((s3[pos] == s2[j]) && match_line[j]) ||
				((s3[pos] == s1[i]) && match_line[j + 1]))
				match_line[j + 1] = true;
			else
				match_line[j + 1] = false;
		}
	}
	return match_line[n];
}

