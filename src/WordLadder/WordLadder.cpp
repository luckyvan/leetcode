// Source : https://oj.leetcode.com/problems/word-ladder/
// Author : Fan Chou
// Date   : 2014-10-12

/**********************************************************************************
*
* Given two words (start and end), and a dictionary, find the length of shortest
* transformation sequence from start to end, such that:
*
* Only one letter can be changed at a time
* Each intermediate word must exist in the dictionary
*
* For example,
*
* Given:
* start = "hit"
* end = "cog"
* dict = ["hot","dot","dog","lot","log"]
*
* As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
* return its length 5.
*
* Note:
*
* Return 0 if there is no such transformation sequence.
* All words have the same length.
* All words contain only lowercase alphabetic characters.
*
*
**********************************************************************************/

#include "../Solution.h"
#include <algorithm>

bool isChangable(string s1, string s2)
{
	if (s1.length() != s2.length()){
		return false;
	}
	size_t diff = 0;
	for (size_t i = 0; i < s1.length(); i++)
	{
		if (s1[i] != s2[i])
			diff++;
	}

	return diff == 1;
}

// a shortest path would appear in a bread-first-traverse, since any path including nodes in the
// same level won't be the shortest.
int Solution::ladderLength(string start, string end, unordered_set<string> &dict) {

	unordered_set<string> transform_seq;
	unordered_set<string> local_dict(dict);
	transform_seq.insert(start);
	unordered_set<string> current_level;
	current_level.insert(start);

	int level_num = 0;
	while (!current_level.empty())
	{
		unordered_set<string> next_level;
		level_num++;
		for (
			unordered_set<string>::iterator it = current_level.begin();
			it != current_level.end();
		it++
			)
		{
			string str = *it;
			if (isChangable(str, end))
				return level_num + 1;
			unordered_set<string>::iterator it1 = local_dict.begin();
			while (it1 != local_dict.end())
			{
				string next = *it1;

				unordered_set<string>::iterator it_temp = it1;
				it1++;

				if (isChangable(str, next))
				{
					next_level.insert(next);
					local_dict.erase(it_temp);
				}
			}

		}
		current_level.swap(next_level);
	}

	return level_num;
}


/**********************************************************************************
*
* Given two words (start and end), and a dictionary, find all shortest transformation
* sequence(s) from start to end, such that:
*
* Only one letter can be changed at a time
* Each intermediate word must exist in the dictionary
*
* For example,
*
* Given:
* start = "hit"
* end = "cog"
* dict = ["hot","dot","dog","lot","log"]
*
* Return
*
*   [
*     ["hit","hot","dot","dog","cog"],
*     ["hit","hot","lot","log","cog"]
*   ]
*
* Note:
*
* All words have the same length.
* All words contain only lowercase alphabetic characters.
*
*
**********************************************************************************/


void findLaddersDST(
	const string& start,
	const string& end,
	unordered_set<string> &dict,
	vector<string>& ladder,
	vector<vector<string> >& ladders)
{
	if (isChangable(start, end))
	{
		ladder.push_back(end);
		ladders.push_back(ladder);
		return;
	}

	unordered_set<string>::iterator it = dict.begin();
	unordered_set<string>::iterator it_end = dict.end();

	while (it != it_end)
	{
		string str = *it;

		if (isChangable(str, start))
		{
			unordered_set<string> new_dict(dict);
			vector<string> new_ladder(ladder);
			new_dict.erase(str);
			new_ladder.push_back(str);

			findLaddersDST(str, end, new_dict, new_ladder, ladders);
		}
		it++;
	}
}

vector<vector<string> > Solution::findLadders(string start, string end, unordered_set<string> &dict)
{
	vector<vector<string> > ladders;
	vector<string> ladder;

	findLaddersDST(start, end, dict, ladder, ladders);

	int shortest_size = INT_MAX;
	for each (vector<string> ladder in ladders)
	{
		if (ladder.size() < shortest_size) shortest_size = ladder.size();
	}

	
	vector<vector<string> >::iterator new_end = remove_if(ladders.begin(), ladders.end(),
		[shortest_size](const vector<string>& ladder){
		     return ladder.size() > shortest_size;
	   }
	);
	vector<vector<string> > new_ladders(ladders.begin(), new_end);
	return new_ladders;
}

