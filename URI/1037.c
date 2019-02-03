#include <stdio.h>

int main(){
  double i;
  scanf("%lf", &i);
  if (0 <= i && i<= 25){
    printf("Intervalo (0,25]\n");
  }else{
    if (25 < i && i <= 50){
      printf("Intervalo (25,50]\n");
    }else{
      if (50 < i && i <= 75){
        printf("Intervalo (50,75]\n");
      }else{
        if (75 < i && i <= 100){
          printf("Intervalo (75,100]\n");
        }else{
          printf("Fora de Intervalo\n");
        }
      }
    }
  }
  return 0;
}
