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

vector<vector<int>> difference(vector<vector<int>>& sets, int new_elem)
{
	vector<vector<int>> new_sets;

	for (vector<int>& set : sets)
	{
		vector<int> new_set(set);
		new_set.push_back(new_elem);

		new_sets.push_back(new_set);
	}
	return new_sets;
}

vector<vector<int> > Solution::subsets(vector<int> &S) {
	return subsets_ii(S);
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

	vector<vector<int>> subsets;
	subsets.push_back(vector<int>()); // add empty sets
	vector<vector<vector<int>>> diffs;

	for (size_t i = 0; i < S.size(); i++)
	{
		if (i == 0 || S[i] != S[i-1])
		{
			diffs.push_back(difference(subsets, S[i]));
		}
		else
		{
			diffs.push_back(difference(diffs[i-1], S[i]));
		}

		subsets.insert(subsets.end(), diffs[i].begin(), diffs[i].end());
	}
	return subsets;
}
