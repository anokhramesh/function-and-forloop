/*using Function and for loop PIC16F877A
 * File:   functionmain.c
 * Author: Anokhautomation
 *
 * Created on July 10, 2022, 8:18 PM
 */
#include <xc.h>
__CONFIG(FOSC_HS & WDTE_OFF & PWRTE_OFF & BOREN_ON & LVP_ON & CPD_OFF & WRT_OFF & CP_OFF);
#define _XTAL_FREQ 20000000 //Specify the XTAL crystall FREQ
sblink(int get) //Function definition with "get" as parameter  

{

  for (int i=0; i<=8 && RB0==0; i++) 

        {

       PORTD = get << i;  //LED move Left Sequence 

       __delay_ms(50);

        }

          for (int i=8; i>=0 && RB0==0; i--)

        {

       PORTD = get << i;  //LED move Left Sequence 

       __delay_ms(50);

        }      

}
void main(void) {
TRISB0=1; //Instruct the MCU that the PORTB pin 0 is used as input for button.

TRISD = 0x00; //Instruct the MCU that all pins are output 

PORTD=0x00; //Initialize all pins to 0

OPTION_REG= 0b00000000;//Enable pull up R on port B


while(1) //Get into the Infinite While loop

{

    

    if (RB0==0)

    {

    

        sblink(1); //FUNCTION CALL 1 with parameter 1 

        sblink(3); //FUNCTION CALL 3 with parameter 3

        sblink(7); //FUNCTION CALL 7 with parameter 7

        sblink(15); //FUNCTION CALL 4 with parameter 15

        

        //while(RB0==0) //If button is still pressed

        {

            //PORTD=0xFF; //Turn ON all LEDs

        }

    }

   

}

}


