
#include <cppunit/config/SourcePrefix.h>
#include "DistinctSubsequencesTest.h"

// Registers the fixture into the 'registry'
CPPUNIT_TEST_SUITE_REGISTRATION(DistinctSubsequencesTest);


void DistinctSubsequencesTest::setUp()
{
}


void DistinctSubsequencesTest::tearDown()
{
}

void DistinctSubsequencesTest::testDistinctSubsequences()
{
	CPPUNIT_ASSERT_EQUAL(int(3),solution.distinctSubsequences("rabbbit", "rabbit"));
}

