#include <stdio.h>
#include <stdlib.h>

int main();
int menuvetor();
int lervetor(int **v1, int **v2, int *t);
int Somar(int *v1, int *v2, int t);
int Mult(int *v1, int *v2, int t);

int lervetor(int **v1, int **v2, int *t){

    int a, i;

    printf("-------------------------\n");
    printf("Tamanho dos vetores: ");
    scanf("%d", t);
    printf("-------------------------\n");
    *v1 = (int*)malloc((*t)*sizeof(int));
    *v2 = (int*)malloc((*t)*sizeof(int));
    for ( i = 0;  i < *t; i++){
        printf("Vetor 1 - Posição [%d]: ", i);
        scanf("%d", &(*v1)[i]);
    }
    printf("-------------------------\n");
    for ( i = 0; i < *t; i++){
        printf("Vetor 2 - Posição [%d]: ", i);
        scanf("%d", &(*v2)[i]);
    }
    return 0;
}

int Somar(int *v1, int *v2, int t){
    printf("\n");
    for (int i = 0; i < t; i++) printf("v1[%d] + v2[%d] = [%d]\n",v1[i], v2[i], v1[i]+v2[i]);
    printf("\n\n\n");
}

int Mult(int *v1, int *v2, int t){
  for (int i=0;i<t;i++){
    printf("%d", v1[i]);
  }
  for (int i=0;i<t;i++){
    printf("%d", v2[i]);
  }
  int escolha, escalar;
  printf("[1] Vetor1\n");
  printf("[2] Vetor2\n");
  printf("Qual dos vetores você quer manipular? \n");
  scanf("%d", &escolha);
  switch (escolha){
    case 1:
      printf("Qual o escalar? \n");
      scanf("%d", &escalar);
      for(int i=0;i<t;i++) printf("[%d] x %d = %d", v1[i], escolha, v1[i]*escalar);
    case 2:
      printf("Qual o escalar? \n");
      scanf("%d", &escalar);
      for(int i=0;i<t;i++) printf("[%d] x %d = %d", v2[i], escolha, v2[i]*escalar);
    default: printf("Opção inválida\n");
  }

}
