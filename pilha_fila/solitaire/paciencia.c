#include "deck.h"
#include <time.h>

typedef struct card{
    char number;
    char suit;
    char color;
    int turn_on;
} card;

void create_deck(card *deck);
void shuffle(card *deck);
void hand_out(stack_top *stack[], stack_top *stock, card *deck);
void show_stack_game(stack_top *stack[], stack_top *stock);
void show_stock(stack_top *stock);
void move_card(stack_top *stack[], stack_top *stock);


int main(){

    card deck[52];
    stack_top *stock = stack_create();
    stack_top *discard = stack_create();
    stack_top *cards_on_game[7];
    
    // stack_top *cards_out[4];

    create_deck(deck);
    shuffle(deck);
    hand_out(cards_on_game, stock, deck);
    show_stack_game(cards_on_game, stock);
    show_stock(stock);
    

    while(!stack_is_empty(stock) && !stack_is_empty(discard)){
        printf("Pop %d\n", stack_pop(stock));
        printf("Pop %d\n", stack_pop(discard));
    }

    // for(int i = 0; i = 7; i++){
    //     stack_destroy(cards_on_game[i]);
    // }
    
    return 0;
}

void create_deck(card *deck){
    srand(time(NULL)); // ATIVAR QUANDO FOR PRECISO EMBARALHAR !!!!!!!!!!!!!!!!!
    char num = 0;
    for(int i = 0; i < 52; i++){
        num++;
        if (i % 13 == 0) num = 1;
        if (i == 0 || i == 13 || i == 26 || i == 39) deck[i].number = 'A';
        else if (i == 10 || i == 23 || i == 36 || i == 49) deck[i].number = 'J';
        else if (i == 11 || i == 24 || i == 37 || i == 50) deck[i].number = 'Q';
        else if (i == 12 || i == 25 || i == 38 || i == 51) deck[i].number = 'K';
        else deck[i].number = num;

        deck[i].turn_on = 0;

        if (i < 13) {deck[i].suit = 'C'; deck[i].color = 'R';} 
        else if (i < 26) {deck[i].suit = 'P'; deck[i].color = 'B';} 
        else if (i < 39) {deck[i].suit = 'O'; deck[i].color = 'R';} 
        else {deck[i].suit = 'E'; deck[i].color = 'B';}
    }    
}

void shuffle(card *deck){
    for (int i = 0; i < 52; i++){
        int r = rand() % 52;

        card temp = deck[i];
        deck[i] = deck[r];
        deck[r] = temp;
	}
}

void hand_out(stack_top *stack[], stack_top *stock, card *deck){
    for(int i = 0; i < 7; i++){
        stack[i] = stack_create();
    }
    int i = 0;
    int turn_on = 0;

    stack_push(stack[0], deck[0].number, deck[0].suit, deck[0].color, turn_on);
                        
    for(i = 1; i < 3; i++) stack_push(stack[1], deck[i].number, deck[i].suit, deck[i].color, turn_on);
    
    for(i = 3; i < 6; i++) stack_push(stack[2], deck[i].number, deck[i].suit, deck[i].color, turn_on);
    
    for(i = 6; i < 10; i++) stack_push(stack[3], deck[i].number, deck[i].suit, deck[i].color, turn_on);
    
    for(i = 10; i < 15; i++) stack_push(stack[4], deck[i].number, deck[i].suit, deck[i].color, turn_on);
    
    for(i = 15; i < 21; i++) stack_push(stack[5], deck[i].number, deck[i].suit, deck[i].color, turn_on);
    
    for(i = 21; i < 28; i++) stack_push(stack[6], deck[i].number, deck[i].suit, deck[i].color, turn_on);
    
    for(i = 28; i < 52; i++) stack_push(stock, deck[i].number, deck[i].suit, deck[i].color, turn_on);

}

void show_stack_game(stack_top *stack[], stack_top *stock){
    for(int i = 0; i < 7; i++){
            printf("\n");
            printf("J%d: ", i+1);
        while(!stack_is_empty(stack[i])){
            printf("|");

            if(stack[i]->head->number == 65 || stack[i]->head->number == 74 || stack[i]->head->number == 75 || stack[i]->head->number == 81){
                printf("%c ", stack[i]->head->number);
            }else{
                printf("%d ", stack[i]->head->number);
            }
            printf("%c ", stack[i]->head->suit);
            printf("%c ", stack[i]->head->color);
            printf("%d ", stack[i]->head->turn_on);
            stack_pop(stack[i]);
        }
    }
    printf("\n\n");

}

void show_stock(stack_top *stock){
    printf("E: \n");
    int a = 0;
    while(!stack_is_empty(stock)){
        printf("|");
        if(stock->head->number == 65 || stock->head->number == 74 || stock->head->number == 75 || stock->head->number == 81){
            printf("%c ", stock->head->number);
        }else{
            printf("%d ", stock->head->number);
        }  

        printf("%c ", stock->head->suit);
        printf("%c ", stock->head->color);
        printf("%d ", stock->head->turn_on);
        a++;
        if(a % 12 == 0) printf("\n");
        stack_pop(stock);
    }
    printf("\n");

}

// void move_card(stack_top *stack[], stack_top *stock, stack_top *discard, stack_top *discard){

// }