
#include <cppunit/config/SourcePrefix.h>
#include "UniquePathsTest.h"

// Registers the fixture into the 'registry'
CPPUNIT_TEST_SUITE_REGISTRATION(UniquePathsTest);


void UniquePathsTest::setUp()
{
}


void UniquePathsTest::tearDown()
{
}

void UniquePathsTest::testUniquePaths()
{
	CPPUNIT_ASSERT_EQUAL(int(2), solution.uniquePaths(2, 2));
	CPPUNIT_ASSERT_EQUAL(int(3), solution.uniquePaths(2, 3));
	CPPUNIT_ASSERT_EQUAL(int(3), solution.uniquePaths(3, 2));
	CPPUNIT_ASSERT_EQUAL(int(28), solution.uniquePaths(3, 7));

}

