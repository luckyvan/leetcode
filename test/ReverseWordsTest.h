// ReverseWordsTest.cpp

#ifndef REVERSEWORDS_H
#define REVERSEWORDS_H

#include <cppunit/extensions/HelperMacros.h>
#include "../src/Solution.h"

class ReverseWordsTest : public CPPUNIT_NS::TestFixture
{
    CPPUNIT_TEST_SUITE( ReverseWordsTest );
    CPPUNIT_TEST(testReverse);
    //CPPUNIT_TEST_EXCEPTION(test_$exception_func, exception);
    CPPUNIT_TEST_SUITE_END();

public: 
   void setUp();
   void tearDown();

   void testReverse();

private:
	Solution solution;
   //void test_$exception_func();
};
#endif
