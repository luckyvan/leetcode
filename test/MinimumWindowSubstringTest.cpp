
#include <cppunit/config/SourcePrefix.h>
#include "MinimumWindowSubstringTest.h"

// Registers the fixture into the 'registry'
CPPUNIT_TEST_SUITE_REGISTRATION(MinimumWindowSubstringTest);


void MinimumWindowSubstringTest::setUp()
{
}


void MinimumWindowSubstringTest::tearDown()
{
}

void MinimumWindowSubstringTest::testMinWindow()
{
	CPPUNIT_ASSERT_EQUAL(string("BANC"), solution.minWindow("ADOBECODEBANC", "ABC"));
}

