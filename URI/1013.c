#include <stdio.h>

int main(){
  int a, b, c, maior;
  scanf("%d%d%d", &a, &b, &c);
  if(a > b && a > c){
    maior = a;
  }else{
    if(b > a && b > c){
      maior = b;
    }else{
      if(c > a && c > b){
        maior = c;
      }
    }
  }

  printf("%d eh o maior\n", maior);

  return 0;
}
