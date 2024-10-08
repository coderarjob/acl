#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

struct llnode {
    void* item;
    struct llnode* next;
    struct llnode* prev;
};

struct linkedlist {
    int (*ismatch) (void* in, void* key);
    void (*free) (void* item);
    char* (*tostring) (void* item);

    struct llnode* head;
};

void acl_ll_remove_node (struct llnode* node, struct linkedlist* ll);
struct llnode* acl_ll_search (struct linkedlist* ll, void* key);
void acl_ll_free (struct linkedlist* ll);
struct llnode* acl_ll_insert (struct linkedlist* ll, void* what, size_t length);
struct linkedlist* acl_ll_create (int (*ismatch) (void* in, void* what), void (*free) (void* item),
                                  char* (*tostring) (void* item));

#endif // LINKEDLIST_H
