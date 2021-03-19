/* 
 * File:   Timer.h
 * Author: luke3
 *
 * Created on March 18, 2021, 2:57 PM
 */

#ifndef TIMER_H
#define	TIMER_H

#define FOSC 32000000UL
#define FCY FOSC/2
#include <xc.h> 
#include <libpic30.h>

//Receive a value in minutes from main representing time
//Recieve a type value from main, 0 for wait and 1 for water
//Timer counts down the given time, resturns a 1 when done wait
//Returns a 0 when done watering
int ProcessTimer(int time, int type);




//Initialize the timer settings and defaults
void InterInit();


//Interrupt to handle the timer
void __attribute__((interrupt(auto_psv))) _T1Interrupt(void);


#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* TIMER_H */

