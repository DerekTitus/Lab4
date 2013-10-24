/*
 * Lab4.c
 *
 *  Created on: Oct 22, 2013
 *      Author: C15Derek.Titus
 */

#ifndef LAB4_C_
#define LAB4_C_

#include "Lab4.h"
#include <msp430.h>
#define RS_MASK 0x40

unsigned char LCDCON;


void initSPI()
{
	UCB0CTL1 |= UCSWRST;
	UCB0CTL0 |= UCCKPH|UCMSB|UCMST|UCSYNC;
	UCB0CTL1 |= UCSSEL1;
	UCB0STAT |= UCLISTEN;

	P1SEL |= BIT5;
	P1SEL2 |= BIT5;
	P1SEL |= BIT6;
	P1SEL2 |= BIT6;
	P1SEL |= BIT7;
	P1SEL2 |= BIT7;

	UCB0CTL1 &= UCSWRST;


}

void SS_HI()
{
	P1DIR |= BIT0;
	P1OUT |= BIT0;
}

void SS_LOW()
{
	P1DIR |= BIT0;
	P1OUT &= BIT0;
}

void longdelay()
{
	__delay_cycles(1760);
}

void shortdelay()
{
	__delay_cycles(44);
}

void LCDwrite4(char NibbletoSend)
{
	unsigned char sendNibble = NibbletoSend;
	sendNibble &= 0x0f;
	sendNibble |= LCDCON;

	sendNibble &= 0x7f;
	SPISend(sendNibble);
	shortdelay();

	sendNibble |= 0x00;
	SPISend(sendNibble);
	shortdelay();

	sendNibble &= 0x7f;
	SPISend(sendNibble);
	shortdelay();
}


void LCDwrite8(char byteToSend)
{
    unsigned char sendByte = byteToSend;

    sendByte &= 0xF0;

    sendByte = sendByte >> 4;               // rotate to the right 4 times

    LCDwrite4(sendByte);

    sendByte = byteToSend;

    sendByte &= 0x0F;

    LCDwrite4(sendByte);
}




void LCDinit()
{


}

void writeCommandNibble(char commandNibble)
{
    LCDCON &= ~RS_MASK;
    LCDwrite4(commandNibble);
    longdelay();
}

void writeCommandByte(char commandByte)
{
    LCDCON &= ~RS_MASK;
    LCDwrite8(commandByte);
    longdelay();
}

void writeDataByte(char dataByte)
{
    LCDCON |= RS_MASK;
    LCDwrite8(dataByte);
    longdelay();
}



void SPI_send(char byteToSend)
{
    char readByte;

    SS_LOW();

    UCB0TXBUF = byteToSend;

    while(!(UCB0RXIFG & IFG2))
    {
        // wait until you've received a byte
    }

    readByte = UCB0RXBUF;

    SS_HI();
}







#endif /* LAB4_C_ */
