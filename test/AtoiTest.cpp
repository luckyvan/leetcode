
#include <cppunit/config/SourcePrefix.h>
#include "../src/Atoi/Atoi.cpp"
#include <stdlib.h>
#include <limits.h>
#include "AtoiTest.h"

// Registers the fixture into the 'registry'
CPPUNIT_TEST_SUITE_REGISTRATION( AtoiTest );


void AtoiTest::setUp()
{
}


void AtoiTest::tearDown()
{
}

void AtoiTest::testNormalCase()
{
   CPPUNIT_ASSERT_EQUAL(int(123), atoi("123"));
   CPPUNIT_ASSERT_EQUAL(int(123), atoi("+123"));
   CPPUNIT_ASSERT_EQUAL(int(-123), atoi("-123"));
}


void AtoiTest::testAheadSpace()
{
   CPPUNIT_ASSERT_EQUAL(int(123), atoi("  123"));
   CPPUNIT_ASSERT_EQUAL(int(123), atoi(" +123"));
   CPPUNIT_ASSERT_EQUAL(int(-123), atoi("   -123"));
}

void AtoiTest::testInvalidTail()
{
   CPPUNIT_ASSERT_EQUAL(int(123), atoi("  123aj"));
   CPPUNIT_ASSERT_EQUAL(int(123), atoi(" +123bc"));
   CPPUNIT_ASSERT_EQUAL(int(-123), atoi("   -123de"));
}


void AtoiTest::testNonConversion()
{
   CPPUNIT_ASSERT_EQUAL(int(0), atoi("  "));
   CPPUNIT_ASSERT_EQUAL(int(0), atoi(NULL));
   CPPUNIT_ASSERT_EQUAL(int(0), atoi("   N-123de"));
}


void AtoiTest::testBoundaries()
{
  //more digits
  CPPUNIT_ASSERT_EQUAL(int(INT_MAX), atoi("12345678901"));
  //max boundaries
  CPPUNIT_ASSERT_EQUAL(int(INT_MAX), atoi("2147483647"));
  CPPUNIT_ASSERT_EQUAL(int(INT_MAX - 1), atoi("2147483646"));
  CPPUNIT_ASSERT_EQUAL(int(INT_MAX), atoi("2147483648"));
  //min boundaries
  CPPUNIT_ASSERT_EQUAL(int(INT_MIN), atoi("-2147483648"));
  CPPUNIT_ASSERT_EQUAL(int(INT_MIN+1), atoi("-2147483647"));
  CPPUNIT_ASSERT_EQUAL(int(INT_MIN), atoi("-2147483649"));
}
