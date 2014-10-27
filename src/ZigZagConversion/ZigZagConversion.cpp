// Source : https://oj.leetcode.com/problems/zigzag-conversion/
// Author : Fan Chou
// Date   : 2014-10-27

/********************************************************************************** 
*
* The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: 
* (you may want to display this pattern in a fixed font for better legibility)
*
* P   A   H   N
* A P L S I I G
* Y   I   R
*
* And then read line by line: "PAHNAPLSIIGYIR"
*
* Write the code that will take a string and make this conversion given a number of rows:
*
* string convert(string text, int nRows);
*
* convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
* convert("PAYPALISHIRING", 4) should return "PINALSIGYAHRPI".
*
*
**********************************************************************************/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

string convert(string s, int nRows) {
  int size = s.size();
  if (nRows<=1 || nRows>=size) return s;

  string result;
  // every nZig characters forms a zig. The 1st zig is "PAYP" in 3 rows case.
  int nZig = 2*nRows - 2;
  for(int row=0; row<nRows; row++) {
    int base = 0; //1st element in each zig
    for(;;)
    {
      //base+row: element in the row belongs to that zig
      if(base+row >= size) break;
      result += s[base+row];

      if((row!=0) && (row!=(nRows-1)))
      {
        //base+nZig-row: next element in the same row.
        if(base+nZig-row >= size) break;
        result += s[base+nZig-row];
      }

      base = base + nZig;
    }
  }

  return result;
}

