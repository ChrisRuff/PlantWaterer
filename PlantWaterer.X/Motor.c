/*
 * File:   Motor.c
 * Author: Chris Ruff
 *
 * Created on March 25, 2021, 3:08 PM
 */

#include "Motor.h"
void initMotor()
{
    /*PWM control register configuration*/
    
    /* Motor uses FRCDIVN, we'll set it to 1MHz*/
    CLKDIVbits.FRCDIV = 1; // 8MHz FRC divided by 2 = 4MHz
    PCLKCONbits.DIVSEL = 0b01; // 1:4 divide ratio -> 4MHz / 4 = 1MHz
    PCLKCONbits.MCLKSEL = 0;   // Use FOSC
    PG1CONLbits.CLKSEL = 1;    // Use FOSC
    
    PG1CONLbits.MODSEL = 0b000; /*Independent edge triggered mode */
    
    
    PG1IOCONHbits.PMOD = 1; // Independant mode
    PG1IOCONHbits.PENH = 1; // Controls the PWM1H pin
    
    /*PWM uses PG1DC, PG1PER, PG1PHASE registers*/
    /*PWM Generator does not broadcast UPDATE status bit state or EOC signal*/
    /*Update the data registers at start of next PWM cycle (SOC) */
    /*PWM Generator operates in Single Trigger mode*/
    /*Start of cycle (SOC) = local EOC*/
    /*Write to DATA REGISTERS*/
    PG1CONH = 0x0000;
    
    // Period of 20000 * (1/1MHz) = 20ms for servo motor
    PG1PER = 20000; 
    PG1DC = PG1PER * 0.50; /* 50% duty - 180 degrees - Start Closed*/
    PG1PHASE = 0; /*Phase offset in rising edge of PWM*/
    PG1DTH = 0; /*Dead time on PWMH */
    PG1DTL = 0; /*Dead time on PWML*/
    PG1CONLbits.ON = 1; // Start PWM
}
void openValve()
{
    soundOpenAlarm();
    PG1CONLbits.ON = 0;
    __delay_ms(5);
    PG1DC = (int)(PG1PER * 0.1); /* 10% duty - 0 degrees*/
    __delay_ms(5);
    PG1CONLbits.ON = 1;
}
void closeValve()
{
    soundCloseAlarm();
    PG1CONLbits.ON = 0;
    __delay_ms(5);
    PG1DC = (int)(PG1PER * 0.50); /* 50% duty - 180 degrees*/
    __delay_ms(5);
    PG1CONLbits.ON = 1;
}
