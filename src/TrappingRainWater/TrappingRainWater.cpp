// Source : https://oj.leetcode.com/problems/trapping-rain-water/
// Author : Fan Chou
// Date   : 2014-11-13

/********************************************************************************** 
* 
* Given n non-negative integers representing an elevation map where the width of each bar is 1, 
* compute how much water it is able to trap after raining. 
* 
* For example, 
* Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
*   
*     ^                                             
*     |                                             
*   3 |                       +--+                  
*     |                       |  |                  
*   2 |          +--+xxxxxxxxx|  +--+xx+--+         
*     |          |  |xxxxxxxxx|  |  |xx|  |         
*   1 |   +--+xxx|  +--+xxx+--+  |  +--+  +--+      
*     |   |  |xxx|  |  |xxx|  |  |  |  |  |  |      
*   0 +---+--+---+--+--+---+--+--+--+--+--+--+----->
*       0  1   0  2  1   0  1  3  2  1  2  1        
* 
* The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 
* 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!
*               
**********************************************************************************/

#include "../Solution.h"

template<class T>
int collect(T begin, T end)
{
	int result = 0;

	int left_height = *begin;
	T it = begin++;
	while (it != end)
	{
		int height = *it;
		if (height > left_height)
		{
			left_height = height;
		}
		else
		{
			result += left_height - height;
		}
		it++;
	}

	return result;
}

int Solution::trap(int a[], int n) {
    int result = 0;
	vector<int> array(a, a + n);

	//find highest bar
	int max = array[0];
	vector<int>::iterator max_it;
	for (vector<int>::iterator it = array.begin(); it != array.end(); it++)
	{
		if (*it > max)
		{
			max_it = it;
			max = *it;
		}
	}

	result += collect(array.begin(), max_it);
	result += collect(array.rbegin(), vector<int>::reverse_iterator(max_it));
    return result;
}
