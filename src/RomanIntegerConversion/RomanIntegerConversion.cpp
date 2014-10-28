// Source : https://oj.leetcode.com/problems/roman-to-integer/
// Author : FanChou
// Date   : 2014-10-28

/**********************************************************************************
*
* Given a roman numeral, convert it to an integer.
*
* Input is guaranteed to be within the range from 1 to 3999.
*
* wiki: en.wikipedia.org/wiki/Roman_numerals
**********************************************************************************/

#include <iostream>
#include <string>
using namespace std;

int romanCharToInt(char ch){
  int d = 0;
  switch(ch){
    case 'I':
      d = 1;
      break;
    case 'V':
      d = 5;
      break;
    case 'X':
      d = 10;
      break;
    case 'L':
      d = 50;
      break;
    case 'C':
      d = 100;
      break;
    case 'D':
      d = 500;
      break;
    case 'M':
      d = 1000;
      break;
  }
  return d;
}

int romanToInt(string s) {
  if (s.size()<=0) return 0;
  int result = romanCharToInt(s[0]);
  for (int i=1; i<s.size(); i++){
    int prev = romanCharToInt(s[i-1]);
    int curr = romanCharToInt(s[i]);
    //if left<right prev number should be subtracted rather than added
    if (prev < curr) {
      result -= prev;
      result -= prev;
    }
    result += curr;
  }
  return result;
}

