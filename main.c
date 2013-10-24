/*
 * Author: C2C Derek Titus
 *
 */

#include <msp430.h> 

#define RS_MASK 0x40

char*message1 = "ECE382 is my favorite class!#";
/*
 * main.c
 */
void main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer

  initSPI();
  LCDinit();
  LCDCLEAR();

  Scrolling(message1,message1);

while(1){}


}
