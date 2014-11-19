// RecoverBinarySearchTreeTest.cpp

#ifndef RECOVERBINARYSEARCHTREE_H
#define RECOVERBINARYSEARCHTREE_H

#include <cppunit/extensions/HelperMacros.h>
#include "../src/Solution.h"

class RecoverBinarySearchTreeTest : public CPPUNIT_NS::TestFixture
{
    CPPUNIT_TEST_SUITE( RecoverBinarySearchTreeTest );
    CPPUNIT_TEST(testRecoverTree);
    //CPPUNIT_TEST_EXCEPTION(test_$exception_func, exception);
    CPPUNIT_TEST_SUITE_END();

public: 
   void setUp();
   void tearDown();

   void testRecoverTree();

private:
	Solution solution;
   //void test_$exception_func();
};
#endif
