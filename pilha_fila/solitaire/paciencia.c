#include "deck.h"
#include <stdlib.h>
#include <time.h>

typedef struct card{
    int number;
    char suit;
    int turn_on;
} card;

void create_deck(stack_top *stack, card *deck){
    srand(time(NULL));
    int num = 0;
    char suit;
    for(int i = 0; i < 52; i++){
        num++;
        if (i % 13 == 0) num = 1;
        deck[i].number = num;
        deck[i].turn_on = 0;
        if (i < 13) deck[i].suit = 'H';
        else if (i < 26) deck[i].suit = 'C';
        else if (i < 39) deck[i].suit = 'D';
        else deck[i].suit = 'S';
    }

    for (int i = 0; i < 52; i++){
        int r = rand() % 52;

        card temp = deck[i];
        deck[i] = deck[r];
        deck[r] = temp;
	}

    for(int i = 0; i < 52; i++){
        printf("%d ", deck[i].number);
        printf("%c ", deck[i].suit);
        printf("%d ", deck[i].turn_on);
        printf("\n");
        stack_push(stack, deck[i].number, deck[i].suit, deck[i].turn_on);
    }
}

// void shuffle_deck(stack_top *deck, int shuffle);
// void move_card();

int main(){

    // stack_top *stack_cards = stack_create();
    card deck[52];
    stack_top *stock = stack_create();

    // for (int i=0; i < 52; i++){
    //     printf("%d ", i);
    //     printf("%d ",1 + rand() % 13);
    //     printf("\n");
    // }
    // printf("\n");
    create_deck(stock, deck);
    
    while(!stack_is_empty(stock)){
        // printf("Pop %d\n", stack_pop(stock));
        stack_pop(stock);
    }

    // stack_top *discard = NULL;
    // stack_top *cards_on_game[7] = {NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    // stack_top *cards_out[4] = {NULL, NULL, NULL, NULL};
    
    return 0;
}