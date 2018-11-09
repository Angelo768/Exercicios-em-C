#include <stdio.h>
#include "menumatriz.h"
#include "menuvetor.h"

int main(){
    int op;

    printf("\e[H\e[2J");
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
