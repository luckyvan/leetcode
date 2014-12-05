// Source : https://oj.leetcode.com/problems/permutations/
// Author : Fan Chou
// Date   : 2014-12-04

/**********************************************************************************
*
* Given a collection of numbers, return all possible permutations.
*
* For example,
* [1,2,3] have the following permutations:
* [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].
*
*
**********************************************************************************/

#include "../Solution.h"
#include <algorithm>

void addElement(vector<vector<int> >& permutations, int new_elem, int duplication)
{
	vector<vector<int> > extended_permutations;
	for each (vector<int> permutation in permutations)
	{
		//skip all duplication for Combination 
		size_t stub = 0;

		for (size_t i = 0, find_num = 0; i < permutation.size() && find_num != duplication; i++)
		{
			if (permutation[i] == new_elem)
			{
				stub = i + 1;
				find_num++;
			}
		}

		//extended [stub, end], insert [begin, stub) 1st
		for (size_t i = stub; i <= permutation.size(); i++)
		{

			extended_permutations.push_back(vector<int>(
				permutation.begin(), permutation.begin() + stub));
			vector<int>& extended_permutation = extended_permutations.back();
			
			for (size_t j = stub; j < i; j++)
			{
				extended_permutation.push_back(permutation[j]);
			}

			extended_permutation.push_back(new_elem);

			for (size_t j = i; j < permutation.size(); j++)
			{
				extended_permutation.push_back(permutation[j]);
			}
		}
	}

	permutations.swap(extended_permutations);
}

vector<vector<int> > Solution::permute(vector<int> &num) {
	return permuteUnique(num);
}


// Source : https://oj.leetcode.com/problems/permutations-ii/
// Author : Fan Chou
// Date   : 2014-12-04

/**********************************************************************************
*
* Given a collection of numbers that might contain duplicates, return all possible unique permutations.
*
* For example,
* [1,1,2] have the following unique permutations:
* [1,1,2], [1,2,1], and [2,1,1].
*
*
**********************************************************************************/
vector<vector<int> > Solution::permuteUnique(vector<int> &nums) {
	std::sort(nums.begin(), nums.end());
	vector<vector<int> > permutations = { vector<int>() }; //empty permutation
	int duplication = 0;
	for (size_t i = 0; i < nums.size(); i++)
	{
		int num = nums[i];
		if ((i == 0) || (nums[i] != nums[i - 1]))
		{
			duplication = 0;
		}
		else
		{
			duplication += i;
		}

		addElement(permutations, num, duplication);
	}

	return permutations;
}