/*
 * File:   Alarm.c
 * Author: Chris
 *
 * Created on April 5, 2021, 2:35 PM
 */

#include "Alarm.h"
void initSpeaker()
{
    //Speaker
    TRISDbits.TRISD15 = 0; // Set as output

    //Configure the source clock for the APLL
    ACLKCON1bits.FRCSEL = 1;
    // Configure the APLL prescalar, APLL feedback divider, and both APLL postscalars
    ACLKCON1bits.APLLPRE = 1; //N1 = 1
    APLLFBD1bits.APLLFBDIV = 125; // M = 125
    APLLDIV1bits.APOST1DIV = 2; // N2 = 2
    APLLDIV1bits.APOST2DIV = 1; // N3 = 1
    // Enable APLL
    ACLKCON1bits.APLLEN = 1;

    //Setup the DAC
    DACCTRL1Lbits.CLKSEL = 2;
    DACCTRL1Lbits.DACON = 1;
    DAC1CONLbits.DACEN = 1;
    DAC1CONLbits.DACOEN = 1;

    //Use Triangle Waves for the DAC
    SLP1DATbits.SLPDAT = 0x2; // Slope rate, counts per step
    SLP1CONHbits.TWME = 1;
    SLP1CONHbits.SLOPEN = 1;
}
void soundOpenAlarm()
{
    DAC1DATHbits.DACDAT = 0xDFF; // Upper data value
    LATDbits.LATD15 = 1;
    __delay_ms(150);
    LATDbits.LATD15 = 0;
    DAC1DATHbits.DACDAT = 0xD32; // Upper data value
    __delay_ms(150);
    LATDbits.LATD15 = 1;
    __delay_ms(200);
    LATDbits.LATD15 = 0;
    __delay_ms(150);
    LATDbits.LATD15 = 1;
    __delay_ms(200);
    LATDbits.LATD15 = 0;
}
void soundCloseAlarm()
{
    DAC1DATHbits.DACDAT = 0xD32; // Upper data value
    LATDbits.LATD15 = 1;
    __delay_ms(150);
    LATDbits.LATD15 = 0;
    DAC1DATHbits.DACDAT = 0xDFF; // Upper data value
    __delay_ms(150);
    LATDbits.LATD15 = 1;
    __delay_ms(200);
    LATDbits.LATD15 = 0;
    __delay_ms(150);
    LATDbits.LATD15 = 1;
    __delay_ms(200);
    LATDbits.LATD15 = 0;
}
