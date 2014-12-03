
#include <cppunit/config/SourcePrefix.h>
#include "MaxPointsOnALineTest.h"

// Registers the fixture into the 'registry'
CPPUNIT_TEST_SUITE_REGISTRATION(MaxPointsOnALineTest);


void MaxPointsOnALineTest::setUp()
{
}


void MaxPointsOnALineTest::tearDown()
{
}

void MaxPointsOnALineTest::testMaxPoints()
{
	vector<Point> points = {
		Point(0, 0), Point(0, 1), Point(0, 2),
		Point(1, 0), Point(1, 1), Point(1, 2),
		Point(2, 0), Point(2, 1), Point(2, 2),
		Point(3, 3),
	};
	CPPUNIT_ASSERT_EQUAL(int(4), solution.maxPoints(points));
}

