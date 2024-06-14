#include <iostream>
#include "stack.h"
#include "stack_int.h"

void Error_Handler() {
    printf("Illegal Operation.");
}

int main() {
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


    return 0;
}
