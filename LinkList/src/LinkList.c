#include "LinkList.h"


void create_list(list_t *p_list)
{
    /* user requested to create the list 
    allocate the memory for head and end node */
    printf("Creating LinkList\n");
    /* Loan the memory from Heap */
    p_list->Head = (node_t*)malloc(sizeof(node_t));
    p_list->Head->Next = NULL;
    p_list->END = p_list->Head;
    p_list->nodeCount = -1;
    printf("Address of Head = %p\n",p_list->Head);

}


void distroy_list(list_t *p_list)
{

}


uint8_t add(list_t*p_list,uint32_t data)
{
    /* Check if this is not the 1st time we called */
    if(p_list->Head->Next == NULL)
    {
        printf("Empty list, Adding item %d\n",data);
        /*If you are here which means this is the 1st item we are going to insert */
        node_t *newNode = (node_t*)malloc(sizeof(newNode));
        newNode->data = data;
        p_list->Head->Next = newNode;
        p_list->END = newNode;
        p_list->nodeCount=1;
    }
    else
    {
        printf("Adding Items %d\n",data);
        /* Loan a memory from Heap for new node */
        node_t *newNode = (node_t*)malloc(sizeof(newNode));
        newNode->data = data;
        newNode->Next = NULL;
        p_list->END->Next = newNode;
        p_list->END = newNode;
        p_list->nodeCount ++;
    }
    return 0;
}

void diplayItems(list_t *p_list)
{
    node_t *itrList = p_list->Head->Next;

    /* Check if the list is empty */
    if(p_list->Head->Next == NULL)
    {
        printf("XXXXXXXX-----No item in the list-----XXXXXXXXX \n");
    }
    else
    {
        printf("--------- displaying all the item in List---------\n");
        printf("HEAD [address of 1st item %p] total nodes [%d]\n",p_list->Head->Next,p_list->nodeCount);
        while (itrList != NULL)
        {
            printf("[addrofNode %p] [Next %p] [Data %d] \n",itrList,itrList->Next,itrList->data);
            itrList = itrList->Next;
        }
        printf("---------------------------------------------------\n\n");
    }
    
    
}

uint8_t remove_item(list_t *p_list,int32_t index)
{
    node_t *cur,*prv;

    /* 1st check if the list it not emplty */
    if(p_list->Head != p_list->END)
    {
        /* if index is passed as -1 remove from the end 
        or
        if user send the index = last item do the same*/
        if((index == -1) || ((p_list->nodeCount-1) == index))
        {
            cur = p_list->Head;
            while (cur->Next != NULL)
            {
                prv = cur;
                cur = cur->Next;
            }
            /* Here we have location of 2 nodes 1 the end and 2nd the prv node
            which is going to be end node after deleting the last node */
            p_list->END = prv;
            p_list->END->Next = NULL;
            p_list->nodeCount --;

            printf("Removed node Addr: [%p] Data [%d]\n\n",cur,cur->data);
            free(cur);
        }
        else
        {
            /* Remove data from anyware */
        }
    }
    else
    {
        printf("Cannot delete the request item : LIST is Empty \n");
        return 1;
    }
    return 0;
}
