// PermutationTest.cpp

#ifndef PERMUTATION_H
#define PERMUTATION_H

#include <cppunit/extensions/HelperMacros.h>
#include "../src/Solution.h"

class PermutationTest : public CPPUNIT_NS::TestFixture
{
    CPPUNIT_TEST_SUITE( PermutationTest );
    CPPUNIT_TEST(testPermutations);
    //CPPUNIT_TEST_EXCEPTION(test_$exception_func, exception);
    CPPUNIT_TEST_SUITE_END();

public: 
   void setUp();
   void tearDown();

   void testPermutations();

private:
	Solution solution;
   //void test_$exception_func();
};
#endif
