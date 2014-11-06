// Source : https://oj.leetcode.com/problems/unique-paths/
// Author : Fan Chou
// Date   : 2014-11-06

/**********************************************************************************
*
* Follow up for "Unique Paths":
*
* Now consider if some obstacles are added to the grids. How many unique paths would there be?
*
* An obstacle and empty space is marked as 1 and 0 respectively in the grid.
*
* For example,
* There is one obstacle in the middle of a 3x3 grid as illustrated below.
*
* [
*   [0,0,0],
*   [0,1,0],
*   [0,0,0]
* ]
*
* The total number of unique paths is 2.
*
* Note: m and n will be at most 100.
*
**********************************************************************************/
#include "../Solution.h"

int Solution::uniquePathsWithObstacles(vector<vector<int> >& obstacleGrid) {     
	int line_length = obstacleGrid[0].size();
	//initialization, 1st stub empty line, 1 slot longer than the original line
	vector<int> cur_line;
	for (size_t i = 0; i < line_length + 1; i++)
	{
		cur_line.push_back(0);
	}
	cur_line[1] = 1;

	//the following lines, each slot has a value which is sumed by its left and down slot
	for (size_t i = 0; i < obstacleGrid.size(); i++)
	{
		for (size_t j = 1; j < line_length + 1; j++)
		{
			if (obstacleGrid[i][j-1] == 1)
				cur_line[j] = 0;
			else
				cur_line[j] += cur_line[j - 1];
		}
	}
	return cur_line[line_length];

}
