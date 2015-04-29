/* Blinker Demo */

// ------- Preamble -------- //
#include <avr/io.h>             /* Defines pins, ports, etc */
#include <util/delay.h>         /* Functions to waste time */

#include "LedDriver/LedDriver.h"

int main(void) {
  // -------- Inits --------- //
  DDRB |= 0b0000001;            /* Data Direction Register B:
                                   writing a one to the bit
                                   enables output. */
  LedDriver_Create(&PORTB);

  while (1) {

    LedDriver_TurnOn(1);
    _delay_ms(8);

    LedDriver_TurnOff(1);
    _delay_ms(1000);

  }
  
  return (0);
}
