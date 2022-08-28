#include <stdio.h>
#include <stdint.h>

void fun(void);

/* How to typeDef a function pointer */
typedef void (*fptr)(void);

/* function delecleration to accept the function as an argument */
void accptFptr(void (*param)(void));
void accptTypeDefFptr(fptr param);

const int *const p;

int main()
{
    fptr p_call = &fun;
    p_call();

    accptFptr(&fun);
    accptTypeDefFptr(&fun);
}

void fun(void)
{
    printf("Hellow fromFPTR\n");
}

void accptFptr(void (*param)(void))
{
    param();
}

void accptTypeDefFptr(fptr param)
{
    param();
}