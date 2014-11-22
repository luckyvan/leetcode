// WordLadderTest.cpp

#ifndef WORDLADDER_H
#define WORDLADDER_H

#include <cppunit/extensions/HelperMacros.h>
#include "../src/Solution.h"

class WordLadderTest : public CPPUNIT_NS::TestFixture
{
    CPPUNIT_TEST_SUITE( WordLadderTest );
    CPPUNIT_TEST(testLadderLength);
	CPPUNIT_TEST(testFindLadders);
    //CPPUNIT_TEST_EXCEPTION(test_$exception_func, exception);
    CPPUNIT_TEST_SUITE_END();

public: 
   void setUp();
   void tearDown();

   void testLadderLength();
   void testFindLadders();

private:
	Solution solution;
   //void test_$exception_func();
};
#endif
