// Source : https://oj.leetcode.com/problems/edit-distance/
// Author : Fan Chou
// Date   : 2014-11-08

/********************************************************************************** 
* 
* Given two words word1 and word2, find the minimum number of steps required to 
* convert word1 to word2. (each operation is counted as 1 step.)
* 
* You have the following 3 operations permitted on a word:
* 
* a) Insert a character
* b) Delete a character
* c) Replace a character
* 
* It's a variant of LCS, see also @DistinctSubsequences              
**********************************************************************************/
#include "../Solution.h"

int Solution::minDistance(string word1, string word2) {
	int m = word1.size();
	int n = word2.size();

	//Since the algorithm here does no require to find the common sequence,
	//We only need to store the previous line in distance table.
	vector<int> csd; 
	for (size_t i = 0; i < m+1; i++)
	{
		csd.push_back(0);
	}

	for (size_t i = 0; i < n; i++)
	{   
		int ij = csd[0]; 
		for (size_t j = 0; j < m; j++)
		{
			//the jth of word1, and ith of word2 specify the [i+1][j+1] element in the table.
			//For the the csd, 
			// 1. ij stores [i][j], 
			// 2. the unmodified csd[j+1] is [i][j+1]
			// 3. the modified csd[j] is [i+1][j]
			int temp = csd[j + 1]; //[i][j+1]
			if (word1[j] == word2[i]){
				csd[j + 1] = ij + 1; //LCS extend for 1
			}
			else{
				if (csd[j] > csd[j + 1])
					csd[j + 1] = csd[j];
			}
			ij = temp;
		}
	}

	return (m > n) ? m - csd[m] : n - csd[m];
}
