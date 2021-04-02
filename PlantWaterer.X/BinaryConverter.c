/*
 * File:   BinaryConverter.c
 * Author: Chris
 *
 * Created on March 13, 2021, 10:07 PM
 */

#include "BinaryConverter.h"
#define DELAY 200
void initSeg()
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

void initLED()
{
    TRISCbits.TRISC6 = 0; // Set pins as output
    TRISCbits.TRISC13 = 0;
    TRISCbits.TRISC15 = 0;
    TRISBbits.TRISB12 = 0;
    TRISDbits.TRISD3 = 0;
    TRISDbits.TRISD4 = 0;
    TRISDbits.TRISD11 = 0;
    
    ANSELCbits.ANSELC6 = 0;
    ANSELDbits.ANSELD11 = 0;
    
    LED1 = 0;
    LED2 = 0;
    LED3 = 0;
    LED4 = 0;
    LED5 = 0;
    LED6 = 0;
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



void toDisplay(int time, int duration)
{
    SegBits segs = toSevenSegment(time);
    
    segUpload(segs);
    ledUpload(duration);
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
    segUpload(segs);
}
void pourDisplay(int remaining)
{
    SegBits segs;
    segs.A = toDigit(11);
    segs.B = toDigit(12);
    segs.C = toDigit(13);
    segs.D = toDigit(14);
    segUpload(segs);
    ledUpload(remaining);
}


void segUpload(SegBits segs)
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
void ledUpload(int duration)
{
    LED1 = 0;
    LED2 = 0;
    LED3 = 0;
    LED4 = 0;
    LED5 = 0;
    LED6 = 0;
    switch(duration/10)
    {
        case 6:
            LED6 = 1;
        case 5:
            LED5 = 1;
        case 4:
            LED4 = 1;
        case 3:
            LED3 = 1;
        case 2:
            LED2 = 1;
        case 1:
            LED1 = 1;
        default:
            break;
    }
}

/*
void toLCD(int time, int duration, LcdBits* lcds)
{
    // Convert binary value to time in seconds based on clock speed
    char mins = time / 60;
    char secs = time % 60;
    
    lcds[0].DATA = 'T';
    lcds[1].DATA = ':';
    lcds[2].DATA = ' ';
    lcds[3].DATA = mins / 60 % 10 + '0';
    lcds[4].DATA = mins % 10 + '0';
    lcds[5].DATA = secs / 60 % 10 + '0';
    lcds[6].DATA = secs % 10 + '0';
    lcds[7].DATA = ' ';
    lcds[8].DATA = 'D';
    lcds[9].DATA = 'u';
    lcds[10].DATA = 'r';
    lcds[11].DATA = ':';
    lcds[12].DATA = ' ';
    lcds[13].DATA = duration / 10 + '0';
    lcds[14].DATA = duration % 10 + '0';
    lcds[15].DATA = ' ';
    
    return lcds;
}
void lcdUpload(LcdBits* lcds)
{
    int i;
    for(i = 0; i < 16; ++i)
    {
        if(i == 15)
            lcdExecCmd(0xc0); // new line
        lcdWriteData(lcds[i].DATA);
        
    }
}
void lcdExecCmd(char cmd)
{
    LCDRS = 0;
    lcdWrite(cmd);
    
    if(cmd == 0x01 || cmd == 0x02) 
        __delay_ms(1000);
}
void lcdWriteData(char data)
{
    LCDRS = 1;
    lcdWrite(data);
}
void lcdWrite(char data)
{
    LCD4 = (data >> 4) & 0x1; // Send higher nibble
    LCD5 = (data >> 5) & 0x1;
    LCD6 = (data >> 6) & 0x1;
    LCD7 = (data >> 7) & 0x1;
    
    LCDEN = 1; // Send high to low pulse
    __delay_us(DELAY);
    LCDEN = 0;
    __delay_us(DELAY);
    
    LCD4 = data & 0x1;        // Send lower nibble
    LCD5 = (data >> 1) & 0x1;
    LCD6 = (data >> 2) & 0x1;
    LCD7 = (data >> 3) & 0x1;
    
    LCDEN = 1; // Send high to low pulse
    __delay_us(DELAY);
    LCDEN = 0;
    __delay_us(DELAY);
}
void lcdClear()
{
    lcdExecCmd(0); // Wipe the screen
    lcdExecCmd(1); // Move to position 1
}
void lcdSetCursor(char a, char b)
{
    if(a == 1)
    {
        lcdExecCmd(0x80 + b - 1);
    }
    else
    {
        lcdExecCmd(0xC0 + b - 1);
    }
}
*/