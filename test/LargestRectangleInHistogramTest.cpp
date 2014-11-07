
#include <cppunit/config/SourcePrefix.h>
#include "LargestRectangleInHistogramTest.h"

// Registers the fixture into the 'registry'
CPPUNIT_TEST_SUITE_REGISTRATION(LargestRectangleInHistogramTest);


void LargestRectangleInHistogramTest::setUp()
{
}


void LargestRectangleInHistogramTest::tearDown()
{
}

void LargestRectangleInHistogramTest::testLargestRectangleInHistogram()
{
	CPPUNIT_ASSERT_EQUAL(int(4),
		solution.largestRectangleInHistogram(vector<int>(
	{ 2, 1, 3, 1 }
	)));
	CPPUNIT_ASSERT_EQUAL(int(6),
		solution.largestRectangleInHistogram(vector<int>(
	{ 4, 2, 0, 3, 2, 5 }
	)));
	CPPUNIT_ASSERT_EQUAL(int(10),
		solution.largestRectangleInHistogram(vector<int>(
	{ 2, 1, 5, 6, 2, 3 }
	)));
}

