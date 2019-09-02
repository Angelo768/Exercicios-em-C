#include "stack.h"

int main(){

    stack_top *stack = stack_create();

    for(int i = 0; i < 10; i++){
        printf("Pushing %d\n", i);
        stack_push(stack, i);
    }
    mostrar(stack);

    // for(int i = 0; i < 10;++i){
    //     printf("\t\t%d\n", stack->head->value);
    //     stack->head->next_element;
    // }

    while(!stack_is_empty(stack)){
        printf("Pop %d\n", stack_pop(stack));
    }

    return 0;
}