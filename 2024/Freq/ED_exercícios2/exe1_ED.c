#include <stdio.h>
int main(int argc , char * argv[])
{
	FILE * fp;
  char ficheiro[30];
  char nome[50];
  printf("Entre com o nome do ficheiro: ");
  scanf("%s", ficheiro);
  fp = fopen(ficheiro, "a");
  printf("Introduza uma frase: ");
  fflush(stdin);
  fgets(nome, 50, stdin);

  if (fp == NULL)
  {
    printf("Erro ao abrir o ficheiro\n");
  }
  else
  {
    fprintf(fp, "%s", nome);
  }
  fclose(fp);
}
