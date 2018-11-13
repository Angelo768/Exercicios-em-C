#include <stdio.h>
#include <stdlib.h>

int main();
int menuvetor();
int lervetor();

int lervetor(int **v1, int **v2, int *t1, int *t2){

    int a, i;

    printf("-------------------------\n");
    printf("Tamanho do 1º vetor: ");
    scanf("%d", t1);
    printf("Tamanho do 2º vetor: ");
    scanf("%d", t2);
    printf("-------------------------\n");
    *v1 = (int*)calloc(*t1,sizeof(int));
    *v2 = (int*)calloc(*t2,sizeof(int));
    for ( i = 0;  i < a; i++){
        printf("Vetor 1 - Posição [%d]: ", i);
        scanf("%d", &(*v1[i]));
    }
    printf("-------------------------\n");
    for ( i = 0; i < a; i++){
        printf("Vetor 2 - Posição [%d]: ", i);
        scanf("%d", &(*v2[i]));
    }
    return 0;
}

// int Somar(){
//     int i, a, V[a];
//     for (i = 0; i < a; i++){
//         printf("%d", V[a]);
//     }
// }
