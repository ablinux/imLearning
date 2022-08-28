#include <stdio.h>
#include <stdint.h>
void uint32_lil_to_big(int *, int *);
void uint32_big_to_lil(int *, int *);
void uint32_lil_to_big_bitWise(uint32_t in, uint32_t *out);

int main()
{
    uint32_t a = 0x0A0B0C0D;
    uint32_t b_out = 0;
    printf("Endiness test program \n");
    /* to check the endiness we need to check how the data is stored in memory 
    Big-endian store the MSB to lower address
    Lil-endian store the MSB to higher address
    */

    /** to check the endianess,
    *  1st point the address to  uint8 check the value if MSB is at higer address its little endian*/
    char *data = (char*)&a;

    /* Check if little endian or big endian */
    /* Here the data assigned to a is 0x1234578 0x12 is MSBand 0x78 is LSB
    to check endianess we will check byte order*/
    printf("Given machine is \n");
    for (int i = 0; i < 4; i++)
    {
        printf("[%d] At address 0x%x      data is: 0x%x\n", i, ((&data + i)-&data), data[i]);
    }
    if (data[0] == 0x0A)
    {
        printf("Bin\n");
    }
    else
    {
        printf("Lil-endian\n");
        printf("Changing Little-Endian to big endian using pointer...\n");
        uint32_lil_to_big(&a, &b_out);
        data = (char*)&b_out;
        for (int i = 0; i < 4; i++)
        {
            printf("[%d] At address 0x%x      data is: 0x%x\n", i, ((&data + i)-&data), data[i]);
        }
        puts("Using Bitwise\n");
        uint32_lil_to_big_bitWise(a, &b_out);
        printf("bitwise endiness change from 0x%x to 0x%x\n",a,b_out);
        data = (char*)&b_out;
        for (int i = 0; i < 4; i++)
        {
            printf("[%d] At address 0x%x      data is: 0x%x\n", i, ((&data + i)-&data), data[i]);
        }
    }

    return 0;
}

void uint32_lil_to_big(int *in, int *out)
{
    char *temp1 = (char *)in;
    char *temp2 = (char *)out;
    temp2[3] = temp1[0];
    temp2[2] = temp1[1];
    temp2[1] = temp1[2];
    temp2[0] = temp1[3];
}

void uint32_lil_to_big_bitWise(uint32_t in, uint32_t *out)
{
    *out = *out|((in>>24)&0x000000ff);printf("0x%x    \n",*out);
    *out = *out|((in>>8)& 0x0000ff00);printf("0x%x    \n",*out);
    *out = *out|((in<<8)& 0x00ff0000);printf("0x%x    \n",*out);
    *out = *out|((in<<24)&0xff000000);printf("0x%x    \n",*out);
}

void uint32_big_to_lil(int *in, int *out)
{
}