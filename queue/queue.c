#include "queue.h"

/* private function to this queue */
static int isFull(void);
static int isEmpty(void); 
 
/* private variable */
queue_t Q;
/* Public */
queue_t *initQueue(uint32_t size)
{
    Q.qsize = size;
    Q.QUEUE = (DT*)malloc(sizeof(DT)*size);
    Q.r = -1;
    Q.f = -1;
    return &Q;
}

int enQueue(DT *item)
{
    /* check if Queue is full */
    if(isFull())
    {
        return 1;
    }
    Q.QUEUE[++Q.r] = (DT)item;
    return 0;

}

DT *deQueue(void)
{
    /*check if Queue is not empty */
    if(isEmpty())
    {
        return NULL;
    }
    return &Q.QUEUE[++Q.f];
}


/* private */

static int isEmpty(void)
{
    return (Q.r == Q.f);
}
static int isFull(void)
{
    return (Q.r == (Q.qsize-1));
}
