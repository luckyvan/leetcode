
#include <cppunit/config/SourcePrefix.h>
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
   string result = solution.convert("PAYPALISHIRING", 3);
   CPPUNIT_ASSERT_EQUAL(string("PAHNAPLSIIGYIR"), result);

   result = solution.convert("PAYPALISHIRING", 4);
   CPPUNIT_ASSERT_EQUAL(string("PINALSIGYAHRPI"), result);
}

