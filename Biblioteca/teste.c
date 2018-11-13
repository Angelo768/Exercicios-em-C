#include <stdio.h>
#include <stdlib.h>

int main(){

    int i, *n = (int*)malloc(5*sizeof(int));
    for(i=0;i<5;i++) printf("Sei lá %d\n", *n);//scanf("%d", &(*n[5]));
}
