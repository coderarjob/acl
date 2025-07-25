#define YUKTI_STRIP_PREFIX
#define YUKTI_TEST_IMPLEMENTATION
#include <yukti.h>
#include <list.h>
#include <queue.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

ListNode head;

typedef struct Queue {
    int number;
    ListNode runlist;
} Queue;

static void s_showQueueItems()
{
    ListNode* node;

    printf ("Printing forward:\n");
    queue_for_each (&head, node)
    {
        Queue* q = LIST_ITEM (node, Queue, runlist);
        printf ("Number: %d\n", q->number);
    }

    printf ("Printing backward:\n");
    queue_for_each_backward (&head, node)
    {
        Queue* q = LIST_ITEM (node, Queue, runlist);
        printf ("Number: %d\n", q->number);
    }
}

TEST (queue, dequeue_empty_queue)
{
    EQ_SCALAR (dequeue (&head), NULL);
    EQ_SCALAR (dequeue_back (&head), NULL);

    END();
}

TEST (queue, enqueue_backward_dequeue_forward_success)
{
    ListNode node1, node2;
    list_init (&node1);
    list_init (&node2);

    enqueue (&head, &node1);
    enqueue (&head, &node2);

    EQ_SCALAR (dequeue (&head), &node1);
    EQ_SCALAR (dequeue (&head), &node2);

    END();
}

TEST (queue, enqueue_forward_dequeue_backward_success)
{
    ListNode node1, node2;
    list_init (&node1);
    list_init (&node2);

    enqueue_front (&head, &node1);
    enqueue_front (&head, &node2);

    EQ_SCALAR (dequeue_back (&head), &node1);
    EQ_SCALAR (dequeue_back (&head), &node2);

    END();
}

TEST (queue, dequeue_forward_excess)
{
    ListNode node1, node2;
    list_init (&node1);
    list_init (&node2);

    enqueue (&head, &node1);
    enqueue (&head, &node2);

    EQ_SCALAR (dequeue (&head), &node1);
    EQ_SCALAR (dequeue (&head), &node2);
    EQ_SCALAR (dequeue (&head), NULL);
    EQ_SCALAR (dequeue (&head), NULL);
    END();
}

TEST (queue, dequeue_backward_excess)
{
    ListNode node1, node2;
    list_init (&node1);
    list_init (&node2);

    enqueue_front (&head, &node1);
    enqueue_front (&head, &node2);

    EQ_SCALAR (dequeue_back (&head), &node1);
    EQ_SCALAR (dequeue_back (&head), &node2);
    EQ_SCALAR (dequeue_back (&head), NULL);
    EQ_SCALAR (dequeue_back (&head), NULL);
    END();
}

TEST (queue, item_removal_success)
{
    ListNode node1, node2, node3;
    list_init (&node1);
    list_init (&node2);
    list_init (&node3);

    enqueue_front (&head, &node1);
    enqueue_front (&head, &node2);
    enqueue_front (&head, &node3);

    queue_remove (&node3);

    EQ_SCALAR (dequeue_back (&head), &node1);
    EQ_SCALAR (dequeue_back (&head), &node2);
    EQ_SCALAR (dequeue_back (&head), NULL);
    END();
}

TEST (queue, enqueue_dequeue_object)
{
    Queue queue[3] = { 0 };

    // Initialize the items array and add it to the queue
    for (int i = 0; i < 3; i++) {
        queue[i].number = 10 + i;
        list_init (&queue[i].runlist);
        enqueue (&head, &queue[i].runlist);
    }

    s_showQueueItems();

    // Dequeue one by one and check if the items match the order in which they
    // were added.
    ListNode* item = NULL;
    int i          = 0;
    while ((item = dequeue (&head)) != NULL) {
        Queue* q = (Queue*)LIST_ITEM (item, Queue, runlist);
        EQ_SCALAR (q, &queue[i++]);
    }

    END();
}

void yt_reset()
{
    list_init (&head);
}

int main()
{
    YT_INIT();
    dequeue_empty_queue();
    enqueue_backward_dequeue_forward_success();
    enqueue_forward_dequeue_backward_success();
    dequeue_forward_excess();
    dequeue_backward_excess();
    enqueue_dequeue_object();
    item_removal_success();

    YT_RETURN_WITH_REPORT();
}
