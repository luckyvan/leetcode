// RegularExpressionMatchingTest.cpp

#ifndef REGULAREXPRESSIONMACHINGTEST_H
#define REGULAREXPRESSIONMACHINGTEST_H

#include <cppunit/extensions/HelperMacros.h>
#include "../src/Solution.h"

class RegularExpressionMatchingTest : public CPPUNIT_NS::TestFixture
{
    CPPUNIT_TEST_SUITE( RegularExpressionMatchingTest );
    CPPUNIT_TEST(testMatching);
    //CPPUNIT_TEST_EXCEPTION(test_$exception_func, exception);
    CPPUNIT_TEST_SUITE_END();

public: 
   void setUp();
   void tearDown();

   void testMatching();

private:
	Solution solution;
   //void test_$exception_func();
};
#endif
