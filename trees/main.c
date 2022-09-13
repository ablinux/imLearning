#include <stdio.h>
#include <stdint.h>
#include "treeTypes.h"
#include "queue.h"
#include "stackLL.h"

void preOrderShow(tree_t *itr);
void levelShow(tree_t *itr);

int main()
{
    int input;
    printf("Add Element in tree..from array\n");
    queue_t *Q = initQueue(100);
    /* Now lets create the root */
    tree_t *root = malloc(sizeof(tree_t));
    printf("Enter Root\n");
    scanf("%d",&input);
    root->data = input;
    /* queue the item */
    enQueue(root);
    while(!isQueueEmpty())
    {
        tree_t *node = deQueue();
        printf("Enter right child\n");
        scanf("%d",&input);
        if(input != -1)
        {
            /* is Right node present ? */
            tree_t *temp = malloc(sizeof(tree_t));
            /* store it into the queue */
            temp->data = input; temp->right,temp->left = NULL;
            node->right = temp;
            enQueue(temp);
        }
        printf("Enter Left child\n");
        scanf("%d",&input);
        if(input != -1)
        {
            /* check if right is present */
            tree_t *temp1 = malloc(sizeof(tree_t));
            /* store it into the queue */
            temp1->data = input;temp1->right,temp1->left = NULL;
            node->left = temp1;
            enQueue(temp1);
        }
        printf("Tree Element till now......\n");
        preOrderShow(root);
        printf("\n");
        levelShow(root);

    }

}

void preOrderShow(tree_t *itr)
{
    if(itr!=NULL)
    {
        printf("%d\n",itr->data);
        preOrderShow(itr->left);
        preOrderShow(itr->right);
    }
}

void levelShow(tree_t *itr)
{
    while(itr!=NULL || !isStackEmpty())
    {
        if(itr!=NULL)
        {
            printf("%d\n", itr->data);
            push(itr);
            itr = itr->left;
        }
        else
        {
            itr = pop();
            itr = itr->right;
        }
    }
}