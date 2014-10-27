// ZigZagConversionTest.cpp

#ifndef ZIGZAGCONVERSIONTEST_H
#define ZIGZAGCONVERSIONTEST_H

#include <cppunit/extensions/HelperMacros.h>

class ZigZagConversionTest : public CPPUNIT_NS::TestFixture
{
    CPPUNIT_TEST_SUITE( ZigZagConversionTest );
    CPPUNIT_TEST(testConversion);
    //CPPUNIT_TEST_EXCEPTION(test_$exception_func, exception);
    CPPUNIT_TEST_SUITE_END();

public: 
   void setUp();
   void tearDown();

   void testConversion();
   //void test_$exception_func();
};
#endif
