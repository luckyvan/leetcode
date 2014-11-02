// LongestCommonPrefixTest.cpp

#ifndef LONGESTCOMMONPREFIX_H
#define LONGESTCOMMONPREFIX_H

#include <cppunit/extensions/HelperMacros.h>
#include "../src/Solution.h"

class LongestCommonPrefixTest : public CPPUNIT_NS::TestFixture
{
    CPPUNIT_TEST_SUITE( LongestCommonPrefixTest );
    CPPUNIT_TEST(testNormalCase);
    //CPPUNIT_TEST_EXCEPTION(test_$exception_func, exception);
    CPPUNIT_TEST_SUITE_END();

public: 
   void setUp();
   void tearDown();

   void testNormalCase();
private:
	Solution solution;

};
#endif
