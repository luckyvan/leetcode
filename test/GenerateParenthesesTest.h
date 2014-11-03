// GenerateParenthesesTest.cpp

#ifndef GENERATEPARENTHESES_H
#define GENERATEPARENTHESES_H

#include <cppunit/extensions/HelperMacros.h>
#include "../src/Solution.h"

class GenerateParenthesesTest : public CPPUNIT_NS::TestFixture
{
    CPPUNIT_TEST_SUITE( GenerateParenthesesTest );
    CPPUNIT_TEST(testGeneration);
    //CPPUNIT_TEST_EXCEPTION(test_$exception_func, exception);
    CPPUNIT_TEST_SUITE_END();

public: 
   void setUp();
   void tearDown();

   void testGeneration();

private:
	Solution solution;
   //void test_$exception_func();
};
#endif
