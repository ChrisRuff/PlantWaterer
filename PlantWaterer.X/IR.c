/*
 * File:   IR.c
 * Author: root
 *
 * Created on March 24, 2021, 11:45 PM
 */
#include "IR.h"

int getCommand() 
{ 
    switch(command)
    {
        case 0x6897:
            return 0;
        case 0x30CF:
            return 1;
        case 0x18E7: 
            return 2;
        case 0x7A85: 
            return 3;
        case 0x10EF: 
            return 4;
        case 0x38C7: 
            return 5;
        case 0x5AA5: 
            return 6;
        case 0x42BD: 
            return 7;
        case 0x4AB5: 
            return 8;
        case 0x52AD: 
            return 9;
        default: 
            return -1;

    }
}
void resetCommand() { command = -1; }
void setupIR()
{
    // CS_2 is input
    TRISCbits.TRISC3 = 1;
    ANSELCbits.ANSELC3 = 0;
    
    // Set PORTC3 to be IC1
    RPINR3bits.ICM1R = 51;
    
    CCP1CON1Lbits.T32 = 1; // 32 bit capture
    CCP1CON1Lbits.CCPMOD = 1; 
    CCP1CON1Lbits.CCPON = 1; // Turn on capture
    CCP1CON1Lbits.CCSEL = 1; // Use input
    CCP1CON2Hbits.ICS = 0;   // Use IC1, which is configured to PORTC3
    CCP1CON2Hbits.AUXOUT = 3; // Input event capture
    
    // Setup input capture interrupts
    IEC0bits.CCP1IE = 1;
    IFS0bits.CCP1IF = 0;
    IPC1bits.CCP1IP = 7;
    command = -1;
}
void parseIR()
{   
    if(command != -1) // If the command hasn't been reset don't overwrite
        return;
    
    // Check 4.5ms space (remote control sends logic low)
    int c = 0;
    while(IR_IN && (c <= 90)) { c++; __delay_us(50); }
    if((c > 90) || (c < 40)) return;
    
    int n;
    for(n = 0; n < 32; ++n)
    {
        c = 0;
        while(!IR_IN && (c <= 23)){ c++; __delay_us(50); }
        if((c > 22) || (c < 4)) return;
        
        c = 0;;
        while(IR_IN && (c <= 45)){ c++; __delay_us(50); }
        if((c > 44) || (c < 8)) return;
        
        // If width is more than 1ms then write 1, else 0
        if(c > 21) 
        {
            command |= 1ul << (31-n);
        }
        else
        {
            command &= ~(1ul << (31-n));
        }
        
    }
    printf("Command: %d\n", command);
}
void __attribute__((interrupt, auto_psv)) _CCP1Interrupt(void)
{
    parseIR();
    IFS0bits.CCP1IF = 0;
}
