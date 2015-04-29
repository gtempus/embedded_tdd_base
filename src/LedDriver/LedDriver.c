#include "LedDriver/LedDriver.h"

volatile static uint8_t *ledsAddress;
enum {ALL_LEDS_ON = 0xff, ALL_LEDS_OFF = 0x00};

void LedDriver_Create(volatile uint8_t *data_register) {
  ledsAddress = data_register;
  *ledsAddress = ALL_LEDS_OFF;
}

void LedDriver_Destroy(void) {
}

void LedDriver_TurnAllOn(void) {
  *ledsAddress = ALL_LEDS_ON;
}

static uint8_t convertLedNumberToBit(int led) {
  return 1 << (led - 1);
}

void LedDriver_TurnOn(int led) {
  *ledsAddress |= convertLedNumberToBit(led);
}

void LedDriver_TurnOff(int led) {
  *ledsAddress &= ~(convertLedNumberToBit(led));
}

