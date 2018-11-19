/*#################################################################
  #    TRABALHO DA CADEIRA DE INTRODUÇÃO A CIÊNCIA DA COMPUTAÇÃO  #
  #         BIBLIOTECA DE MANIPULAÇÃO DE VETORES EM C             #
  #            Autor: Raimundo Angeliano Gonçalves de Sousa       #
  #               UNIVERSIDADE ESTADUAL DO CEÁRA                  #
  #                   FORTALEZA/CE - 2018                         #
  #################################################################*/

#include <stdio.h>
#include <stdlib.h>

int main();
int menuvetor();
int lervetor(int **v1, int **v2, int *t);
int Somar(int *v1, int *v2, int t);
int Mult(int *v1, int *v2, int t);
int Prod2V(int *v1, int *v2, int t);
int linhavet(int l){
    for(int i = 0; i < l; i++){
        printf("-");
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

    int a, i, c;
    linhavet(30);
    printf("Tamanho dos vetores: \n");
    linhavet(30);
    scanf("%d", t);
    linhavet(30);
    printf("Confirmar tamanho: \n1 => SIM\n2 => NÃO\n");
    linhavet(30);
    scanf("%d", &c);
    switch (c) {
      case 1: {
        linhavet(30);
        *v1 = (int*)malloc((*t)*sizeof(int));
        *v2 = (int*)malloc((*t)*sizeof(int));
        for ( int j = 0;  j < *t; j++){
            printf("Vetor 1 - Posição [%d]: ", j);
            scanf("%d", &(*v1)[j]);
        }
        linhavet(30);
        for ( int j = 0; j < *t; j++){
            printf("Vetor 2 - Posição [%d]: ", j);
            scanf("%d", &(*v2)[j]);
        }
      }break;
      case 2: printf("Voltando ao menu inicial digite 0 para voltar "); scanf("%d", &i); main(); break;
      default: {
        printf("Opção inválida...Voltando ao menu inicial\n\nAperte 0 para continuar ");
        scanf("%d", &i); main();
      }
    }

    return 0;
}


// FUNÇÃO PARA SOMAR OS DOIS VETORES LIDOS NA FUNÇÃO lervetor();
int Somar(int *v1, int *v2, int t){
    printf("\n");
    int p;
    linhavet(30);
    for (int i = 0; i < t; i++) printf("v1[%d] + v2[%d] = [%d]\n",v1[i], v2[i], v1[i]+v2[i]);
    linhavet(30);
    voltavet();
}


// FUNÇÃO PARA MULTIPLICAR POR UM ESCALAR
int Mult(int *v1, int *v2, int t){
    printf("\n");
    linhavet(30);
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
    linhavet(30);
    int escolha, escalar, voltar;
    printf("\nQual dos vetores você quer multiplicar? ");
    scanf("%d", &escolha);
  switch (escolha){
    case 1:{
      printf("\nQual o escalar? ");
      while(escalar != 0){
          scanf("%d", &escalar);
          linhavet(30);
          for(int i=0;i<t;i++) printf("v1[%d] x %d = [%d]\n", v1[i], escalar, v1[i]*escalar); break;
      }   linhavet(30); voltavet(); break;

  } break;
    case 2:{
      printf("\nQual o escalar? ");
      while(escalar != 0){
          scanf("%d", &escalar);
          linhavet(30);
          for(int i=0;i<t;i++) printf("v1[%d] x %d = [%d]\n", v2[i], escalar, v2[i]*escalar); break;
      } linhavet(30); voltavet(); break;

  } break;
    default: {
        linhavet(40);
        printf("Opção inválida "); voltavet();
        linhavet(40);
    }

  }

}


// FUNÇÃO QUE RETORNA O PRODUTO ENTRE DOIS VETORES LIDOS PELA FUNÇÃO lervetor();
int Prod2V(int *v1, int *v2, int t){
    linhavet(20);
    for(int i = 0; i < t; i++){
        printf("v1[%d] * v2[%d] = [%d]\n", v1[i], v2[i], v1[i]*v2[i]);
    }
    linhavet(20);
    voltavet();
}
