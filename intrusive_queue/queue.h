#ifndef INTRU_QUEUE_H
#define INTRU_QUEUE_H
#include <list.h>

static inline void queue_init(ListNode *forward, ListNode *backward)
{
    list_init(forward);
    list_init(backward);
    list_add_after(forward, backward);
}

static inline void enqueue_back(ListNode *backward, ListNode *item) 
{
    list_add_before(backward, item);
}

static inline ListNode* dequeue_forward(ListNode *forward, ListNode *backward)
{
    if (forward->next == backward) {
        return NULL;
    }
    ListNode *node =  forward->next;
    list_remove(forward->next);
    return  node;
}

static inline void queue_remove(ListNode *node)
{
    list_remove(node);
}

static inline void enqueue_forward(ListNode *forward, ListNode *item)
{
    list_add_after(forward, item);
}

static inline ListNode* dequeue_backward(ListNode *forward, ListNode *backward)
{
    if (backward->prev == forward) {
        return NULL;
    }

    ListNode *node = backward->prev;
    list_remove(backward->prev);
    return node;
}

#endif // INTRU_QUEUE_H

