#include "unity.h"

#include <stdint.h>

#include "cpu_temp.h"

static uint16_t rawVal = 3000;

void setReadReturnVal(uint16_t val)
{
    rawVal = val;
}

void setUp(void)
{

}

void tearDown(void)
{

}

uint16_t RawRead(void)
{
    return rawVal;
}

void test_Init_should_initialized_read_function(void)
{
    TEST_ASSERT_EQUAL(CPU_TEMP_OK, CPU_Temp_Init(&RawRead));
}

void test_Init_should_fail_with_notValid_functionPonter(void)
{
    TEST_ASSERT_NOT_EQUAL(CPU_TEMP_OK, CPU_Temp_Init(0));
}

void test_Read_should_return0_on_succes(void)
{
    int16_t temperature;

    CPU_Temp_Init(&RawRead);

    TEST_ASSERT_EQUAL(CPU_TEMP_OK, CPU_Temp_Read(&temperature));
}

void test_Read_should_return30_when_adc_is_1775(void)
{
    int16_t temperature;

    CPU_Temp_Init(&RawRead);

    setReadReturnVal(1775);
    TEST_ASSERT_EQUAL(CPU_TEMP_OK, CPU_Temp_Read(&temperature));
    TEST_ASSERT_EQUAL(30, temperature);
}

void test_Read_should_returnError_when_adcIs_0(void)
{
    int16_t temperature;

    CPU_Temp_Init(&RawRead);

    setReadReturnVal(0);
    TEST_ASSERT_NOT_EQUAL(CPU_TEMP_OK, CPU_Temp_Read(&temperature));
}

int main(void) {
    UNITY_BEGIN();

    // Init
    RUN_TEST(test_Init_should_initialized_read_function);
    RUN_TEST(test_Init_should_fail_with_notValid_functionPonter);

    // Read
    RUN_TEST(test_Read_should_return0_on_succes);
    RUN_TEST(test_Read_should_return30_when_adc_is_1775);
    RUN_TEST(test_Read_should_returnError_when_adcIs_0);

    return UNITY_END();
}
