/* #############################################################
    TRABALHO DA CADEIRA DE INTRODUÇÃO A CIÊNCIA DA COMPUTAÇÃO
         BIBLIOTECA DE MANIPULAÇÃO DE VETORES EM C
            Autor: Raimundo Angeliano Gonçalves de Sousa
               UNIVERSIDADE ESTADUAL DO CEÁRA
                   FORTALEZA/CE - 2018
################################################################*/

#include <stdio.h>
#include <stdlib.h>

int main();
int menuvetor();
int lervetor(int **v1, int **v2, int *t);
int Somar(int *v1, int *v2, int t);
int Mult(int *v1, int *v2, int t);
int Prod2V(int *v1, int *v2, int t);
int linhap(int l){
    for(int i = 0; i < l; i++){
        printf("=");
    }
    printf("\n");
}

int voltavet(){
    int voltar;
    printf("0 para voltar ao menu: ");
    scanf("%d", &voltar);
}


// FUNÇÃO PARA LEITURA DE DOIS VETORES
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


// FUNÇÃO PARA SOMAR OS DOIS VETORES LIDOS NA FUNÇÃO lervetor();
int Somar(int *v1, int *v2, int t){
    printf("\n");
    int p;
    for (int i = 0; i < t; i++) printf("v1[%d] + v2[%d] = [%d]\n",v1[i], v2[i], v1[i]+v2[i]);
    printf("\n\n");
    voltavet();
}


// FUNÇÃO PARA MULTIPLICAR POR UM ESCALAR
int Mult(int *v1, int *v2, int t){
    printf("\n");
    printf("===========================\n");
    printf("[1] Vetor1: ");
    for (int i=0;i<t;i++){
        printf("%d ", v1[i]);
  }
    printf("\n");
    printf("[2] Vetor2: ");
    for (int i=0;i<t;i++){
        printf("%d ", v2[i]);
  }
    printf("\n");
    printf("===========================\n");
    int escolha, escalar, voltar;
    printf("\nQual dos vetores você quer multiplicar? ");
    scanf("%d", &escolha);
  switch (escolha){
    case 1:{
      printf("\nQual o escalar?");
      scanf("%d", &escalar);
      while(escalar != 0){
          if (escalar == 0) break;
          for(int i=0;i<t;i++) printf("v1[%d] x v2[%d] = [%d]\n", v1[i], escalar, v1[i]*escalar); break;
      } voltavet(); break;

  } break;
    case 2:{
      printf("\nQual o escalar? ");
      scanf("%d", &escalar);
      while(escalar != 0){
          if (escalar == 0) break;
          for(int i=0;i<t;i++) printf("v1[%d] x v2[%d] = [%d]\n", v2[i], escalar, v2[i]*escalar); break;
      } voltavet(); break;

  } break;
    default: {
        printf("==================================================\n");
        printf("Opção inválida           \n"); voltavet();
        printf("==================================================\n");
    }

  }

}


// FUNÇÃO QUE RETORNA O PRODUTO ENTRE DOIS VETORES LIDOS PELA FUNÇÃO lervetor();
int Prod2V(int *v1, int *v2, int t){
    printf("============================\n");
    for(int i = 0; i < t; i++){
        printf("v1[%d] * v2[%d] = [%d]\n", v1[i], v2[i], v1[i]*v2[i]);
    }
    printf("============================\n");
    voltavet();
}
