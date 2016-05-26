/**
 *	File	transceive.c
 *	Created 17-05-2016
 *	Author	Matthijs Visser
 *			Amsterdam University of applied sciences
 *	contact Matthijs.Visser@hva.nl
**/

#include "main.h"
#include "uart.h"
char value[64];
char message[64];

extern USART_data_t uartC0;
extern USART_data_t uartC1;

/**
 * Ranging result notification flag
 * @param  	
 * @param	
 */
void RRN (){
	uart_puts(&uartC1, "functieeee\r\n");
}


/**
 * Determines the meaning of the message
 * @param  	value	received value
 * @param	DetermineCommandtype
 */
void DetermineCommandtype (){
	char value[16], command[16];
	
	memset(command, '\0', strlen(command));

	value[0] = uart_getc(&uartC0);
	strcpy(command, value);
	uart_puts(&uartC1, value);
	

	while (value[0] != ':'){
		value[0] = uart_getc(&uartC0);
		//if (value[0] != ':'){
			strcat(command, value);
		//}
	}
	uart_puts(&uartC1, command);
/*

	uart_getc(&uartC0); // skip ':'
	
	uart_puts(&uartC1, command);
	uart_puts(&uartC1, "\r\n");

	if (strcmp(command, 	 "RRN") == 0){ // Data Notification Message
		RRN();
	}else if(strcmp(command, "DNO") == 0){ // Node ID Notification Message
		//printf("DNO\n");
	}else if(strcmp(command, "NIN") == 0){ // Ranging Result Notification Message
		//printf("NIN\n");
	}else if(strcmp(command, "SDAT") == 0){// SDAT Notification Messages
		//printf("SDAT\n");
	}else if(strcmp(command, "AIR") == 0){ // AIR Notification Message
		//printf("AIR\n");
	}else{
		//printf("else\n");
	}
*/
}

/**
 * Translates the received message converts characters
 * to a single string
 * @param  	value	received value
 * @return	message pointer to the translated message
 */
char * TranslateMessage (void){

	memset(message, '\0', strlen(message));

	value[0] = uart_getc(&uartC0);
	strcpy(message, value);
	while (value[0] != '\n'){
		value[0] = uart_getc(&uartC0);	
		strcat(message, value);
	}
	//uart_puts(&uartC1, message);
	//printf("message: %s", message);

	//printf("\n");

	return message;
}

/*
int main (void){
	// system("clear");
	char test[64];
	// strcpy(test,TranslateMessage());
	// printf("%s\n",test);
	// strcpy(test,TranslateMessage());	
	// printf("%s\n",test);
	while(1){
		strcpy(test,TranslateMessage());	
		printf("%s\n",test);
	}
	// DetermineCommandtype();
	return 0;
}
*/