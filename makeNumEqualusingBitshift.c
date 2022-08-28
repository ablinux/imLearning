#include <stdio.h>
#include <stdint.h>

int ops_cnt(int a, int b);
int main()
{
    printf("%d\n", ops_cnt(5, 10));
}
int ops_cnt(int a, int b)
{
    /*ntake 1st (a) as ideal value */
    int i = 0, cnt = 0;
    while ((a != b) && i < 32)
    {
        printf("sn= %d  a= %d   b= %d\n", i, (a >> i) & 0x1, (b >> i) & 0x1);
        if (((a >> i) & 0x1) != ((b >> i) & 0x1))
        {
            b = b ^ (1 << i);
            printf("b=\t\t\t----   %d\n", b);
            cnt++;
        }
        i++;
    }
    printf(" a = %d b = %d\n", a, b);
    return cnt;
}