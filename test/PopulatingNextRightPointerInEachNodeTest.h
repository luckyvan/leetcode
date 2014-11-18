// PopulatingNextRightPointerInEachNodeTest.cpp

#ifndef POPULATINGNEXTRIGHTPOINTERINEACHNODE_H
#define POPULATINGNEXTRIGHTPOINTERINEACHNODE_H


#include <cppunit/extensions/HelperMacros.h>
#include "../src/Solution.h"

class PopulatingNextRightPointerInEachNodeTest : public CPPUNIT_NS::TestFixture
{
    CPPUNIT_TEST_SUITE( PopulatingNextRightPointerInEachNodeTest );
	CPPUNIT_TEST(testPopulating);
    //CPPUNIT_TEST_EXCEPTION(test_$exception_func, exception);
    CPPUNIT_TEST_SUITE_END();

public: 
   void setUp();
   void tearDown();

   void testPopulating();

private:
	Solution solution;
   //void test_$exception_func();
};
#endif
