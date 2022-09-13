#ifndef STCKSLD
#define STCKSLD

#include<stdint.h>
#include<stdio.h>
#include <stdlib.h>

#define datatype uint8_t
#define pointer  

/* link list */
typedef struct st_list
{
    datatype data;
    struct st_list *next;
}list_t;

/*Fucntions */
int push(datatype *data);
datatype *pop(void);
int isFull(void);
int isEmpty(void);
int initStack(uint32_t size );

#endif