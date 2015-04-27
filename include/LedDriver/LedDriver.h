#ifndef D_LedDriver_H
#define D_LedDriver_H

#include <stdint.h>

void LedDriver_Create(volatile uint8_t *data_register);
void LedDriver_Destroy(void);

#endif  /* D_LedDriver_H */
