#include <stdio.h>
#include <stdint.h>

int main()
{
    volatile const int a = 10;

    int *p = (int *)&a;
    printf("%d\n", a);
    *p = 200;
    printf("%d\n", a);
}