/*
 * File:   BinaryConverter.c
 * Author: root
 *
 * Created on March 13, 2021, 10:07 PM
 */

#include "BinaryConverter.h"

int toDigit(char in)
{
    switch(in)
    {
        case 0:
            return 0b1111110;
            break;
        case 1:
            return 0b0110000;
            break;
        case 2:
            return 0b1101101;
            break;
        case 3:
            return 0b1111001;
            break;
        case 4:
            return 0b0110011;
            break;
        case 5:
            return 0b1011011;
            break;
        case 6:
            return 0b1011111;
            break;
        case 7:
            return 0b1110000;
            break;
        case 8:
            return 0b1111111;
            break;
        case 9:
            return 0b1111011;
            break;
        default:
            return 0b1111111;
    }
}

SegBits toSevenSegment(int binary)
{
    // Convert binary value to time in seconds based on clock speed
    int time = TIMER_PERIOD * binary;
    char A = time / 1000 % 10;
    char B = time / 100 % 10;
    char C = time / 10 % 10;
    char D = time % 10;
    
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
    SEGD1=0;
    SEGD2=0;
    SEGD3=0;
    SEGD4=0;
    for(i = 0; i < 4; ++i)
    {
        switch(i) 
        {
            case 0: 
                SEGD1=1;
                SEGD3=0; 
                SEGA = (segs.A & ( 1 << 7 )) >> 7;
                SEGB = (segs.A & ( 1 << 6 )) >> 6;
                SEGC = (segs.A & ( 1 << 5 )) >> 5;
                SEGD = (segs.A & ( 1 << 4 )) >> 4;
                SEGE = (segs.A & ( 1 << 3 )) >> 3;
                SEGF = (segs.A & ( 1 << 2 )) >> 2;
                SEGG = (segs.A & ( 1 << 1 )) >> 1;
                break;
            case 1: 
                SEGD2=1;
                SEGD1=0; 
                SEGA = (segs.B & ( 1 << 7 )) >> 7;
                SEGB = (segs.B & ( 1 << 6 )) >> 6;
                SEGC = (segs.B & ( 1 << 5 )) >> 5;
                SEGD = (segs.B & ( 1 << 4 )) >> 4;
                SEGE = (segs.B & ( 1 << 3 )) >> 3;
                SEGF = (segs.B & ( 1 << 2 )) >> 2;
                SEGG = (segs.B & ( 1 << 1 )) >> 1;
                SEGDEC = 1;
                break;
            case 2: 
                SEGD3=1;
                SEGD2=0; 
                SEGA = (segs.C & ( 1 << 7 )) >> 7;
                SEGB = (segs.C & ( 1 << 6 )) >> 6;
                SEGC = (segs.C & ( 1 << 5 )) >> 5;
                SEGD = (segs.C & ( 1 << 4 )) >> 4;
                SEGE = (segs.C & ( 1 << 3 )) >> 3;
                SEGF = (segs.C & ( 1 << 2 )) >> 2;
                SEGG = (segs.C & ( 1 << 1 )) >> 1;
            case 3: 
                SEGD4=1;
                SEGD3=0; 
                SEGA = (segs.D & ( 1 << 7 )) >> 7;
                SEGB = (segs.D & ( 1 << 6 )) >> 6;
                SEGC = (segs.D & ( 1 << 5 )) >> 5;
                SEGD = (segs.D & ( 1 << 4 )) >> 4;
                SEGE = (segs.D & ( 1 << 3 )) >> 3;
                SEGF = (segs.D & ( 1 << 2 )) >> 2;
                SEGG = (segs.D & ( 1 << 1 )) >> 1;
        }
        
        __delay_ms(5);
    }
}
