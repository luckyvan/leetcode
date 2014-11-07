// LargestRectangleInHistogramTest.cpp

#ifndef LARGESTRECTANGLEINHISTOGRAM_H
#define LARGESTRECTANGLEINHISTOGRAM_H

#include <cppunit/extensions/HelperMacros.h>
#include "../src/Solution.h"

class LargestRectangleInHistogramTest : public CPPUNIT_NS::TestFixture
{
    CPPUNIT_TEST_SUITE( LargestRectangleInHistogramTest );
    CPPUNIT_TEST(testLargestRectangleInHistogram);
    //CPPUNIT_TEST_EXCEPTION(test_$exception_func, exception);
    CPPUNIT_TEST_SUITE_END();

public: 
   void setUp();
   void tearDown();

   void testLargestRectangleInHistogram();

private:
	Solution solution;
   //void test_$exception_func();
};
#endif
