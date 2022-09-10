#include<stdio.h>
#include<stdint.h>
#include <stdlib.h>
#include <string.h>

void show_bin(uint8_t);

int main(int argc, char *argv[])
{
    uint8_t data = atoi(argv[1]);
    uint8_t rot = atoi(argv[2]);
    printf("number %d is entered Bin representation is:\n",data);
    show_bin(data);
    printf("Rotating by %d number\n",rot);
    data = (data>>rot)|data&((1<<rot)-1);
    printf("number %d is roteted by %d times Bin representation is:\n",data, rot);
    show_bin(data);

}

void show_bin(uint8_t data)
{
    for(int i = sizeof(data)*8 -1 ; i >= 0 ; i--)
    {
        printf(" %d ", (data>>i)&0x1);
    }
    printf("\n");
}