
#include <cppunit/config/SourcePrefix.h>
#include "FindMinimumInRotatedSortedArrayTest.h"

// Registers the fixture into the 'registry'
CPPUNIT_TEST_SUITE_REGISTRATION(FindMinimumInRotatedSortedArrayTest);


void FindMinimumInRotatedSortedArrayTest::setUp()
{
}


void FindMinimumInRotatedSortedArrayTest::tearDown()
{
}

void FindMinimumInRotatedSortedArrayTest::testFindMin()
{
	int a[] = {4, 5, 6, 7, 0, 1, 2};
	vector<int> array(a, a+7);
	CPPUNIT_ASSERT_EQUAL(int(0), solution.findMin(array));
}

void FindMinimumInRotatedSortedArrayTest::testFindMinWithDuplication()
{
	int a[] = { 3, 3, 3, 1, 3};
	vector<int> array(a, a + 5);
	CPPUNIT_ASSERT_EQUAL(int(1), solution.findMinWithDuplication(array));
}
