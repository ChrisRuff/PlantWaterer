/*
 * File:   IR.c
 * Author: root
 *
 * Created on March 24, 2021, 11:45 PM
 */

#include "IR.h"

int getCommand()
{
    return command;
}
void resetCommand() { command = 0; }
void setupIR()
{
    // RST_2 is input
    TRISCbits.TRISC3 = 1;
   
    // Set Change notification interrupt enable and edge select for PORTD
    CNCONDbits.ON = 1;
    CNCONDbits.CNSTYLE = 0;
    CNEN0Cbits.CNEN0C3 = 1;
    CNEN1Cbits.CNEN1C3 = 0;
    
    // Setup Change notification interrupts
    IEC1bits.CNCIE = 1;
    IFS1bits.CNCIF = 0;
    IPC4bits.CNCIP = 7;
    command = 0;
}
void parseIR()
{
    int time = TMR1;
    int n;
    int bits[12];
    for(n = 0; n < 12; ++n)
    {
        while(PORTDbits.RD11);
        TMR1 = 0;
        while(PORTDbits.RD11 && TMR1 < 10000);
        bits[n] = TMR1;
    }
    TMR1 = time;
    command = 1;
    if(bits[6] > 3000) command += 64;
    if(bits[5] > 3000) command += 32;
    if(bits[4] > 3000) command += 16;
    if(bits[3] > 3000) command += 8;
    if(bits[2] > 3000) command += 4;
    if(bits[1] > 3000) command += 2;
    if(bits[0] > 3000) command += 1;
    printf("Command: %d", command);
}
void __attribute__((interrupt, no_auto_psv)) _CNDInterrupt( void )
{
    parseIR();
    IFS4bits.CNDIF = 0;
}

