#ifndef D_LedDriver_H
#define D_LedDriver_H

#include <stdint.h>

void LedDriver_Create(volatile uint8_t *data_register);
void LedDriver_Destroy(void);

void LedDriver_TurnAllOn();

void LedDriver_TurnOn(int led);
void LedDriver_TurnOff(int led);
#endif  /* D_LedDriver_H */
