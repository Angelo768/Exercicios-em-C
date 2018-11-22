/*#################################################################
  #    TRABALHO DA CADEIRA DE INTRODUÇÃO A CIÊNCIA DA COMPUTAÇÃO  #
  #       BIBLIOTECA DE MANIPULAÇÃO DE VETORES E MATRIZES EM C    #
  #            Autor: Raimundo Angeliano Gonçalves de Sousa       #
  #               UNIVERSIDADE ESTADUAL DO CEARÁ                  #
  #                   FORTALEZA/CE - 2018                         #
  #################################################################*/

#include <stdio.h>
#include "funções_matriz.h"
#include "funções_vetor.h"

int tam = 1, *vector1 = NULL , *vector2 = NULL;
int l1=1, c1=1, l2=1, c2=1, **M1=NULL, **M2=NULL;
int confirma, emv, emp;


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
        case 2: lermat(&M1, &l1, &c1, &M2, &l2, &c2); menumatriz(); break;
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
        case 2: Somarvet(vector1, vector2, tam); menuvetor(); break;
        case 3: Multvet(vector1, vector2, tam); menuvetor(); break;
        case 4: Prod2Vet(vector1, vector2, tam); menuvetor(); break;
        case 5: main(); break;
        default: printf("Opção inválida... Tente uma das opções do menu!\n\n"); menuvetor();
    }
}


int menumatriz(){
    int mm;
    printf("\e[H\e[2J");
    linhaM(45);
    printf("|      BEM VINDO AO MENU DE MATRIZES        |\n");
    linhaM(45);
    printf("|1. Ler outras matrizes                     |\n");
    printf("|2. Somar duas matrizes                     |\n");
    printf("|3. Multiplicar duas matrizes               |\n");
    printf("|4. Calcular a transposta                   |\n");
    printf("|5. Calcular o determinante                 |\n");
    printf("|6. Verificar se há uma matriz simétrica    |\n");
    printf("|7. Voltar ao menu anterior                 |\n");
    linhaM(45);
    printf("\nOpção desejada: ");
    scanf("%d", &mm);
    switch (mm){
        case 1: lermat(&M1, &l1, &c1, &M2, &l2, &c2); menumatriz(); break;
        case 2: SomarMat(&M1 , &l1, &c1, &M2, &l2, &c2); menumatriz(); break;
        //case 3: MultMat(&M1, &l1, &c1, &M2, &l2, &c2); break;
        case 4: Transp(&M1 , &l1, &c1, &M2, &l2, &c2); menumatriz(); break;
        case 5: Det(&M1 , &l1, &c1, &M2, &l2, &c2); break;
        // case 6: Sime(&M1 , &l1, &c1, &M2, &l2, &c2); break;
        case 7: main(); break;
        default: printf("Opção inválida... Tente uma das opções do menu!\n\n"); voltamat();
    }
}
