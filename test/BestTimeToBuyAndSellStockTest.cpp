
#include <cppunit/config/SourcePrefix.h>
#include "BestTimeToBuyAndSellStockTest.h"

// Registers the fixture into the 'registry'
CPPUNIT_TEST_SUITE_REGISTRATION(BestTimeToBuyAndSellStockTest);


void BestTimeToBuyAndSellStockTest::setUp()
{
}


void BestTimeToBuyAndSellStockTest::tearDown()
{
}

void BestTimeToBuyAndSellStockTest::testMaxProfit()
{
	int prices[] = { 2, 2, 5, 4, 1, 5 };
	CPPUNIT_ASSERT_EQUAL(
		int(4),
		solution.maxProfit(vector<int>(prices, prices + 6))
		);

	CPPUNIT_ASSERT_EQUAL(
		int(7),
		solution.maxProfitWithMultipleTransactions(vector<int>(prices, prices + 6))
		);

	CPPUNIT_ASSERT_EQUAL(
		int(7),
		solution.maxProfitWithTwoTransactions(vector<int>(prices, prices + 6))
		);
}

