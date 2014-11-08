// BestTimeToBuyAndSellStockTest.cpp

#ifndef BESTTIMETOBUYANDSELLSTOCK_H
#define BESTTIMETOBUYANDSELLSTOCK_H

#include <cppunit/extensions/HelperMacros.h>
#include "../src/Solution.h"

class BestTimeToBuyAndSellStockTest : public CPPUNIT_NS::TestFixture
{
    CPPUNIT_TEST_SUITE( BestTimeToBuyAndSellStockTest );
    CPPUNIT_TEST(testMaxProfit);
    //CPPUNIT_TEST_EXCEPTION(test_$exception_func, exception);
    CPPUNIT_TEST_SUITE_END();

public: 
   void setUp();
   void tearDown();

   void testMaxProfit();

private:
	Solution solution;
   //void test_$exception_func();
};
#endif
