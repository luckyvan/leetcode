
#include <cppunit/config/SourcePrefix.h>
#include "JumpGameTest.h"

// Registers the fixture into the 'registry'
CPPUNIT_TEST_SUITE_REGISTRATION(JumpGameTest);


void JumpGameTest::setUp()
{
}


void JumpGameTest::tearDown()
{
}

void JumpGameTest::testCanJump()
{
	int a1[] = { 2, 3, 1, 1, 4 };
	int a2[] = { 3, 2, 1, 0, 4 };

	CPPUNIT_ASSERT(solution.canJump(a1, sizeof(a1) / sizeof(int)));
	CPPUNIT_ASSERT(!solution.canJump(a2, sizeof(a2) / sizeof(int)));

}

void JumpGameTest::testJump()
{
	int a1[] = { 2, 3, 1, 1, 4 };
	
	CPPUNIT_ASSERT_EQUAL(int(2), solution.jump(a1, sizeof(a1) / sizeof(int)));
	
}