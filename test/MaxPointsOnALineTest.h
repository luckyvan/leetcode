// MaxPointsOnALineTest.cpp

#ifndef MAXPOINTSONALINE_H
#define MAXPOINTSONALINE_H

#include <cppunit/extensions/HelperMacros.h>
#include "../src/Solution.h"

class MaxPointsOnALineTest : public CPPUNIT_NS::TestFixture
{
    CPPUNIT_TEST_SUITE( MaxPointsOnALineTest );
    CPPUNIT_TEST(testMaxPoints);
    //CPPUNIT_TEST_EXCEPTION(test_$exception_func, exception);
    CPPUNIT_TEST_SUITE_END();

public: 
   void setUp();
   void tearDown();

   void testMaxPoints();

private:
	Solution solution;
   //void test_$exception_func();
};
#endif
