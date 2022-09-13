#include "stackLL.h"


/* Private to Stack */
list_t *top = NULL;
static void insert(list_t *,datatype *);
static void delete(list_t *, datatype *);
static void initList(list_t **);
void show(list_t *top);

int main()
{
    datatype data = 9;
    push(&data);data++;
    push(&data);data++;
    push(&data);data++;
    push(&data);data++;
    push(&data);data++;
    push(&data);data++;
    push(&data);data++;
    show(top);
    pop();
    pop();
    pop();
    pop();
    pop();
    pop();
    show(top);


}

/* Stack FUnctions */
int push(datatype *data)
{
    if(isFull())
    {
        puts("Stack is full");
        return 1;
    }
    insert(top,data);
    return 0;
}

datatype *pop(void)
{
    static datatype returnData;
    if(isEmpty())
    {
        return NULL;
    }
    else
    {
        list_t *temp_top = top;
        returnData = top->data;
        top = top->next;
        free(temp_top);
        return &returnData;
    }

}

int isFull(void)
{
    /* Only way to check if stack is full by verifying that no more head is available */
    list_t *temp = malloc(sizeof(list_t));
    if(temp == NULL)
    {
        return 1;
    }
    else
    {
        free(temp);
        return 0;
    }
}

int isEmpty(void)
{
    return (top==NULL);
}

int initStack(uint32_t size )
{

}

/* Linked list function s*/
static void insert(list_t *LastItem, datatype *data)
{
    if(top == NULL) /* 1st time push */
    {
        initList(&top);
        top->data = *data;
        top->next = NULL;
        puts("Fresh Creation of list");
    }
    else /* otherwise */
    {
        list_t *temp = malloc(sizeof(list_t));
        temp->data = *data;
        temp->next = top;
        top = temp;
    }
    
}
static void delete(list_t *LastItem, datatype *data)
{

}
static void initList(list_t **head)
{
    *head = malloc(sizeof(list_t));
}
void show(list_t *top)
{
    list_t *itr = top;
    while(itr != NULL)
    {
        printf("%d ",itr->data);
        itr = itr->next;
    }
    printf("\n");
}