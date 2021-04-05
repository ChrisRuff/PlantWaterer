/* 
 * File:   override.h
 * Author: bball
 *
 * Created on April 3, 2021, 2:28 PM
 */

#ifndef OVERRIDE_H
#define	OVERRIDE_H
#include "Globals.h"

static int override;
int getOverride();
void initOverride();
void resetOverride();
void __attribute__((interrupt(auto_psv))) _CCP2Interrupt(void);

#endif	/* OVERRIDE_H */

