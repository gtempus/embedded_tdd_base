extern "C"
{
#include "LedDriver/LedDriver.h"
#include "mocks/RuntimeErrorStub.h"
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

TEST(LedDriver, UpperAndLowerBounds) {
  LedDriver_TurnOn(1);
  LedDriver_TurnOn(8);
  BYTES_EQUAL(0b10000001, virtualLeds);
}

TEST(LedDriver, OutOfBoundsTurnOnDoesNoHarm) {
  LedDriver_TurnOn(-1);
  LedDriver_TurnOn(0);
  LedDriver_TurnOn(9);
  LedDriver_TurnOn(3141);
  BYTES_EQUAL(0b00000000, virtualLeds);
}

TEST(LedDriver, OutOfBoundsTurnOffDoesNoHarm) {
  LedDriver_TurnAllOn();
  LedDriver_TurnOff(-1);
  LedDriver_TurnOff(0);
  LedDriver_TurnOff(9);
  LedDriver_TurnOff(3141);
  BYTES_EQUAL(0b11111111, virtualLeds);
}

TEST(LedDriver, OutOfBoundsTurnOnProducesRuntimeError) {
  LedDriver_TurnOn(-1);
  STRCMP_EQUAL("LED Driver: out-of-bounds LED", RuntimeErrorStub_GetLastError());
  LONGS_EQUAL(-1, RuntimeErrorStub_GetLastParameter());
}

TEST(LedDriver, OutOfBoundsTurnOffProducesRuntimeError) {
  LedDriver_TurnOff(9);
  STRCMP_EQUAL("LED Driver: out-of-bounds LED", RuntimeErrorStub_GetLastError());
  LONGS_EQUAL(9, RuntimeErrorStub_GetLastParameter());
}
