/*
 * File:   ADC.c
 * Author: Reid Hurlburt
 *
 * Created on March 24, 2021, 11:45 PM
 */

#include "Globals.h"
#include "ADC.h"

void setupADC()
{
    ADCON1L = 0x8000;
    ADCON1H = 0x0;
    ADCON2L = 0x0;
    ADCON2H = 0x0;
    ADCON3L = 0x0212;
    ADCON3H = 0x4080;
    ADCON4L = 0x0;
    ADCON4H = 0x0;
    ADCON5L = 0x80;
    ADCON5H = 0x80;
    ADMOD0L = 0x0;
    ADMOD0H = 0x0;
    ADMOD1L = 0x0;
    ADMOD1H = 0x0;
    ADIEL = 0x0;
    ADIEH = 0x0;
    ADC_an = 1;
    ADC_in = 1;
}

void triggerADC()
{
    ADCON3Lbits.CNVRTCH = 1;
}

unsigned short readADC()
{
    while(ADSTATHbits.AN18RDY!=1);
    return ADCBUF18;
}
