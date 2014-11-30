
#include <cppunit/config/SourcePrefix.h>
#include "TrappingRainWaterTest.h"

// Registers the fixture into the 'registry'
CPPUNIT_TEST_SUITE_REGISTRATION(TrappingRainWaterTest);


void TrappingRainWaterTest::setUp()
{
}


void TrappingRainWaterTest::tearDown()
{
}

void TrappingRainWaterTest::testTrap()
{
	int a[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
	CPPUNIT_ASSERT_EQUAL(int(6), solution.trap(a, sizeof(a)/sizeof(int)));
}

