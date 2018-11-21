/*#################################################################
  #    TRABALHO DA CADEIRA DE INTRODUÇÃO A CIÊNCIA DA COMPUTAÇÃO  #
  #         BIBLIOTECA DE MANIPULAÇÃO DE MATRIZES EM C            #
  #            Autor: Raimundo Angeliano Gonçalves de Sousa       #
  #               UNIVERSIDADE ESTADUAL DO CEARÁ                  #
  #                   FORTALEZA/CE - 2018                         #
  #################################################################*/


#include <stdio.h>
#include <stdlib.h>

int main();
int menumatriz();
int lermat(int ***M1, int *l1, int *c1, int ***M2, int *l2, int *c2);
int SomarMat(int ***mat1, int *linha1, int *coluna1, int ***mat2, int *linha2, int *coluna2);
int Transp(int ***mat1, int *l1, int *c1, int ***mat2, int *l2, int *c2);
int voltamat(){
    int voltar;
    printf("0 para voltar ao menu: ");
    scanf("%d", &voltar);
}

int linhamat(int l){
    for(int i = 0; i < l; i++){
        printf("-");
    }
    printf("\n");
}

// FUNÇÃO QUE LER DUAS MATRIZES - OK!!
int lermat(int ***mat1, int *l1, int *c1, int ***mat2, int *l2, int *c2){
  int tamanho, c;
  // LENDO A PRIMEIRA MATRIZ
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
  // LENDO A SEGUNDA MATRIZ
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


// SOMANDO DUAS MATRIZES - OK!!
int SomarMat(int ***mat1, int *l1, int *c1, int ***mat2, int *l2, int *c2){
  linhamat(50);
  if (*l1 == *l2 && *c1 == *c2){  // PRINTANDO A PRIMEIRA MATRIZ
    for (int i = 0; i < *l1; i++){
      for (int j = 0; j < *c1; j++){
        printf("\t[ %d ]", (*mat1)[i][j]);
      }
      printf("\n");
    }
    printf("\t      +\n");
    for (int i = 0; i < *l1; i++){    // PRINTANDO A SEGUNDA MATRIZ
      for (int j = 0; j < *c1; j++){
        printf("\t[ %d ]", (*mat2)[i][j]);
      }
      printf("\n");
    }
    printf("\t      =\n");          // PRINTANDO A SOMA DAS MATRIZES
    for (int i = 0; i < *l1; i++){
      for (int j = 0; j < *c1; j++){
        printf("\t[ %d ]", ((*mat1)[i][j])+((*mat2))[i][j]);
      }
      printf("\n");
    }
  }else{
    printf("Para realizar a soma de matrizes\nessas devem ser mesma ordem\n");
  }
  linhamat(50);
    printf("\n");
    voltamat();
}

// FUNÇÃO QUE CALCULA PRODUTO ENTRE MATRIZES - MANUTENÇÃO
int MultMat(int ***mat1, int *l1, int *c1, int ***mat2, int *l2, int *c2){
  if (*l1 == *c2){
    for (int i = 0; i < *l1; i++){
      for (int j = 0; j < *c1; j++){
        printf("[ %d ]", (*mat1)[i][j]);
      }
    printf("\n");
    }
    printf("\t      *\n");
    for (int i = 0; i < *l2; i++){
      for (int j = 0; j < *c2; j++){
        printf("[ %d ]", (*mat2)[i][j]);
      }
    printf("\n");
    }
    printf("\t      =\n");
    for (int i = 0; i < (*l1)*(*c1); i++){
      for (int j = 0; j < (*c2)*(*l2); j++){
        printf("[ %d ]", (*mat1)[j][i]*(*mat2)[i][j]);
      }
    printf("\n");
    }
  }
}

int Transp(int ***mat1, int *l1, int *c1, int ***mat2, int *l2, int *c2){
  int escolha;
  printf("\n=======  MATRIZ 01  =======\n");    // Printando a Matriz 01
  for (int i = 0; i < *l1; i++){
    printf("\t");
    for (int j = 0; j < *c1; j++){
      printf("[ %d ]", (*mat1)[i][j]);
    }
  printf("\n");
  }
  printf("\n=======  MATRIZ 02  =======\n");    // Printando a Matriz 02
  for (int i = 0; i < *l2; i++){
    printf("\t");
    for (int j = 0; j < *c2; j++){
      printf("[ %d ]", (*mat2)[i][j]);
    }
  printf("\n");
  }
  linhamat(45);
  printf("Qual das matrizes você quer a transpor ?\n1 => MATRIZ 01\n2 => MATRIZ 02\n");
  linhamat(45);
  scanf("%d", &escolha);
  switch (escolha) {
    case 1:{
      linhamat(30);
      printf("    Transposta da MATRIZ 01\n");
      linhamat(30);
      for (int j = 0; j < *l1; j++){          // CÁLCULO DA TRANSPOSTA DA MATRIZ 01
        printf("\t");
        for (int i = 0; i < *c1; i++){
          printf("[ %d ]", (*mat1)[i][j]);
        }
      printf("\n");
      }
    } printf("\n"); voltamat(); break;
    case 2: {
      linhamat(30);
      printf("    Transposta da MATRIZ 02\n");
      linhamat(30);
      for (int j = 0; j < *l2; j++){          // CÁLCULO DA TRANSPOSTA DA MATRIZ 02
        printf("\t");
        for (int i = 0; i < *c2; i++){
          printf("[ %d ]", (*mat2)[i][j]);
        }
      printf("\n");
      }
    } printf("\n"); voltamat(); break;
    default : printf("Opção inválida...Tente uma do menu!"); voltamat();
  }
}
