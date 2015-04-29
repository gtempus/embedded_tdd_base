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
  BYTES_EQUAL(0x00, virtualLeds);
}

TEST(LedDriver, TurnOnLedOne) {
  LedDriver_TurnOn(1);
  BYTES_EQUAL(0x01, virtualLeds);
}

TEST(LedDriver, TurnOffLedOne) {
  LedDriver_TurnOn(1);
  LedDriver_TurnOff(1);
  BYTES_EQUAL(0x00, virtualLeds);
}

