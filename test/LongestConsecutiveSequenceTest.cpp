
#include <cppunit/config/SourcePrefix.h>
#include "LongestConsecutiveSequenceTest.h"

// Registers the fixture into the 'registry'
CPPUNIT_TEST_SUITE_REGISTRATION(LongestConsecutiveSequenceTest);


void LongestConsecutiveSequenceTest::setUp()
{
}


void LongestConsecutiveSequenceTest::tearDown()
{
}

void LongestConsecutiveSequenceTest::testLongestConsecutive()
{
	vector<int> numbers = { 100, 4, 200, 3, 1, 2 };

	CPPUNIT_ASSERT_EQUAL(int(4), solution.longestConsecutive(numbers));
}

