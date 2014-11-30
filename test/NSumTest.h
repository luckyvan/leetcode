// NSumTest.cpp

#ifndef NSUM_H
#define NSUM_H

#include <cppunit/extensions/HelperMacros.h>
#include "../src/Solution.h"

class NSumTest : public CPPUNIT_NS::TestFixture
{
    CPPUNIT_TEST_SUITE( NSumTest );
    CPPUNIT_TEST(testThreeSum);
	CPPUNIT_TEST(testFourSum);

    //CPPUNIT_TEST_EXCEPTION(test_$exception_func, exception);
    CPPUNIT_TEST_SUITE_END();

public: 
   void setUp();
   void tearDown();

   void testThreeSum();
   void testFourSum();

private:
	Solution solution;
   //void test_$exception_func();
};
#endif
