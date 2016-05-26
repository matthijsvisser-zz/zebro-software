#ifndef MAIN_H_
#define MAIN_H_

#define F_CPU 32000000UL
//#define PERIOD (3199631/369) //PERIOD= 32000000/(x+1)
//#define DUTY 0.5*PERIOD

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include <util/delay.h>
#include <string.h>
#include "clk.h"



void TranslateMessage (void);

#endif /* MAIN_H_ */