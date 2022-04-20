#include <util/delay.h>
#include <avr/io.h>

int main(){
  #define F_CPU 16000000UL
  for(int i = 4 ; i < 8 ; i++){
    DDRB |= (1 << i);
  }
  DDRH |= (1 << DDH5);

  // While loop turn on PB5 pin
  while (1) {
   for(int i = 7 ; i > 3 ; i--){
     PORTB |= (1 << i);
    _delay_ms(1000);
   }
    PORTH |= (1 << PH5); // Turn on PB5
    _delay_ms(1000); // Delay 1 second


    for(int i = 7 ; i > 3 ; i--){
     PORTB &= ~(1 << i);
    _delay_ms(1000);
   }
    PORTH &= ~(1 << PH5); // Turn off PB5 pin
    _delay_ms(1000); // Delay 1 second
  }
}