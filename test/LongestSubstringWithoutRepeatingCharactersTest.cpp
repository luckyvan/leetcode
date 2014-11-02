
#include <cppunit/config/SourcePrefix.h>
#include "LongestSubstringWithoutRepeatingCharactersTest.h"

// Registers the fixture into the 'registry'
CPPUNIT_TEST_SUITE_REGISTRATION(LongestSubstringWithoutRepeatingCharactersTest);


void LongestSubstringWithoutRepeatingCharactersTest::setUp()
{
}


void LongestSubstringWithoutRepeatingCharactersTest::tearDown()
{
}

void LongestSubstringWithoutRepeatingCharactersTest::testInterleavingSubstring()
{
	string interleave = "abcdccbb";
	CPPUNIT_ASSERT_EQUAL(int(4), solution.longestSubstringWithoutRepeatingCharacters(interleave));


}

