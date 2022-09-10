#include<stdint.h>
#include<stdio.h>
#include<stdlib.h>

int main()
{
    puts("Program to allocate 2D array");
    int **pp = NULL;
    int r= 5;
    int c= 5;


    /* allocate the memory to pp */
    pp = malloc(r*c*sizeof(int));

    for(int i = 0; i<r; i++)
    {
        *(pp+i) = malloc(c*sizeof(int));
    }

    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j< c; j++)
        {
            *(*(pp+i)+j) = j+i;
        }
    }

    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j< c; j++)
        {
            printf("%d",*(*(pp+i)+j));
        }
        printf("\n");
    }

}