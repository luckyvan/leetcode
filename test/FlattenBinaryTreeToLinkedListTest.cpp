
#include <cppunit/config/SourcePrefix.h>
#include "FlattenBinaryTreeToLinkedListTest.h"

// Registers the fixture into the 'registry'
CPPUNIT_TEST_SUITE_REGISTRATION(FlattenBinaryTreeToLinkedListTest);


void FlattenBinaryTreeToLinkedListTest::setUp()
{
}


void FlattenBinaryTreeToLinkedListTest::tearDown()
{
}

void FlattenBinaryTreeToLinkedListTest::testFlatten()
{
	TreeNode n1(1), n2(2), n3(3), n4(4), n5(5), n6(6);
	n1.left = &n2; n1.right = &n5;
	n2.left = &n3; n2.right = &n4;
	n5.right = &n6;

	solution.flatten(&n1);

	TreeNode* root = &n1;
	int i = 1;
	while (root != NULL)
	{
		CPPUNIT_ASSERT_EQUAL(i, root->val);
		i++;
		root = root->right;
	}
}

