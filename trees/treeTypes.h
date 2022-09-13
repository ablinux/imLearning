#ifndef TREETYPE
#define TREETYPE
#include <stdio.h>
#include <stdint.h>
typedef struct st_tree
{
    uint32_t data;
    struct st_tree *left;
    struct st_tree *right;
}tree_t;


#endif