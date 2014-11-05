// Source : https://oj.leetcode.com/problems/unique-paths/
// Author : Fan Chou
// Date   : 2014-11-05

/********************************************************************************** 
* 
* A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
* 
* The robot can only move either down or right at any point in time. The robot is trying to reach 
* the bottom-right corner of the grid (marked 'Finish' in the diagram below).
* 
* How many possible unique paths are there?
* 
* Above is a 3 x 7 grid. How many possible unique paths are there?
* 
* Note: m and n will be at most 100.
*               
**********************************************************************************/
#include "../Solution.h"

int Solution::uniquePaths(int m, int n) {
	vector<int> current_line; //m+1 slots, 1st 0, others 1
	current_line.push_back(0);
	for (size_t i = 0; i < m; i++)
	{
		current_line.push_back(1);
	}

	//the following lines, each slot has a value which is sumed by its left and down slot
	for (size_t i = 0; i < n - 1; i++)
	{
		for (size_t j = 1; j < m+1; j++)
		{
			current_line[j] += current_line[j - 1];
		}
	}
    return current_line[m];
}
