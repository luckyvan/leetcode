
#include <cppunit/config/SourcePrefix.h>
#include "MaximumSubarrayTest.h"

// Registers the fixture into the 'registry'
CPPUNIT_TEST_SUITE_REGISTRATION(MaximumSubarrayTest);


void MaximumSubarrayTest::setUp()
{
}


void MaximumSubarrayTest::tearDown()
{
}

void MaximumSubarrayTest::testMaximumSubarray()
{
	int a[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
	CPPUNIT_ASSERT_EQUAL(
		int(6), 
		solution.maximumSubarray(a, sizeof(a)/sizeof(int))
		);
}

