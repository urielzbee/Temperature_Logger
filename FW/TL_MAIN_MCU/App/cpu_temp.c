#include "cpu_temp.h"

/* Temperature sensor calibration value address */
#ifndef TEST
#define TS_CAL1 (*((uint16_t*) ((uint32_t) 0x1FFFF7B8)))
#else
uint32_t TS_CAL1 = 1775;
#endif
#define TS_CAL1_TEMP 30
#define VDD_CALIB ((uint32_t) (3300))
#define VDD_APPLI ((uint32_t) (3300))
#define AVG_SLOPE ((int32_t)  (5337))  // AVG_SLOPE in ADC conversion 
                                       // step (@3.3V)/°C multiplied 
                                       // by 1000 for precision on the division
/*  
*   TL : V_SENSE linearity with temperature - +-1°C
*   
*   Avg_Slope: Average Slope - 4.3mV/°C
*
*   V_30: Voltage at 30°C(+-5°C) - 1.43V
* 
*   TS_temp : ADC sampling time when reading the
*   temperature 2   
*
*/

static CPU_Temp_RawRead rawRead;

CPU_TEMP_StatusTypeDef CPU_Temp_Init(CPU_Temp_RawRead read)
{
    if(read == 0)
    {
        return 1;
    }
    rawRead = read;
    return CPU_TEMP_OK;
}

void CPU_Temp_DeInit(void)
{   
    rawRead = 0;
}       

CPU_TEMP_StatusTypeDef CPU_Temp_Read(int16_t *temp)
{
    uint16_t rawVal = 0;
    int32_t temperature;
    uint32_t senseData;

    rawVal = rawRead();

    if(rawVal == 0)
    {
        return CPU_TEMP_ERROR;
    }

    senseData = (rawVal * VDD_APPLI) / VDD_CALIB;

    temperature = TS_CAL1 - senseData;
    temperature = (temperature * 1000) / AVG_SLOPE;
    temperature = temperature + TS_CAL1_TEMP;
    *temp = (uint32_t)temperature;

    return CPU_TEMP_OK;
}
