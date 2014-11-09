
#include <cppunit/config/SourcePrefix.h>
#include "ScrambleStringTest.h"

// Registers the fixture into the 'registry'
CPPUNIT_TEST_SUITE_REGISTRATION(ScrambleStringTest);


void ScrambleStringTest::setUp()
{
}


void ScrambleStringTest::tearDown()
{
}

void ScrambleStringTest::testIsScramble()
{
	CPPUNIT_ASSERT(solution.isScramble("great", "rgtae"));
	CPPUNIT_ASSERT(!solution.isScramble("great", "egart"));
}

