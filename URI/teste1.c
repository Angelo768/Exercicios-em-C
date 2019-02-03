#include <stdio.h>
int main()
{
FILE *arq;
char Linha[100];
char *result;
int i;
// Abre um arquivo TEXTO para LEITURA
arq = fopen("texto.txt", "r");
if (arq == NULL) // Verifica se houve erro na abertura
{
printf("Problemas na abertura do arquivo!\n");
return 1;
}

i = 1;
while (!feof(arq))
{
// Le uma linha (inclusive com o '\n')

result = fgets(Linha, 100, arq); // o 'fgets' lê até 99 caracteres ou até o '\n'
if (result) // Se foi possivel ler
printf("Linha %d : %s",i,Linha);

i++;
}
  fclose(arq);
}
