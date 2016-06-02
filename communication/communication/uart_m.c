/**
 *  File    uart_m.c
 *  Created 26-05-2016
 *  Author  Matthijs Visser
 *          Amsterdam University of applied sciences
 *  contact Matthijs.Visser@hva.nl
**/
#include "uart.h"

extern USART_data_t uartC0;
extern USART_data_t uartC1;

void DebugPrint (char *debugData){
    uart_puts(&uartC1, debugData);
}

void Command (char *command){
    uart_puts(&uartC1, command);
}