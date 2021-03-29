/*
 * File:   IR.c
 * Author: root
 *
 * Created on March 24, 2021, 11:45 PM
 */

#include "Globals.h"
#include "ADC.h"

void setupADC()
{
    ANSELBbits.ANSELB2 = 1; // AN1 connected the dedicated core 1
    TRISBbits.TRISB2 = 1;   // Set CS_1 as input
    ADCON3Hbits.CLKSEL = 1;  // Set ADC clock to FOSC
    ADCON3Hbits.CLKDIV = 0;  // No clock division (1:1)
    //ADCORE1Hbits.ADCS = 0; // ADC core 0 clock = FOSC/2
    //ADCORE1Hbits.RES = 0;
    ADCON3Lbits.REFSEL = 0;
    ADCON1Hbits.FORM = 0;    // Set output format to integer
    ADMOD0Lbits.SIGN1 = 0;
    ADMOD0Lbits.DIFF1 = 0;    
    ADCON4Hbits.C1CHS = 0;
    // Turn on ADC module
    ADCON1Lbits.ADON = 1;
    // Turn on analog power for dedicated core 1
    ADCON5Lbits.C1PWR = 1;
    // Wait when the core 1 is ready for operation
    while(ADCON5Lbits.C1RDY == 0);
    // Turn on digital power to enable triggers to the core 1 
    ADCON3Hbits.C1EN = 1;
    ADIELbits.IE1 = 1; // Enable interrupt for AN1
    _ADCAN1IF = 0; // Clear interrupt flag for AN1
    _ADCAN1IE = 1; // Enable interrupt for AN1
    //ADCON3Lbits.CNVCHSEL = 0;
    //ADTRIG0Lbits.TRGSRC1 = 1;
}

