/*
 * File:   BinaryConverter.c
 * Author: root
 *
 * Created on March 13, 2021, 10:07 PM
 */

#include "BinaryConverter.h"

void initSeg()
{
    TRISCbits.TRISC0 = 0;
    TRISCbits.TRISC8 = 0;
    TRISCbits.TRISC12 = 0;
    TRISCbits.TRISC9 = 0;
    TRISCbits.TRISC7 = 0;
    TRISBbits.TRISB13 = 0;
    TRISBbits.TRISB14 = 0;
    //TRISBbits.TRISB2 = 0;
    TRISBbits.TRISB8 = 0;
    TRISBbits.TRISB9 = 0;
    TRISBbits.TRISB15 = 0;
    TRISBbits.TRISB7 = 0;
}
void initLCD()
{
}
int toDigit(char in)
{
    switch(in)
    {
        case 0:
            return 0b1111110 ^ 127;
        case 1:
            return 0b0110000 ^ 127;
        case 2:
            return 0b1101101 ^ 127;
        case 3:
            return 0b1111001 ^ 127;
        case 4:
            return 0b0110011 ^ 127;
        case 5:
            return 0b1011011 ^ 127;
        case 6:
            return 0b1011111 ^ 127;
        case 7:
            return 0b1110000 ^ 127;
        case 8:
            return 0b1111111 ^ 127;
        case 9:
            return 0b1111011 ^ 127;
        case 10: // '-'
            return 0b0000001 ^ 127;
        case 11: // 'P'
            return 0b1100111 ^ 127;
        case 12: // 'O'
            return 0b1111110 ^ 127;
        case 13: // 'U'
            return 0b0111110 ^ 127;
        case 14: // 'R'
            return 0b1100110 ^ 127;
        default:
            return 0b1111111 ^ 127;
    }
}


SegBits toSevenSegment(int time)
{
    char A,B,C,D;
    if(time == -1) // "----"
    {
        A = 10;
        B = 10;
        C = 10; 
        D = 10;
    }
    else if(time == -2) // "POUR"
    {
        A = 11;
        B = 12;
        C = 13; 
        D = 14;  
    }
    else
    {
        // Convert binary value to time in seconds based on clock speed
        char mins = time / 60;
        char secs = time % 60;
        A = mins / 10 % 10;
        B = mins % 10;
        //char D = time / 1000 % 10;
        //char C = time / 100 % 10;
        C = secs / 10 % 10;
        D = secs % 10;
    }
    
    
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
    upload(segs);
}
void irDisplay(int* commands, int n)
{
    SegBits segs;
    switch(n)
    {
        case 1:
            segs.D = toDigit(commands[0]);
            segs.C = toDigit(10);
            segs.B = toDigit(10);
            segs.A = toDigit(10);
            break;
        case 2:
            segs.D = toDigit(commands[1]);
            segs.C = toDigit(commands[0]);
            segs.B = toDigit(10);
            segs.A = toDigit(10);
            break;
        case 3:
            segs.D = toDigit(commands[2]);
            segs.C = toDigit(commands[1]);
            segs.B = toDigit(commands[0]);
            segs.A = toDigit(10);
            break;
        default:
            segs.D = toDigit(commands[3]);
            segs.C = toDigit(commands[2]);
            segs.B = toDigit(commands[1]);
            segs.A = toDigit(commands[0]);
            break;
    }
    upload(segs);
}
void pourDisplay()
{
    SegBits segs;
    segs.A = toDigit(11);
    segs.B = toDigit(12);
    segs.C = toDigit(13);
    segs.D = toDigit(14);
    upload(segs);
}
void upload(SegBits segs)
{
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
    SEGD1=0;
    SEGD2=0; 
    SEGD3=0; 
    SEGD4=0; 
}