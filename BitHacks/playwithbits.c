#include<stdio.h>
#include<stdint.h>



int main()
{
    uint8_t a = 0xF2;
    int loc = 1;
    /* Clear the bit */
    printf("current value %x now clearing the %d bit from it\nNew value is %x\n",a,loc, a = a&(~(1<<loc)));

    /* Set the bit */
    printf("current value %x now setting the %d bit from it\nNew value is %x\n",a,loc, a = a|(1<<loc));

    /* Toggle a bit */
    printf("current value %x now toggling the %d bit from it\nNew value is %x\n",a,loc, a = a^(1<<loc));
}