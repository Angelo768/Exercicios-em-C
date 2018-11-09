int menuvetor();
int menuvetor(){
    int mv;
    
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
        case 5: main(); break;
        default: printf("Opção inválida\n"); break;
    }
}
