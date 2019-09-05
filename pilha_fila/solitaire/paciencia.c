#include "solitaire_functions.h"

int main(){

    card deck[52];
    stack_top *stock_discard[2];
    stack_top *cards_on_game[7];
    stack_top *cards_out[4];
    
    create_deck(deck);
    shuffle(deck);
    hand_out(cards_on_game, cards_out, stock_discard, deck);
    // show_stack(cards_on_game, 7, 'J');
    // printf("Number: %d \n", stock_discard[0]->head->number);
    // show_stack(stock_discard, 2, 'E');
    // move_card(stock_discard[0], stock_discard[1], 6);
    play_the_game(stock_discard, cards_on_game, cards_out);

    show_stack(stock_discard, 2, 'E');
    // show_stack(cards_out, 4, 'S');

    for(int i = 0; i < 7;i++){
        while(!stack_is_empty(cards_on_game[i])){
            stack_pop(cards_on_game[i]);
        }
    }

    for(int i = 0; i < 2;i++){
        while(!stack_is_empty(stock_discard[i])){
            stack_pop(stock_discard[i]);
        }
    }

    for(int i = 0; i < 4;i++){
        while(!stack_is_empty(cards_out[i])){
            stack_pop(cards_out[i]);
        }
    }  
    return 0;
}

