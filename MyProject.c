#include "std_types.h"
#include "common_macros.h"
 
        // LCD module connections
sbit LCD_RS at RC4_bit;
sbit LCD_EN at RC5_bit;
sbit LCD_D4 at RC0_bit;
sbit LCD_D5 at RC1_bit;
sbit LCD_D6 at RC2_bit;
sbit LCD_D7 at RC3_bit;

sbit LCD_RS_Direction at TRISC4_bit;
sbit LCD_EN_Direction at TRISC5_bit;
sbit LCD_D4_Direction at TRISC0_bit;
sbit LCD_D5_Direction at TRISC1_bit;
sbit LCD_D6_Direction at TRISC2_bit;
sbit LCD_D7_Direction at TRISC3_bit;
// End LCD module connections


char i;

void main(){
uint8 temperature = 60;  // Temperature is set initially to 60
  PORTB = 0;
  TRISB = 0;     // All port B pins are output
  TRISD = 1;
  portd.b1=0;    //Pin 1 represents the electric water heater and it is initaily off

  
  Lcd_Init();   // Led initialization
  Lcd_Cmd(_LCD_CLEAR);      // Clears the screen
  Lcd_Cmd(_LCD_CURSOR_OFF);
  Lcd_Out(1, 1, "Heater OFF");

   while(1)
   {                       // Pin 0 represents the on/off button
                           // On Mode
           if(portd.b0==1 && portd.b1==0)      //if on/off button is pressed and heater is off, turn the heater on
                          {        delay_ms(50);    //To avoid rebouncing
                                   Lcd_Cmd(_LCD_CLEAR);      // Clears the screen
                                   portd.b1=1;
                                 //   text[] = "Heater ON" ;
                                   Lcd_Out(1, 1, "Heater ON");
                                    
                                    if ( portd.b3 ==1)  //Pin 3 port D represents up button
                                    {
                                        temperature=temperature+5;
                                    }
                                     if ( portd.b4 ==1)  //Pin 4 port D represents down button
                                    {
                                        temperature=temperature-5;
                                    }
                                    
                          }
                           // OFF Mode
            if (portd.b0==1 && portd.b1==1)         //if on/off button is pressed and heater is on, turn the heater off
                            {
                                     delay_ms(50);    //To avoid rebouncing
                                    Lcd_Cmd(_LCD_CLEAR);      // Clears the screen
                                    Lcd_Out(1, 1, "Heater OFF");
                                      portd.b1=0;
                             }
  }
}