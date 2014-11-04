
#include <cppunit/config/SourcePrefix.h>
#include "LongestValidParenthesesTest.h"

// Registers the fixture into the 'registry'
CPPUNIT_TEST_SUITE_REGISTRATION(LongestValidParenthesesTest);


void LongestValidParenthesesTest::setUp()
{
}


void LongestValidParenthesesTest::tearDown()
{
}

void LongestValidParenthesesTest::testValidParentheses()
{
	CPPUNIT_ASSERT_EQUAL(int(2), solution.longestValidParentheses("(()"));
	CPPUNIT_ASSERT_EQUAL(int(4), solution.longestValidParentheses("(()()"));
	CPPUNIT_ASSERT_EQUAL(int(6), solution.longestValidParentheses("((())))))()()"));
}

