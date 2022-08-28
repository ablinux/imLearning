#include <stdint.h>
#include <stdio.h>
int a = 0;

#define __IO volatile
#define __I const
#define __O volatile

typedef union
{
    uint32_t CAN_CTRL;
    struct
    {
        uint32_t CAN_EN : 4;
        uint32_t CAN_CLOCK : 4;
        uint32_t Reserved_ : 24;
    };
    /* data */
} CAN_CTRL_bit_t;

#define CAN_BASE_REG &a
#define CAN1 ((CAN_CTRL_bit_t *)CAN_BASE_REG)

int main()
{
    CAN1->CAN_EN = 0xE;
    CAN1->CAN_CLOCK = 0xF;
    printf("%x\n", CAN1->CAN_CTRL);
}
