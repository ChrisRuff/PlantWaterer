/*
 * File:   Motor.c
 * Author: Chris
 *
 * Created on March 25, 2021, 3:08 PM
 */

#include "Motor.h"
void initMotor()
{
    PG5CONLbits.ON = 0; // Turn off PWM
    
    TRISCbits.TRISC5 = 0; // Set PWM pins to outputs
    TRISCbits.TRISC4 = 0; 
    
    MPER = 10000;
    MPHASE = 0;
    MDC = MPER / 4; // 25% Duty cycle
    
    PG5CONHbits.MDCSEL = 1;  // Use MPER, MPHASE, and MDC
    PG5CONHbits.MPERSEL = 1;
    PG5CONHbits.MPHSEL = 1;
    PG5CONHbits.TRGMOD = 0;
    
    PCLKCONbits.MCLKSEL = 0; // Use FOSC
    PG5CONLbits.HREN = 1;
    PG5CONLbits.MODSEL = 0; // Use independant edge mode
    
    PG5IOCONHbits.PMOD = 1;
    PG5IOCONHbits.PENH = 1;
    PG5IOCONHbits.PENL = 1;
    
    PG5IOCONLbits.OVRENH = 0;
    PG5IOCONLbits.OVRENL = 0;
}
void openValve()
{
    PG5CONLbits.ON = 1;
}
void closeValve()
{
    PG5CONLbits.ON = 0; 
}
