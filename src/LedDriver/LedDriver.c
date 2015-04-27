#include "LedDriver/LedDriver.h"

void LedDriver_Create(volatile uint8_t *data_register)
{
  *data_register = 0x00;
}

void LedDriver_Destroy(void)
{
}


