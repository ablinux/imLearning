#include<stdio.h>
#include<stdint.h>

void shortArray(uint8_t *, uint8_t* ,uint32_t);
void show(uint8_t *p_int, uint32_t size);
/* What is selection short alog? */

int main()
{
    uint8_t unsortedArray[] = {4,3,2,1};
    uint8_t sortedArray[8];

    printf("Unsorted array is - \n");
    show(unsortedArray,sizeof(unsortedArray));

    shortArray(unsortedArray,sortedArray,sizeof(unsortedArray));

    printf("Sorted array is - \n");
    show(unsortedArray,sizeof(unsortedArray));

}

void shortArray(uint8_t *p_in, uint8_t *p_out ,uint32_t size)
{ /* ex = 8,1,6,7,6,5,9,2 */
    uint8_t smallest, temp, smallest_at_index,swap;
    for(int i=0; i<size;i++)
    {
        smallest = p_in[i];
        for (int j = i; j < size; j++)
        {
            if(smallest > p_in[j]) /* check if the nth element is bigger then the n+1th aka next element */
            {
                smallest = p_in[j];
                smallest_at_index = j;
                swap = 1;
            }
        }
        if(swap)
        {
            temp = p_in[i];
            p_in[smallest_at_index] = temp;
            p_in[i] = smallest;
            swap = 0;
        }
        printf("Pass %04d:   ",i);show(p_in,size);
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