#include <stdio.h>

int soma(int a, int b){
    int s = a + b;
    return s;
}

int main(){
    int f, g;
    scanf("%d", &f);
    scanf("%d", &g);
    printf("%d",soma(f, g));

}
