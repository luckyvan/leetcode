// ValidParenthesesTest.cpp

#ifndef VALIDPARENTHESES_H
#define VALIDPARENTHESES_H

#include <cppunit/extensions/HelperMacros.h>

class ValidParenthesesTest : public CPPUNIT_NS::TestFixture
{
    CPPUNIT_TEST_SUITE( ValidParenthesesTest );
    CPPUNIT_TEST(testNormalCase);
    //CPPUNIT_TEST_EXCEPTION(test_$exception_func, exception);
    CPPUNIT_TEST_SUITE_END();

public: 
   void setUp();
   void tearDown();

   void testNormalCase();
};
#endif
