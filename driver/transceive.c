/**
 *	File	transceive.c
 *	Created 17-05-2016
 *	Author	Matthijs Visser
 *			Amsterdam University of applied sciences
 *	contact Matthijs.Visser@hva.nl
**/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * Determines the meaning of the message
 * @param  	value	received value
 * @param	DetermineCommandtype
 */
void DetermineCommandtype (){
	char value[16];
	char command[16];

	memset(command, '\0', strlen(command));

	value[0] = getchar();
	//value[0] = uart_getchar(stdin);
	strcpy(command, value);

	while (value[0] != ':'){
		value[0] = getchar();
		//value[0] = uart_getchar(stdin);
		if (value[0] != ':'){strcat(command, value);};
	}

	if (strcmp(command, 	 "RRN") == 0){ // Data Notification Message
		printf("RRN\n");
	}else if(strcmp(command, "DNO") == 0){ // Node ID Notification Message
		printf("DNO\n");
	}else if(strcmp(command, "NIN") == 0){ // Ranging Result Notification Message
		printf("NIN\n");
	}else if(strcmp(command, "SDAT") == 0){// SDAT Notification Messages
		printf("SDAT\n");
	}else if(strcmp(command, "AIR") == 0){ // AIR Notification Message
		printf("AIR\n");
	}else{
		printf("else\n");
	}
}

/**
 * Translates the received message converts characters
 * to a single string
 * @param  	value	received value
 * @return	message pointer to the translated message
 */
char * TranslateMessage (void){
	char value [2];
	static char message[64];

	memset(message, '\0', strlen(message));

	value[0] = getchar();
	//value[0] = uart_getchar(stdin);
	strcpy(message, value);
	
	while (value[0] != '\n'){
		value[0] = getchar();
		//value[0] = uart_getchar(stdin);	
		strcat(message, value);
	}
	return message;
}

int main (void){
	system("clear");
	char test[64];
	// strcpy(test,TranslateMessage());
	// printf("%s\n",test);
	// strcpy(test,TranslateMessage());	
	// printf("%s\n",test);
	// strcpy(test,TranslateMessage());	
	// printf("%s\n",test);

	DetermineCommandtype();
	return 0;
}