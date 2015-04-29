extern "C"
{
#include "LedDriver/LedDriver.h"
}

#include "CppUTest/TestHarness.h"


TEST_GROUP(LedDriver) {
  void setup() {

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
  uint8_t virtualLeds;
  LedDriver_Create(&virtualLeds);
  LedDriver_TurnOn(1);
  BYTES_EQUAL(0x01, virtualLeds);
}

TEST(LedDriver, TurnOffLedOne) {
  uint8_t virtualLeds;
  LedDriver_Create(&virtualLeds);
  LedDriver_TurnOn(1);
  LedDriver_TurnOff(1);
  BYTES_EQUAL(0x00, virtualLeds);
}

