// Source : https://oj.leetcode.com/problems/maximum-subarray/
// Author : Fan Chou
// Date   : 2014-11-07

/********************************************************************************** 
* 
* Find the contiguous subarray within an array (containing at least one number) 
* which has the largest sum.
* 
* For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
* the contiguous subarray [4,−1,2,1] has the largest sum = 6.
* 
* More practice:
* 
* If you have figured out the O(n) solution, try coding another solution using 
* the divide and conquer approach, which is more subtle.
* 
*               
**********************************************************************************/
#include "../Solution.h"

// define an array sum[] with input array a[], in which,
// sum[i] indicates the largest subarray including the i element as its right end.
// We won't miss the maximum subarray with this definition.
//
// Optimum substructure:
//   if sum[i-1] > 0, then sum[i] = sum[i-1] + a[i], since the current maximum subarray
//   must include the previous one.
//   Or else, sum[i] = a[i], since the current maximum subarray best have the current element only.
int Solution::maximumSubarray(int a[], size_t n)
{
	vector<int> sum;
	sum.push_back(a[0]);
	int maxSum = a[0];
	for (size_t i = 1; i < n; i++)
	{
		if (sum[i - 1] > 0)
			sum.push_back(sum[i - 1] + a[i]);
		else
			sum.push_back(a[i]);
		maxSum = maxSum > sum[i] ? maxSum : sum[i];
	}
	return maxSum;
}