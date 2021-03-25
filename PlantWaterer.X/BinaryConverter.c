/*
 * File:   BinaryConverter.c
 * Author: root
 *
 * Created on March 13, 2021, 10:07 PM
 */

#include "BinaryConverter.h"
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
void initSegPins()
{
    TRISCbits.TRISC0 = 0;
    TRISCbits.TRISC8 = 0;
    TRISCbits.TRISC12 = 0;
    TRISCbits.TRISC9 = 0;
    TRISCbits.TRISC7 = 0;
    TRISBbits.TRISB13 = 0;
    TRISBbits.TRISB14 = 0;
    TRISBbits.TRISB2 = 0;
    TRISBbits.TRISB8 = 0;
    TRISBbits.TRISB9 = 0;
    TRISBbits.TRISB15 = 0;
    TRISBbits.TRISB7 = 0;
}
int toDigit(char in)
{
    switch(in)
    {
        case 0:
            return 0b1111110 ^ 127;
            break;
        case 1:
            return 0b0110000 ^ 127;
            break;
        case 2:
            return 0b1101101 ^ 127;
            break;
        case 3:
            return 0b1111001 ^ 127;
            break;
        case 4:
            return 0b0110011 ^ 127;
            break;
        case 5:
            return 0b1011011 ^ 127;
            break;
        case 6:
            return 0b1011111 ^ 127;
            break;
        case 7:
            return 0b1110000 ^ 127;
            break;
        case 8:
            return 0b1111111 ^ 127;
            break;
        case 9:
            return 0b1111011 ^ 127;
            break;
        default:
            return 0b1111111 ^ 127;
    }
}

SegBits toSevenSegment(int time)
{
    // Convert binary value to time in seconds based on clock speed
    char mins = time / 60;
    char secs = time % 60;
    char A = mins / 10 % 10;
    char B = mins % 10;
    //char D = time / 1000 % 10;
    //char C = time / 100 % 10;
    char C = secs / 10 % 10;
    char D = secs % 10;
    
    SegBits outBits;
    outBits.A = toDigit(A);
    outBits.B = toDigit(B);
    outBits.C = toDigit(C);
    outBits.D = toDigit(D);
    return outBits;
}
LcdBits toLCD(int binary)
{
    LcdBits b;
    return b;
}


void toDisplay(int binary)
{
    SegBits segs = toSevenSegment(binary);
    int i;
    for(i = 0; i < 4; ++i)
    {
        
        switch(i) 
        {
            case 0: 
                SEGD1=1;
                SEGD2=0; 
                SEGD3=0; 
                SEGD4=0; 
                SEGA = (segs.A & ( 1 << 7-1 )) != 0;
                SEGB = (segs.A & ( 1 << 6-1 )) != 0;
                SEGC = (segs.A & ( 1 << 5-1 )) != 0;
                SEGD = (segs.A & ( 1 << 4-1 )) != 0;
                SEGE = (segs.A & ( 1 << 3-1 )) != 0;
                SEGF = (segs.A & ( 1 << 2-1 )) != 0;
                SEGG = (segs.A & ( 1 << 1-1 )) != 0;
                break;
            case 1: 
                SEGD2=1; 
                SEGD1=0;
                SEGD3=0; 
                SEGD4=0; 
                SEGA = (segs.B & ( 1 << 7-1 )) != 0;
                SEGB = (segs.B & ( 1 << 6-1 )) != 0;
                SEGC = (segs.B & ( 1 << 5-1 )) != 0;
                SEGD = (segs.B & ( 1 << 4-1 )) != 0;
                SEGE = (segs.B & ( 1 << 3-1 )) != 0;
                SEGF = (segs.B & ( 1 << 2-1 )) != 0;
                SEGG = (segs.B & ( 1 << 1-1 )) != 0;
                SEGDEC = 1;
                break;
            case 2: 
                SEGD3=1;
                SEGD1=0;
                SEGD2=0; 
                SEGD4=0; 
                SEGA = (segs.C & ( 1 << 7-1 )) != 0;
                SEGB = (segs.C & ( 1 << 6-1 )) != 0;
                SEGC = (segs.C & ( 1 << 5-1 )) != 0;
                SEGD = (segs.C & ( 1 << 4-1 )) != 0;
                SEGE = (segs.C & ( 1 << 3-1 )) != 0;
                SEGF = (segs.C & ( 1 << 2-1 )) != 0;
                SEGG = (segs.C & ( 1 << 1-1 )) != 0;
                break;
            case 3: 
                SEGD1=0;
                SEGD2=0; 
                SEGD3=0; 
                SEGD4=1;
                SEGA = (segs.D & ( 1 << 7-1 )) != 0;
                SEGB = (segs.D & ( 1 << 6-1 )) != 0;
                SEGC = (segs.D & ( 1 << 5-1 )) != 0;
                SEGD = (segs.D & ( 1 << 4-1 )) != 0;
                SEGE = (segs.D & ( 1 << 3-1 )) != 0;
                SEGF = (segs.D & ( 1 << 2-1 )) != 0;
                SEGG = (segs.D & ( 1 << 1-1 )) != 0;
        }
        __delay_ms(5);
    }
}
