// Source : https://oj.leetcode.com/problems/minimum-window-substring/
// Author : Fan Chou
// Date   : 2014-11-24

/**********************************************************************************
*
* Given a string S and a string T, find the minimum window in S which will
* contain all the characters in T in complexity O(n).
*
* For example,
* S = "ADOBECODEBANC"
* T = "ABC"
*
* Minimum window is "BANC".
*
* Note:
*
* > If there is no such window in S that covers all characters in T,
*   return the emtpy string "".
*
* > If there are multiple such windows, you are guaranteed that there
*   will always be only one unique minimum window in S.
*
*
**********************************************************************************/

#include "../Solution.h"
#include <map>
#include <queue>
#include <stdlib.h>

string Solution::minWindow(string S, string T) {
	map<char, int> char_to_num_t; // in string T, character to its ocurrence
	map<char, int> char_to_num_s; // in string S, character to its current occurence
	queue<int> pos_q; // position queue.
	int matched_num = 0;

	//init
	for each (char c in T)
	{
		if (char_to_num_t.find(c) != char_to_num_t.end())
		{
			char_to_num_t[c] += 1;
		}
		else
		{
			char_to_num_t[c] = 1;
		}
		char_to_num_s[c] = 0;
	}

	int distint_char_num = char_to_num_t.size();
	string minium_window = "";
	for (size_t i = 0; i < S.size(); i++)
	{
		char ch = S[i];
		// a character also in T
		if (char_to_num_t.find(ch) != char_to_num_t.end())
		{
			pos_q.push(i);

			char_to_num_s[ch] += 1;


			// a new completely matched character
			if (char_to_num_s[ch] == char_to_num_t[ch])
			{
				matched_num += 1;

				// deprive redundant characters in the window front
				char front_ch;
				while ((pos_q.size() > 0) &&
					(front_ch = S[pos_q.front()], char_to_num_s[front_ch] > char_to_num_t[front_ch]))
				{
					char_to_num_s[front_ch] -= 1;
					pos_q.pop();
				}

				if (matched_num == distint_char_num) // a match
				{
					string window(S.begin() + pos_q.front(), S.begin() + pos_q.back() + 1);
					if ((minium_window == "") ||
						(minium_window.size() > window.size())){
						minium_window = window;
					}

					char front_ch = S[pos_q.front()];
					char_to_num_s[front_ch] -= 1;
					matched_num -= 1;
					pos_q.pop();
				}
			}
		}
	}
	return minium_window;
}



