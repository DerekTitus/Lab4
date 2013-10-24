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

void SPI_send(char byteToSend)
{
    volatile char readByte;

    SS_LOW();

    UCB0TXBUF = byteToSend;

    while(!(UCB0RXIFG & IFG2))
    {
        // wait until you've received a byte
    }

    readByte = UCB0RXBUF;

    SS_HI();
}


void LCDwrite4(char NibbletoSend)
{
	unsigned char sendNibble = NibbletoSend;
	sendNibble &= 0x0f;
	sendNibble |= LCDCON;

	sendNibble &= 0x7f;
	SPI_send(sendNibble);
	shortdelay();

	sendNibble |= 0x00;
	SPI_send(sendNibble);
	shortdelay();

	sendNibble &= 0x7f;
	SPI_send(sendNibble);
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

void LCDCLEAR()
{
	writeCommandByte(1);
	LCDCON |= RS_MASK;
	longdelay();
}



void LineTwo()
{
	writeCommandByte(0xC0);
	LCDCON |= RS_MASK;
	longdelay();
}
void LineOne()
{
	writeCommandByte(0x40);
}

void writeASCII(char asciiChar)
{
	writeDataByte(asciiChar);
}


void LCDinit()
{
    writeCommandNibble(0x03);

    writeCommandNibble(0x03);

    writeCommandNibble(0x03);

    writeCommandNibble(0x02);

    writeCommandByte(0x28);

    writeCommandByte(0x0C);

    writeCommandByte(0x01);

    writeCommandByte(0x06);

    writeCommandByte(0x01);

    writeCommandByte(0x02);

    SPI_send(0);
    shortdelay();
}

void writing(char message[], char messagesize)
{
	volatile int i = 0;
	for(i = 0; i < messagesize; i++)
	{
		writeChar(message[i]);
	}
}

void scrolling(char message[], char messagesize)
{
	volatile int i = 0;
	int place = 0;
	place = message[0];


	for(i=0; i < messagesize; i++)
	{
		message[i] = message[i+1];
	}
	message[messagesize - 1] = place;
}





#endif /* LAB4_C_ */
