
#include <cppunit/config/SourcePrefix.h>
#include <stdlib.h>
#include <limits.h>
#include "ValidParenthesesTest.h"

// Registers the fixture into the 'registry'
CPPUNIT_TEST_SUITE_REGISTRATION(ValidParenthesesTest);


void ValidParenthesesTest::setUp()
{
}


void ValidParenthesesTest::tearDown()
{
}

void ValidParenthesesTest::testNormalCase()
{
	CPPUNIT_ASSERT(solution.isValid(string("()")));
	CPPUNIT_ASSERT(solution.isValid(string("()[]{}")));
	CPPUNIT_ASSERT(solution.isValid(string("([{}])")));

	CPPUNIT_ASSERT(!solution.isValid(string("({[}])")));
	CPPUNIT_ASSERT(!solution.isValid(string("(]")));
}


