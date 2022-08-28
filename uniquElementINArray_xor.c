#include <stdio.h>
#include <stdint.h>

int main()
{
    char arry[] = {1,1,1,3,3,2};
    char unique = 0;

    /* to get the unique element in the arry we will xor the number */
    for(int i=0; i<sizeof(arry);i++)
    {
        unique = arry[i]^unique;
    }

    printf("%d\n",unique);          
}