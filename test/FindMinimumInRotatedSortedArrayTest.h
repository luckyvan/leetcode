// FindMinimumInRotatedSortedArrayTest.cpp

#ifndef FINDMINIMUMINROTATEDSORTEDARRAY_H
#define FINDMINIMUMINROTATEDSORTEDARRAY_H

#include <cppunit/extensions/HelperMacros.h>
#include "../src/Solution.h"

class FindMinimumInRotatedSortedArrayTest : public CPPUNIT_NS::TestFixture
{
    CPPUNIT_TEST_SUITE( FindMinimumInRotatedSortedArrayTest );
    CPPUNIT_TEST(testFindMin);
	CPPUNIT_TEST(testFindMinWithDuplication);

    //CPPUNIT_TEST_EXCEPTION(test_$exception_func, exception);
    CPPUNIT_TEST_SUITE_END();

public: 
   void setUp();
   void tearDown();

   void testFindMin();
   void testFindMinWithDuplication();

private:
	Solution solution;
   //void test_$exception_func();
};
#endif
