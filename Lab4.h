/*
 * Lab4.h
 *
 *  Created on: Oct 22, 2013
 *      Author: C15Derek.Titus
 */

#ifndef LAB4_H_
#define LAB4_H_

void INITSPI();

void INITLCD();

void LCDCLEAR;

void changeLine;

void writeChar(char singleChar);

void writeString(char*string1);

void scrollString(char*string2, char*string3);




#endif /* LAB4_H_ */
