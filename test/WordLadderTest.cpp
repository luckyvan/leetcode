
#include <cppunit/config/SourcePrefix.h>
#include "WordLadderTest.h"

// Registers the fixture into the 'registry'
CPPUNIT_TEST_SUITE_REGISTRATION(WordLadderTest);


void WordLadderTest::setUp()
{
}


void WordLadderTest::tearDown()
{
}

void WordLadderTest::testLadderLength()
{
	string start = "hit";
	string end = "cog";
	string dict_a[] = { "hot", "dot", "dog", "lot", "log"
	};
	unordered_set<string> dict(dict_a, dict_a+5);

	CPPUNIT_ASSERT_EQUAL(int(5), solution.ladderLength(start, end, dict));
}

void WordLadderTest::testFindLadders()
{
	string start = "hit";
	string end = "cog";
	string dict_a[] = { "hot", "dot", "dog", "lot", "log"
	};
	unordered_set<string> dict(dict_a, dict_a + 5);

	solution.findLadders(start, end, dict);
}