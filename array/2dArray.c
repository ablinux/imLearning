#include <stdio.h>
void fun1(char pp[][2]);
void fun2(char *p);

int main()
{
    /* Example 1, basic decleration and printting 2d array */
    char DDarray[2][2] = {
    {1,2},
    {3,4}
    };
    puts("Using basic array noatation\n");
    for (int r=0; r<2;r++)
    {
        for(int c=0;c<2;c++)
            printf("%d ",DDarray[r][c]);
        printf("\n");
        
    }

    /* example 2 printring using pointer notation */
    puts("Using basic pointeer noatation\n");
    for (int r=0; r<2;r++)
    {
        for(int c=0;c<2;c++)
            printf("%d ",*(*(DDarray+r)+c));
        printf("\n");
        
    }

    /* example 3 using mixed notation */
    puts("Using mixed pointeer and array noatation\n");
    for (int r=0; r<2;r++)
    {
        for(int c=0;c<2;c++)
            printf("%d ",*(DDarray[r]+c));
        printf("\n");
    }   

    /* example 4 */
    puts("passing 2d array to function arr[][2] and printing as pointer notation\n");
    fun1(DDarray);

    /* example 5 */
    puts("passing 2d array to function *p and printing as pointer notation\n");
    fun2((char*)DDarray);
    
}

void fun1(char pp[][2])
{
    for (int r=0; r<2;r++)
    {
        for(int c=0;c<2;c++)
            printf("%d ",*(*(pp+r)+c));
        printf("\n");
    } 

}

void fun2(char *p)
{
    for(int r=0;r<4;r++)
    {
        printf("%d ",*(p+r));
    }
}