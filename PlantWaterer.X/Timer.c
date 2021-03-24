/*
 * File:   Timer.c
 * Author: root
 *
 * Created on March 18, 2021, 3:03 PM
 * 
 */

#include "Timer.h"

int countTime = 0;
int done = 0;

int ProcessTimer(int time, int type){
    countTime = time*60;
    InterInit();
    while(done = 0){
        
    }
    if(type = 0){
        return 1;
    }
    else{
        return 0;
    }
    
}


void InterInit(){
    T1CON=0; //clear controller
    T1CONbits.TON=1;        //Timer1 enable
    T1CONbits.TECS=1;       //Timer1 Extended Clock
    T1CONbits.TCS=1;        //Timer1 clock source
    T1CONbits.TCKPS=3;      //Timer1 Input Clock Prescale
    T1CONbits.TSYNC=0;      //Timer1 External Clock Input Synchronization
    IFS0bits.T1IF=0;        //reset interrupt flag
    IEC0bits.T1IE=1;        //enable _TimerInterrupt
    TMR1=0x0;               //ensure timer register is cleared
    PR1=0xF424;             //count period, 1 second delay
}

void __attribute__((interrupt(auto_psv))) _T1Interrupt(void){
    if(countTime = 0){
        done = 1;
        IFS0bits.T1IF = 0;
        T1CONbits.TON = 0;
        return;
    }
    countTime --;
    IFS0bits.T1IF = 0;
    PR1 = 0xF424;
}


