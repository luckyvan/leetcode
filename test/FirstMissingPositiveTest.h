// FirstMissingPositiveTest.cpp

#ifndef FIRSTMISSINGPOSITIVE_H
#define FIRSTMISSINGPOSITIVE_H

#include <cppunit/extensions/HelperMacros.h>
#include "../src/Solution.h"

class FirstMissingPositiveTest : public CPPUNIT_NS::TestFixture
{
    CPPUNIT_TEST_SUITE( FirstMissingPositiveTest );
    CPPUNIT_TEST(testFirstMissingPositive);
    //CPPUNIT_TEST_EXCEPTION(test_$exception_func, exception);
    CPPUNIT_TEST_SUITE_END();

public: 
   void setUp();
   void tearDown();

   void testFirstMissingPositive();

private:
	Solution solution;
   //void test_$exception_func();
};
#endif
