#include <iostream>
#include "stack.h"
#include "stack_int.h"

void Error_Handler() {
    printf("Illegal Operation.");
}

int main() {
    stack_t stack;

    int i = [](){
        return 1;
    }();

    stack_initialize_int(&stack, 10);
    stack_push_int(&stack, 1);
    stack_push_int(&stack, 2);
    stack_push_int(&stack, 3);

    printf("%d", stack_pop_int(&stack));
    printf("%d", stack_pop_int(&stack));
    printf("%d", stack_pop_int(&stack));

    return 0;
}
