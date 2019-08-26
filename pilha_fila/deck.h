#include <stdlib.h>
#include <stdio.h>

typedef struct stack_element{
    int number;
    int suit;
    int naipe;
    int turn;
    struct stack_element *next_card;
} stack_element;

typedef struct{
    stack_element *head;
} stack_top;


stack_top *stack_create(){
    stack_top *stack = (stack_top*) malloc(sizeof(stack_top));
    if (stack == NULL){ 
        printf("Memory Error!!");
        exit(1);
    }
    stack->head = NULL;
    return stack;
}

void stack_push(stack_top *stack, int number){
    stack_element *card = (stack_element*) malloc(sizeof(stack_element));
    if (stack == NULL){
        printf("Memory Error!!");
    }
    card->number = number;
    card->suit = number%13;
    // card->naipe = number%13;
    card->turn = 1;
    card->next_card = stack->head;
    stack->head = card;
}

int stack_pop(stack_top *stack){
    stack_element *to_Free;
    int toReturn;
    if (stack->head != NULL){
        to_Free = stack->head;
        toReturn = to_Free->number;
        stack->head = stack->head->next_card;
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

