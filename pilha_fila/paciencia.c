#include "deck.h"

create_deck();
shuffle_deck(card_top deck, int shuffle);
hand_out_cards();
move_card();

int main(){

    card_top deck[52];

    stack_cards *deck = stack_create();

    card_top *stock = NULL;
    card_top *discard = NULL;
    card_top *cards_on_game[7] = {NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    card_top *cards_out[4] = {NULL, NULL, NULL, NULL};
    
    return 0;
}