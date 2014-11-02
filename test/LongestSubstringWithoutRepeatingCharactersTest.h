// LongestSubstringWithoutRepeatingCharactersTest.cpp

#ifndef LONGESTSUBSTRINGWITHOUTREPEATINGCHARACTERS_H
#define LONGESTSUBSTRINGWITHOUTREPEATINGCHARACTERS_H

#include <cppunit/extensions/HelperMacros.h>
#include "../src/Solution.h"

class LongestSubstringWithoutRepeatingCharactersTest : public CPPUNIT_NS::TestFixture
{
    CPPUNIT_TEST_SUITE( LongestSubstringWithoutRepeatingCharactersTest );
    CPPUNIT_TEST(testInterleavingSubstring);
    //CPPUNIT_TEST_EXCEPTION(test_$exception_func, exception);
    CPPUNIT_TEST_SUITE_END();

public: 
   void setUp();
   void tearDown();

   void testInterleavingSubstring();

private:
	Solution solution;
   //void test_$exception_func();
};
#endif
