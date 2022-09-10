#include<stdio.h>
#include<stdint.h>

void shortArray(uint8_t *, uint8_t* ,uint32_t);
void show(uint8_t *p_int, uint32_t size);
/* What is selection short alog? */

int main()
{
    uint8_t unsortedArray[] = {1,2,3,5,4};
    uint8_t sortedArray[8];

    printf("Unsorted array is - \n");
    show(unsortedArray,sizeof(unsortedArray));

    shortArray(unsortedArray,sortedArray,sizeof(unsortedArray));

    printf("Sorted array is - \n");
    show(unsortedArray,sizeof(unsortedArray));

}

void shortArray(uint8_t *p_in, uint8_t *p_out ,uint32_t size)
{ /* ex = 9,3,2,6,4,8,5,0,1,7 */
    uint8_t temp;
    uint8_t is_swaped = 0;
    for(int i = 0 ; i < size-1; i++)
    {
        is_swaped = 0;

        for(int j = 0 ; j < size-1; j++)
        {
            if(p_in[j] > p_in[j+1])
            {
                /* swap */
                temp = p_in[j];
                p_in[j] = p_in[j+1];
                p_in[j+1] = temp;
                is_swaped = 1;
            }
        }
        if(is_swaped == 0)
        {
            /* which means list is already sorted or become sorted after some but not complete iteration  */
            printf("Sorted soon \nPass %d    ",i+1); show(p_in,size);
            break;
        }
        printf("Pass %d    ",i+1); show(p_in,size);
    }

}
void show(uint8_t* p_in, uint32_t size)
{
    for(int i = 0 ; i< size; i++)
    {
        printf("-%d",p_in[i]);
    }
    printf("\n");
}