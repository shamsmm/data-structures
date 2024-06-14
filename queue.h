#ifndef DATASTRUCTURES_QUEUE_H
#define DATASTRUCTURES_QUEUE_H


typedef struct queue_item {
    int value;
    queue_item * next;
} queue_item_t;

typedef struct queue {
    queue_item_t * head;
    queue_item_t * tail;
} queue_t;

#endif //DATASTRUCTURES_QUEUE_H
