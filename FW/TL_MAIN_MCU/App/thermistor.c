#include "thermistor.h"

static ADC_HandleTypeDef * adc;

void Thermistor_Init(ADC_HandleTypeDef * adc_handle)
{
    adc = adc_handle;
}
void Thermistor_DeInit(void)
{

}