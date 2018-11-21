
#include <stdio.h>
#include <stdlib.h>

int main();
int menumatriz();
int lermat(int ***M1, int *l1, int *c1, int ***M2, int *l2, int *c2);
int SomarMat(int ***mat1, int *linha1, int *coluna1, int ***mat2, int *linha2, int *coluna2);
int MostrarMat(int ***matriz1, int *li1, int *column1, int ***matriz2, int *li2, int *column2);


int lermat(int ***mat1, int *l1, int *c1, int ***mat2, int *l2, int *c2){
  int tamanho, c;
  printf("\n======= MATRIZ 01 =======\n");
  printf("Tamanho da linha: ");
  scanf("%d", l1);
  printf("Tamanho da coluna: ");
  scanf("%d", c1);
  printf("\n");
  (*mat1) = (int **)malloc((*l1)*sizeof(int*));
  for (int i = 0; i < *l1; i++){
    (*mat1)[i] = (int *)malloc((*c1)*sizeof(int*));
  }
  printf("Posição: \n");
  for(int i = 0; i < *l1; i++){
    for(int j = 0; j < *c1; j++){
      printf("[%d][%d]: ", i, j);
      scanf("%d", &(*mat1)[i][j]);
    }
  }

  printf("\n======= MATRIZ 02 =======\n");
  printf("Tamanho da linha: ");
  scanf("%d", l2);
  printf("Tamanho da coluna: ");
  scanf("%d", c2);
  (*mat2) = (int **)malloc((*l2)*sizeof(int*));
  for (int i = 0; i < *l2; i++){
    (*mat2)[i] = (int *)malloc((*c2)*sizeof(int*));
  }
  printf("Posição: \n");
  for(int i = 0; i < *l2; i++){
    for(int j = 0; j < *c2; j++){
      printf("[%d][%d]: ", i, j);
      scanf("%d", &(*mat2)[i][j]);
    }
  }

}


int MostrarMat(int ***matriz1, int *li1, int *column1, int ***matriz2, int *li2, int *column2){
  if (*li1 == *li2 && *column1 == *c2)
    for (int i = 0; i < *l1; i++){
      for (int j = 0; j < *c1; j++){
        printf("[ %d ]", (*mat1)[i][j]);
          if (i == j-1) printf("\n");
      }
    }
    printf("\n");
    for (int i = 0; i < *l1; i++){
      for (int j = 0; j < *c1; j++){
        printf("[ %d ]", (*mat2)[i][j]);
          if (i == j-1) printf("\n");
      }
    }
    printf("\n\n");
}

int SomarMat(int ***mat1, int *l1, int *c1, int ***mat2, int *l2, int *c2){

}
