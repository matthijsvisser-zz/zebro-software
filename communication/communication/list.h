/**
 *	File	list.h
 *	Created 03-05-2016
 *	Author	Matthijs Visser
 *			Amsterdam University of applied sciences
 *	contact Matthijs.Visser@hva.nl
**/

#ifndef LIST_H_
#define LIST_H_

#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <util/delay.h>

#define DATASIZE 5
#define FIRSTDATAITEM 0

typedef struct node {
	char* data [DATASIZE];
	struct node * next;
}node_t;

typedef struct row {
	char id			[13];
	char targetID	[13];
	char longRange	[7];
	char shortX		[4];
	char shortY		[4];
	char status		[2];
}row_t;




void print_list(node_t *listHead);
void insert (node_t ** listHead, char* data[DATASIZE]);
void append (node_t *listHead, char* data[DATASIZE]);
char* pop (node_t ** head);
char* popListByNumber(node_t ** head, int indexNumber);
char* popListByValue(node_t ** head, char* value, int sizeOfList);

#endif /* LIST_H_ */