#include "deck.h"
#include <stdlib.h>
#include <time.h>

typedef struct card{
    int number;
    char suit;
    int turn_on;
} card;

void create_deck(card *deck);
void shuffle(card *deck);
void hand_out(stack_top *stack[], stack_top *stock, card *deck);


// void move_card();

int main(){

    card deck[52];
    stack_top *stock = stack_create();
    stack_top *cards_on_game[7];
    
    // stack_top *discard = NULL;
    // stack_top *cards_out[4];


    create_deck(deck);
    shuffle(deck);
    hand_out(cards_on_game, stock, deck);

    // for(int i = 0; i < 52; i++){
    //     printf("%d ", deck[i].number);
    //     printf("%c ", deck[i].suit);
    //     printf("%d ", deck[i].turn_on);
    //     printf("\n");
        // stack_push(stock, deck[i].number, deck[i].suit, deck[i].turn_on);
    // }

    for(int i = 0; i < 7; i++){
        while(!stack_is_empty(cards_on_game[i])){
            // printf("Pop %d\n", stack_pop(cards_on_game[i]));
            printf("%d", cards_on_game[i]->head->number);
            printf("%c ", cards_on_game[i]->head->suit);
            printf("%d ", cards_on_game[i]->head->turn_on);
            printf("\n");
            stack_pop(cards_on_game[i]);
        }
    }

    // while(!stack_is_empty(cards_on_game[0])){
            // printf("Pop %d\n", stack_pop(cards_on_game[i]));
    //         stack_pop(cards_on_game[0]);
    // }
    
    return 0;
}


void shuffle(card *deck){
    for (int i = 0; i < 52; i++){
        int r = rand() % 52;

        card temp = deck[i];
        deck[i] = deck[r];
        deck[r] = temp;
	}
}

void create_deck(card *deck){
    srand(time(NULL));
    int num = 0;
    char suit;
    for(int i = 0; i < 52; i++){
        num++;
        if (i % 13 == 0) num = 1;
        // if (i == 0 || i == 13 || i == 26 || i == 39) num = 65;
        // else if (i == 11 || i == 24 || i == 37 || i == 50) num = 65;
        // else if (i == 12 || i == 25 || i == 38 || i == 51) num = 65;
        // else if (i == 13 || i == 26 || i == 39 || i == 52) num = 65;
        // else num = 48;
        deck[i].number = num;
        deck[i].turn_on = 0;
        if (i < 13) deck[i].suit = 'C';
        else if (i < 26) deck[i].suit = 'P';
        else if (i < 39) deck[i].suit = 'O';
        else deck[i].suit = 'E';
    }    
}

void hand_out(stack_top *stack[], stack_top *stock, card *deck){
    for(int i = 0; i < 7; i++){
        stack[i] = stack_create();
    }

    stack_push(stack[0], deck[0].number, deck[0].suit, deck[0].turn_on);

    for(int i = 1; i < 3; i++) stack_push(stack[1], deck[i].number, deck[i].suit, deck[i].turn_on);
    
    for(int i = 3; i < 6; i++) stack_push(stack[2], deck[i].number, deck[i].suit, deck[i].turn_on);
    
    for(int i = 6; i < 10; i++) stack_push(stack[3], deck[i].number, deck[i].suit, deck[i].turn_on);
    
    for(int i = 10; i < 15; i++) stack_push(stack[4], deck[i].number, deck[i].suit, deck[i].turn_on);
    
    for (int i = 15; i < 21; i++) stack_push(stack[5], deck[i].number, deck[i].suit, deck[i].turn_on);
    
    for(int i = 21; i < 28; i++) stack_push(stack[6], deck[i].number, deck[i].suit, deck[i].turn_on);
    
    for(int i = 28; i < 52; i++) stack_push(stock, deck[i].number, deck[i].suit, deck[i].turn_on);
}