// MaximumSubarrayTest.cpp

#ifndef MAXIMUMSUBARRAY_H
#define MAXIMUMSUBARRAY_H

#include <cppunit/extensions/HelperMacros.h>
#include "../src/Solution.h"

class MaximumSubarrayTest : public CPPUNIT_NS::TestFixture
{
    CPPUNIT_TEST_SUITE( MaximumSubarrayTest );
    CPPUNIT_TEST(testMaximumSubarray);
    //CPPUNIT_TEST_EXCEPTION(test_$exception_func, exception);
    CPPUNIT_TEST_SUITE_END();

public: 
   void setUp();
   void tearDown();

   void testMaximumSubarray();

private:
	Solution solution;
   //void test_$exception_func();
};
#endif
