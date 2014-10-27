
#include <cppunit/config/SourcePrefix.h>
#include "../src/ZigZagConversion/ZigZagConversion.cpp"
#include "ZigZagConversionTest.h"

// Registers the fixture into the 'registry'
CPPUNIT_TEST_SUITE_REGISTRATION( ZigZagConversionTest );


void ZigZagConversionTest::setUp()
{
}


void ZigZagConversionTest::tearDown()
{
}

void ZigZagConversionTest::testConversion ()
{
   string result = convert("PAYPALISHIRING", 3);
   CPPUNIT_ASSERT_EQUAL(string("PAHNAPLSIIGYIR"), result);

   result = convert("PAYPALISHIRING", 4);
   CPPUNIT_ASSERT_EQUAL(string("PINALSIGYAHRPI"), result);
}

