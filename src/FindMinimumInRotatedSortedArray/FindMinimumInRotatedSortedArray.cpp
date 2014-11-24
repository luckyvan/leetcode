// Source : https://oj.leetcode.com/problems/find-minimum-in-rotated-sorted-array/
// Author : Fan Chou
// Date   : 2014-11-24

/********************************************************************************** 
* 
* Suppose a sorted array is rotated at some pivot unknown to you beforehand.
* 
* (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
* 
* Find the minimum element.
* 
* You may assume no duplicate exists in the array.
*               
**********************************************************************************/
#include "../Solution.h"

int Solution::findMin(vector<int> &num) {

    int low=0, high=num.size()-1;

	//if mid is greater than low, [low .. mid] is non-rotated
    while(high-low>0){
        int mid = low + (high-low)/2;
		if (num[low] < num[mid] && num[mid] < num[high]) //already sorted
			break;

		if (num[mid] > num[low]) //[low .. mid] sorted
		{
			low = mid + 1;
		}
		else //[mid+1 .. high] sorted
		{
			high = mid - 1;
		}
    }
	return num[low];
}

int Solution::findMinWithDuplication(vector<int> &num)
{
	int low = 0, high = num.size() - 1;
	while (low < high)
	{
		while (num[low] == num[high])
		{
			low++;
			high--;
			continue;
		}

		int mid = low + (high - low) / 2;
		if (num[low] <= num[mid] && num[mid] <= num[high]) //already sorted
			break;

		if (num[mid] < num[low]) //[mid .. high] sorted
		{
			high = mid - 1;
		}
		
		if (num[mid] > num[high])//[low .. mid - 1] sorted
		{
			low = mid + 1;
		}
	}

	return num[low];
}

