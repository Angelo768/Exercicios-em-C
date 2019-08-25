#include "stack.h"

int main(){

    stack_top *stack = stack_create();

    for(int i = 0; i < 10; i++){
        printf("Pushing %d\n", i);
        stack_push(stack, i);
    }

    while(!stack_is_empty(stack)){
        printf("Pop %d\n", stack_pop(stack));
    }

    stack_destroy(stack);
    return 0;
}