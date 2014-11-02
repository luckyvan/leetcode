
#include <cppunit/config/SourcePrefix.h>
#include "StrStrTest.h"

// Registers the fixture into the 'registry'
CPPUNIT_TEST_SUITE_REGISTRATION(StrStrTest);


void StrStrTest::setUp()
{
}


void StrStrTest::tearDown()
{
}

void StrStrTest::testKmp()
{
	char* haystack = "aabaabaaa";
	char* needle = "aabaaa";
	vector<int> prefix_function = solution.computePrefixFunction(needle);
	int prefix_a[] = {0, 1, 0, 1, 2, 2};
	for (size_t i = 0; i < prefix_function.size(); i++)
	{
		CPPUNIT_ASSERT_EQUAL(prefix_a[i], prefix_function[i]);
	}

	char* pos = solution.strStr_kmp(haystack, needle);
	int offset = pos - haystack;
	CPPUNIT_ASSERT_EQUAL(int(3), offset);

	haystack = "bacbababacacbab";
	needle = "ababaca";
	pos = solution.strStr_kmp(haystack, needle);
	offset = pos - haystack;
	CPPUNIT_ASSERT_EQUAL(int(4), offset);
}

