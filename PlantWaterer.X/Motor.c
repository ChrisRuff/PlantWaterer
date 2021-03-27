/*
 * File:   Motor.c
 * Author: root
 *
 * Created on March 25, 2021, 3:08 PM
 */

#include "Motor.h"
void initMotor()
{
    PG5CONLbits.ON = 0; // Turn off PWM
    
    TRISCbits.TRISC5 = 0; // Set PWM pins to outputs
    TRISCbits.TRISC4 = 0; 
    
    MPER = 20000; // 200 kHz period
    MPHASE = 50000;
    MDC = MPER / 2;
    
    PG5CONHbits.MDCSEL = 1;  // Use MPER, MPHASE, and MDC
    PG5CONHbits.MPERSEL = 1;
    PG5CONHbits.MPHSEL = 1;
    
    PCLKCONbits.MCLKSEL = 0; // Use FOSC
    PG5CONLbits.HREN = 1;
    
    
    PG5CONLbits.MODSEL = 1; // Independant edge
}
void openValve()
{
    PG5CONLbits.ON = 1;
}
void closeValve()
{
    PG5CONLbits.ON = 0; 
}
