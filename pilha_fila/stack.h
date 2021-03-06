#include <stdlib.h>
#include <stdio.h>

typedef struct stack_element{
    int value;
    struct stack_element *next_element;
} stack_element;

typedef struct stack_topper{
    stack_element *head;
} stack_top;

int tam;

stack_top *stack_create(){
    tam = 0;
    stack_top *stack = (stack_top*) malloc(sizeof(stack_top));

    if (stack == NULL){ 
        printf("Memory Error!!");
        exit(1);
    }
    stack->head = NULL;
    return stack;
}

void stack_push(stack_top *stack, int value){
    stack_element *element = (stack_element*) malloc(sizeof(stack_element));
    if (stack == NULL){
        printf("Memory Error!!");
    }
    element->value = value;
    tam++;
    element->next_element = stack->head;
    stack->head = element;
}

int stack_pop(stack_top *stack){
    stack_element *to_Free;
    int toReturn;
    if (stack->head != NULL){
        to_Free = stack->head;
        toReturn = to_Free->value;
        stack->head = stack->head->next_element;
    }else{
        printf("Stack is empty!!\n");
        exit(1);
    }
    return toReturn;
}

int stack_is_empty(stack_top *stack){
    if (stack->head == NULL){
        return 1;
    }else{
        return 0;
    }
}

void stack_destroy(stack_top *stack){
    while(stack_is_empty(stack) == 1){
        stack_pop(stack);
    }
    free(stack);
}

 