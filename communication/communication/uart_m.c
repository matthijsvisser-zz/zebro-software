/**
 *  File    uart_m.c
 *  Created 26-05-2016
 *  Author  Matthijs Visser
 *          Amsterdam University of applied sciences
 *  contact Matthijs.Visser@hva.nl
**/
#include "uart.h"
#include "uart_m.h"

extern USART_data_t uartC0;
extern USART_data_t uartC1;

/**
 * Print a string of information on the UART C1 (DEBUG) interface.
 * @param   *debugData	String of information
 * @param   value		Temporarily string value to add a cariage return and new line feed
 */
void DebugPrint (char *debugData){
	char value[64];
	strcpy(value, debugData);
	strcat(value, "\r\n");
    uart_puts(&uartC1, value);
}

/**
 * Sends a 'command' to the UART C0 (COMMAND) interface
 * @param   *command	Command
 */
void Command (char *command){
    uart_puts(&uartC0, command);
}