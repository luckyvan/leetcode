
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


void BinaryTreeTraversalTest::testInOrderTraversal()
{
	TreeNode leaf(3);
	TreeNode middle(2);
	TreeNode root(1);
	root.right = &middle;
	middle.left = &leaf;

	CPPUNIT_ASSERT_EQUAL(int(1), solution.inorderTraversal(&root)[0]);
	CPPUNIT_ASSERT_EQUAL(int(3), solution.inorderTraversal(&root)[1]);
	CPPUNIT_ASSERT_EQUAL(int(2), solution.inorderTraversal(&root)[2]);
}

void BinaryTreeTraversalTest::testTreeCompare()
{
	TreeNode leaf(3);
	TreeNode middle(2);
	TreeNode root1(1), root2(1);
	root1.right = &middle;
	middle.left = &leaf;
	root2.left = &middle;
	CPPUNIT_ASSERT(!solution.compareTree(&root1, &root2));
	CPPUNIT_ASSERT(solution.compareTree(&root2, &root2));
	CPPUNIT_ASSERT(solution.compareTree(&root1, &root1));

}

void BinaryTreeTraversalTest::testBuildTree()
{
	TreeNode root('F');
	TreeNode l11('B');
	TreeNode l12('G');
	TreeNode l21('A'), l22('D'), l24('I');
	TreeNode l33('C'), l34('E'), l35('H');
	
	root.left = &l11; root.right = &l12;
	l11.left = &l21; l11.right = &l22; l12.right = &l24;
	l22.left = &l33; l22.right = &l34; l24.left = &l35;
	int in_order[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I' };
	int pre_order[] = { 'F', 'B', 'A', 'D', 'C', 'E', 'G', 'I', 'H' };
	int post_order[] = { 'A', 'C', 'E', 'D', 'B', 'H', 'I', 'G', 'F' };
	vector<int> in(in_order, in_order + 9);
	vector<int> pre(pre_order, pre_order + 9);
	vector<int> post(post_order, post_order + 9);

	CPPUNIT_ASSERT(solution.compareTree(&root, solution.buildTreePI(pre, in)));
	CPPUNIT_ASSERT(solution.compareTree(&root, solution.buildTreeIP(in, post)));
}