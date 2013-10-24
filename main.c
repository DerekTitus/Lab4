/*
 * Author: C2C Derek Titus
 *
 */

#include <msp430.h> 
#include "lab4.h"

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

while(1)
{
	writing(message1, 8);
	LineTwo();
	writing(message2, 8);
	LineOne();
	__delay_cycles(100000);	//waits at this screen for 10000 cycles until it shifts to the left(scrolls)

	scrolling(message1, message1size);
	scrolling(message2, message2size);
	__delay_cycles(100000);

	LCDCLEAR();



}


}
