#include <stdlib.h>
#include <stdio.h>

typedef struct stack_cards{
    int value;
    int turn;
    char suit;
    struct stack_cards *next_element;
} stack_cards;

typedef struct{
    stack_cards *head;
} card_top;


card_top *stack_create(){
    card_top *stack = (card_top*) malloc(sizeof(card_top));
    if (stack == NULL){ 
        printf("Memory Error!!");
        exit(1);
    }
    stack->head = NULL;
    return stack;
}

void stack_push(card_top *stack, int value){
    stack_cards *element = (stack_cards*) malloc(sizeof(stack_cards));
    if (stack == NULL){
        printf("Memory Error!!");
    }
    element->value = value;
    element->next_element = stack->head;
    stack->head = element;
}

int stack_pop(card_top *stack){
    stack_cards *to_Free;
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

int stack_is_empty(card_top *stack){
    if (stack->head == NULL){
        return 1;
    }else{
        return 0;
    }
}

void stack_destroy(card_top *stack){
    while(stack_is_empty(stack) == 1){
        stack_pop(stack);
    }
    free(stack);
}

