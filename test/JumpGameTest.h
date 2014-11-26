// JumpGameTest.cpp

#ifndef JUMPGAME_H
#define JUMPGAME_H

#include <cppunit/extensions/HelperMacros.h>
#include "../src/Solution.h"

class JumpGameTest : public CPPUNIT_NS::TestFixture
{
    CPPUNIT_TEST_SUITE( JumpGameTest );
    CPPUNIT_TEST(testCanJump);
	CPPUNIT_TEST(testJump);

	//CPPUNIT_TEST_EXCEPTION(test_$exception_func, exception);
    CPPUNIT_TEST_SUITE_END();

public: 
   void setUp();
   void tearDown();

   void testCanJump();
   void testJump();

private:
	Solution solution;
   //void test_$exception_func();
};
#endif
