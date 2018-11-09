
#include <stdio.h>
int main();
int menumatriz();
int menumatriz(){
    int mm;
    printf("\e[H\e[2J");
    printf("=============================================\n");
    printf("|\t\tMenu Matriz                 |\n");
    printf("=============================================\n");
    printf("|1. Ler matrizes                            |\n");
    printf("|2. Somar duas matrizes                     |\n");
    printf("|3. Multiplicar duas matrizes               |\n");
    printf("|4. Calcular a transposta                   |\n");
    printf("|5. Calcular o determinante                 |\n");
    printf("|6. Verificar se há uma matriz simétrica    |\n");
    printf("|7. Voltar ao menu anterior                 |\n\n");
    printf("Opção desejada: ");
    scanf("%d", &mm);
    switch (mm){
        case 7: main(); break;
        default: printf("Opção inválida\n"); break;
    }
}
