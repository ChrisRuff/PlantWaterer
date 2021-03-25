/*
 * File:   Timer.c
 * Author: root
 *
 * Created on March 18, 2021, 3:03 PM
 * 
 */

#include "Timer.h"

int getCount() { return countTime; }

void ProcessTimer(int time)
{
    countTime = time*60;
    done = 0;
    InterInit();
}


void InterInit(){
    T1CONbits.TECS=1;       //Timer1 TCY
    T1CONbits.TCS=1;        //Timer1 use external clock 
    T1CONbits.TCKPS=3;      //Timer1 prescale 1:256
    T1CONbits.TSYNC=0;      //Timer1 Sycnronize the clock
    IFS0bits.T1IF=0;        //reset interrupt flag
    IEC0bits.T1IE=1;        //enable _TimerInterrupt
    TMR1=0x0;               //ensure timer register is cleared
    PR1=FCY/256;             //count period, 1 second delay
    T1CONbits.TON=1;        //Timer1 enable
}

void __attribute__((interrupt(auto_psv))) _T1Interrupt(void){
    if(countTime == 0){
        done = 1;
        IFS0bits.T1IF = 0;
        T1CONbits.TON = 0;
        return;
    }
    countTime --;
    PR1 = 0xF424;
    IFS0bits.T1IF = 0;
}


