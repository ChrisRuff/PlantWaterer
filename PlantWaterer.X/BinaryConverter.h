/* Microchip Technology Inc. and its subsidiaries.  You may use this software 
 * and any derivatives exclusively with Microchip products. 
 * 
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES, WHETHER 
 * EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED 
 * WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A 
 * PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION 
 * WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION. 
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
 * INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
 * WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS 
 * BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE 
 * FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS 
 * IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF 
 * ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE 
 * TERMS. 
 */

/* 
 * File:   
 * Author: Chris
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef BINARY_CONVERTER_H
#define	BINARY_CONVERTER_H

#include "Globals.h"

void initSeg();
void initLED();
/**
 * Convert a single 0-9 digit to seven segment format
 * @param in digit to be converted
 * @return 0b0000000 - 0b1111111
 */
int toDigit(char in);

/**
 * Converts value given from the timer to seven segment value
 * @param binary value from the timer 0x00000000 -> 0xFFFFFFFF
 * @return binary value for all the 7segs 
 * INT(31-24)(ABCDEFG)1 
 * INT(23-16)(ABCDEFG)2
 * INT(15-8) (ABCDEFG)3
 * INT(7-0)  (ABCDEFG)4
 */
SegBits toSevenSegment(int binary);

/**
 * 
 * @param binary
 * @return 
 */

/**
 * Send timer value to display
 * @param timer binary val
 */
void toDisplay(int time, int duration);

void irDisplay(int* commands, int n);

void pourDisplay();

void segUpload(SegBits segs);
void ledUpload(int duration);



void toLCD(int time, int duration, LcdBits* lcds);
void lcdUpload(LcdBits* segs);
void lcdClear();
void lcdWriteData(char data);
void lcdSetCursor(char a, char b);
void lcdExecCmd(char cmd);
void lcdWrite(char data);


#endif	/* BINARY_CONVERTER_H */

