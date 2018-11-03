#include <stdio.h>

int main(){
  int t, p1, p2;
  int v1[t], v2[t];
  printf("\e[H\e[2J");
  printf("Tamanho do vetor 01: ");
  scanf("%d", &t);
  for (p1=0;p1<=t-1;p1++){        // Lendo o vetor01
    printf("Posição: [%d]: ", p1);
    scanf("%d", &v1[p1]);
  }
  printf("Tamanho do vetor 02: \n");
  for (p2=0;p2<=t-1;p2++) {
    printf("Posição [%d]: ", p2);
    scanf("%d", &v2[p2]);
  }


}
