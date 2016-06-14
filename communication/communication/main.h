#ifndef MAIN_H_
#define MAIN_H_

#ifndef F_CPU
#define F_CPU 32000000UL
#endif
//#define PERIOD (3199631/369) //PERIOD= 32000000/(x+1)
//#define DUTY 0.5*PERIOD

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include <util/delay.h>
#include <string.h>

#include "clk.h"

#include "list.h"
#include "transceive.h"
#include "uart_m.h"




//void init_uart(USART_data_t *uart, USART_t *usart, uint32_t f_cpu, uint32_t baud, uint8_t clk2x);


char * TranslateMessage (void);
void DetermineCommandtype ();









#endif /* MAIN_H_ */