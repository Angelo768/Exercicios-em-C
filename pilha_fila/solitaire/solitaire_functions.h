#include "deck.h"
#include <time.h>

typedef struct card{
    char number;
    char next;
    char prev;
    char suit;
    char color;
    int turn_on;
} card;

void create_deck(card *deck);
void shuffle(card *deck);
void hand_out(stack_top *stack[], stack_top *cards_out[], stack_top *stock_discard[], card *deck);
void show_stack(stack_top *stack[], int tam, char letra);

void move_cards(stack_top *comes, stack_top *from, int cards);
void move_to_out(stack_top *stock_discard[], stack_top *cards_on_game[], stack_top *cards_out[]);
void move_stack_game_to_stack_game(stack_top *cards_on_game[]);

void play_the_game(stack_top *stock_discard[], stack_top *cards_on_game[], stack_top *cards_out[]);

void create_deck(card *deck){
    // srand(time(NULL)); // ATIVAR QUANDO FOR PRECISO EMBARALHAR !!!!!!!!!!!!!!!!!
    char num = 0;
    for(int i = 0; i < 52; i++){
        num++;
        if (i % 13 == 0) num = 1;
        if (i == 0 || i == 13 || i == 26 || i == 39) {
            deck[i].number = 'A';
            deck[i].next = 2;
        } else if (i == 1 || i == 14 || i == 27 || i == 40) {
            deck[i].prev = 'A';
            deck[i].number = 2;
            deck[i].next = 3;
        } else if (i == 9 || i == 22 || i == 35 || i == 48) {
            deck[i].prev = 9;
            deck[i].number = 10;
            deck[i].next = 'J';
        } else if (i == 10 || i == 23 || i == 36 || i == 49) {
            deck[i].prev = 10;
            deck[i].number = 'J';
            deck[i].next = 'Q';
        } else if (i == 11 || i == 24 || i == 37 || i == 50) {
            deck[i].prev = 'K';
            deck[i].number = 'Q';
            deck[i].next = 'J';
        } else if (i == 12 || i == 25 || i == 38 || i == 51) {
            deck[i].prev = 'Q';
            deck[i].number = 'K';
        } else {
            deck[i].prev = num-1;
            deck[i].number = num;
            deck[i].next = num+1;
        }

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

void hand_out(stack_top *stack[], stack_top *cards_out[], stack_top *stock_discard[], card *deck){

    for(int i = 0; i < 7; i++){
        stack[i] = stack_create();
    }

    stack_push(stack[0], deck[0].prev, deck[0].number, deck[0].next, deck[0].suit, deck[0].color, 1);
                        
    for(int i = 1; i < 2; i++){
        stack_push(stack[1], deck[i].prev, deck[i].number, deck[i].next, deck[i].suit, deck[i].color, 0);
    }
    stack_push(stack[1], deck[2].prev, deck[2].number, deck[2].next, deck[2].suit, deck[2].color, 1);
    
    for(int i = 3; i < 5; i++){
        stack_push(stack[2], deck[i].prev, deck[i].number, deck[i].next, deck[i].suit, deck[i].color, 0);
    }
    stack_push(stack[2], deck[5].prev, deck[5].number, deck[5].next, deck[5].suit, deck[5].color, 1);

    for(int i = 6; i < 9; i++){
        stack_push(stack[3], deck[i].prev, deck[i].number, deck[i].next, deck[i].suit, deck[i].color, 0);
    }
    stack_push(stack[3], deck[9].prev, deck[9].number, deck[9].next, deck[9].suit, deck[9].color, 1);

    for(int i = 10; i < 14; i++){
        stack_push(stack[4], deck[i].prev, deck[i].number, deck[i].next, deck[i].suit, deck[i].color, 0);
    }
    stack_push(stack[4], deck[14].prev, deck[14].number, deck[14].next, deck[14].suit, deck[14].color, 1);
    
    for(int i = 15; i < 20; i++){
        stack_push(stack[5], deck[i].prev, deck[i].number, deck[i].next, deck[i].suit, deck[i].color, 0);
    }
    stack_push(stack[5], deck[20].prev, deck[20].number, deck[20].next, deck[20].suit, deck[20].color, 1);
    
    for(int i = 21; i < 27; i++){
        stack_push(stack[6], deck[i].prev, deck[i].number, deck[i].next, deck[i].suit, deck[i].color, 0);
    }
    stack_push(stack[6], deck[27].prev, deck[27].number, deck[27].next, deck[27].suit, deck[27].color, 1);
    
    for(int i = 0; i < 2; i++) stock_discard[i] = stack_create();

    for(int i = 28; i < 52; i++) stack_push(stock_discard[0], deck[i].prev, deck[i].number, deck[i].next, deck[i].suit, deck[i].color, 1);

    for(int i = 0; i < 4; i++){
        cards_out[i] = stack_create();
    }

}

void show_stack(stack_top *stack[], int tam, char letra){
    
    for(int i = 0; i < tam; i++){
        printf("\n");
        printf("%c%d: ",letra, i+1);
        printf("T%d", stack[i]->tam);
        while(!stack_is_empty(stack[i])){
            printf("|");

            if(stack[i]->head->number > 9){
                if(stack[i]->head->number == 65 || stack[i]->head->number == 74 || stack[i]->head->number == 75 || stack[i]->head->number == 81){
                    printf(" %c", stack[i]->head->number);
                }else{
                    printf("%d", stack[i]->head->number);
                }
            } else printf(" %d", stack[i]->head->number);
            printf("%c ", stack[i]->head->suit);
            printf("%c ", stack[i]->head->color);
            printf("%d ", stack[i]->head->turn_on);
            stack_pop(stack[i]);
        }
            if (tam == 2) printf("\n");
    }
    printf("\n");
}

void move_cards(stack_top *comes, stack_top *from, int cards){
        for(int i = 0; i < cards; i++){
            stack_push(from, comes->head->prev, comes->head->number, comes->head->next, comes->head->suit, comes->head->color, comes->head->turn_on);
            stack_pop(comes);
        }
}

void play_the_game(stack_top *stock_discard[], stack_top *cards_on_game[], stack_top *cards_out[]){
    
    // abre uma carta de _estoque_
    // tenta mover cartas {
    //     1. pilha de jogo e pilha de descate para pilha de saída;
    //     2. pilha de jogo para pilha de jogo;
    //     3. pilha de descarte para pilha de jogo;
    // }
    // se n tiver movimento possível, go to 157;

    move_cards(stock_discard[0], stock_discard[1], 1);
    // move_stack_game_to_stack_game(cards_on_game);
    // move_to_out(stock_discard, cards_on_game, cards_out);
}

void move_to_out(stack_top *stock_discard[], stack_top *cards_on_game[], stack_top *cards_out[]){

    while(stock_discard[1]->head->number == 'A'){
        if (stock_discard[1]->head->suit == 'E'){
            printf("E S1 AE\n");
            move_cards(stock_discard[1], cards_out[0], 1);
            move_cards(stock_discard[0], stock_discard[1], 1);

        } else if (stock_discard[1]->head->suit == 'C') {
            printf("E S2 AC\n");
            move_cards(stock_discard[1], cards_out[1], 1);
            move_cards(stock_discard[0], stock_discard[1], 1);

        } else if (stock_discard[1]->head->suit == 'P') {
            printf("E S3 AP\n");
            move_cards(stock_discard[1], cards_out[2], 1);
            move_cards(stock_discard[0], stock_discard[1], 1);

        } else if (stock_discard[1]->head->suit == 'O') {
            printf("E S4 AO\n");
            move_cards(stock_discard[1], cards_out[3], 1);
            move_cards(stock_discard[0], stock_discard[1], 1);
        }
    }

    for(int i = 0; i < 7; i++){
        if(cards_on_game[i]->head->number == 'A'){
            if (cards_on_game[i]->head->suit == 'E'){
                printf("J%d S1 AE\n", i+1);
                move_cards(cards_on_game[i], cards_out[0], 1);

            } else if (cards_on_game[i]->head->suit == 'C') {
                printf("J%d S2 AC\n", i+1);
                move_cards(cards_on_game[i], cards_out[1], 1);

            } else if (cards_on_game[i]->head->suit == 'P') {
                printf("J%d S3 AP\n", i+1);
                move_cards(cards_on_game[i], cards_out[2], 1);

            } else if (cards_on_game[i]->head->suit == 'O') {
                printf("J%d S4 AO\n", i+1);
                move_cards(cards_on_game[i], cards_out[3], 1);
            } 
         }
        if(cards_on_game[i]->head != NULL) cards_on_game[i]->head->turn_on = 1;
    }


        for(int i = 0; i < 4; i++){
            if(cards_out[i]->head == NULL){
                i++;
            } else {
                for(int j = 0; j < 7; j++){
                    if(cards_on_game[j]->head != NULL){
                        if((cards_on_game[j]->head->number == cards_out[i]->head->next) && (cards_on_game[j]->head->suit == cards_out[i]->head->suit)){
                            if(cards_on_game[i]->head->number != 65 || cards_on_game[i]->head->number != 74 || cards_on_game[i]->head->number != 75 || cards_on_game[i]->head->number != 81){
                                printf("J%d S%d %d%c", j+1, i+1, cards_on_game[j]->head->number, cards_on_game[i]->head->suit);
                            }
                            move_cards(cards_on_game[j], cards_out[i], 1);
                            if(cards_on_game[j]->head != NULL) cards_on_game[j]->head->turn_on = 1;
                        }
                    }
                }
            }
    }
}

void move_stack_game_to_stack_game(stack_top *cards_on_game[]){
    stack_element *aux;
    for (int i = 0; i < 7; i++){
        if(cards_on_game[i]->head == NULL) i++;
        
        aux = cards_on_game[i]->head;
        for (int n = 1; aux != NULL; n++){
            if(aux->turn_on == 0) {break;};
            for(int j=0; j<7;j++) {
                if(cards_on_game[j]->head != NULL) {
                    if(cards_on_game[j]->head->number == aux->next) {
                        printf("J%d J%d %d%c\n ", 1+i, 1+j, aux->number, aux->suit);
                        move_cards(cards_on_game[i], cards_on_game[j], n);
                        break;
                    }
                }
            }
            aux = aux->next_element;
        }
    }
}