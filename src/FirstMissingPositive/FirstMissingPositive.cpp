// Source : https://oj.leetcode.com/problems/first-missing-positive/
// Author : Fan Chou
// Date   : 2014-11-24

/**********************************************************************************
*
* Given an unsorted integer array, find the first missing positive integer.
*
* For example,
* Given [1,2,0] return 3,
* and [3,4,-1,1] return 2.
*
* Your algorithm should run in O(n) time and uses constant space.
*
*
**********************************************************************************/

#include "../Solution.h"
#include <stdlib.h>
#include <algorithm>

int Solution::firstMissingPositive(int A[], int n) {
	//1. find minimum positive
	int min = INT_MAX;
	for (size_t i = 0; i < n; i++)
	{
		if ((A[i] >= 0) && (A[i] < min)) min = A[i];
	}

	//2. place every positive into its rightful place
	for (size_t i = 0; i < n;)
	{
		int pos = A[i] - min;
		if (
			(A[i] >= 0) && //postive
			(pos != i)) //not in the right place
		{
			//switch
			std::swap(A[i], A[pos]);

		}
		else
		{
			i++;
		}
	}

	//3. find index
	size_t i = 0;
	for (; i < n; i++)
	{
		int pos = A[i] - min;
		if (pos != i)
		{
			break;
		}
	}

	return min + i;
}
