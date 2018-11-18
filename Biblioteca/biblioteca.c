#include <stdio.h>
#include "menumatriz.h"
#include "menuvetor.h"

int tam = 1, *vector1 = NULL , *vector2 = NULL;
int emv=0, emp=0;

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
        default: printf("Opção inválida... Tente uma das opções do menu!\n\n"); main();
    }

    emp++;
}


int menuvetor(){
    int mv;

    printf("\e[H\e[2J");
    printf("===================================================\n");
    printf("|\t\tMenu Vetor                        |\n");
    printf("===================================================\n");
    printf("|1. Ler vetores.                                  |\n");
    printf("|2. Ler outros vetores.                           |\n");
    printf("|3. Somar os dois vetores.                        |\n");
    printf("|4. Multiplicar um dos vetores por um escalar.    |\n");
    printf("|5. Realizar o produto escalar entre dois vetores.|\n");
    printf("|6. Voltar ao menu anterior.                      |\n\n");
    printf("Opção desejada: ");
    scanf("%d", &mv);
    switch (mv) {
        case 1: lervetor(&vector1, &vector2, &tam); menuvetor(); break;
        case 2: lervetor(&vector1, &vector2, &tam); menuvetor(); break;
        case 3: Somar(vector1, vector2, tam); break;
        case 4: Mult(vector1, vector2, tam); break;
        case 6: main(); break;
        default: printf("Opção inválida... Tente uma das opções do menu!\n\n"); menuvetor();
    }
}
