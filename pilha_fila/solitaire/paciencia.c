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
void hand_out(stack_top *stack[], stack_top *cards_out[], stack_top *stock, card *deck);
void show_stack_game(stack_top *stack[], stack_top *stock);
void show_stock_discard(stack_top *stock, stack_top *discard);
void show_stack_cards_out(stack_top *stack[]);
void move_card(stack_top *stack[], stack_top *stock);


int main(){

    card deck[52];
    stack_top *stock = stack_create();
    stack_top *discard = stack_create();
    stack_top *cards_on_game[7];
    stack_top *cards_out[4];
    
    create_deck(deck);
    shuffle(deck);
    hand_out(cards_on_game, cards_out, stock, deck);
    show_stack_game(cards_on_game, stock);
    show_stock_discard(stock, discard);
    show_stack_cards_out(cards_out);
    // move_card

    while(!stack_is_empty(stock) && !stack_is_empty(discard)){
        printf("Pop %d\n", stack_pop(stock));
        printf("Pop %d\n", stack_pop(discard));
    }
    
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

void hand_out(stack_top *stack[], stack_top *cards_out[], stack_top *stock, card *deck){
    for(int i = 0; i < 7; i++){
        stack[i] = stack_create();
    }
    stack_push(stack[0], deck[0].number, deck[0].suit, deck[0].color, 1);
                        
    for(int i = 1; i < 2; i++){
        stack_push(stack[1], deck[i].number, deck[i].suit, deck[i].color, 0);
    }
    stack_push(stack[1], deck[2].number, deck[2].suit, deck[2].color, 1);
    
    for(int i = 3; i < 5; i++){
        stack_push(stack[2], deck[i].number, deck[i].suit, deck[i].color, 0);
    }
    stack_push(stack[2], deck[5].number, deck[5].suit, deck[5].color, 1);

    for(int i = 6; i < 9; i++){
        stack_push(stack[3], deck[i].number, deck[i].suit, deck[i].color, 0);
    }
    stack_push(stack[3], deck[9].number, deck[9].suit, deck[9].color, 1);

    for(int i = 10; i < 14; i++){
        stack_push(stack[4], deck[i].number, deck[i].suit, deck[i].color, 0);
    }
    stack_push(stack[4], deck[14].number, deck[14].suit, deck[14].color, 1);
    
    for(int i = 15; i < 20; i++){
        stack_push(stack[5], deck[i].number, deck[i].suit, deck[i].color, 0);
    }
    stack_push(stack[5], deck[20].number, deck[20].suit, deck[20].color, 1);
    
    for(int i = 21; i < 27; i++){
        stack_push(stack[6], deck[i].number, deck[i].suit, deck[i].color, 0);
    }
    stack_push(stack[6], deck[27].number, deck[27].suit, deck[27].color, 1);
    
    for(int i = 29; i < 52; i++) stack_push(stock, deck[i].number, deck[i].suit, deck[i].color, 1);

    for(int i = 0; i < 4; i++){
        cards_out[i] = stack_create();
    }
}

void show_stack_game(stack_top *stack[], stack_top *stock){
    for(int i = 0; i < 7; i++){
            printf("\n");
            printf("J%d: ", i+1);
            printf("T%d", stack[i]->tam);
        while(!stack_is_empty(stack[i])){
            printf("|");

            if(stack[i]->head->number > 9) {
                if(stack[i]->head->number == 65 || stack[i]->head->number == 74 || stack[i]->head->number == 75 || stack[i]->head->number == 81){
                    printf(" %c ", stack[i]->head->number);
                }else{
                    printf("%d ", stack[i]->head->number);
                }
            } else printf(" %d ", stack[i]->head->number);
            printf("%c ", stack[i]->head->suit);
            printf("%c ", stack[i]->head->color);
            printf("%d ", stack[i]->head->turn_on);
            stack_pop(stack[i]);
        }
    }
    printf("\n\n");

}

void show_stock_discard(stack_top *stock, stack_top *discard){
    int a = 0;
    printf("E: T%d\n", stock->tam);
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

    printf("D: T%d\n", discard->tam);
    while(!stack_is_empty(discard)){
        printf("|");
        if(discard->head->number == 65 || discard->head->number == 74 || discard->head->number == 75 || discard->head->number == 81){
            printf("%c ", discard->head->number);
        }else{
            printf("%d ", discard->head->number);
        }  

        printf("%c ", discard->head->suit);
        printf("%c ", discard->head->color);
        printf("%d ", discard->head->turn_on);
        a++;
        if(a % 12 == 0) printf("\n");
        stack_pop(discard);
    }
    
}

void show_stack_cards_out(stack_top *cards_out[]){
    printf("\n");
    for(int i = 0; i < 4; i++){
            printf("S: T%d", cards_out[i]->tam);
            printf("\n");
        while(!stack_is_empty(cards_out[i])){
            printf("|");

            if(cards_out[i]->head->number > 9) {
                if(cards_out[i]->head->number == 65 || cards_out[i]->head->number == 74 || cards_out[i]->head->number == 75 || cards_out[i]->head->number == 81){
                    printf(" %c ", cards_out[i]->head->number);
                }else{
                    printf("%d ", cards_out[i]->head->number);
                }
            } else printf(" %d ", cards_out[i]->head->number);
            printf("%c ", cards_out[i]->head->suit);
            printf("%c ", cards_out[i]->head->color);
            printf("%d ", cards_out[i]->head->turn_on);
            stack_pop(cards_out[i]);
        }
    }
    printf("\n");

}
// void move_card(stack_top *stack[], stack_top *stock, stack_top *discard, stack_top *discard){

// }