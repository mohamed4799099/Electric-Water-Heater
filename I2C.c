#include "external_eeprom.h"


void main() {
        unsigned char my_data = 0;
         uint8 a =0;
   TRISB = 0;                 // Configure PORTB as output
   PORTB = 0;

  EEPROM_init();
  EEPROM_writeByte(0x30);
  Delay_100ms();
  my_data = EEPROM_readByte();
  PORTB = my_data;



}
