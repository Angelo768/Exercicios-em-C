#include "solitaire_functions.h"

int main(){

    card deck[52];
    stack_top *stock_discard[2];
    stack_top *cards_on_game[7];
    stack_top *cards_out[4];
    
    create_deck(deck);
    shuffle(deck);
    hand_out(cards_on_game, cards_out, stock_discard, deck);
    // printf("%d ", stock_discard[0]->head->number);
    // show_stack_game(cards_on_game);
    show_stack(cards_on_game);
    show_stock_discard(stock_discard);
    show_stack_cards_out(cards_out);
    // move_card(stock_discard[0], stock_discard[1]);

    for(int i = 0; i < 2;i++){
        while(!stack_is_empty(stock_discard[i])){
            stack_pop(stock_discard[i]);
        }
    }
    
    return 0;
}

void move_card(stack_top *comes[], stack_top *from[]){
    // stack_top *aux;
    // aux->head->number = comes[0]->head->number;
    // aux->head->suit = comes[0]->head->suit;
    // aux->head->color = comes[0]->head->color;
    // aux->head->turn_on = comes[0]->head->turn_on;
    stack_push(from[1], comes[0]->head->number, comes[0]->head->suit, comes[0]->head->color, comes[0]->head->turn_on);
    stack_pop(comes[0]);
}