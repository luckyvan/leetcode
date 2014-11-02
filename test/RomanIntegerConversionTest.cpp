
#include <cppunit/config/SourcePrefix.h>
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
   CPPUNIT_ASSERT_EQUAL(int(2), solution.romanToInt("II"));
   CPPUNIT_ASSERT_EQUAL(int(13), solution.romanToInt("XIII"));
   CPPUNIT_ASSERT_EQUAL(int(90), solution.romanToInt("XC"));
   CPPUNIT_ASSERT_EQUAL(int(1954), solution.romanToInt("MCMLIV"));
   CPPUNIT_ASSERT_EQUAL(int(1990), solution.romanToInt("MCMXC"));
   CPPUNIT_ASSERT_EQUAL(int(2014), solution.romanToInt("MMXIV"));
}

void RomanIntegerConversionTest::testIntegerToRoman()
{
	CPPUNIT_ASSERT_EQUAL(string("II"), solution.intToRoman(int(2)));
	CPPUNIT_ASSERT_EQUAL(string("XIII"), solution.intToRoman(int(13)));
	CPPUNIT_ASSERT_EQUAL(string("XC"), solution.intToRoman(int(90)));
	CPPUNIT_ASSERT_EQUAL(string("MCMLIV"), solution.intToRoman(int(1954)));
	CPPUNIT_ASSERT_EQUAL(string("MCMXC"), solution.intToRoman(int(1990)));
	CPPUNIT_ASSERT_EQUAL(string("MMXIV"), solution.intToRoman(int(2014)));
}
