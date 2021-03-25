/*
 * File:   Motor.c
 * Author: root
 *
 * Created on March 25, 2021, 3:08 PM
 */

#include "Motor.h"
void initMotor()
{
    MPER = 0xFFFF;
    MPHASE = 2000;
   
}
void openValve()
{
    CMBTRIGLbits.CTA1EN = 1;
}
void closeValve()
{
    
}
