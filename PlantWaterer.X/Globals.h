#ifndef GLOBALS
#define	GLOBALS

#define FOSC 32000000UL
#define FCY FOSC/2
#define TCY 1/FCY
#include <xc.h> 
#include <libpic30.h>

// Define wire placements

#define LED1 LATCbits.LATC13  // PWM on MikroBus A
#define LED2 LATBbits.LATB12  // TX on MikroBus A
#define LED3 LATDbits.LATD3    // SCL on MikroBus A
#define LED4 LATDbits.LATD4   // SDA on MikroBus A  
#define LED5 LATCbits.LATC6   // SCK on MikroBus B
#define LED6 LATDbits.LATD11  // RST on MikroBus B
 
typedef struct lcd_bits
{
    unsigned int DATA : 8;
}LcdBits;


// Define wire placements
#define SEGD1  LATCbits.LATC0  // AN on MikroBus A
#define SEGA   LATCbits.LATC12  // PWM on MikroBus B
#define SEGF   LATBbits.LATB15  // INT on MikroBus B
#define SEGD2  LATBbits.LATB13  // TX on MikroBus B
#define SEGD3  LATBbits.LATB14  // RX on MikroBus B
#define SEGB   LATCbits.LATC9  // SCL on MikroBus B

#define SEGE   LATBbits.LATB9  // MOSI on MikroBus A
#define SEGD   LATBbits.LATB8  // MISO on MikroBus A
#define SEGDEC LATBbits.LATB7  // SCK on MikroBus A
#define SEGC   LATBbits.LATB2  // CS on MikroBus A
#define SEGG   LATCbits.LATC7  // RST on MikroBus A
#define SEGD4  LATCbits.LATC8  // SDA on MikroBus B
 
typedef struct seg_bits 
{
    unsigned int A : 7; // Leftmost seven seg
    unsigned int B : 7;
    unsigned int C : 7;
    unsigned int D : 7; // Rightmost seven seg
}SegBits;

// Define ADC wires
#define ADC_in TRISDbits.TRISD10  // AN on MikroBus B
#define ADC_an ANSELDbits.ANSELD10

#define IR_IN PORTCbits.RC3 // CS on MikroBus B
#endif	/* GLOBALS */

