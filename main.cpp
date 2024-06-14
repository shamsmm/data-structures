#include <iostream>

void Error_Handler() {
    printf("Illegal Operation.");
}

typedef struct stack {
    u_int size;
    void * sl;
    void * sp;
} stack_t;

void stack_initialize_int(stack_t * stack, u_int size) {
    stack->size = size;
    stack->sl = ((int *) malloc(sizeof(int) * size ));
    stack->sp = ((int *) stack->sl) + size;
}

void stack_push_int(stack_t * stack, int value) {
    stack->sp = ((int *) stack->sp) - 1;

    if (stack->sp < stack->sl)
        Error_Handler();

    *((int *) stack->sp) = value;
}

int stack_pop_int(stack_t * stack) {
    int * value = (int *) stack->sp;
    stack->sp = (int *) stack->sp + 1;

    if(stack->sp > ((int *) stack->sl) + stack->size)
        Error_Handler();

    return *value;
}

int main() {
    stack_t stack;

    stack_initialize_int(&stack, 10);
    stack_push_int(&stack, 1);
    stack_push_int(&stack, 2);
    stack_push_int(&stack, 3);

    printf("%d", stack_pop_int(&stack));
    printf("%d", stack_pop_int(&stack));
    printf("%d", stack_pop_int(&stack));

    return 0;
}
