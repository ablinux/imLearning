// #include <stdio.h>
// struct test {
// 	unsigned int x;
// 	unsigned int y : 33;
// 	unsigned int z;
// };
// int main()
// {
// 	printf("%lu", sizeof(struct test));
// 	return 0;
// }
//output
//error: width of ‘y’ exceeds its type
//  unsigned int y : 33;


#include <stdio.h>
struct test {
    unsigned int x;
    long int y : 10;
    unsigned int z;
};
int main()
{
    struct test t;
    unsigned int* ptr1 = &t.x;
    unsigned int* ptr2 = &t.y;
    printf("%d", ptr2 - ptr1);
    return 0;
}