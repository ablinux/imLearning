#include <stdio.h>
#include <stdint.h>
/* Lets learn the structure and bit fields */

/* Question : Create a Timer register of 32 and mentioned fields like : 16 bit : timer value , 1 bit start or stop, */

union Timer_A
{
    uint32_t Timer_A_whole_data;
    struct __attribute__((packed))
    {
        unsigned c:8;
        unsigned b:8;
        unsigned a:8;
        
    };
};

int main()
{
    union Timer_A GPT;
    GPT.a = 0xAB;
    GPT.b = 0xCD;
    GPT.c = 0xEF;

    printf("THe value of Timer_A register is %x\n", GPT.Timer_A_whole_data);
    printf("Size of union is %d\n",sizeof(GPT));
}