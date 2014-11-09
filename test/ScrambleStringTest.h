// ScrambleStringTest.cpp

#ifndef STRSTR_H
#define STRSTR_H

#include <cppunit/extensions/HelperMacros.h>
#include "../src/Solution.h"

class ScrambleStringTest : public CPPUNIT_NS::TestFixture
{
    CPPUNIT_TEST_SUITE( ScrambleStringTest );
    CPPUNIT_TEST(testIsScramble);
    //CPPUNIT_TEST_EXCEPTION(test_$exception_func, exception);
    CPPUNIT_TEST_SUITE_END();

public: 
   void setUp();
   void tearDown();

   void testIsScramble();

private:
	Solution solution;
   //void test_$exception_func();
};
#endif
