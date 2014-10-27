
#include <cppunit/config/SourcePrefix.h>
#include "../src/LongestCommonPrefix/LongestCommonPrefix.cpp"
#include <stdlib.h>
#include <limits.h>
#include "LongestCommonPrefixTest.h"

// Registers the fixture into the 'registry'
CPPUNIT_TEST_SUITE_REGISTRATION( LongestCommonPrefixTest );


void LongestCommonPrefixTest::setUp()
{
}


void LongestCommonPrefixTest::tearDown()
{
}

void LongestCommonPrefixTest::testNormalCase()
{
  string mystrings[] = {string("abc"), string("abdef"), string("abccc")};
  vector<string> strs (mystrings, mystrings + sizeof(mystrings)/sizeof(string));

  CPPUNIT_ASSERT_EQUAL (string("ab"), longestCommonPrefix(strs));
}


