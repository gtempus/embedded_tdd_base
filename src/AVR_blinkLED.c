/* Blinker Demo */

// ------- Preamble -------- //
#include <avr/io.h>             /* Defines pins, ports, etc */
#include <util/delay.h>         /* Functions to waste time */

#include "util/RuntimeError.h"
#include "LedDriver/LedDriver.h"

void RuntimeError(const char* m, int p, const char* f, int l) {
  return; //need to log this!
}

void POVDisplay(uint8_t oneByte) {
  PORTB = oneByte;
  _delay_ms(5);
}

int main(void) {
  // -------- Inits --------- //
  DDRB |= 0b11111111;            /* Data Direction Register B:
                                   writing a one to the bit
                                   enables output. */
  while (1) {
    POVDisplay(0b00001100);
    POVDisplay(0b01010010);
    POVDisplay(0b10100010);
    POVDisplay(0b10100100);
    POVDisplay(0b11001001);
    POVDisplay(0b01010010);
    POVDisplay(0b11111100);
    POVDisplay(0b01010010);
    POVDisplay(0b11001001);
    POVDisplay(0b10100100);
    POVDisplay(0b10100010);
    POVDisplay(0b01010010);
    POVDisplay(0b00001100);

    PORTB = 0;
    _delay_ms(40);
  }
  
  return (0);
}
