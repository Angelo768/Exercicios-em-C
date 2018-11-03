#include <stdio.h>

int main();

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
    return 0;
}


int menuvetor(){
    int mv;
    FILE *file;
    char linha[100];
    char *result;
    file = fopen("cvetor.c", "r");
    if (file == NULL){
      printf("Arquivo não encontrado");
      return 1;
    }

    printf("\e[H\e[2J");
    printf("===================================================\n");
    printf("|\t\tMenu Vetor                        |\n");
    printf("===================================================\n");
    printf("|1. Ler vetores.                                  |\n");
    printf("|2. Somar dois vetores.                           |\n");
    printf("|3. Multiplicar um dos vetores por um escalar.    |\n");
    printf("|4. Realizar o produto escalar entre dois vetores.|\n");
    printf("|5. Voltar ao menu anterior.                      |\n\n");
    printf("Opção desejada: ");
    scanf("%d", &mv);
    switch (mv) {
        case 1: result = fgets(linha, 100, file);
        case 5: main(); break;
        default: printf("Opção inválida\n"); break;
    }
    fclose(file);
    return 0;
}


int main(){
    int op;
    printf("\e[H\e[2J");
    printf("==============================\n");
    printf("|\tMenu Inicial         |\n");
    printf("==============================\n");
    printf("|1. Operações com vetores    |\n");
    printf("|2. Operações com matrizes   |\n");
    printf("|3. Sair do programa         |\n\n");
    printf("Operação desejada: ");
    scanf("%d", &op);
    switch (op){
        case 1: menuvetor(); break;
        case 2: menumatriz(); break;
        case 3: printf("Encerrando programa...\n"); break;
        default: printf("Opção inválida\n"); break;
    }
    return 0;
}
