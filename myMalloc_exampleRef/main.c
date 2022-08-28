#include <stdio.h>
extern char memory[5000];
void displayPool();
void displayPool()
{
    for(int i=0;i<=sizeof(memory);i++)
    {
        if(!(i%32))
            printf("\n0x%X : ",&memory[i]);
        if(!(i%4))
            printf("  ");
        if(memory[i]==0x00)
        {
            printf(" --");   
        }
        else
        {
            printf(" %02X",memory[i]);
        }
    }
    
    printf("\n");
}
int main()
{

        int *p = (int)MyMalloc(100 * sizeof(int)); // Memory allocation
        printf("int p address %x\n", p);
        char *q = (char)MyMalloc(250 * sizeof(char)); // Memory allocation
        printf("char q address %x\n", q);

        int *r = (int)MyMalloc(1000 * sizeof(int)); // Memory allocation
        printf("int p address %x\n", p);
        displayPool();
        MyFree(p);
        char *w = (char)MyMalloc(700); // Memory allocation
        MyFree(r);
        int *k = (int)MyMalloc(500 * sizeof(int));
        printf("Allocation and deallocation is done successfully!");
        displayPool();

}