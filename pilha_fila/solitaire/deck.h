#include <stdlib.h>
#include <stdio.h>

typedef struct stack_element{
    char number;
    char suit;
    int turn_on;
    struct stack_element *next_element;
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

void stack_push(stack_top *stack, int number, char suit, int turn_on){
    stack_element *element = (stack_element*) malloc(sizeof(stack_element));
    if (stack == NULL){
        printf("Memory Error!!");
    }
    element->number = number;
    element->suit = suit;
    element->turn_on = turn_on;
    element->next_element = stack->head;
    stack->head = element;
}

int stack_pop(stack_top *stack){
    stack_element *to_Free;
    int toReturn;
    if (stack->head != NULL){
        to_Free = stack->head;
        toReturn = to_Free->number;
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

void exibe(stack_top *stack){
    if(stack->head == NULL){
        printf("Stack is empty");
    }

    stack_element *tmp;
    tmp = stack->head->next_element;
    printf("stack:");
    while( tmp != NULL){
        printf("%d", tmp->number);
        printf("%c", tmp->suit);
        printf("%d", tmp->turn_on);
        tmp = tmp->next_element;
    }

    printf("\n        ");

    for(int count=0 ; count < 52 ; count++)
    printf("  ^  ");
    printf("\nOrdem:");
    for(int count=0 ; count < 52 ; count++)
    printf("%5d", count+1);


    printf("\n\n");
}
