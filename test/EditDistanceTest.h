// EditDistanceTest.cpp

#ifndef EDITDISTANCE_H
#define EDITDISTANCE_H

#include <cppunit/extensions/HelperMacros.h>
#include "../src/Solution.h"

class EditDistanceTest : public CPPUNIT_NS::TestFixture
{
    CPPUNIT_TEST_SUITE( EditDistanceTest );
    CPPUNIT_TEST(testEditDistance);
    //CPPUNIT_TEST_EXCEPTION(test_$exception_func, exception);
    CPPUNIT_TEST_SUITE_END();

public: 
   void setUp();
   void tearDown();

   void testEditDistance();

private:
	Solution solution;
   //void test_$exception_func();
};
#endif
