#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
typedef struct list
{
    uint8_t data;
    struct list *next;
} list_t;
void add_front(list_t **head, uint8_t data);
void display(list_t **head);
void ret(uint8_t *a);

int main()
{
    list_t Head = {.data=0,.next=NULL};
    add_front(&Head, 10);
    add_front(&Head, 20);
    add_front(&Head, 30);
    add_front(&Head, 40);

    display(&Head);
int a = 10;
ret(&a);
printf("%d\n",a);
}

void add_front(list_t **head, uint8_t data)
{
    list_t *newList = (list_t *)malloc(sizeof(list_t));
    newList->data = data;
    newList->next = *head;
    *head = newList;
}

void display(list_t **head)
{
    list_t *temp = *head;
    while (temp != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}
void ret(uint8_t *a)
{
}