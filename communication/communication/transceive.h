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
#include <string.h>

//#include "uart.h"

void DetermineCommandtype ();
//char * TranslateMessage (void);
void TranslateMessage (void);
//static char uart_getchar(FILE *stream);

#endif /* MAIN_H_ */
/**
 * Determines the meaning of the message
 * @param  	value	received value
 * @param	DetermineCommandtype
 */