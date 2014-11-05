// DistinctSubsequencesTest.cpp

#ifndef DISTINCTSUBSEQUENCES_H
#define DISTINCTSUBSEQUENCES_H

#include <cppunit/extensions/HelperMacros.h>
#include "../src/Solution.h"

class DistinctSubsequencesTest : public CPPUNIT_NS::TestFixture
{
    CPPUNIT_TEST_SUITE( DistinctSubsequencesTest );
    CPPUNIT_TEST(testDistinctSubsequences);
    //CPPUNIT_TEST_EXCEPTION(test_$exception_func, exception);
    CPPUNIT_TEST_SUITE_END();

public: 
   void setUp();
   void tearDown();

   void testDistinctSubsequences();

private:
	Solution solution;
   //void test_$exception_func();
};
#endif
