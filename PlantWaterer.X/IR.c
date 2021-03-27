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
        case 0:
            return 0;
        case 0x000F:
            return 1;
        case 0x0F8C: 
            return 2;
        case 0x0FBD: 
            return 3;
        case 0x0F88: 
            return 4;
        case 0x0F9C: 
            return 5;
        case 0x0FAD: 
            return 6;
        case 0x0FA1: 
            return 7;
        case 0x0FA5: 
            return 8;
        case 0x0FA9: 
            return 9;
        default: 
            return command;
    }
}
void resetCommand() { command = 0; }
void setupIR()
{
    // CS_2 is input
    TRISCbits.TRISC3 = 1;
    ANSELCbits.ANSELC3 = 0;
    
    // Set PORTC3 to be IC1
    RPINR3bits.ICM1R = 51;
    
    CCP1CON1Lbits.T32 = 1;
    CCP1CON1Lbits.CCPMOD = 1;
    CCP1CON1Lbits.CCPON = 1;
    CCP1CON1Lbits.CCSEL = 1;
    CCP1CON2Hbits.ICS = 0;
    CCP1CON2Hbits.AUXOUT = 3;
    
    // Setup input capture interrupts
    IEC0bits.CCP1IE = 1;
    IFS0bits.CCP1IF = 0;
    IPC1bits.CCP1IP = 7;
    command = 0;
}
void parseIR()
{   
    int c = 0;
    while((IR_IN == 0) && (c < 180))
    {
        c++;
        __delay_us(50);
    }
    if( (c > 179) || (c < 120))
        return;
    
    c = 0;
    while(IR_IN && (c < 90))
    {
        c++;
        __delay_us(50);
    }
    if((c > 89) || (c < 40))
        return;
    
    int n;
    for(n = 0; n < 12; ++n)
    {
        c = 0;
        while(!IR_IN && c <= 23)
        {
            c++;
            __delay_us(50);
        }
        if(c > 23) return;
        
        c = 0;
        while(IR_IN && c <= 45)
        {
            c++;
            __delay_us(50);
        }
        if(c > 45) return;
        if(c > 21)
            command |= 1ul << (11-n);
        else
            command &= ~(1ul << (11-n));
    }
    printf("Command: %d\n", command);
}
void __attribute__((interrupt, auto_psv)) _CCP1Interrupt(void)
{
    parseIR();
    IFS0bits.CCP1IF = 0;
}
