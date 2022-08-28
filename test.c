#include <stdio.h>
#define R 10
#define C 20
struct test
{
    char b[100];
};
int main()
{
    struct test st;
       
    printf("SIze %d\n",(char*)&st - (char*)(&st+1));
    return 0;
}