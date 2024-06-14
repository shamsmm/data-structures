#ifndef DATASTRUCTURES_STACK_INT_H
#define DATASTRUCTURES_STACK_INT_H

#include <cstdlib>
#include "stack.h"

void stack_initialize_int(stack_t * stack, u_int size);
void stack_push_int(stack_t * stack, int value);
int stack_pop_int(stack_t * stack);

#endif //DATASTRUCTURES_STACK_INT_H
