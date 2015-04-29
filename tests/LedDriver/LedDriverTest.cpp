extern "C"
{
#include "LedDriver/LedDriver.h"
}

#include "CppUTest/TestHarness.h"

static uint8_t virtualLeds;

TEST_GROUP(LedDriver) {
  void setup() {
    LedDriver_Create(&virtualLeds);
  }

  void teardown() {
    LedDriver_Destroy();
  }
};

TEST(LedDriver, LedsAreOffAfterCreate) {
  uint8_t virtualLeds = 0xff;
  LedDriver_Create(&virtualLeds);    
  BYTES_EQUAL(0b00000000, virtualLeds);
}

TEST(LedDriver, TurnOnLedOne) {
  LedDriver_TurnOn(1);
  BYTES_EQUAL(0b00000001, virtualLeds);
}

TEST(LedDriver, TurnOffLedOne) {
  LedDriver_TurnOn(1);
  LedDriver_TurnOff(1);
  BYTES_EQUAL(0b00000000, virtualLeds);
}

TEST(LedDriver, TurnOnMultipleLeds) {
  LedDriver_TurnOn(5);
  LedDriver_TurnOn(4);
  BYTES_EQUAL(0b00011000, virtualLeds);
}

TEST(LedDriver, TurnOffAnyLed) {
  LedDriver_TurnAllOn();
  LedDriver_TurnOff(4);
  BYTES_EQUAL(0b11110111, virtualLeds);
}

TEST(LedDriver, TurnAllOn) {
  LedDriver_TurnAllOn();
  BYTES_EQUAL(0b11111111, virtualLeds);
}
