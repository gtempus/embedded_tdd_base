extern "C"
{
#include "LedDriver/LedDriver.h"
}

#include "CppUTest/TestHarness.h"

uint8_t virtualLeds = 0xff;

TEST_GROUP(LedDriver) {
  void setup() {
    LedDriver_Create(&virtualLeds);    
  }

  void teardown() {
    LedDriver_Destroy();
  }
};

TEST(LedDriver, Create) {
  BYTES_EQUAL(0x00, virtualLeds);
}

