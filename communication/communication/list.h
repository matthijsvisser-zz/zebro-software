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
	char longRange	[5];
	char shortX		[3];
	char shortY		[3];
	char status		[2];
}row_t;


void print_list(node_t *listHead);
void insert (node_t ** listHead, char* data[DATASIZE]);
void append (node_t *listHead, char* data[DATASIZE]);

#endif /* LIST_H_ */