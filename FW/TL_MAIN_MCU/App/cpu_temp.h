#include <stdint.h>

typedef enum 
{
  CPU_TEMP_OK       = 0x00U,
  CPU_TEMP_ERROR
} CPU_TEMP_StatusTypeDef;

typedef uint16_t (*CPU_Temp_RawRead)(void);

CPU_TEMP_StatusTypeDef CPU_Temp_Init(CPU_Temp_RawRead read);
void CPU_Temp_DeInit(void);

CPU_TEMP_StatusTypeDef CPU_Temp_Read(int16_t *temp);