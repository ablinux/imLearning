// Link list

//1 2 3 4 
//2 1 4 3

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct st_node
{
    uint8_t data;
    struct st_node *next;
}node_t;

node_t *start;

void show(node_t *);


int main()
{
    node_t node1,node2,node3,node4,node5,node6;
    start = &node1;
    node1.data = 1;node1.next = &node2;
    node2.data = 2;node2.next = &node3;
    node3.data = 3;node3.next = &node4;
    node4.data = 4;node4.next = &node5;
    node5.data = 5;node5.next = &node6; 
    node6.data = 6;node6.next = NULL;

    show(start);

    /* swaping */
    node_t *r,*p,*q;
    r,q = NULL;
    p = start;
    int i = 0;int run1st=1;
    while(p!=NULL)
    {
       if(i%2)
       {
        puts("Swapping now");
        int temp = q->data;
        q->data = p->data;
        p->data = temp;
       }
       q = p;
       p = p->next;
       i++;
    }


    show(start);


}

void show(node_t *node)
{
    node_t *temp = node;
    while(temp)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


