
#include <cppunit/config/SourcePrefix.h>
#include "RecoverBinarySearchTreeTest.h"

// Registers the fixture into the 'registry'
CPPUNIT_TEST_SUITE_REGISTRATION(RecoverBinarySearchTreeTest);


void RecoverBinarySearchTreeTest::setUp()
{
}


void RecoverBinarySearchTreeTest::tearDown()
{
}

void RecoverBinarySearchTreeTest::testRecoverTree()
{
	TreeNode n1(1), n2(2), n3(3), n4(4), n5(5), n6(6);
	TreeNode n11(1), n21(2), n31(3), n41(4), n51(5), n61(6);

	//BST
	n4.left = &n2;
	n2.left = &n1;
	n2.right = &n3;
	n4.right = &n5;
	n5.right = &n6;

	//wrong BST1, n2, n3 swap
	n41.left = &n31;
	n31.left = &n11;
	n31.right = &n21;
	n41.right = &n51;
	n51.right = &n61;

	CPPUNIT_ASSERT(!solution.compareTree(&n4, &n41));
	solution.recoverTree(&n41);
	CPPUNIT_ASSERT(solution.compareTree(&n4, &n41));

	//swap n3 and n6 val
	int val = n31.val;
	n31.val = n61.val;
	n61.val = val;
	CPPUNIT_ASSERT(!solution.compareTree(&n4, &n41));
	solution.recoverTree(&n41);
	CPPUNIT_ASSERT(solution.compareTree(&n4, &n41));

}

