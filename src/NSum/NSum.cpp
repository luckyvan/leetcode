// Source : https://oj.leetcode.com/problems/3sum/
// Author : Fan Chou
// Date   : 2014-11-30

/**********************************************************************************
*
* Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0?
* Find all unique triplets in the array which gives the sum of zero.
*
* Note:
*
* Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
* The solution set must not contain duplicate triplets.
*
*     For example, given array S = {-1 0 1 2 -1 -4},
*
*     A solution set is:
*     (-1, 0, 1)
*     (-1, -1, 2)
*
*
**********************************************************************************/

#include "../Solution.h"
#include <algorithm>
#include <numeric>

vector<vector<int> > nSum(vector<int> &num, const int subset_size, const int target)
{
	std::sort(num.begin(), num.end());

	vector<vector<int> > subsets;
	vector<vector<int> > result;

	subsets.push_back(vector<int>()); // add empty sets

	vector<int> subset_first_elem = { num[0] }; // add subset with 1st element
	subsets.push_back(subset_first_elem);

	vector<vector<int> > previous_new_sets = { subset_first_elem };
	// 1. in each iter, the result already have all subsets including elements [0 .. i)
	// 2. add element i to create new subset.
	//   2.1 if S[i] == S[i-1], then S[i] could only be used to extend previous_new_sets, 
	//       or duplicated subsets will be added
	//   2.2 otherwise, S[i] could be used to extend whole subsets;
	// 3. at the end, result have all subsets including elements [0 .. i]
	for (size_t i = 1; i < num.size(); i++)
	{
		vector<vector<int> > subsets_i;
		vector<vector<int> >* p_extendable_subsets = &subsets;
		if (num[i] == num[i - 1])
		{
			p_extendable_subsets = &previous_new_sets;
		}

		for each (vector<int> extendable_subset in *p_extendable_subsets)
		{
			vector<int> new_subset(extendable_subset);
			new_subset.push_back(num[i]);

			int sum = std::accumulate(new_subset.begin(), new_subset.end(), 0);
			if (
				(new_subset.size() == subset_size) &&
				(sum == target)
				)
			{
				result.push_back(new_subset);
			}
			else if (new_subset.size() < subset_size)
			{
				subsets_i.push_back(new_subset);
			}
		}

		std::copy(subsets_i.begin(), subsets_i.end(), std::back_inserter(subsets));
		previous_new_sets.swap(subsets_i);
	}

	return result;
}

vector<vector<int> > Solution::threeSum(vector<int> &num)
{
	return nSum(num, 3, 0);
}

/**********************************************************************************
*
* Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target?
* Find all unique quadruplets in the array which gives the sum of target.
*
* Note:
*
* Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
* The solution set must not contain duplicate quadruplets.
*
*     For example, given array S = {1 0 -1 0 -2 2}, and target = 0.
*
*     A solution set is:
*     (-1,  0, 0, 1)
*     (-2, -1, 1, 2)
*     (-2,  0, 0, 2)
*
*
**********************************************************************************/
vector<vector<int> > Solution::fourSum(vector<int> &num, int target)
{
	return nSum(num, 4, target);
}