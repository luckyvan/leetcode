// LongestValidParenthesesTest.cpp

#ifndef LONGESTVALIDPARENTHESES_H
#define LONGESTVALIDPARENTHESES_H

#include <cppunit/extensions/HelperMacros.h>
#include "../src/Solution.h"

class LongestValidParenthesesTest : public CPPUNIT_NS::TestFixture
{
    CPPUNIT_TEST_SUITE( LongestValidParenthesesTest );
    CPPUNIT_TEST(testValidParentheses);
    //CPPUNIT_TEST_EXCEPTION(test_$exception_func, exception);
    CPPUNIT_TEST_SUITE_END();

public: 
   void setUp();
   void tearDown();

   void testValidParentheses();

private:
	Solution solution;
   //void test_$exception_func();
};
#endif
