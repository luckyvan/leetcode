// Source : https://oj.leetcode.com/problems/jump-game/
// Author : Fan Chou
// Date   : 2014-11-26

/********************************************************************************** 
* 
* Given an array of non-negative integers, you are initially positioned at the first index of the array.
* 
* Each element in the array represents your maximum jump length at that position. 
* 
* Determine if you are able to reach the last index.
* 
* For example:
* A = [2,3,1,1,4], return true.
* 
* A = [3,2,1,0,4], return false.
* 
*               
**********************************************************************************/

#include "../Solution.h"
bool Solution::canJump(int A[], int n) {
	int lower = -1; // (lower .. upper]
	int upper = 0;
	while (true)
	{
		int new_upper = upper; // cal new range, from (upper .. new_upper]
		for (size_t i = lower+1; i <= upper; i++)
		{
			if (i+A[i] > new_upper)
			{
				new_upper = i + A[i];
			}
		}

		lower = upper;
		upper = new_upper;
		// no element in range
		if (upper == lower) return false;
		// already cover
		if (upper >= (n - 1)) return true;

	}
}

/**********************************************************************************
*
* Given an array of non-negative integers, you are initially positioned at the first index of the array.
*
* Each element in the array represents your maximum jump length at that position.
*
* Your goal is to reach the last index in the minimum number of jumps.
*
* For example:
* Given array A = [2,3,1,1,4]
*
* The minimum number of jumps to reach the last index is 2.
* (Jump 1 step from index 0 to 1, then 3 steps to the last index.)
*
*
**********************************************************************************/

int Solution::jump(int A[], int n)
{
	int lower = -1; // (lower .. upper]
	int upper = 0;
	int step = 0;
	while (true)
	{
		int new_upper = upper; // cal new range, from (upper .. new_upper]
		for (size_t i = lower + 1; i <= upper; i++)
		{
			if (i + A[i] > new_upper)
			{
				new_upper = i + A[i];
			}
		}

		lower = upper;
		upper = new_upper;
		step += 1;
		// no element in range
		if (upper == lower) return -1;
		// already cover
		if (upper >= (n - 1)) return step;

	}
}