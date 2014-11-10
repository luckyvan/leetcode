// InterleavingStringTest.cpp

#ifndef INTERLEAVING_H
#define INTERLEAVING_H

#include <cppunit/extensions/HelperMacros.h>
#include "../src/Solution.h"

class InterleavingStringTest : public CPPUNIT_NS::TestFixture
{
    CPPUNIT_TEST_SUITE( InterleavingStringTest );
    CPPUNIT_TEST(testInterleaving);
    //CPPUNIT_TEST_EXCEPTION(test_$exception_func, exception);
    CPPUNIT_TEST_SUITE_END();

public: 
   void setUp();
   void tearDown();

   void testInterleaving();

private:
	Solution solution;
   //void test_$exception_func();
};
#endif
