// SubsetTest.cpp

#ifndef SUBSET_H
#define SUBSET_H

#include <cppunit/extensions/HelperMacros.h>
#include "../src/Solution.h"

class SubsetTest : public CPPUNIT_NS::TestFixture
{
    CPPUNIT_TEST_SUITE( SubsetTest );
    CPPUNIT_TEST(testSubsets);
    //CPPUNIT_TEST_EXCEPTION(test_$exception_func, exception);
    CPPUNIT_TEST_SUITE_END();

public: 
   void setUp();
   void tearDown();

   void testSubsets();

private:
	Solution solution;
   //void test_$exception_func();
};
#endif
