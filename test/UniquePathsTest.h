// UniquePathsTest.cpp

#ifndef UNIQUEPATHS_H
#define UNIQUEPATHS_H

#include <cppunit/extensions/HelperMacros.h>
#include "../src/Solution.h"

class UniquePathsTest : public CPPUNIT_NS::TestFixture
{
    CPPUNIT_TEST_SUITE( UniquePathsTest );
    CPPUNIT_TEST(testUniquePaths);
	CPPUNIT_TEST(testUniquePathsWithObstacles);
    //CPPUNIT_TEST_EXCEPTION(test_$exception_func, exception);
    CPPUNIT_TEST_SUITE_END();

public: 
   void setUp();
   void tearDown();

   void testUniquePaths();
   void testUniquePathsWithObstacles();

private:
	Solution solution;
   //void test_$exception_func();
};
#endif
