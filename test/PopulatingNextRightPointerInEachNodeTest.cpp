
#include <cppunit/config/SourcePrefix.h>
#include "PopulatingNextRightPointerInEachNodeTest.h"

// Registers the fixture into the 'registry'
CPPUNIT_TEST_SUITE_REGISTRATION(PopulatingNextRightPointerInEachNodeTest);


void PopulatingNextRightPointerInEachNodeTest::setUp()
{
}


void PopulatingNextRightPointerInEachNodeTest::tearDown()
{
}

void PopulatingNextRightPointerInEachNodeTest::testPopulating()
{
	TreeLinkNode n1(1), n2(2), n3(3), n4(4), n5(5), n7(7);
	n1.left = &n2; n1.right = &n3;
	n2.left = &n4; n2.right = &n5;
	n3.right = &n7;

	solution.connect(&n1);

	CPPUNIT_ASSERT(n1.next == NULL);
	CPPUNIT_ASSERT_EQUAL(int(2), n1.left->val);
	CPPUNIT_ASSERT_EQUAL(int(3), n1.left->next->val);
	CPPUNIT_ASSERT_EQUAL(int(4), n1.left->left->val);
	CPPUNIT_ASSERT_EQUAL(int(5), n1.left->left->next->val);
	CPPUNIT_ASSERT_EQUAL(int(7), n1.left->left->next->next->val);
}

