/**
 *  File    uart_m.c
 *  Created 26-05-2016
 *  Author  Matthijs Visser
 *          Amsterdam University of applied sciences
 *  contact Matthijs.Visser@hva.nl
**/

void DebugPrint (char *debugData){
    uart_puts(&uartC1, debugData);
}

void Command (char *command){
    strcat(command, "\r\n");
    uart_puts(&uartC1, debugData);
}