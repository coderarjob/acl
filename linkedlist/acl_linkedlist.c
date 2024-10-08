/*
 * This linked list is part of acl (Arjob's Common Library)
 *
 * Author: Arjob Mukherjee (mukherjeearjob@gmail.com)
 * Dated: 4 Jan 2019
 *
 * Version 1b
 */
#include "acl_linkedlist.h"

static struct llnode* malloc_llnode (void* what, size_t length);

static struct llnode* malloc_llnode (void* what, size_t length)
{
    struct llnode* newnode = NULL;
    newnode                = (struct llnode*)malloc (sizeof (struct llnode));

    newnode->item = calloc (1, length);
    memcpy (newnode->item, what, length);

    newnode->next = NULL;
    newnode->prev = NULL;

    return newnode;
}

struct llnode* acl_ll_search (struct linkedlist* ll, void* key)
{
    struct llnode* thisnode = ll->head;

    while (thisnode != NULL) {
        if (ll->ismatch (thisnode->item, key))
            return thisnode;

        thisnode = thisnode->next;
    }

    return NULL;
}

static void remove_headNode (struct linkedlist* ll, struct llnode* next)
{
    if (next != NULL)
        next->prev = ll->head->prev;

    ll->head = next;
}

static void remove_lastNode (struct linkedlist* ll, struct llnode* node)
{
    ll->head->prev = node->prev;
}

void acl_ll_remove_node (struct llnode* node, struct linkedlist* ll)
{
    if (node == ll->head)
        remove_headNode (ll, ll->head->next);
    else {
        node->prev->next = node->next;

        if (node->next == NULL)
            remove_lastNode (ll, node);
        else
            node->next->prev = node->prev;
    }

    free (node->item);
    free (node);
}

void acl_ll_free (struct linkedlist* ll)
{
    fprintf (stderr, "FREE\n");

    struct llnode* thisnode = ll->head;
    struct llnode* nextnode;
    while (thisnode != NULL) {
        nextnode = thisnode->next;
        ll->free (thisnode->item);
        free (thisnode);
        thisnode = nextnode;
    }
}

struct linkedlist* acl_ll_create (int (*ismatch) (void* in, void* what), void (*free) (void* item),
                                  char* (*tostring) (void* item))
{
    struct linkedlist* newll = malloc (sizeof (struct linkedlist));
    newll->ismatch           = ismatch;
    newll->free              = free;
    newll->tostring          = tostring;
    newll->head              = NULL;
    return newll;
}

struct llnode* acl_ll_insert (struct linkedlist* ll, void* what, size_t length)
{
    struct llnode* newnode = malloc_llnode (what, length);

    if (ll->head == NULL) {
        // create head
        ll->head       = newnode;
        ll->head->prev = ll->head;
    } else {
        newnode->prev        = ll->head->prev;
        ll->head->prev->next = newnode;
        ll->head->prev       = newnode;
    }

    return newnode;
}
