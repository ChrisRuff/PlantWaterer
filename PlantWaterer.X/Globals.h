#ifndef GLOBALS
#define	GLOBALS

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


// Define wire placements
#define SEGD1  LATCbits.LATC0  // AN on MikroBus A
#define SEGD2  LATBbits.LATB13  // TX on MikroBus B
#define SEGD3  LATBbits.LATB14  // RX on MikroBus B
#define SEGD4  LATCbits.LATC8  // SDA on MikroBus B
#define SEGA   LATCbits.LATC12  // PWM on MikroBus B
#define SEGB   LATCbits.LATC9  // SCL on MikroBus B
#define SEGC   LATBbits.LATB2  // CS on MikroBus A
#define SEGD   LATBbits.LATB8  // MISO on MikroBus A
#define SEGE   LATBbits.LATB9  // MOSI on MikroBus A
#define SEGF   LATBbits.LATB15  // INT on MikroBus B
#define SEGG   LATCbits.LATC7  // RST on MikroBus A
#define SEGDEC LATBbits.LATB7  // SCK on MikroBus A
 
typedef struct seg_bits 
{
    unsigned int A : 7; // Leftmost seven seg
    unsigned int B : 7;
    unsigned int C : 7;
    unsigned int D : 7; // Rightmost seven seg
}SegBits;
#endif	/* GLOBALS */

