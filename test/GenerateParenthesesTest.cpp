
#include <cppunit/config/SourcePrefix.h>
#include "GenerateParenthesesTest.h"

// Registers the fixture into the 'registry'
CPPUNIT_TEST_SUITE_REGISTRATION(GenerateParenthesesTest);


void GenerateParenthesesTest::setUp()
{
}


void GenerateParenthesesTest::tearDown()
{
}

void GenerateParenthesesTest::testGeneration()
{
	string a[] = { string("()()"), string("(())") };
	vector<string> p2 = solution.generateParentheses(2);
	for (size_t i = 0; i < p2.size(); i++)
	{
		CPPUNIT_ASSERT_EQUAL(a[i], p2[i]);
	}
	string a1[] = {
		string("()()()"), string("()(())"),
		string("(())()"),
		string("(()())"), string("((()))"),
	};
	vector<string> p3 = solution.generateParentheses(3);
	for (size_t i = 0; i < p3.size(); i++)
	{
		CPPUNIT_ASSERT_EQUAL(a1[i], p3[i]);
	}
}

