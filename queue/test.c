#include <stdio.h>
#include <stdint.h>
#include "queue.h"

int main()
{
    printf("Queue example \n");
    queue_t *Q = initQueue(5);
    DT *item;
    /* test 1 check the que full */
    for (int i = 0; i <= 5; i++)
    {
        if(enQueue(i) == 1)
        {
            printf("Queue is full after inserting %d item\n",i+1);
        }
    }

    /* Test remove item from queue */
    for (int i = 0; i <= 5; i++)
    {
        item = deQueue();
        if(item == NULL)
        {
            printf("Queue is Empty after removing %d item\n",i+1);
        }
        else
            printf("removed item from Queue is %lf\n",*item);
    }



    

}