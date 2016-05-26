/**
 *	File	transceive.h
 *	Created 19-05-2016
 *	Author	Matthijs Visser
 *			Amsterdam University of applied sciences
 *	contact Matthijs.Visser@hva.nl
**/
#ifndef TRANSCEIVE_H_
#define TRANSCEIVE_H_

#include <stdlib.h>
#include <stdio.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <string.h>

void DetermineCommandtype ();
//char * TranslateMessage (void);
char * TranslateMessage (void);
//static char uart_getchar(FILE *stream);
uint16_t uart_getc(USART_data_t *uart);
#include "uart.h"

#endif /* MAIN_H_ */
/**
 * Determines the meaning of the message
 * @param  	value	received value
 * @param	DetermineCommandtype
 */