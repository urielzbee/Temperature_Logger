#include "unity.h"
#include "cpu_temp.h"

void setUp(void)
{

}

void tearDown(void)
{

}

void test_TheFirst(void)
{
    TEST_ASSERT_EQUAL(1,0);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_TheFirst);
    return UNITY_END();
}
