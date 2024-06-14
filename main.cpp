#include <iostream>
#include "stack.h"
#include "stack_int.h"
#include "queue.h"

void Error_Handler() {
    printf("Illegal Operation.");
}

void stack_test();
void circular_queue_test();
void linked_list_test();

void add_to_queue(queue_t * queue, int value) {
    auto * item = (queue_item *) malloc(sizeof(queue_item));
    item->value = value;

    if (queue->tail) {
        queue->tail->next = item;
    }

    queue->tail = item;

    if (!queue->head) {
        queue->head = item;
    }
}

int consume_queue(queue_t * queue) {
    if (!queue->head)
        return 0;

    queue_item * item = queue->head;
    queue->head = queue->head->next;

    int value = item->value;
    free(item);

    return value;
}

int main() {
    stack_test();

    queue queue{};
    add_to_queue(&queue, 1);
    add_to_queue(&queue, 2);
    add_to_queue(&queue, 3);


    printf("%d", consume_queue(&queue));
    printf("%d", consume_queue(&queue));
    printf("%d", consume_queue(&queue));

    // consume

    return 0;
}

void stack_test() {
    stack_t stack;

    // using integer functions
    stack_initialize_int(&stack, 10);
    stack_push_int(&stack, 1);
    stack_push_int(&stack, 2);
    stack_push_int(&stack, 3);

    printf("%d\n", stack_pop_int(&stack));
    printf("%d\n", stack_pop_int(&stack));
    printf("%d\n", stack_pop_int(&stack));

    // using macros
    stack_t  * stack_ptr = &stack;
    stack_initialize(std::string, stack_ptr, 5);
    stack_push(std::string, stack_ptr, "First Element");
    stack_push(std::string, stack_ptr, "Second Element");
    stack_push(std::string, stack_ptr, "Third Element");

    printf("%s\n", stack_pop(std::string, stack_ptr).c_str());
    printf("%s\n", stack_pop(std::string, stack_ptr).c_str());
    printf("%s\n", stack_pop(std::string, stack_ptr).c_str());
}
