#ifndef THERMISTOR
#define THERMISTOR

#include "stm32f0xx_hal_adc.h"

void Thermistor_Init(ADC_HandleTypeDef * adc_handle);
void Thermistor_DeInit(void);

#endif