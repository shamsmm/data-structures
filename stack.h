#ifndef DATASTRUCTURES_STACK_H
#define DATASTRUCTURES_STACK_H

extern void Error_Handler();

typedef struct stack {
    u_int size;
    void * sl;
    void * sp;
} stack_t;

#define stack_initialize(datatype, stack, amount) \
do { \
    stack->size = amount; \
    stack->sl = ((datatype *) malloc(sizeof(datatype) * amount )); \
    stack->sp = ((datatype *) stack->sl) + amount; \
} while(0)

#define stack_push(datatype, stack, value) \
do { \
    stack->sp = ((datatype *) stack->sp) - 1; \
    if (stack->sp < stack->sl) \
        Error_Handler(); \
    *((datatype *) stack->sp) = value; \
} while(0)

#define stack_pop(datatype, stack) \
[&stack](){ \
    datatype * value = (datatype *) stack->sp; \
    stack->sp = (datatype *) stack->sp + 1; \
    if(stack->sp > ((datatype *) stack->sl) + stack->size) \
        Error_Handler(); \
    return *value; \
}()

#endif //DATASTRUCTURES_STACK_H
