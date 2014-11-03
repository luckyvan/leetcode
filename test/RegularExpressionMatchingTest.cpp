
#include <cppunit/config/SourcePrefix.h>
#include "RegularExpressionMatchingTest.h"

// Registers the fixture into the 'registry'
CPPUNIT_TEST_SUITE_REGISTRATION(RegularExpressionMatchingTest);


void RegularExpressionMatchingTest::setUp()
{
}


void RegularExpressionMatchingTest::tearDown()
{
}

void RegularExpressionMatchingTest::testMatching()
{
	CPPUNIT_ASSERT(!solution.isMatch("aa", "a"));
	CPPUNIT_ASSERT(solution.isMatch("aa", "aa"));
	CPPUNIT_ASSERT(!solution.isMatch("aaa", "aa"));

	CPPUNIT_ASSERT(solution.isMatch("aa", "a."));
	CPPUNIT_ASSERT(solution.isMatch("aa", "a*"));
	CPPUNIT_ASSERT(solution.isMatch("aa", ".*"));
	CPPUNIT_ASSERT(solution.isMatch("ab", ".*"));
	CPPUNIT_ASSERT(solution.isMatch("aab", "c*a*b"));

	CPPUNIT_ASSERT(solution.isMatch(
		"(t = text; *t != \'\\0\' && (*t == c || c == '.'); t++)", "(.*)"));

}

