#include <stdio.h>
#include <stdint.h>


int main()
{
    int a = 10;
    int *p;
    p = &a;

    printf("d-ref *p in\n*(p+0) = %d\np[0] = %d\nand *p = %d\n",*(p+0),p[0],*p);

    puts("Now play with double pointer \n");

    int **pp;
    pp = &p;

    printf("d-ref **pp in\n*(*(pp+0)+0) = %d\npp[0][0] = %d\nand **pp = %d\n",*(*(pp+0)+0),pp[0][0],**pp);

    printf("d-ref *pp holds the address to variable and it can be written as\n*(pp+0) = %p\npp[0] = %p\nand *p = %p\naddress of var &a = %p\n",*(pp+0),pp[0],*pp,&a);
}