#include <stdint.h>
#include <stdio.h>

#define BITWIDTH(datatype) sizeof(datatype)*8U

#define SET_BIT(data,pos)  data |= (1<<pos)
#define CLR_BIT(data,pos)  data &= (~(1<<pos))
#define IS_SET(data,pos)   (data>>pos)&0x1

uint8_t flag = 0U;

int main()
{
    SET_BIT(flag,32);
    SET_BIT(flag,0);

    for(int i = BITWIDTH(flag)-1; i>=0; i--)
    {
        if(IS_SET(flag,i))
        {
            printf("1");
        }
        else{
            printf("0");
        }
    }
    printf(" == %u\n",flag);

}