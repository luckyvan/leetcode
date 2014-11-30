
#include <cppunit/config/SourcePrefix.h>
#include "NSumTest.h"

// Registers the fixture into the 'registry'
CPPUNIT_TEST_SUITE_REGISTRATION(NSumTest);


void NSumTest::setUp()
{
}


void NSumTest::tearDown()
{
}

void NSumTest::testThreeSum()
{
	vector<int> numbers = { -1, 0, 1, 2, -1, -4 };
	CPPUNIT_ASSERT_EQUAL(size_t(2), solution.threeSum(numbers).size());
}

void NSumTest::testFourSum()
{
	vector<int> numbers = { 1, 0, -1, 0, -2, 2 };
	CPPUNIT_ASSERT_EQUAL(size_t(3), solution.fourSum(numbers, 0).size());
}