// BinaryTreePostOrderTraversalTest.cpp

#ifndef STRSTR_H
#define STRSTR_H

#include <cppunit/extensions/HelperMacros.h>
#include "../src/Solution.h"

class BinaryTreeTraversalTest : public CPPUNIT_NS::TestFixture
{
    CPPUNIT_TEST_SUITE( BinaryTreeTraversalTest );
    CPPUNIT_TEST(testPostOrderTraversal);
	CPPUNIT_TEST(testPreOrderTraversal);
	CPPUNIT_TEST(testInOrderTraversal);
	CPPUNIT_TEST(testTreeCompare);
	CPPUNIT_TEST(testBuildTree);
	//CPPUNIT_TEST_EXCEPTION(test_$exception_func, exception);
    CPPUNIT_TEST_SUITE_END();

public: 
   void setUp();
   void tearDown();

   void testPostOrderTraversal();
   void testPreOrderTraversal();
   void testInOrderTraversal();
   void testTreeCompare();
   void testBuildTree();

private:
	Solution solution;
   //void test_$exception_func();
};
#endif
