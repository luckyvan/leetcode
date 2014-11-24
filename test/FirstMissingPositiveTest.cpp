
#include <cppunit/config/SourcePrefix.h>
#include "FirstMissingPositiveTest.h"

// Registers the fixture into the 'registry'
CPPUNIT_TEST_SUITE_REGISTRATION(FirstMissingPositiveTest);


void FirstMissingPositiveTest::setUp()
{
}


void FirstMissingPositiveTest::tearDown()
{
}

void FirstMissingPositiveTest::testFirstMissingPositive()
{
	int a1[] = { 1, 2, 0 };
	int a2[] = { 3, 4, -1, 1 };
	CPPUNIT_ASSERT_EQUAL(int(3), solution.firstMissingPositive(a1, 3));
	CPPUNIT_ASSERT_EQUAL(int(2), solution.firstMissingPositive(a2, 4));
}

