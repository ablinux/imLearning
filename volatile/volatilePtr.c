#include <stdio.h>
#include <stdint.h>

int main()
{
    int const *volatile ptr; // (*p)++ invalid
    (*ptr)++;
    ptr++;
}