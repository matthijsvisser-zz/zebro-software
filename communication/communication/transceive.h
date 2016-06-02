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

#include "uart.h"

/* Command lengths */
#define RRN_LENGTH	43
#define TYPE_RRN	1

/* Swarm Bee API commands */
#define GNID		"gnid\r\n"
#define GDAT		"gdat\r\n"
#define GRWL		"grwl\r\n"
#define SBIV1000	"SBIV 1000\r\n"

void DetermineCommandtype ();
char * TranslateMessage (void);
uint8_t ValidateMessage (char *message, uint8_t command);
uint16_t uart_getc(USART_data_t *uart);



#endif /* MAIN_H_ */
/**
 * Determines the meaning of the message
 * @param  	value	received value
 * @param	DetermineCommandtype
 */