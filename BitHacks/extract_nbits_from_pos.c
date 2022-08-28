#include <stdio.h>
#include <math.h>
#include <stdint.h>

#define BITS(value,bits,pos)  ((value&(((1<<bits)-1)<<pos))>>pos) // complicated na, lets simplify this

#define MASK(bits,pos) (((1<<bits)-1)<<pos) 
#define EXTRACT(value,bits,pos)  (value&MASK(bits,pos))>>pos

int main()
{
    uint32_t data = 0x18;

    printf("%d\n",EXTRACT(data,2,3));
    printf("%d\n",BITS(data,2,3));

}