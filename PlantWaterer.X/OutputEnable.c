
/*
 * File:   OutputEnable.c
 * Author: Reid
 *
 * Created on March 17, 2021, 1:54 PM
 */

#include "LCD.h"
#include "SevenSeg.h"
#include "stdbool.h"

/**
 * Transfer data from LcdBits to signals
 * @param LcdBits struct containing data
 * @param en boolean turning output on/off
 */
void LCD_out(LcdBits data, int en)
{
    if (en==true)
    {
        switch (data.DATA) 
        {
            case 0:
                //output 0
                break;
            case 1:
                //output 1
                break;
            case 2:
                //output 2
                break;
            case 3:
                //output 3
                break;
            case 4:
                //output 4
                break;
            case 5:
                //output 5
                break;
            case 6:
                //output 6
                break;
            case 7:
                //output 7
                break;
            case 8:
                //output 8
                break;
            case 9:
                //output 9
                break;
        }
    }
    else 
    {
        //Output nothing
    }
}

/**
 * Transfer data from seg_bits to signals
 * @param seg_bits struct containing data
 * @param en boolean turning output on/off
 */
void sevenSegOut (SegBits data, int en)
{
    if (en==true)
    {
        switch (data.A) 
        {
            case 0:
                //output 0
                break;
            case 1:
                //output 1
                break;
            case 2:
                //output 2
                break;
            case 3:
                //output 3
                break;
            case 4:
                //output 4
                break;
            case 5:
                //output 5
                break;
            case 6:
                //output 6
                break;
            case 7:
                //output 7
                break;
            case 8:
                //output 8
                break;
            case 9:
                //output 9
                break;
        }
        switch (data.B) 
        {
            case 0:
                //output 0
                break;
            case 1:
                //output 1
                break;
            case 2:
                //output 2
                break;
            case 3:
                //output 3
                break;
            case 4:
                //output 4
                break;
            case 5:
                //output 5
                break;
            case 6:
                //output 6
                break;
            case 7:
                //output 7
                break;
            case 8:
                //output 8
                break;
            case 9:
                //output 9
                break;
        }
        switch (data.C) 
        {
            case 0:
                //output 0
                break;
            case 1:
                //output 1
                break;
            case 2:
                //output 2
                break;
            case 3:
                //output 3
                break;
            case 4:
                //output 4
                break;
            case 5:
                //output 5
                break;
            case 6:
                //output 6
                break;
            case 7:
                //output 7
                break;
            case 8:
                //output 8
                break;
            case 9:
                //output 9
                break;
        }
        switch (data.D) 
        {
            case 0:
                //output 0
                break;
            case 1:
                //output 1
                break;
            case 2:
                //output 2
                break;
            case 3:
                //output 3
                break;
            case 4:
                //output 4
                break;
            case 5:
                //output 5
                break;
            case 6:
                //output 6
                break;
            case 7:
                //output 7
                break;
            case 8:
                //output 8
                break;
            case 9:
                //output 9
                break;
        }
    }
    else 
    {
        //Output nothing
    }
    
}
