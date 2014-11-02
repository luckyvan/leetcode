
#include <cppunit/config/SourcePrefix.h>
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
   CPPUNIT_ASSERT_EQUAL(int(123), solution.atoi("123"));
   CPPUNIT_ASSERT_EQUAL(int(123), solution.atoi("+123"));
   CPPUNIT_ASSERT_EQUAL(int(-123), solution.atoi("-123"));
}


void AtoiTest::testAheadSpace()
{
   CPPUNIT_ASSERT_EQUAL(int(123), solution.atoi("  123"));
   CPPUNIT_ASSERT_EQUAL(int(123), solution.atoi(" +123"));
   CPPUNIT_ASSERT_EQUAL(int(-123), solution.atoi("   -123"));
}

void AtoiTest::testInvalidTail()
{
   CPPUNIT_ASSERT_EQUAL(int(123), solution.atoi("  123aj"));
   CPPUNIT_ASSERT_EQUAL(int(123), solution.atoi(" +123bc"));
   CPPUNIT_ASSERT_EQUAL(int(-123), solution.atoi("   -123de"));
}


void AtoiTest::testNonConversion()
{
   CPPUNIT_ASSERT_EQUAL(int(0), solution.atoi("  "));
   CPPUNIT_ASSERT_EQUAL(int(0), solution.atoi(NULL));
   CPPUNIT_ASSERT_EQUAL(int(0), solution.atoi("   N-123de"));
}


void AtoiTest::testBoundaries()
{
  //more digits
  CPPUNIT_ASSERT_EQUAL(int(INT_MAX), solution.atoi("12345678901"));
  //max boundaries
  CPPUNIT_ASSERT_EQUAL(int(INT_MAX), solution.atoi("2147483647"));
  CPPUNIT_ASSERT_EQUAL(int(INT_MAX - 1), solution.atoi("2147483646"));
  CPPUNIT_ASSERT_EQUAL(int(INT_MAX), solution.atoi("2147483648"));
  //min boundaries
  CPPUNIT_ASSERT_EQUAL(int(INT_MIN), solution.atoi("-2147483648"));
  CPPUNIT_ASSERT_EQUAL(int(INT_MIN+1), solution.atoi("-2147483647"));
  CPPUNIT_ASSERT_EQUAL(int(INT_MIN), solution.atoi("-2147483649"));
}
