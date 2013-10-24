/*
 * Author: C2C Derek Titus
 *
 */

#include <msp430.h> 

#define RS_MASK 0x40

char message1[] = "ECE382 is my favorite class!";
char message2[] = "Dr. York is the best!";
char message1size = 30;
char message2size = 21;

/*
 * main.c
 */
void main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer

  initSPI();
  LCDinit();
  LCDCLEAR();

  scrolling(message1,message1);

while(1)
{



}


}
