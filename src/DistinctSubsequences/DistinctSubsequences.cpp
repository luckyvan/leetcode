// Source : https://oj.leetcode.com/problems/distinct-subsequences/
// Author : Fan Chou
// Date   : 2014-11-05

/********************************************************************************** 
* 
* Given a string S and a string T, count the number of distinct subsequences of T in S.
* 
* A subsequence of a string is a new string which is formed from the original string 
* by deleting some (can be none) of the characters without disturbing the relative positions 
* of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).
* 
* Here is an example:
* S = "rabbbit", T = "rabbit"
* 
* Return 3.
* 
*               
**********************************************************************************/
#include "../Solution.h"

static int distinctPath(vector<vector<int>>& c, string& T, string& S, int line, int column)
{
	if (line == 0 && column == 0) //reach the left upmost corner
	{
		return 1;
	}

	if (c[line][column - 1] == c[line][column] && T[line - 1] == S[column - 1]) // left and left up are correct direction
	{
		return distinctPath(c, T, S, line, column - 1) + distinctPath(c, T, S, line - 1, column - 1);
	}
	else if (T[line - 1] == S[column - 1]) {
		return distinctPath(c, T, S, line - 1, column - 1);
	}
	else{
		return distinctPath(c, T, S, line, column - 1);
	}
}

int Solution::distinctSubsequences(string S, string T)
{
	//c[i,j] stores common sequence length between T[0..i-1] and S[0..j-1], including the empty string
	//hence c has T.size() + 1 lines and S.size() + 1 columns
	vector<vector<int>> c;
	//1. initialization
	int s_size = S.size();
	int t_size = T.size();
	// 1.1 the 1st line
	vector<int> c_line0;
	for (size_t i = 0; i < s_size + 1; i++)
	{
		c_line0.push_back(0);
	}
	c.push_back(c_line0);
	// 1.2 the 1st column
	for (size_t i = 0; i < t_size; i++)
	{
		vector<int> c_line;
		c_line.push_back(0);
		c.push_back(c_line);
	}

	//2. calculate
	for (size_t line = 1; line < t_size + 1; line++)
	{
		vector<int>& c_line = c[line];
		for (size_t column = 1; column < s_size + 1; column++)
		{
			if (T[line - 1] == S[column - 1])
				c_line.push_back(c[line - 1][column - 1] + 1);
			else
				c_line.push_back(
					c[line - 1][column] > c[line][column - 1] ? c[line - 1][column] : c[line][column - 1]
				);
		}
	}

	if (c[t_size][s_size] != t_size) // not a subsequence
	{
		return 0;
	}

	//3. traverse through distinct paths
	return distinctPath(c, T, S, t_size, s_size);
}