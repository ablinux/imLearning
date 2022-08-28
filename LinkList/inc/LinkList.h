#ifndef LINKLIST_H
#define LINKLIST_H


#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct st_Node
{
    struct st_Node *Next;
    uint32_t data;
}node_t;


typedef struct linkList
{
    node_t *Head;
    node_t *END;
    u_int64_t nodeCount;
}list_t;


void create_list(list_t *);
void distroy_list(list_t *);
uint8_t add(list_t*,uint32_t);
uint8_t remove_item(list_t *p_list,int32_t index);
void diplayItems(list_t *p_list);

#endif