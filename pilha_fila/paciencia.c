#include "deck.h"

// i%13 = 0 -> Espadas
// i%13 = 1 -> Paus
// i%13 = 2 -> Ouros
// i%13 = 3 -> Copas

int main(){

    stack_top *cards = stack_create();
    for(int i = 0; i < 52; i++){
        stack_push(cards , i);
        printf("number = %d   ", cards->head->number);
        printf("naipe = %d   ", cards->head->suit);
        printf("Turn = %d\n", cards->head->turn);
    }

    while(!stack_is_empty(cards)){
        printf("naipe = %d   ", cards->head->suit);
        printf("Turn = %d   ", cards->head->turn);
        printf("Pop %d\n", stack_pop(cards));
    }

    // stack_top *normal_stack_cards[7];
    // for(int i = 0; i < 7; i++){
    //     normal_stack_cards[i] = stack_create();
    // }

    // // Pilhas de monte e descarte
    // stack_top *stack_discard = stack_create();
    // stack_top *stack_stock = stack_create();

    // // Pilha de naipes
    // // 0 -> Espadas, 1 -> Copas, 2 -> Paus, 3 -> Ouros
    // stack_top *suits[4];
    // for(int i = 0; i < 4; i++){
    //     suits[i] = stack_create();
    // }

    // // Destruindo as pilhas
    // stack_destroy(stack_discard);
    // stack_destroy(stack_stock);
    stack_destroy(cards);

    // for(int i = 0; i < 7; i++){
    //     stack_destroy(normal_stack_cards[i]);
    // }

    // for(int i = 0; i < 4; i++){
    //     stack_destroy(suits[i]);
    // }

    return 0;
}