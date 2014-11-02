// Source : https://oj.leetcode.com/problems/longest-substring-without-repeating-characters/
// Author : Fan Chou
// Date   : 2014-11-12

/**********************************************************************************
*
* Given a string, find the length of the longest substring without repeating characters.
* For example, the longest substring without repeating letters for "abcabcbb" is "abc",
* which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.
*
**********************************************************************************/

#include "../Solution.h"
#include <limits.h>

int Solution::longestSubstringWithoutRepeatingCharacters(string s) {
	int charPos[UCHAR_MAX];
	memset(charPos, -1, sizeof(charPos));

	int max_length = 0;
	size_t subStringHeadPos = 0;
	for (size_t i = 0; i < s.size(); i++)
	{
		char c = s[i];
		int lastPosOfTheChar = charPos[c];
		charPos[c] = i;
		if (-1 == lastPosOfTheChar) // non-existent
		{
		    int subStringLength = i - subStringHeadPos + 1;
			max_length = (max_length < subStringLength) ? subStringLength : max_length;
		}
		else{
			/*longest substring must be consecutive, so we can rule out any characters 
			ahead of the previous repeating character*/
			subStringHeadPos = lastPosOfTheChar + 1;
		}
	}
	return max_length;
}
