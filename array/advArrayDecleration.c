#include <stdio.h>
#include <stdint.h>

void arrayPrint(int *a, uint8_t size);

int main()
{
    /* this is how we can declere an array */
    int a[] = {1, 2, 3, 4, 5};
    arrayPrint(a, sizeof(a) / sizeof(a[0]));
    /* also like this */
    int b[10] = {1, [2] = 3, [4 ... 9] = 9};
    arrayPrint(b, sizeof(b) / sizeof(b[0]));
}

void arrayPrint(int *a, uint8_t size)
{
    int i = 0;
    while (size)
    {
        printf(" %d ", a[i]);
        i++;
        size--;
    }
    printf("\n");
}