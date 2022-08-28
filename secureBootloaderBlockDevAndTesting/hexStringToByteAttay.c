#include<stdio.h>
#include<stdint.h>

void stringHex_to_ByteHexArray(uint8_t *p_src_string, uint32_t string_size, uint8_t *p_dest_bytes, uint32_t *ret_byte_size);

int main()
{
    uint8_t *pkey_str = "3036021900D321AFF20FBF68C0A293AF79E9C226D9AD5A1A3BC51D30BC021900D981ACC7343A8A7EDDF196A86F98ADE883E7FD71BB9C32DB";
    printf("users pkey in str is: %s \n",pkey_str);

    puts("Converting it to bin form\n");

    /* Allocate the enough memory for array to hold the data */
    uint8_t size = strlen(pkey_str);

    printf("Nedded %d size to hold the pkey in byte array \n",size);

    uint8_t pkey_byte[size];int byte_index=0; int len;
    uint8_t temp[2];int store = 0;

    memset(pkey_byte,0x0,size);

    stringHex_to_ByteHexArray(pkey_str,strlen(pkey_str),pkey_byte,&len);
    printf("Got %d byte \n",len);
    for(int i=0; i<=len;i++)
    {
        printf("%X",pkey_byte[i]);
    }
    puts("\n");

    puts("Printing in Byte array form\n");
    for(int i=0; i<=len;i++)
    {
        if(!((i+1)%10))
            printf("\n");
        printf("0x%X, ",pkey_byte[i]);
    }

}

void stringHex_to_ByteHexArray(uint8_t *p_src_string, uint32_t string_size, uint8_t *p_dest_bytes, uint32_t *ret_byte_size)
{
    /* Now the actual logic */
    int i;
    uint8_t temp[2]; int store = 0; int byte_index = 0;
    for(i = 0; i<=string_size; i++)
    {
        if(p_src_string[i] >= 'A' && p_src_string[i] <= 'F')
        {
            temp[store++] = (p_src_string[i] - 'A') + 10U;
        }
        else if(p_src_string[i]>= '0' && p_src_string[i] <= '9')
        {
            temp[store++] = p_src_string[i] - '0';
        }

        if(!((i+1)%2)) /* Stored 2 strings ? now process them as byte */
        {
            store = 0;
            p_dest_bytes[byte_index] = (temp[0]<<4)|(temp[1]);
            // printf("%X",p_dest_bytes[byte_index]);
            byte_index++;
        }
    }
    *ret_byte_size = byte_index - 1;
}