#include "include/list.h"
#include <stdio.h>

/*This is an example of linear list implemented using this library*/




//This is pre-defined meacros in header which replaces functions for DS datatype
DEFINE_LL_STRUCT(intlist, int data);
DEFINE_LL_CREATENODE_FUN(intlist, int data, .data = data);
DEFINE_LL_NTH_NODE_FUN(intlist)
DEFINE_LL_DELETENODE_FUN(intlist)


int main(){

    //This how we use in functions.
    struct ll_intlist *head = intlist_createNode(10);
    head->next = intlist_createNode(20);
    head->next->next = intlist_createNode(30);

    struct ll_intlist *second = intlist_get_nthNode(head, 1);
    if (second)     printf("Second node value = %d\n", second->data);


    intlist_deleteNode(head);
    return 0;
}