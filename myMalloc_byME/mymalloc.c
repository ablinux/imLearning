#include <stdio.h>
#include <stdint.h>
#include <string.h>
/* This is custom malloc function created using the linklist */

/* Memory pool aka Heap */
uint8_t memPool[1000];
/* general structure for allocated block of memory */
typedef struct memHeader
{
    uint8_t isFree;
    uint32_t blockSize;
    struct memHeader *nextBlock;
    uint8_t *memBlock;
} memHeader_t;

/* private to mymalloc file */
static memHeader_t *firstBlock;


/* Public Functions */
void *myMalloc(uint32_t size);
void *myfree(void *location);
void displayPool();
/* Private function */
void init(void);

int main()
{
    char str[] = "\033[1;31mbold red text\033[0m\n";
    char str2[] = "+++";

    char *p_dy = myMalloc(sizeof(str));

    memcpy(p_dy,str,sizeof(str));

    puts(p_dy);

    displayPool();

    myfree(p_dy);

    puts(p_dy);
    displayPool();


}

void displayPool()
{
    printf(" dot .. is 00, all other number are in \033[1;31m RED Color \033[0m\n");
    for(int i=0;i<=sizeof(memPool);i++)
    {
        if(!(i%32))
            printf("\n0x%X : ",&memPool[i]);
        if(!(i%4))
            printf("  ");
        if(memPool[i]==0x00)
        {
            printf(" ..");   
        }
        else
        {
            printf(" \033[1;31m%02X\033[0m",memPool[i]);
        }
    }
    
    printf("\n");
}

/* Public Functions */
/* Alloc memory */
void *myMalloc(uint32_t reqSize)
{
    int i = 0;
    memHeader_t *curr;
    if(firstBlock == NULL)
    {
        puts("Internal memory init...");
        init();
    }
    curr = firstBlock;
    /* Seach for free block *//* Check if the request size can fit on given free block */
         
    while(((curr->isFree == 0) || /* continue if block is not free OR */
          (curr->blockSize < reqSize)) /* requested size cannot fit in the available block  AND*/
           
           && (curr->nextBlock != NULL)) /* Next block is not null */
    {
        curr = curr->nextBlock;
        i++;
    }
    printf("Found the block.. address = %p index %d\n",curr,i);

    /*Note: We found the block which can fit (exactly or losly) the the requested size of memory */
    /* Check if it fits perfectly ? */
    if(reqSize == curr->blockSize)
    {
        /* return the memory address */
        printf("got exect match of free size at Node %p index %d\n",curr,i);
        curr->isFree = 0;
        curr->blockSize = reqSize;
        return curr->memBlock;
    } 
    
    /* free block has more space then needed ? split the memory */
    if(reqSize < curr->blockSize)
    {
        memHeader_t *newBlock;
        /* Split the memory */
        /* Assign the memory to memBlock */
        curr->isFree = 0;

        /* Creating new block */
        newBlock = (uint8_t *)curr->memBlock+reqSize;//Size is 
        newBlock->nextBlock = NULL;
        newBlock->blockSize = curr->blockSize - reqSize;
        newBlock->isFree = 1;
        newBlock->memBlock = curr->memBlock+reqSize+16;

        curr->blockSize = reqSize;
        curr->nextBlock = newBlock;
        printf("Splitting the memory block \nNew Block %p and returning memory from Node %p at Index %d\n",newBlock,curr,i);
        return curr->memBlock;

    } 

}

/* Free memory */
void *myfree(void *location)
{
    memHeader_t *temp = firstBlock;
    int i = 0;
    /* compare the pointer to the list of allocated memory */
    while(temp->nextBlock!=NULL)
    {
        if(temp->memBlock == location)
        {
            /* set isFree = 1 */
            temp->isFree = 1;
            printf("Node %p at Index %d is free\n",temp,i);
            return;
        }
        temp = temp->nextBlock;
        i++;
    }
}

/* Private function */

/* init the memory */
void init(void)
{
    firstBlock = (memHeader_t *)memPool;
    firstBlock->blockSize = sizeof (memPool) - sizeof(memHeader_t);
    firstBlock->isFree = 1;
    firstBlock->nextBlock = NULL;
    firstBlock->memBlock = memPool+16;
    puts("memory init... complete");
}