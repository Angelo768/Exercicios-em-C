#include <stdio.h>
int main();
int menuvetor();
int lervetor();

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
        case 1: lervetor(); menuvetor();
        // case 2: Somar();
        case 5: main(); break;
        default: printf("Opção inválida\n"); break;
    }
}

int lervetor(){

    int a, i;

    printf("-------------------------\n");
    printf("Tamanho dos vetores: ");
    scanf("%d", &a);
    printf("-------------------------\n");
    int V1[a], V2[a];
    for ( i = 0;  i < a; i++){
        printf("Vetor 1 - Posição [%d]: ", i);
        scanf("%d", &V1[i]);
    }
    printf("-------------------------\n");
    for ( i = 0; i < a; i++){
        printf("Vetor 2 - Posição [%d]: ", i);
        scanf("%d", &V2[i]);
    }
    return a, V1[a], V2[a];
}

int Somar(){
    int i, a, V[a];
    for (i = 0; i < a; i++){
        printf("%d", V[a]);
    }
}
