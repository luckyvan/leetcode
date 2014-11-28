
#include <cppunit/config/SourcePrefix.h>
#include "SubsetTest.h"

// Registers the fixture into the 'registry'
CPPUNIT_TEST_SUITE_REGISTRATION(SubsetTest);


void SubsetTest::setUp()
{
}


void SubsetTest::tearDown()
{
}

void SubsetTest::testSubsets()
{
	vector<int> s = {1, 2, 3};
	vector<vector<int> > subsets = solution.subsets(s);

	CPPUNIT_ASSERT_EQUAL(size_t(8), subsets.size());

	vector<int> s_d = { 1, 2, 2 };
	vector<vector<int> > subsets_d = solution.subsets_ii(s_d);

	CPPUNIT_ASSERT_EQUAL(size_t(6), subsets_d.size());

}

