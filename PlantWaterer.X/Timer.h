/* 
 * File:   Timer.h
 * Author: luke3
 *
 * Created on March 18, 2021, 2:57 PM
 */

#ifndef TIMER_H
#define	TIMER_H

#include "Globals.h"

// TIme in seconds on timer
static int countTime = 0;
static int done = 0;

int getCount();

//Receive a value in minutes from main representing time
//Recieve a type value from main, 0 for wait and 1 for water
//Timer counts down the given time, resturns a 1 when done wait
//Returns a 0 when done watering
void ProcessTimer(int time);

//Initialize the timer settings and defaults
void InterInit();

//Interrupt to handle the timer
void __attribute__((interrupt(auto_psv))) _T1Interrupt(void);

#endif	/* TIMER_H */

