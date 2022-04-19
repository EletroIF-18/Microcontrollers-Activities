#include <Arduino.h>
#include <util/delay.h>
#include <avr/io.h>

void setup() {
  #define F_CPU 16000000UL
}

void loop() {
  DDRB |= (1 << DDB5); // Set PB5 to output

  // While loop turn on PB5 pin
  while (1) {
    PORTB |= (1 << PORTB5); // Turn on PB5
    _delay_ms(1000); // Delay 1 second
    PORTB &= ~(1 << PORTB5); // Turn off PB5 pin
    _delay_ms(1000); // Delay 1 second
  }
}