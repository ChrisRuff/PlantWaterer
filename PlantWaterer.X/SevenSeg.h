/* 
 * File:   SevenSeg.h
 * Author: burt
 *
 * Created on March 17, 2021, 1:08 PM
 */

#ifndef SevenSeg_H
#define	SevenSeg_H

#include "Globals.h"


/**
 * Transfer data from seg_bits to signals
 * @param seg_bits struct containing data
 */
void sevenSegOut (SegBits data, int en);

#ifdef	__cplusplus
extern "C" {
#endif


#ifdef	__cplusplus
}
#endif

#endif	/* SevenSeg_H */

