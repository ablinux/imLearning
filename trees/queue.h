#ifndef QZXC
#define QZXC

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "userdefine.h"

typedef struct st_queue
{
    int f;
    int r;
    int qsize; 
    DT **QUEUE;
}queue_t;


int enQueue(DT *item);
DT *deQueue(void);
queue_t *initQueue(uint32_t size);

int isQueueFull(void);
int isQueueEmpty(void); 

#endif