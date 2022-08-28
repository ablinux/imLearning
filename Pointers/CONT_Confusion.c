#include <stdio.h>

/* this will give you compilation error */
// if you assign new value to a
// const int  a = 10;
// int const a = 10;

int main()
{
    /******EXAMPLE 1************/
    const int *p; /* read right to left : p is pinter to integer constant*/
    /* or we can also say */
    int const *q; /* q is a pointer to constant integer */
    /* Both statment is correct */

    /* in the above decleration we can increment the pointer ex: p++ or p = p + n is a valid statment
    but (*p)++ is invalid because we are trying to modify the const int */

    int a = 10;
    /* Example of const int * */
    p = &a;
    /* this is wrong */
    p++;
    /* this will through error if you uncomment the below statment */
    // (*p)++;

    /********EXAMPLE 2************/
    int b = 10;
    int *const r = &b; /* r is const pointer to integer*/
    /* in this statement r is constant pointer which means that r can not be modified once it points to any address, but value to which it 
    is pointing can be modified
    ex : r++ is invalid but (*r)++ is valid */
    (*r)++; // this is fine
    // r++; // this is error

    /******Example 3 *************/
    int c = 30;
    const int *const s; /* s is const pointer to interger constant */
    /* s++ or (*s)++ both illgle */
    // s++;
    // (*s)


    /* Excersice 1********/
    const int ab = 10;
    int *const pq = &ab;
    (*pq)++; /* will compile with warning */
    printf("%d\n",*pq); 
}