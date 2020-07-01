


// hena ana 3mlt include l driver el i2c gowa driver el EEPROM ..... tab leh m3mlt4 include ll i2c.h gowa el header bta3 el eeprom m4 el .c file bta3o ????  la2n ana lw kont 3mltlo include gowa el header bta3o w b3dha 3mlt ll(eeprom.h) include gowa el main fa kda el main feha el driver bta3 el eeprom el gowah aslun driver el i2c w dy 7aga m4 7lwa mmkn tedorny ........fa 34an kda 3mlto include gowa el .c m4 el .h bta3 el eeprom.......asma3 el record......

#include "external_eeprom.h"
 unsigned short global;
void EEPROM_init(void)  // lama a43'l el EEPROM kda ana sha3'alt el I2C ............mmkn ageb EEPROM t4t3'l m3 SPI msln fa hya hya lama a43'l el EEPROM h43'l el I2C ....la2n el I2C howa el by43'l el memory dy............
{
  I2C1_Init(100000);         // initialize I2C communication
}

void EEPROM_writeByte(uint8 my_data)  // h3ml write(y3ny hkteb f el EEPROM). ...fa hya bta5od awl 7aga address el memory loc. el hykteb feh 34an kda 3mlto uint16 la2no 11 bits ......w hta5od el data el htktbha (el eeprom ht5zn el data dy f el address da el enta ba3ethom) ... fa dlw2ty ana 3ayz a3ml write ...yb2a lazm a3ml el frame b2a..............yb2a el func dy bta5od el address el gowa el eeprom el ht5zn feh el data bta3tak w hta5od el data el ht5znha ..........................
{

  I2C1_Start();              // issue I2C start signal
  I2C1_Wr(0xA2);            // send byte via I2C  (device address + W)
  I2C1_Wr(2);                // send byte (address of EEPROM location)
  I2C1_Wr(my_data);            // send data (data to be written)
  I2C1_Stop();               // issue I2C stop signal
}

uint8 EEPROM_readByte()
{
    uint8 my_data;
    I2C1_Start();              // issue I2C start signal
  I2C1_Wr(0xA2);           // send byte via I2C  (device address + W)
  I2C1_Wr(2);               // send byte (data address)

  I2C1_Repeated_Start();     // issue I2C signal repeated start
  I2C1_Wr(0xA3);             // send byte (device address + R)

  my_data = I2C1_Rd(0u);       // Read the data (NO acknowledge)
  I2C1_Stop();               // issue I2C stop signal
  return my_data;
}
