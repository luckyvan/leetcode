// InsertIntervalTest.cpp

#ifndef INSERTINTERVAL_H
#define INSERTINTERVAL_H

#include <cppunit/extensions/HelperMacros.h>
#include "../src/Solution.h"

class InsertIntervalTest : public CPPUNIT_NS::TestFixture
{
    CPPUNIT_TEST_SUITE( InsertIntervalTest );
    CPPUNIT_TEST(testInsertInterval);
    //CPPUNIT_TEST_EXCEPTION(test_$exception_func, exception);
    CPPUNIT_TEST_SUITE_END();

public: 
   void setUp();
   void tearDown();

   void testInsertInterval();

private:
	Solution solution;
   //void test_$exception_func();
};
#endif
