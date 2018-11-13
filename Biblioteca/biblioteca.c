#include <stdio.h>
#include "menumatriz.h"
#include "menuvetor.h"

int **vector1 = NULL , **vector2 = NULL;
int *tam1, **tam2;

int main(){
    int op;


    //printf("\e[H\e[2J");
    printf("==============================\n");
    printf("|\tMenu Inicial         |\n");
    printf("==============================\n");
    printf("|1. Operações com vetores    |\n");
    printf("|2. Operações com matrizes   |\n");
    printf("|3. Sair do programa         |\n\n");
    printf("Operação desejada: ");
    scanf("%d", &op);
    switch (op){
        case 1: menuvetor(); break;
        case 2: menumatriz(); break;
        case 3: printf("Encerrando programa...\n"); break;
        default: printf("Opção inválida\n"); break;
    }
}


int menuvetor(){
    int mv;

    printf("\e[H\e[2J");
    printf("===================================================\n");
    printf("|\t\tMenu Vetor                        |\n");
    printf("===================================================\n");
    printf("|1. Ler vetores.                                  |\n");
    printf("|2. Somar dois vetores.                           |\n");
    printf("|3. Multiplicar um dos vetores por um escalar.    |\n");
    printf("|4. Realizar o produto escalar entre dois vetores.|\n");
    printf("|5. Voltar ao menu anterior.                      |\n\n");
    printf("Opção desejada: ");
    scanf("%d", &mv);
    switch (mv) {
        case 1: lervetor(&vector1, &vector2, &tam1, &tam2); menuvetor();
        // case 2: Somar();
        case 5: main(); break;
        default: printf("Opção inválida\n"); break;
    }
}
