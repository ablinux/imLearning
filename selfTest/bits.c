#include<stdio.h>
#include<stdint.h>
#include <stdlib.h>
#include <string.h>

void show_bin(uint8_t);

int main(int argc, char *argv[])
{
    uint8_t data = atoi(argv[1]);
    uint8_t k = atoi(argv[2]);
    show_bin(data);

    /* set bit at k th location  k = 4*/
    // data = data|(1<<k);
    printf("setting 1 at %dth location result = %x\n",k, data = data|(1<<k));
    show_bin(data);


    /* toggling a bit at kth location */
    // data = data^(1<<k);
    printf("toggling bit at %dth location result = %x\n",k,data = data^(1<<k));
    show_bin(data);


    /* clear a bit at kth location */
    // data = data&(~(1<<k));
    printf("clearning bit at %dth location result = %x\n",k,data = data&(~(1<<k)));
    show_bin(data);


}

void show_bin(uint8_t data)
{
    for(int i = sizeof(data)*8 -1 ; i >=0 ; i--)
    {
        printf(" %d ", (data>>i)&0x1);
    }
    printf("\n");
}