
#include <cppunit/config/SourcePrefix.h>
#include "../src/RomanIntegerConversion/RomanIntegerConversion.cpp"
#include <stdlib.h>
#include <limits.h>
#include "RomanIntegerConversionTest.h"

// Registers the fixture into the 'registry'
CPPUNIT_TEST_SUITE_REGISTRATION( RomanIntegerConversionTest );


void RomanIntegerConversionTest::setUp()
{
}


void RomanIntegerConversionTest::tearDown()
{
}

void RomanIntegerConversionTest::testRomanToInteger()
{
   CPPUNIT_ASSERT_EQUAL(int(2), romanToInt("II"));
   CPPUNIT_ASSERT_EQUAL(int(13), romanToInt("XIII"));
   CPPUNIT_ASSERT_EQUAL(int(90), romanToInt("XC"));
   CPPUNIT_ASSERT_EQUAL(int(1954), romanToInt("MCMLIV"));
   CPPUNIT_ASSERT_EQUAL(int(1990), romanToInt("MCMXC"));
   CPPUNIT_ASSERT_EQUAL(int(2014), romanToInt("MMXIV"));
}


