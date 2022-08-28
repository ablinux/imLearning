#include <stdio.h>
#include <stdint.h>

#define __IO         (volatile)
#define __I          (volatile const)
#define __O          (volatile)

int a;
#define CAN_REG_BASE (volatile unsigned int const*)&a

typedef union 
{
    struct
    {
      uint32_t B:16;  /* data */
      uint32_t A:16;
    }b;
    uint32_t whole;
}RegA;

int main()
{
    RegA data;
    data.b.A = 0xAAAA;
    data.b.B = 0xBBBB;
    printf("%d\n",sizeof(RegA));

    printf("%x\n%x\n%x\n",data.b.A,data.b.B,data.whole);
    printf("Base Register: 0x%x\n",CAN_REG_BASE);
}