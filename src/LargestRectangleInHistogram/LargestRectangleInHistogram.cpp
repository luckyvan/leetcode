// Source : https://oj.leetcode.com/problems/largest-rectangle-in-histogram/
// Author : Hao Chen
// Date   : 2014-07-20

/********************************************************************************** 
* 
* Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, 
* find the area of largest rectangle in the histogram.
* 
* Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].
* 
* The largest rectangle is shown in the shaded area, which has area = 10 unit.
* 
* For example,
* Given height = [2,1,5,6,2,3],
* return 10.
* 
*               
**********************************************************************************/

#include "../Solution.h"

// From left to right, bottom to top, traverse the whole histogram point by point,
// take current point as the right-top point of a rectangle and it's height is 'h',
//    1. If it's left has a point, then current rectangle is h greater than the left one,
//    2. Or else, current point only has 1 column and its area is h
int Solution::largestRectangleInHistogram(vector<int> &heights) {
	vector<int> areas_by_column;

	int max_area = 0;
	for (size_t i = 0; i < heights.size(); i++)
	{
		size_t j = 0;
		for (; j < heights[i]; j++)
		{
			size_t cur_height = j + 1;
			if (j < areas_by_column.size()) //extend a rectangle
				areas_by_column[j] += cur_height;
			else							//a new rectangle
				areas_by_column.push_back(cur_height);
			max_area = max_area > areas_by_column[j] ? max_area : areas_by_column[j];
		}
		//remove invalid rectangle record from previous column
		for (size_t i = areas_by_column.size(); i > j; i--)
		{
			areas_by_column.pop_back();
		}
	}
	return max_area;
}

