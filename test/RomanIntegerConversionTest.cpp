
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

void RomanIntegerConversionTest::testIntegerToRoman()
{
	CPPUNIT_ASSERT_EQUAL(string("II"), intToRoman(int(2)));
	CPPUNIT_ASSERT_EQUAL(string("XIII"), intToRoman(int(13)));
	CPPUNIT_ASSERT_EQUAL(string("XC"), intToRoman(int(90)));
	CPPUNIT_ASSERT_EQUAL(string("MCMLIV"), intToRoman(int(1954)));
	CPPUNIT_ASSERT_EQUAL(string("MCMXC"), intToRoman(int(1990)));
	CPPUNIT_ASSERT_EQUAL(string("MMXIV"), intToRoman(int(2014)));
}
