#include <stdio.h>
#include "menumatriz.h"
#include "menuvetor.h"

int tam = 1, *vector1 = NULL , *vector2 = NULL;
int emv, emp;


int linhaM(int l){
    for(int i = 0; i < l; i++){
        printf("=");
    }
    printf("\n");
}

// MENU PRINCIPAL DA BIBLIOTECA DE VETORES E MATRIZES
int main(){
    int op, voltar;
    emp = 0;
    printf("\e[H\e[2J");
    linhaM(30);
    printf("|\tMenu Inicial         |\n");
    linhaM(30);
    printf("|1. Operações com vetores    |\n");
    printf("|2. Operações com matrizes   |\n");
    printf("|3. Sair do programa         |\n");
    linhaM(30); printf("\n");
    printf("Operação desejada: "); scanf("%d", &op);

    switch (op){
        case 1: lervetor(&vector1, &vector2, &tam); menuvetor(); break;
        case 2: menumatriz(); break;
        case 3: printf("Encerrando programa...\n"); break;
        default:{
            printf("\nOpção inválida... Tente uma das opções do menu!\n\n0 para voltar ao menu: ");
            scanf("%d", &voltar); emp++; main();
        }
    }

}


int menuvetor(){
    int mv;
    printf("\e[H\e[2J");
    linhaM(51);
    printf("\t  BEM VINDO AO MENU DE VETORES            |\n");
    linhaM(51);
    printf("|1. Escolher outros vetores.                      |\n");
    printf("|2. Somar os dois vetores.                        |\n");
    printf("|3. Multiplicar um dos vetores por um escalar.    |\n");
    printf("|4. Realizar o produto escalar entre dois vetores.|\n");
    printf("|5. Voltar ao menu anterior.                      |\n");
    linhaM(51); printf("\n");
    printf("Opção desejada: "); scanf("%d", &mv);

    switch (mv) {
        case 1: lervetor(&vector1, &vector2, &tam); menuvetor(); break;
        case 2: Somar(vector1, vector2, tam); menuvetor(); break;
        case 3: Mult(vector1, vector2, tam); menuvetor(); break;
        case 4: Prod2V(vector1, vector2, tam); menuvetor(); break;
        case 5: main(); break;
        default: printf("Opção inválida... Tente uma das opções do menu!\n\n"); menuvetor();
    }
}
