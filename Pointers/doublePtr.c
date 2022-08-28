#include <stdio.h>

#include <stdint.h>


int main()
{
    int a = 10;
    int *p = &a;
    int **pp = NULL;
    pp = &p;

    printf("&pp = %p\npp = %p  &p = %p\n*pp = %p  &a = %p\n**pp = %p  a = %p\n",&pp,pp,&p,*pp,&a,**pp,a);

}