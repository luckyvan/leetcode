// Source : https://oj.leetcode.com/problems/string-to-integer-atoi/
// Author : Fan Chou
// Date   : 2014-10-27

/********************************************************************************** 
*
* Implement atoi to convert a string to an integer.
*
* Hint: Carefully consider all possible input cases. If you want a challenge,
*       please do not see below and ask yourself what are the possible input cases.
*
* Notes:
*   It is intended for this problem to be specified vaguely (ie, no given input specs).
*   You are responsible to gather all the input requirements up front.
*
*
* Requirements for atoi:
*
* The function first discards as many whitespace characters as necessary until the first
* non-whitespace character is found. Then, starting from this character, takes an optional
* initial plus or minus sign followed by as many numerical digits as possible, and interprets
* them as a numerical value.
*
* The string can contain additional characters after those that form the integral number,
* which are ignored and have no effect on the behavior of this function.
*
* If the first sequence of non-whitespace characters in str is not a valid integral number,
* or if no such sequence exists because either str is empty or it contains only whitespace
* characters, no conversion is performed.
*
* If no valid conversion could be performed, a zero value is returned. If the correct value
* is out of the range of representable values, INT_MAX (2147483647) or INT_MIN (-2147483648)
* is returned.
*
**********************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <limits.h>


int atoi(const char *s) {
  if (s==NULL || *s=='\0')
  {
    return 0;
  }

  //skipping leading space
  const char *sc = s;
  for(;isspace(*sc); sc++);

  char sign = *sc == '-' || *sc == '+' ? *sc++ : '+';

  //skipping leading zero
  const char *s1 = sc;
  for (; *sc == '0'; ++sc);

  unsigned long ret = 0;
  unsigned long tmp = 0;
  const char *s2 = sc;
  int digit = 0;
  for(; isdigit(*sc); sc++) {
    digit = (*sc-'0');
    tmp = ret;                  /* for overflow checking */
    ret = 10*ret + digit ;
  }

  if (s1 == sc) return 0;       /* check string validity */

  int n = sc - s2;

  bool overflow = false;
  if (n < 10) //when base is 10, can have 10 digits at most
    ;
  else if (10 < n                  /* more digits than required */
      || ret < ret - digit        /* near ULONG_MAX, the last digit cause overflow */
      || (ret - digit) / 10 != tmp)  /* far bigger than ULONG_MAX */
  {
    overflow = true;
  }else{
    overflow = (sign == '-') ? (ret > (-((unsigned long)INT_MIN))) : (ret > INT_MAX);
  }

  if (overflow) return (sign == '-') ? INT_MIN : INT_MAX;

  return sign == '-'? -ret : ret;
}


