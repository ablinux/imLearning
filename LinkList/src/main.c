#include <stdio.h>
#include "LinkList.h"
int main()
{

    puts("___LinkList Test Program___");
    list_t list;
    create_list(&list);
    diplayItems(&list);
    add(&list,10);
    add(&list,20);
    add(&list,30);
    
    diplayItems(&list);

    remove_item(&list,-1);
    diplayItems(&list);
    remove_item(&list,-1);
    diplayItems(&list);
    remove_item(&list,-1);
    diplayItems(&list);
    remove_item(&list,-1);
    diplayItems(&list);
    add(&list,10);
    add(&list,20);
    add(&list,30);
    
    diplayItems(&list);

    return 0;
}