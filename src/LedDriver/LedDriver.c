#include <stdbool.h>
#include "LedDriver/LedDriver.h"
#include "util/RuntimeError.h"

enum {ALL_LEDS_ON = 0xff, ALL_LEDS_OFF = 0x00};

volatile static uint8_t *ledsAddress;

void LedDriver_Create(volatile uint8_t *data_register) {
  ledsAddress = data_register;
  *ledsAddress = ALL_LEDS_OFF;
}

void LedDriver_Destroy(void) {
}

void LedDriver_TurnAllOn(void) {
  *ledsAddress = ALL_LEDS_ON;
}

void LedDriver_TurnAllOff(void) {
  *ledsAddress = ALL_LEDS_OFF;
}

static uint8_t convertLedNumberToBit(int led) {
  return 1 << (led - 1);
}

static bool outOfBounds(int led) {
  if (led <= 0 || led > 8) {
    RUNTIME_ERROR("LED Driver: out-of-bounds LED", led);
    return true;
  }
  return false;
}

void LedDriver_TurnOn(int led) {
  if (outOfBounds(led)) return;
  *ledsAddress |= convertLedNumberToBit(led);
}

void LedDriver_TurnOff(int led) {
  if (outOfBounds(led)) return;
  *ledsAddress &= ~(convertLedNumberToBit(led));
}

