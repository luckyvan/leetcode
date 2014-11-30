// Source : https://oj.leetcode.com/problems/longest-consecutive-sequence/
// Author : Fan Chou
// Date   : 2014-11-30

/**********************************************************************************
*
* Given an unsorted array of integers, find the length of the longest consecutive elements sequence.
*
* For example,
* Given [100, 4, 200, 1, 3, 2],
* The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.
*
* Your algorithm should run in O(n) complexity.
*
*
**********************************************************************************/

#include "../Solution.h"
#include <unordered_set>

int Solution::longestConsecutive(vector<int> &nums) {
	unordered_set<int> set(nums.begin(), nums.end());
	
	int max_seq = 0;
	//each elem would be accessed and erased only once for O(n)
	while (!set.empty())
	{
		int cnt = 1;
		int number = *set.begin();

		for (int next = number + 1; set.find(next) != set.end(); next++)
		{
			set.erase(set.find(next));
			cnt++;
		}

		for (int previous = number - 1; set.find(previous) != set.end(); previous--)
		{
			set.erase(set.find(previous));
			cnt++;
		}

		if (max_seq < cnt)
		{
			max_seq = cnt;
		}

		set.erase(set.begin());
	}
		
	return max_seq;
}
