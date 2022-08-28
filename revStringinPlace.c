#include<stdio.h>
#include<string.h>

int main()
{
    char str[120];
    printf("Enter the string to reverse in place \n");
    printf("> ");scanf("%s",str);
    char temp;
    int strSize = strlen(str);
    printf("User string is = %s, size = %d\n",str,strSize);
    fflush(stdin);
    for(int i=0;i<strSize/2;i++)/* Loop has to run only half time if str len is 3 it will run for 1 time*/
    {
        /*store the value in temp location 1st */
        temp = str[i];
        /* Now copy the last char to 1st location */
        str[i] = str[(strSize)-i-1];
        /* Now Store the 1st element to Last location*/
        str[(strSize) - i-1] = temp;
        fflush(stdout);
    }
    printf("Reversed Str = %s\n",str);
}