
#include <cppunit/config/SourcePrefix.h>
#include "ReverseWordsTest.h"

// Registers the fixture into the 'registry'
CPPUNIT_TEST_SUITE_REGISTRATION(ReverseWordsTest);


void ReverseWordsTest::setUp()
{
}


void ReverseWordsTest::tearDown()
{
}

void ReverseWordsTest::testReverse()
{
	CPPUNIT_ASSERT_EQUAL(string("blue is sky the"), solution.reverseWords(string("the sky is blue")));
}

