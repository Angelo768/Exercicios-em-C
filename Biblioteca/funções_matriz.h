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
int SomarMat(int ***mat1, int *l1, int *c1, int ***mat2, int *l2, int *c2);
int MostrarMat1(int ***mat1, int *l1, int *c1, int ***mat2, int *l2, int *c2);
int MostrarMat2(int ***mat1, int *l1, int *c1, int ***mat2, int *l2, int *c2);
int Transp(int ***mat1, int *l1, int *c1, int ***mat2, int *l2, int *c2);
int Det(int ***mat1, int *l1, int *c1, int ***mat2, int *l2, int *c2);
int Sime(int ***mat1, int *l1, int *c1, int ***mat2, int *l2, int *c2);

int voltamat(){   // FUNÇÃO QUE FINALIZA AS OUTRAS FUNÇÕES
    int voltar;
    printf("Digite 0 para voltar ao menu: ");
    scanf("%d", &voltar);
}

// FUNÇÃO PARA MOSTRAR A MATRIZ 01
int MostrarMat1(int ***mat1, int *l1, int *c1, int ***mat2, int *l2, int *c2){

  for (int i = 0; i < *l1; i++){
    for (int j = 0; j < *c1; j++){
      printf("\t[ %d ]", (*mat1)[i][j]);
    }
    printf("\n");
  }
}

// FUNÇÃO PARA MOSTRAR A MATRIZ 02
int MostrarMat2(int ***mat1, int *l1, int *c1, int ***mat2, int *l2, int *c2){

  for (int i = 0; i < *l2; i++){
    for (int j = 0; j < *c2; j++){
      printf("\t[ %d ]", (*mat2)[i][j]);
    }
    printf("\n");
  }
}

int linhamat(int l){
    for(int i = 0; i < l; i++){
        printf("-");
    }
    printf("\n");
}

// FUNÇÃO QUE LÊ DUAS MATRIZES - OK!!
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

  MostrarMat1(mat1, l1, c1, mat2, l2, c2);
    printf("\t      +\n");
  MostrarMat2(mat1, l1, c1, mat2, l2, c2);
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

// FUNÇÃO QUE CÁLCULA A TRANSPOSTA DA MATRIZ ESCOLHIDA - OK!!
int Transp(int ***mat1, int *l1, int *c1, int ***mat2, int *l2, int *c2){
  int escolha;
  printf("\n=======  MATRIZ 01  =======\n");
  MostrarMat1(mat1, l1, c1, mat2, l2, c2);  // Printando a Matriz 01
  printf("\n=======  MATRIZ 02  =======\n");
  MostrarMat2(mat1, l1, c1, mat2, l2, c2);  // Printando a Matriz 02
  linhamat(45);
  printf("Qual das matrizes você quer transpor ?\n1 => MATRIZ 01\n2 => MATRIZ 02\n");
  linhamat(45);
  scanf("%d", &escolha);
  switch (escolha) {
    case 1:{
      linhamat(30);
      printf("    Transposta da MATRIZ 01\n");
      linhamat(30);
      for (int i = 0; i < *l1; i++){          // CÁLCULO DA TRANSPOSTA DA MATRIZ 01
        printf("\t");
        for (int j = 0; j < *c1; j++){
          printf("[ %d ]", (*mat1)[j][i]);
        }
      printf("\n");
      }
    } printf("\n"); voltamat(); break;
    case 2: {
      linhamat(30);
      printf("    Transposta da MATRIZ 02\n");
      linhamat(30);
      for (int i = 0; i < *l2; i++){          // CÁLCULO DA TRANSPOSTA DA MATRIZ 02
        printf("\t");
        for (int j = 0; j < *c2; j++){
          printf("[ %d ]", (*mat2)[j][i]);
        }
      printf("\n");
      }
    } printf("\n"); voltamat(); break;
    default : printf("Opção inválida...Tente uma do menu!"); voltamat();
  }
}

// FUNÇÃO QUE CHECA SE A MATRIZ ESCOLHIDA É SIMÉTRICA - MANUTENÇÃO
int Sime(int ***mat1, int *l1, int *c1, int ***mat2, int *l2, int *c2){
  int escolha, i, j, S1[*l1][*c1], S2[*l2][*c2];
  linhamat(30);
  printf("\n=======  MATRIZ 02  =======\n");
  MostrarMat1(mat1, l1, c1, mat2, l2, c2);
  printf("\n=======  MATRIZ 02  =======\n");
  MostrarMat2(mat1, l1, c1, mat2, l2, c2);
  printf("\nVocê quer checar qual matriz ?\n1 => MATRIZ 01\n2 => MATRIZ 02\n");
  linhamat(30);
  scanf("%d", &escolha);
  switch (escolha) {
    case 1: {
      if (*l1 == *c1){
      for (i = 0; i < *l1; i++){        // Armazenando a matriz transposta
        for ( j = 0; j < *c1; j++){
          S1[*l1][*c1] = (*mat1)[j][i];
        }
      }
    }else{
      printf("ESSA MATRIZ NÃO É SIMÉTRICA!!\n");
    }
      if(S1[*l1][*c1] == (*mat1)[i][j]) printf("A MATRIZ 01 é Simétrica\n");
    } menumatriz(); break;
    default : printf("Voltando ao menu de matriz..\n\n"); voltamat();
  }
}

// FUNÇÃO QUE CALCULA O DETERMINANTE DA MATRIZ ESCOLHIDA
int Det(int ***mat1, int *l1, int *c1, int ***mat2, int *l2, int *c2){
  int escolha, D;
  printf("AVISO!!: Aqui os cálculos de determinate vale para\nmatrizes quadradas de até ordem 3x3");
  printf("\n=======  MATRIZ 01  =======\n");
  MostrarMat1(mat1, l1, c1, mat2, l2, c2);
  printf("\n=======  MATRIZ 02  =======\n");
  MostrarMat2(mat1, l1, c1, mat2, l2, c2);
  linhamat(30);
  printf("De qual matriz você quer o determinante ?\n\n1 => MATRIZ 01\n2 => MATRIZ 02\n");
  linhamat(30);
  scanf("%d", &escolha);
  if(escolha == 1){
  switch((*l1)*(*c1)){
    case 1:{
      D = (*mat1)[0][0]; printf("O determinante Vale: %d\n", D);
    } voltamat(); menumatriz(); break;
    case 4:{
      D = ((*mat1)[0][0]*(*mat1)[1][1]) - ((*mat1)[0][1]*(*mat1)[1][0]);
      printf("O determinante Vale: %d\n", D);
  } voltamat(); menumatriz(); break;
    case 9:{
      D = (((*mat1)[2][0]*(*mat1)[0][1]*(*mat1)[1][2]) +
           ((*mat1)[0][0]*(*mat1)[1][1]*(*mat1)[2][2]) +
           ((*mat1)[1][0]*(*mat1)[2][1]*(*mat1)[0][2])) +
                              -
          (((*mat1)[2][2]*(*mat1)[0][1]*(*mat1)[1][0]) +
           ((*mat1)[0][2]*(*mat1)[1][1]*(*mat1)[2][0]) +
           ((*mat1)[1][2]*(*mat1)[2][1]*(*mat1)[0][0]));
      printf("O determinante Vale: %d\n", D);
    } voltamat(); menumatriz(); break;
    default : printf("Só cálculo determinante de matrizes 1x1, 2x2 e 3x3\n"); voltamat(); menumatriz();
    }
  }
  if(escolha == 2){
  switch((*l2)*(*c2)){
    case 1:{
      D = (*mat2)[0][0]; printf("O determinante Vale: %d\n", D);
    } voltamat(); menumatriz(); break;
    case 4:{
      D = ((*mat2)[0][0]*(*mat2)[1][1]) - ((*mat2)[0][1]*(*mat2)[1][0]);
      printf("O determinante Vale: %d\n", D);
  } voltamat(); menumatriz(); break;
    case 9:{
      D = (((*mat2)[2][0]*(*mat2)[0][1]*(*mat2)[1][2]) +
           ((*mat2)[0][0]*(*mat2)[1][1]*(*mat2)[2][2]) +
           ((*mat2)[1][0]*(*mat2)[2][1]*(*mat2)[0][2])) +
                              -
          (((*mat2)[2][2]*(*mat2)[0][1]*(*mat2)[1][0]) +
           ((*mat2)[0][2]*(*mat2)[1][1]*(*mat2)[2][0]) +
           ((*mat2)[1][2]*(*mat2)[2][1]*(*mat2)[0][0]));
      printf("O determinante Vale: %d\n", D);
    } voltamat(); menumatriz(); break;
    default : printf("Só cálculo determinante de matrizes 1x1, 2x2 e 3x3\n"); voltamat(); menumatriz();
    }
  }
}
