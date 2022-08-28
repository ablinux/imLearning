#include <stdio.h>

typedef struct userdefined {
    int a;
    float b;
    char c;
}userdef_t;

int main()
{
    int a;
    printf("c lib size of int %d\n",sizeof(a));

    printf("&a = %x\n&a+1 = %x\nsubstraction = %x\n",&a,&a+1,((&a+1)-&a));
    printf("char * &a =%x\nchar* &a+1 = %x\n",(char*)&a,(char*)(&a + 1));
    printf("user size of int %d\n",(char*)(&a+1)- (char*)&a);

    userdef_t user_def;

    printf("c lib size of userdefined struct = %d\n",sizeof(user_def));
    printf("user size of userdefined struct = %d\n",(char*)(&user_def + 1)-(char*)&user_def);

}