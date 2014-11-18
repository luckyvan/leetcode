// FlattenBinaryTreeToLinkedListTest.cpp

#ifndef FLATTENBINARYTREETOLINKEDLIST_H
#define FLATTENBINARYTREETOLINKEDLIST_H

#include <cppunit/extensions/HelperMacros.h>
#include "../src/Solution.h"

class FlattenBinaryTreeToLinkedListTest : public CPPUNIT_NS::TestFixture
{
    CPPUNIT_TEST_SUITE( FlattenBinaryTreeToLinkedListTest );
    CPPUNIT_TEST(testFlatten);
    //CPPUNIT_TEST_EXCEPTION(test_$exception_func, exception);
    CPPUNIT_TEST_SUITE_END();

public: 
   void setUp();
   void tearDown();

   void testFlatten();

private:
	Solution solution;
   //void test_$exception_func();
};
#endif
