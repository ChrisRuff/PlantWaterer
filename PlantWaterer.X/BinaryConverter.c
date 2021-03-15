/*
 * File:   BinaryConverter.c
 * Author: root
 *
 * Created on March 13, 2021, 10:07 PM
 */

#include <BinaryConverter.h>

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

SegBits toSevenSegment(int binary);
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
int toLCD(int binary)
{
    return 0;
}
