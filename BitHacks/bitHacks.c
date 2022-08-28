#include <stdint.h>
#include <stdio.h>


int main()
{
    NumToBIN(0x5);
    /*********************************************************/
    printf ("Check if 2int are diffrence in sign or not\n");
    uint32_t a = 10;
    int32_t b = -11;
    printf ("bin rep of a = 10   ");uint32DecToBin(a);
    printf ("\nbin rep of b = 11   ");int32DecToBin(b);
    printf ("\na xor b =           "); int32DecToBin(a^b);
    printf ("\n axb in dec = %d",a^b);

    /*********************************************************/
    printf ("Adding 1 to any number \n");
    uint32_t c = 4;
    printf ("bin rep of c = 4   ");uint32DecToBin(c);
    printf ("\nbin rep of c = ~c  ");int32DecToBin(~c);
    printf ("\nbin rep of c = -~c "); int32DecToBin(-~c);
    printf ("\n Result = %d",-~c);

    /*********************************************************/
    printf ("Turning off 4th bit in num 10 \n");
    uint32_t d = 10;
    printf ("bin rep of 10 = d           ");uint32DecToBin(d);
   printf("\nbin rep of 1<<4 =           ");int32DecToBin(1<<(4-1));
  printf ("\nturnoff the bit d^(1<< k-1) ");int32DecToBin(d^(1<<(4-1)));
    printf ("\n Result = %d",d^(1<<(4-1)));
  
    // printf ("\n Result = %d",-~c);

    return 0;
}

/**
 *  Output the number in bin for uint32
 *  */
void uint32DecToBin(uint32_t decNumber)
{
    uint8_t output;
    for (int i=31; i>=0; i--)
    {
        output = ((decNumber>>i)&0x1);
        
        printf(" %d ",output);
    }

}
/*  output the bin data for int32_t*/
void int32DecToBin(int32_t decNumber)
{
    uint8_t output;
    for (int i=31; i>=0; i--)
    {
        output = ((decNumber>>i)&0x1);
        
        printf(" %d ",output);
    }

}

void NumToBIN(uint8_t num)
{
    uint8_t output = 0;
    for(int i=7; i>=0;i--)
    {
        output = (num>>i)&0x1;
        printf(" %d ",output);
    }
    printf("\n");
}