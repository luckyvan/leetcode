
#include <cppunit/config/SourcePrefix.h>
#include "InterleavingStringTest.h"

// Registers the fixture into the 'registry'
CPPUNIT_TEST_SUITE_REGISTRATION(InterleavingStringTest);


void InterleavingStringTest::setUp()
{
}


void InterleavingStringTest::tearDown()
{
}

void InterleavingStringTest::testInterleaving()
{
	CPPUNIT_ASSERT(solution.isInterleave(string("aabcc"), string("dbbca"), string("aadbbcbcac")));
	CPPUNIT_ASSERT(!solution.isInterleave(string("aabcc"), string("dbbca"), string("aadbbbaccc")));
}

