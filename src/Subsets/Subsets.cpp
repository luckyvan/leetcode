// Source : https://oj.leetcode.com/problems/subsets/
// Author : Fan Chou
// Date   : 2014-11-28

/********************************************************************************** 
* 
* Given a set of distinct integers, S, return all possible subsets.
* 
* Note:
* 
* Elements in a subset must be in non-descending order.
* The solution set must not contain duplicate subsets.
* 
* For example,
* If S = [1,2,3], a solution is:
* 
* [
*   [3],
*   [1],
*   [2],
*   [1,2,3],
*   [1,3],
*   [2,3],
*   [1,2],
*   []
* ]
* 
*               
**********************************************************************************/


#include "../Solution.h"
#include <algorithm>

vector<vector<int> > Solution::subsets(vector<int> &S) {
	std::sort(S.begin(), S.end());

	vector<vector<int> > result;
	result.push_back(vector<int>()); // put empty sets as init
	// 1. in each iter, the result already have all subsets including elements [0 .. i)
	// 2. add element i to create new subset.
	// 3. at the end, result have all subsets including elements [0 .. i]
	for (size_t i = 0; i < S.size(); i++)
	{
		vector<vector<int >> subsets_i;
		for each (vector<int> subset in result)
		{
			vector<int> new_set(subset);
			new_set.push_back(S[i]);
			subsets_i.push_back(new_set);
		}
		std::copy(subsets_i.begin(), subsets_i.end(), std::back_inserter(result));
	}
	return result;
}

/**********************************************************************************
*
* Given a collection of integers that might contain duplicates, S, return all possible subsets.
*
* Note:
*
* Elements in a subset must be in non-descending order.
* The solution set must not contain duplicate subsets.
*
* For example,
* If S = [1,2,2], a solution is:
*
* [
*   [2],
*   [1],
*   [1,2,2],
*   [2,2],
*   [1,2],
*   []
* ]
*
*
**********************************************************************************/

vector<vector<int> > Solution::subsets_ii(vector<int> &S) {
	std::sort(S.begin(), S.end());

	vector<vector<int> > subsets;
	subsets.push_back(vector<int>()); // add empty sets
	
	vector<int> subset_first_elem = { S[0] }; // add subset with 1st element
	subsets.push_back(subset_first_elem);
	
	vector<vector<int> > previous_new_sets = {subset_first_elem};
	// 1. in each iter, the result already have all subsets including elements [0 .. i)
	// 2. add element i to create new subset.
	//   2.1 if S[i] == S[i-1], then S[i] could only be used to extend previous_new_sets, 
	//       or duplicated subsets will be added
	//   2.2 otherwise, S[i] could be used to extend whole subsets;
	// 3. at the end, result have all subsets including elements [0 .. i]
	for (size_t i = 1; i < S.size(); i++)
	{
		vector<vector<int> > subsets_i;
		vector<vector<int> >* p_extendable_subsets = &subsets;
		if (S[i] == S[i-1])
		{
			p_extendable_subsets = &previous_new_sets;
		}

		for each (vector<int> extendable_subset in *p_extendable_subsets)
		{
			vector<int> new_subset(extendable_subset);
			new_subset.push_back(S[i]);
			subsets_i.push_back(new_subset);
		}

		std::copy(subsets_i.begin(), subsets_i.end(), std::back_inserter(subsets));
		previous_new_sets.swap(subsets_i);
	}
	return subsets;

}
