
#include <cppunit/config/SourcePrefix.h>
#include "EditDistanceTest.h"

// Registers the fixture into the 'registry'
CPPUNIT_TEST_SUITE_REGISTRATION(EditDistanceTest);


void EditDistanceTest::setUp()
{
}


void EditDistanceTest::tearDown()
{
}

void EditDistanceTest::testEditDistance()
{
	CPPUNIT_ASSERT_EQUAL(int(2), solution.minDistance("abb", "abccb"));
}

