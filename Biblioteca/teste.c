#include <stdio.h>
 #define LIMITE 25

int main(){
     
    printf("\n====================== NOVA MATRIZ 2======================\n\n");
    for (int i = 0; i < *l2; i++) {
        for (int j = 0; j < *c1; j++) {
            P2[i][j] = 0;
            for (int k = 0; k < *l1; k++)
                P2[i][j] = P2[i][j] + (*mat2)[i][k]*(*mat1)[k][j];
            printf("[ %d ]", P2[i][j]);
        }
        printf("\t\n");
    }
}
