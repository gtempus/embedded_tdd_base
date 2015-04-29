#include "LedDriver/LedDriver.h"

volatile static uint8_t *ledsAddress;

void LedDriver_Create(volatile uint8_t *data_register) {
  ledsAddress = data_register;
  *ledsAddress = 0x00;
}

void LedDriver_Destroy(void) {
}

void LedDriver_TurnOn(int led) {
  *ledsAddress = 0x01;
}

void LedDriver_TurnOff(int led) {
  *ledsAddress = 0x00;
}

