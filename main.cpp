#include <iostream>
#include "stack.h"
#include "stack_int.h"
#include "queue.h"

void Error_Handler() {
    printf("Illegal Operation.");
}

void stack_test();
void queue_test();
void circular_queue_test();
void linked_list_test();


int main() {
    stack_test();
    queue_test();

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

void queue_test() {
    queue queue{};
    queue_t * queue_ptr = &queue;

    enqueue_queue(int, queue_ptr, 1);
    enqueue_queue(int, queue_ptr, 2);
    enqueue_queue(int, queue_ptr, 3);


    printf("%d", consume_queue(int, queue_ptr));
    printf("%d", consume_queue(int, queue_ptr));
    printf("%d", consume_queue(int, queue_ptr));
}