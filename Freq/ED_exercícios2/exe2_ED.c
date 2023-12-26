#include <stdio.h>

int main()
{
  FILE * fp;
  char ficheiro[30];
  char nome[50], caractere;
  int contador=0;
  int contador_pal = 0, contador_cara = 0, contador_caractere = 0;
  printf("Entre com o nome do ficheiro: ");
  scanf("%s", ficheiro);
  fp = fopen(ficheiro, "r");

  if (fp == NULL)
  {
    printf("Erro ao abrir o ficheiro\n");
  }
  else
  {
    printf("Introduza o caractere que quer procurar: ");
    fflush(stdin);
    scanf("%c",&caractere );
    while ((nome[50] = fgetc(fp)) != EOF)
   {
     if (nome[50] == '\n')
     {
      contador++;
     }
     if (nome[50] == ' ' || nome[50] == '\n')
     {
       contador_pal++;
     }
     if (nome[50] != ' ' && nome[50] != '\n')
     {
      contador_cara++;
     }
     if(caractere == nome[50])
      contador_caractere++;
    }
     printf("numero de linhas: %d", contador);
     printf("\n");
     printf("numero de palavras: %d", contador_pal);
     printf("\n");
     printf("numero de caracteres: %d", contador_cara);
     printf("\n");
     printf("Numero de caracteres encontrados: %d", contador_caractere);
 fclose(fp);
 }
}
