#include <stdio.h>
#include <stdint.h>


int main()
{
    /* array of pointers */
    int *are_of_ptr[10];
    printf("size of array of pointer = %d\n",sizeof(are_of_ptr));
    
    int array[10];
    int (*arry_pointer)[10] = &array;
    printf("size of pointer to an array of size 10 is = %d  address jump of pointer to an array of 10 in %p to %p is jump of %d\n",sizeof(arry_pointer),arry_pointer,arry_pointer+1,(uint8_t*)arry_pointer-(uint8_t*)(arry_pointer+1));

    arry_pointer = &array;
    printf("Size of array %d\n",(char*)array - (char*)(array+1));

    // Pointer to an array of 5 integers
    int (*ptr)[5];
    int arr[5];

     // Points to the whole array arr.
    ptr = &arr;

}


// C program to understand difference between
// pointer to an integer and pointer to an
// array of integers.
// #include<stdio.h>
 
// int main()
// {
//     // Pointer to an integer
//     int *p;
     
//     // Pointer to an array of 5 integers
//     int (*ptr)[5];
//     int arr[5];
     
//     // Points to 0th element of the arr.
//     p = arr;
     
//     // Points to the whole array arr.
//     ptr = &arr;
     
//     printf("p = %p, ptr = %p\n", p, ptr);
     
//     p++;
//     ptr++;
     
//     printf("p = %p, ptr = %p\n", p, ptr);
     
//     return 0;
// }