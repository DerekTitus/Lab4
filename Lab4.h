/*
 * Lab4.h
 *
 *  Created on: Oct 22, 2013
 *      Author: C15Derek.Titus
 */

#ifndef LAB4_H_
#define LAB4_H_

void initSPI();

void LCDinit();

void LCDCLEAR();

void SPISEND(char byteToSend);

void SS_HI();

void SS_LOW();

void shortdelay();

void longdelay();

void LCDwrite8(char byteToSend);

void LCDwrite4(char sendNibble);

void LineTwo();

void LineOne();

void writeChar(char singleChar);

void writeString(char*string1);

void scrollString(char*string2, char*string3);

void writeDataByte(char dataByte);
void writeCommandNibble(char commandNibble);
void writeCommandByte(char commandByte);


#endif /* LAB4_H_ */
