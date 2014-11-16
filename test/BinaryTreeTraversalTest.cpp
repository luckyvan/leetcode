
#include <cppunit/config/SourcePrefix.h>
#include "BinaryTreeTraversalTest.h"

// Registers the fixture into the 'registry'
CPPUNIT_TEST_SUITE_REGISTRATION(BinaryTreeTraversalTest);


void BinaryTreeTraversalTest::setUp()
{
}


void BinaryTreeTraversalTest::tearDown()
{
}

void BinaryTreeTraversalTest::testPostOrderTraversal()
{
	TreeNode leaf(3);
	TreeNode middle(2);
	TreeNode root(1);
	root.right = &middle;
	middle.left = &leaf;

	CPPUNIT_ASSERT_EQUAL(int(3), solution.postorderTraversal(&root)[0]);
	CPPUNIT_ASSERT_EQUAL(int(2), solution.postorderTraversal(&root)[1]);
	CPPUNIT_ASSERT_EQUAL(int(1), solution.postorderTraversal(&root)[2]);
}

void BinaryTreeTraversalTest::testPreOrderTraversal()
{
	TreeNode leaf(3);
	TreeNode middle(2);
	TreeNode root(1);
	root.right = &middle;
	middle.left = &leaf;

	CPPUNIT_ASSERT_EQUAL(int(1), solution.preorderTraversal(&root)[0]);
	CPPUNIT_ASSERT_EQUAL(int(2), solution.preorderTraversal(&root)[1]);
	CPPUNIT_ASSERT_EQUAL(int(3), solution.preorderTraversal(&root)[2]);
}
