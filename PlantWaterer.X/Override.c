//Manual Override
//Jack Shaw
//April 3rd 2021

#include "Override.h"


int getOverride()
{
    return override;
}
void resetOverride()
{
    override = 0;   
}
void initOverride(void){
      // MOSI_2 is input
    TRISCbits.TRISC1 = 1;
    ANSELCbits.ANSELC1 = 0;
}
/*
    // Set PORTC1 to be IC2
    RPINR4bits.ICM2R = 49;
    
    CCP2CON1Lbits.T32 = 1; // 32 bit capture
    CCP2CON1Lbits.CCPMOD = 1; 
    CCP2CON1Lbits.MOD = 2;
    CCP2CON1Lbits.CCPON = 1; // Turn on capture
    CCP2CON1Lbits.CCSEL = 1; // Use input
    CCP2CON2Hbits.ICS = 0;   // Use IC2, which is configured to PORTC3
    CCP2CON2Hbits.AUXOUT = 3; // Input event capture
    
    // Setup input capture interrupts
    IEC1bits.CCP2IE = 1;
    IFS1bits.CCP2IF = 0;
    IPC5bits.CCP2IP = 5;
    override=0;
}

void __attribute__((interrupt, auto_psv)) _CCP2Interrupt(void){
    override = 1;
    IFS1bits.CCP2IF=0;
}
*/

