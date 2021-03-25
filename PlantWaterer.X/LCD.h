/* 
 * File:   LCD.h
 * Author: burt
 *
 * Created on March 17, 2021, 1:08 PM
 */

#ifndef LCD_H
#define	LCD_H

#include "Globals.h"

/**
 * Transfer data from LcdBits to signals
 * @param LcdBits struct containing data
 */
void LCD_out (LcdBits data, int en);

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* LCD_H */

