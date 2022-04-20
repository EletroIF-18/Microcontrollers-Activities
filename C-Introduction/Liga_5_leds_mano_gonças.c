#include <util/delay.h>
#include <avr/io.h>

int main(){
  #define F_CPU 16000000UL
  DDRB |= (1 << DDB7); // Set PB5 to output
  DDRB |= (1 << DDB6);
  DDRB |= (1 << DDB5);
  DDRB |= (1 << DDB4);
  DDRH |= (1 << DDH5);

  // While loop turn on PB5 pin
  while (1) {
    PORTB |= (1 << PORTB7); // Turn on PB5
    _delay_ms(1000); // Delay 1 second
    PORTB |= (1 << PORTB6); // Turn on PB5
    _delay_ms(1000); // Delay 1 second
    PORTB |= (1 << PORTB5); // Turn on PB5
    _delay_ms(1000); // Delay 1 second
    PORTB |= (1 << PORTB4); // Turn on PB5
    _delay_ms(1000); // Delay 1 second
    PORTH |= (1 << PH5); // Turn on PB5
    _delay_ms(1000); // Delay 1 second

    PORTB &= ~(1 << PORTB7); // Turn off PB5 pin
    _delay_ms(1000); // Delay 1 second
    PORTB &= ~(1 << PORTB6); // Turn off PB5 pin
    _delay_ms(1000); // Delay 1 second
    PORTB &= ~(1 << PORTB5); // Turn off PB5 pin
    _delay_ms(1000); // Delay 1 second
    PORTB &= ~(1 << PORTB4); // Turn off PB5 pin
    _delay_ms(1000); // Delay 1 second
    PORTH &= ~(1 << PH5); // Turn off PB5 pin
    _delay_ms(1000); // Delay 1 second
  }
}