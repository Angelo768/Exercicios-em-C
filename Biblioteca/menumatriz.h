
#include <stdio.h>
#include <stdlib.h>

int main();
int lermat(int ***M1, int *l1, int *c1, int ***M2, int *l2, int *c2);

int lermat(int ***M1, int *l1, int *c1, int ***M2, int *l2, int *c2){
  int tamanho, c;
  printf("======= MATRIZ 01 =======\n");
  printf("Tamanho da linha: ");
  scanf("%d", l1);
  printf("Tamanho da coluna: ");
  scanf("%d", c1);
  printf("\n");
  (*M1) = (int **)malloc((*l1)*sizeof(int*));
  for (int i = 0; i < *l1; i++){
    (*M1)[i] = (int *)malloc((*c1)*sizeof(int*));
  }
  for(int i = 0; i < *l1; i++){
    for(int j = 0; j < *c1; j++){
      printf("Posição [%d][%d]: ", i, j);
      scanf("%d", &(*M1)[i][j]);
    }
  }
  printf("\n");

  printf("======= MATRIZ 02 =======\n");
  printf("Tamanho da linha: ");
  scanf("%d", l2);
  printf("Tamanho da coluna: ");
  scanf("%d", c2);
  (*M2) = (int **)malloc((*l2)*sizeof(int*));
  for (int i = 0; i < *l2; i++){
    (*M2)[i] = (int *)malloc((*c2)*sizeof(int*));
  }
  for(int i = 0; i < *l2; i++){
    for(int j = 0; j < *c2; j++){
      printf("Posição [%d][%d]: ", i, j);
      scanf("%d", &(*M1)[i][j]);
    }
  }

}
