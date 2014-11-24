
#include <cppunit/config/SourcePrefix.h>
#include "InsertIntervalTest.h"

// Registers the fixture into the 'registry'
CPPUNIT_TEST_SUITE_REGISTRATION(InsertIntervalTest);


void InsertIntervalTest::setUp()
{
}


void InsertIntervalTest::tearDown()
{
}

void InsertIntervalTest::testInsertInterval()
{
/*	*Example 1:
	*Given intervals[1, 3], [6, 9], insert and merge[2, 5] in as[1, 5], [6, 9].
		*
		* Example 2 :
		*Given[1, 2], [3, 5], [6, 7], [8, 10], [12, 16], insert and merge[4, 9] in as[1, 2], [3, 10], [12, 16].
		*/
	vector<Interval> intervals = {Interval(1, 3), Interval(6, 9)};
	
	vector<Interval> intervals_m = solution.insert(intervals, Interval(2, 5));
	CPPUNIT_ASSERT_EQUAL(Interval(1, 5), intervals_m[0]);
	CPPUNIT_ASSERT_EQUAL(Interval(6, 9), intervals_m[1]);

	vector<Interval> intervals1 = { 
		Interval(1, 2), Interval(3, 5), Interval(6,7),
		Interval(8, 10), Interval(12, 16)
	};
	vector<Interval> intervals1_m = solution.insert(intervals1, Interval(4, 9));
	CPPUNIT_ASSERT_EQUAL(Interval(1, 2), intervals1_m[0]);
	CPPUNIT_ASSERT_EQUAL(Interval(3, 10), intervals1_m[1]);
	CPPUNIT_ASSERT_EQUAL(Interval(12, 16), intervals1_m[2]);

}

