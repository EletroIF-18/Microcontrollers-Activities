#include <LCD.h>

int main() {

  unsigned char charcs1[8] = {
    0b01110,
    0b11011,
    0b10101,
    0b11011,
    0b01110,
    0b00100,
    0b00100,
    0b01110
  };

  DDRB = 0xFF;
  DDRD = 0xFF;
  PORTB = 0x00;

  set_bit(PORTB, 2);
  inic_LCD_4bits();

  cmd_LCD(0x40, 0);
  for(int k=0; k<8; k++) {
    cmd_LCD(charcs1[k], 1);
  }
  cmd_LCD(0x00, 1);

  cmd_LCD(0x40, 0);
  for(int k=0; k<8; k++) {
    cmd_LCD(0xFF, 1);
  }
  cmd_LCD(0x00, 1);

  cmd_LCD(0x81, 0);
  cmd_LCD(0x00, 1);
  cmd_LCD(0x01, 1);

   for(;;);

  return 1;
}
