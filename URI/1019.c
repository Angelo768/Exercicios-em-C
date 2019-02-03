#include <stdio.h>

int main(){
  int seg;
  int min = 0;
  int hora = 0;
  scanf("%d", &seg);
  while (seg >= 60){
    seg -= 60;
    min++;
    }
    while(min >= 60){
      min -= 60;
      hora++;
    }
    printf("%d:%d:%d\n", hora, min,seg);
    return 0;
  }
