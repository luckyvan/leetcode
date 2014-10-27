// AtoiTest.cpp

#ifndef ATOI_H
#define ATOI_H

#include <cppunit/extensions/HelperMacros.h>

class AtoiTest : public CPPUNIT_NS::TestFixture
{
    CPPUNIT_TEST_SUITE( AtoiTest );
    CPPUNIT_TEST(testNormalCase);
    CPPUNIT_TEST(testAheadSpace);
    CPPUNIT_TEST(testInvalidTail);
    CPPUNIT_TEST(testNonConversion);
    CPPUNIT_TEST(testBoundaries);
    //CPPUNIT_TEST_EXCEPTION(test_$exception_func, exception);
    CPPUNIT_TEST_SUITE_END();

public: 
   void setUp();
   void tearDown();

   void testNormalCase();
   void testAheadSpace();
   void testInvalidTail();
   void testNonConversion();
   void testBoundaries();
};
#endif
