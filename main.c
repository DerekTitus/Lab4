/*
 * Author: C2C Derek Titus
 *
 */

#include <msp430.h> 

#define RS_MASK 0x40


/*
 * main.c
 */
void main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer
    INITSPI();
    SS_HI();
    SS_LOW();
    longdelay();
    shortdelay();
    LCDwrite4();
    LCDwrite8();


while(1)
{


}


}
