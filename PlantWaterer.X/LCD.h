/* 
 * File:   LCD.h
 * Author: burt
 *
 * Created on March 17, 2021, 1:08 PM
 */

#ifndef LCD_H
#define	LCD_H

#define FOSC 32000000UL
#define FCY FOSC/2
#define TIMER_PERIOD 1/FCY
#include <xc.h> 
#include <libpic30.h>

// Define wire placements

#define LCD4 LATCbits.LATC6   // SCK on MikroBus B
#define LCD5 LATCbits.LATC2   // MISO on MikroBus B
#define LCD6 LATCbits.LATC1    // MOSI on MikroBus B
#define LCD7 LATDbits.LATD10    // AN on MikroBus B
#define LCDRS LATCbits.LATC3   // CS on MikroBus B
#define LCDEN LATDbits.LATD11  // RST on MikroBus B
 
typedef struct lcd_bits
{
    unsigned int RS : 1;
    unsigned int EN : 1;
    unsigned int DATA : 8;
}LcdBits;

/**
 * Transfer data from LcdBits to signals
 * @param LcdBits struct containing data
 */
void LCD_out (LcdBits data);

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* LCD_H */

