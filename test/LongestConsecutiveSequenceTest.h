// LongestConsecutiveSequenceTest.cpp

#ifndef LONGESTCONSECUTIVESEQUENCE_H
#define LONGESTCONSECUTIVESEQUENCE_H

#include <cppunit/extensions/HelperMacros.h>
#include "../src/Solution.h"

class LongestConsecutiveSequenceTest : public CPPUNIT_NS::TestFixture
{
    CPPUNIT_TEST_SUITE( LongestConsecutiveSequenceTest );
    CPPUNIT_TEST(testLongestConsecutive);
    //CPPUNIT_TEST_EXCEPTION(test_$exception_func, exception);
    CPPUNIT_TEST_SUITE_END();

public: 
   void setUp();
   void tearDown();

   void testLongestConsecutive();

private:
	Solution solution;
   //void test_$exception_func();
};
#endif
