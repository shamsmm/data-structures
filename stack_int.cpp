#include <cstdlib>
#include "stack_int.h"
#include "stack.h"

void stack_initialize_int(stack_t * stack, u_int size) {
    stack_initialize(int, stack, size);
}

void stack_push_int(stack_t * stack, int value) {
    stack_push(int, stack, value);
}

int stack_pop_int(stack_t * stack) {
    return stack_pop(int, stack);
}

