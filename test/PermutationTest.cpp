
#include <cppunit/config/SourcePrefix.h>
#include "PermutationTest.h"

// Registers the fixture into the 'registry'
CPPUNIT_TEST_SUITE_REGISTRATION(PermutationTest);


void PermutationTest::setUp()
{
}


void PermutationTest::tearDown()
{
}

void PermutationTest::testPermutations()
{
	vector<int> s = {1, 2, 3};
	vector<vector<int> > permutations = solution.permute(s);

	CPPUNIT_ASSERT_EQUAL(size_t(6), permutations.size());

	vector<int> s_d = { 1, 2, 2 };
	vector<vector<int> > permutations_uniq = solution.permuteUnique(s_d);

	CPPUNIT_ASSERT_EQUAL(size_t(3), permutations_uniq.size());

	vector<int> s_d1 = { 1, 2, 2, 3, 3 }; //C(1,1)*C(3,2)*C(5,2)
	vector<vector<int> > permutations_uniq1 = solution.permuteUnique(s_d1);

	CPPUNIT_ASSERT_EQUAL(size_t(30), permutations_uniq1.size());

}

