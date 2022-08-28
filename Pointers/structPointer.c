#include <stdint.h>
#include <stdio.h>
typedef struct value {
    double a;
    int b;
    int c;
} value_t;

int main()
{
    value_t val = {1,2,3};
    value_t *ptr = &val;

    printf("%d %d \n",*ptr, *(ptr+1));
}