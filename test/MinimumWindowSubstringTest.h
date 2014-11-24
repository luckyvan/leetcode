// MinimumWindowSubstringTest.cpp

#ifndef MINIMUMWINDOWSUBSTRING_H
#define MINIMUMWINDOWSUBSTRING_H

#include <cppunit/extensions/HelperMacros.h>
#include "../src/Solution.h"

class MinimumWindowSubstringTest : public CPPUNIT_NS::TestFixture
{
    CPPUNIT_TEST_SUITE( MinimumWindowSubstringTest );
    CPPUNIT_TEST(testMinWindow);
    //CPPUNIT_TEST_EXCEPTION(test_$exception_func, exception);
    CPPUNIT_TEST_SUITE_END();

public: 
   void setUp();
   void tearDown();

   void testMinWindow();

private:
	Solution solution;
   //void test_$exception_func();
};
#endif
