/*#################################################################
  #    TRABALHO DA CADEIRA DE INTRODUÇÃO A CIÊNCIA DA COMPUTAÇÃO  #
  #         BIBLIOTECA DE MANIPULAÇÃO DE MATRIZES EM C            #
  #            Autor: Raimundo Angeliano Gonçalves de Sousa       #
  #               UNIVERSIDADE ESTADUAL DO CEARÁ                  #
  #                   FORTALEZA/CE - 2018                         #
  #################################################################*/


#include <stdio.h>
#include <stdlib.h>

int menumatriz();


int voltamat(){   // FUNÇÃO QUE FINALIZA AS OUTRAS FUNÇÕES
    int voltar;
    printf("Digite 0 para voltar ao menu: ");
    scanf("%d", &voltar);
}

// FUNÇÃO PARA MOSTRAR A MATRIZ 01
int MostrarMat1(int ***mat1, int *l1, int *c1, int ***mat2, int *l2, int *c2){

  for (int i = 0; i < *l1; i++){
    printf("\t  ");
    for (int j = 0; j < *c1; j++){
      printf("\t[ %d ]", (*mat1)[i][j]);
    }
    printf("\n");
  }
}

// FUNÇÃO PARA MOSTRAR A MATRIZ 02
int MostrarMat2(int ***mat1, int *l1, int *c1, int ***mat2, int *l2, int *c2){

  for (int i = 0; i < *l2; i++){
    printf("\t    ");
    for (int j = 0; j < *c2; j++){
      printf("\t[ %d ]", (*mat2)[i][j]);
    }
    printf("\n");
  }
}

//FUNÇÃO PARA PRINTAR LINHAS NA TELA
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
  printf("\n====================== MATRIZ 01 ======================\nInsira o tamanho da linha e coluna \n\n");
  printf("Tamanho da linha: ");
  scanf("%d", l1);
  printf("Tamanho da coluna: ");
  scanf("%d", c1);
  printf("\n");
  
  (*mat1) = (int **)malloc((*l1)*sizeof(int*));
  for (int i = 0; i < *l1; i++){
    (*mat1)[i] = (int *)malloc((*c1)*sizeof(int*));
  }
  linhamat(44);
  printf("Lendo dados da matriz - Posição: \n");
  linhamat(44); printf("\n");
  for(int i = 0; i < *l1; i++){
    for(int j = 0; j < *c1; j++){
      printf("\t[%d][%d]: ", i, j);
      scanf("%d", &(*mat1)[i][j]);
    }
  }

  // LENDO A SEGUNDA MATRIZ
  printf("\n====================== MATRIZ 02 ======================\nInsira o tamanho da linha e coluna\n\n");
  printf("Tamanho da linha: ");
  scanf("%d", l2);
  printf("Tamanho da coluna: ");
  scanf("%d", c2);
  (*mat2) = (int **)malloc((*l2)*sizeof(int*));
  for (int i = 0; i < *l2; i++){
    (*mat2)[i] = (int *)malloc((*c2)*sizeof(int*));
  }
  linhamat(44);
  printf("Lendo dados da matriz - Posição: \n");
  linhamat(44); printf("\n");
  for(int i = 0; i < *l2; i++){
    for(int j = 0; j < *c2; j++){
      printf("\t[%d][%d]: ", i, j);
      scanf("%d", &(*mat2)[i][j]);
    }
  }
}

// SOMANDO DUAS MATRIZES - OK!!
int SomarMat(int ***mat1, int *l1, int *c1, int ***mat2, int *l2, int *c2){
  linhamat(50);
  if (*l1 == *l2 && *c1 == *c2){  // PRINTANDO A PRIMEIRA MATRIZ

  MostrarMat1(mat1, l1, c1, mat2, l2, c2);
    printf("\t\t\t  +\n");
  MostrarMat2(mat1, l1, c1, mat2, l2, c2);
    printf("\t\t\t  =\n");          // PRINTANDO A SOMA DAS MATRIZES
    for (int i = 0; i < *l1; i++){
	    printf("\t");
      for (int j = 0; j < *c1; j++){
        printf("\t[ %d ]", ((*mat1)[i][j])+((*mat2))[i][j]);
      }
      printf("\n");
    }
  }else{
    printf("Para efetuar uma soma as matrizes\ndevem ter a mesma ordem\n\n");
  }
  linhamat(50);
    printf("\n"); voltamat();
}

// FUNÇÃO QUE CALCULA PRODUTO ENTRE MATRIZES - MANUTENÇÃO
int MultMat(int ***mat1, int *l1, int *c1, int ***mat2, int *l2, int *c2){
  int escolha, lin, i, j, P1[*l1][*c1];
  printf("\n====================  MATRIZ 01  ====================\n\n");
  MostrarMat1(mat1, l1, c1, mat2, l2, c2);  printf("\n");// Printando a Matriz 01
  printf("\n====================  MATRIZ 02  ====================\n\n");
  MostrarMat2(mat1, l1, c1, mat2, l2, c2);  printf("\n");// Printando a Matriz 02
  linhamat(57);
  printf("\t     Escolha um dos produtos a seguir\n\n\t\t1 => MATRIZ01 X MATRIZ02\n\t\t2 => MATRIZ02 X MATRIZ01\n\n");
  linhamat(57);
  scanf("%d", &escolha);
  switch(escolha) {
        case 1:{
            if (*c1 == *l2){
            printf("\n====================== NOVA MATRIZ ======================\n\n");
            for (int i = 0; i < *l1; i++) {
		    printf("\t      ");
                for (int j = 0; j < *c2; j++) {
                    P1[i][j] = 0;
                    for (int k = 0; k < *l2; k++)
                        P1[i][j] = P1[i][j] + (*mat1)[i][k]*(*mat2)[k][j];
                    printf("   [ %d ]", P1[i][j]);
                    }
                printf("\n");
        	}
       	     }
   	 } printf("\n"); voltamat(); break;
    case 2:{
        if(*l2 == *c1){
            printf("\n====================== NOVA MATRIZ ======================\n\n");
            for (int i = 0; i < *c1; i++) {
		    printf("\t      ");
                for (int j = 0; j < *l2; j++) {
                    P1[i][j] = 0;
                    for (int k = 0; k < *l1; k++)
                        P1[i][j] = P1[i][j] + (*mat2)[i][k]*(*mat1)[k][j];
                    printf("   [ %d ]", P1[i][j]);
                    }
                    printf("\n");
                }
            }
        } printf("\n"); voltamat(); break;
        default :{ 
			 printf("Opção inválida...Tente uma das opções sugeridas!!\n\n"); 
		 } voltamat(); break;
    }
}

// FUNÇÃO QUE CÁLCULA A TRANSPOSTA DA MATRIZ ESCOLHIDA - OK!!
int Transp(int ***mat1, int *l1, int *c1, int ***mat2, int *l2, int *c2){
  int escolha;
  printf("\n=====================  MATRIZ 01  ======================\n\n");
  MostrarMat1(mat1, l1, c1, mat2, l2, c2);  // Printando a Matriz 01
  printf("\n=====================  MATRIZ 02  ======================\n\n");
  MostrarMat2(mat1, l1, c1, mat2, l2, c2);  // Printando a Matriz 02
  linhamat(45);
  printf("Qual das matrizes você quer transpor ?\n1 => MATRIZ 01\n2 => MATRIZ 02\n");
  linhamat(45);
  scanf("%d", &escolha);
  switch (escolha) {
    case 1: {
      linhamat(45);
      printf("\tTransposta da MATRIZ 01\n");
      linhamat(45); printf("\n");
      for (int j = 0; j < *c1; j++){          // CÁLCULO DA TRANSPOSTA DA MATRIZ 01
        printf("\t");
        for (int i = 0; i < *l1; i++){
          printf("[ %d ]", (*mat1)[i][j]);
        }
      printf("\n");
      }
    } printf("\n"); voltamat(); break;
    case 2: {
      linhamat(45);
      printf("\tTransposta da MATRIZ 02\n");
      linhamat(45); printf("\n");
      for (int j = 0; j < *c2; j++){          // CÁLCULO DA TRANSPOSTA DA MATRIZ 02
        printf("\t");
        for (int i = 0; i < *l2; i++){
          printf("[ %d ]", (*mat2)[i][j]);
        }
      printf("\n");
      }
    } printf("\n"); voltamat(); break;
    default : printf("Opção inválida...Tente uma do menu!\n\n"); voltamat();
  }
}

// FUNÇÃO QUE CHECA SE A MATRIZ ESCOLHIDA É SIMÉTRICA - OK!!
int Sime(int ***mat1, int *l1, int *c1, int ***mat2, int *l2, int *c2){
  int escolha, i, j, S1[*l1][*c1], S2[*l2][*c2];
  linhamat(30);
  printf("\n=====================  MATRIZ 02  =====================\n");
  MostrarMat1(mat1, l1, c1, mat2, l2, c2);
  printf("\n=====================  MATRIZ 02  =====================\n");
  MostrarMat2(mat1, l1, c1, mat2, l2, c2);
  printf("\nVocê quer checar qual matriz ?\n1 => MATRIZ 01\n2 => MATRIZ 02\n");
  linhamat(30);
  scanf("%d", &escolha);
  switch (escolha) {
    case 1: {
      if (*l1 == *c1){
          for (i = 0; i < *l1; i++){        // Armazenando a matriz 01 transposta
            for ( j = 0; j < *c1; j++){
              (S1)[i][j] = (*mat1)[j][i];
        }
      }
      for (i = 0; i < *l1; i++){        // Comparando a matriz 01 com a sua transposta
        for ( j = 0; j < *c1; j++){
          if((S1)[i][j] != (*mat1)[i][j]) break;
            }
            if (j != *c1) break;
        }
        if (i == *l1) {
	    linhamat(44);
            printf("A MATRIZ 01 É SIMÉTRICA!!\n");
	    linhamat(44);
        }else{
	    linhamat(44);	
            printf("A MATRIZ 01 NÃO É SIMÉTRICA!!\n");
	    linhamat(44);
        }
    }else{
	linhamat(44);
        printf("A MATRIZ 01 NÃO É SIMÉTRICA!!\n");
	linhamat(44);
    }
  } voltamat(); break;
  case 2:{
        if (*l2 == *c2){
            for (i = 0; i < *l2; i++){        // Armazenando a matriz 02 transposta
              for ( j = 0; j < *c2; j++){
                (S2)[i][j] = (*mat2)[j][i];
          }
        }
        for (i = 0; i < *l2; i++){        // Comparando a matriz 02 com a sua transposta
          for ( j = 0; j < *c2; j++){
            if((S2)[i][j] != (*mat2)[i][j]) break;
              }
              if (j != *c2) break;
          }
          if (i == *l2) {
		  linhamat(44);
		  printf("A MATRIZ 02 É SIMÉTRICA!!\n");
		  linhamat(44);
          }else{
		linhamat(44);
              	printf("A MATRIZ 02 NÃO É SIMÉTRICA!!\n");
		linhamat(44);
          }
      }else{
	      linhamat(44);
    	      printf("A MATRIZ 02 NÃO É SIMÉTRICA!!\n");
	      linhamat(44);
      }
    } voltamat(); break;
    default : printf("Voltando ao menu de matrizes..\n\n"); voltamat();
  }
}

// FUNÇÃO QUE CALCULA O DETERMINANTE DA MATRIZ ESCOLHIDA - OK!!
int Det(int ***mat1, int *l1, int *c1, int ***mat2, int *l2, int *c2){
  int escolha, D;
  linhamat(44);
  printf("AVISO!!: Aqui os cálculos de determinate vale para\nmatrizes quadradas de até ordem 3x3\n");
  linhamat(44);
  printf("\n=====================  MATRIZ 01  ======================\n");
  MostrarMat1(mat1, l1, c1, mat2, l2, c2);
  printf("\n=====================  MATRIZ 02  ======================\n");
  MostrarMat2(mat1, l1, c1, mat2, l2, c2);
  linhamat(44);
  printf("De qual matriz você quer o determinante ?\n\n1 => MATRIZ 01\n2 => MATRIZ 02\n");
  linhamat(44);
  scanf("%d", &escolha);
  if(escolha == 1){
  switch((*l1)*(*c1)){
    case 1:{
      D = (*mat1)[0][0];
      linhamat(44);
      printf("O determinante Vale: %d\n", D);
      linhamat(44);
    } voltamat(); break;
    case 4:{
      D = ((*mat1)[0][0]*(*mat1)[1][1]) - ((*mat1)[0][1]*(*mat1)[1][0]);
      linhamat(44);
      printf("O determinante Vale: %d\n", D);
      linhamat(44);
  } voltamat(); break;
    case 9:{
      D = (((*mat1)[2][0]*(*mat1)[0][1]*(*mat1)[1][2]) +
           ((*mat1)[0][0]*(*mat1)[1][1]*(*mat1)[2][2]) +
           ((*mat1)[1][0]*(*mat1)[2][1]*(*mat1)[0][2])) +
                              -
          (((*mat1)[2][2]*(*mat1)[0][1]*(*mat1)[1][0]) +
           ((*mat1)[0][2]*(*mat1)[1][1]*(*mat1)[2][0]) +
           ((*mat1)[1][2]*(*mat1)[2][1]*(*mat1)[0][0]));
      linhamat(44);
      printf("O determinante Vale: %d\n", D);
      linhamat(44);
    } voltamat(); break;
    default : {
		      linhamat(44);
		      printf("Só cálculo determinante de matrizes 1x1, 2x2 e 3x3\n"); voltamat();
		      linhamat(44);
	      }
    }
  }
  if(escolha == 2){
  switch((*l2)*(*c2)){
    case 1:{
      D = (*mat2)[0][0]; printf("O determinante Vale: %d\n\n", D);
    } voltamat(); break;
    case 4:{
      D = ((*mat2)[0][0]*(*mat2)[1][1]) - ((*mat2)[0][1]*(*mat2)[1][0]);
      linhamat(44);
      printf("O determinante Vale: %d\n\n", D);
      linhamat(44);
  } voltamat(); break;
    case 9:{
      D = (((*mat2)[2][0]*(*mat2)[0][1]*(*mat2)[1][2]) +
           ((*mat2)[0][0]*(*mat2)[1][1]*(*mat2)[2][2]) +
           ((*mat2)[1][0]*(*mat2)[2][1]*(*mat2)[0][2])) +
                              -
          (((*mat2)[2][2]*(*mat2)[0][1]*(*mat2)[1][0]) +
           ((*mat2)[0][2]*(*mat2)[1][1]*(*mat2)[2][0]) +
           ((*mat2)[1][2]*(*mat2)[2][1]*(*mat2)[0][0]));
      linhamat(44);
      printf("O determinante Vale: %d\n\n", D);
      linhamat(44);
    } voltamat(); break;
    default : printf("\nSó cálculo determinante de matrizes 1x1, 2x2 e 3x3\n"); voltamat();
    }
  }
}
