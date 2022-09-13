#include "queue.h"

/* private function to this queue */

 
/* private variable */
queue_t Q;
/* Public */
queue_t *initQueue(uint32_t size)
{
    Q.qsize = size;
    Q.QUEUE = malloc(size*sizeof(DT));
    Q.r = -1;
    Q.f = -1;
    return &Q;
}

int enQueue(DT *item)
{
    /* check if Queue is full */
    if(isQueueFull())
    {
        return 1;
    }
    Q.QUEUE[++Q.r] = item;
    return 0;

}

DT *deQueue(void)
{
    /*check if Queue is not empty */
    if(isQueueEmpty())
    {
        return NULL;
    }
    return Q.QUEUE[++Q.f];
}


/* private */

int isQueueEmpty(void)
{
    return (Q.r == Q.f);
}
int isQueueFull(void)
{
    return (Q.r == (Q.qsize-1));
}
