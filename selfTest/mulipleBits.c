#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

/* question is to set data into position k in given data */
void show_bin(uint8_t data);
int main()
{
    uint8_t data = 0x00;
    uint8_t toset = 0x4;
    uint8_t loc   = 3; /* from zero */

    printf("location = %d data to set %x, Result = %d\n",loc,toset, data = data|(toset<<loc));
    show_bin(data);
}
void show_bin(uint8_t data)
{
    for(int i = sizeof(data)*8-1 ; i >=0 ; i--)
    {
        printf(" %d ", (data>>i)&0x1);
    }
    printf("\n");
}