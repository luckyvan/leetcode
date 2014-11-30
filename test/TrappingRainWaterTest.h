// TrappingRainWaterTest.cpp

#ifndef TRAPPINGRAINWATER_H
#define TRAPPINGRAINWATER_H

#include <cppunit/extensions/HelperMacros.h>
#include "../src/Solution.h"

class TrappingRainWaterTest : public CPPUNIT_NS::TestFixture
{
    CPPUNIT_TEST_SUITE( TrappingRainWaterTest );
    CPPUNIT_TEST(testTrap);
    //CPPUNIT_TEST_EXCEPTION(test_$exception_func, exception);
    CPPUNIT_TEST_SUITE_END();

public: 
   void setUp();
   void tearDown();

   void testTrap();

private:
	Solution solution;
   //void test_$exception_func();
};
#endif
