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

RegA *CAN = (RegA *)CAN_REG_BASE;

int main()
{
    CAN->b.A = 0xAAAA;
    CAN->b.B = 0xBBBB;
    printf("%d\n",sizeof(CAN));

    printf("data.b.A = %x\ndata.b.B = %x\ndata.whole = %x\n",CAN->b.A,CAN->b.B,CAN->whole);
    printf("Base Register: 0x%x\n",*CAN_REG_BASE);
}