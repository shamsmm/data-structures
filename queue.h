#ifndef DATASTRUCTURES_QUEUE_H
#define DATASTRUCTURES_QUEUE_H


typedef struct queue_item {
    void * value;
    queue_item * next;
} queue_item_t;

typedef struct queue {
    queue_item_t * head;
    queue_item_t * tail;
} queue_t;

#define enqueue_queue(datatype, queue, x) \
do {                                          \
    auto * item = (queue_item *) malloc(sizeof(queue_item)); \
    item->value = malloc(sizeof(datatype));      \
    *((datatype *) item->value) = x;      \
    if (queue->tail) {                        \
        queue->tail->next = item;             \
    }                                         \
    queue->tail = item;                       \
    if (!queue->head) {                       \
        queue->head = item;                   \
    }                                         \
} while(0)

#define consume_queue(datatype, queue) \
[&queue](){                            \
    if (!queue->head){ return 0; } \
    queue_item * item = queue->head; \
    queue->head = queue->head->next; \
    datatype value = *((datatype *) item->value); \
    free(item); \
    return value;                                       \
}()
#endif //DATASTRUCTURES_QUEUE_H
