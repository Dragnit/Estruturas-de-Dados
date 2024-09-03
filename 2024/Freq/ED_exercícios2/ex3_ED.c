#include <stdio.h>
#include <time.h>
int main()
{
  FILE * fp;
  char ficheiro[30];
  char nome[50], caractere;
  time_t dataNewLine;
  time_t dataCara;
  time_t dataCarac;
  time_t dataPalavras;
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
      time(&dataNewLine);
     }
     if (nome[50] == ' ' || nome[50] == '\n')
     {
       contador_pal++;
       time(&dataPalavras);
     }
     if (nome[50] != ' ' && nome[50] != '\n')
     {
      contador_cara++;
      time(&dataCara);
     }
     if(caractere == nome[50])
      contador_caractere++;
      time(&dataCarac);
    }
     printf("numero de linhas: %d", contador);
     printf("\nAltura: %s", ctime(&dataNewLine));
     printf("\n");
     printf("numero de palavras: %d", contador_pal);
     printf("\nAltura: %s", ctime(&dataPalavras));
     printf("\n");
     printf("numero de caracteres: %d", contador_cara);
     printf("\nAltura: %s", ctime(&dataCarac));
     printf("\n");
     printf("Numero de caracteres encontrados: %d", contador_caractere);
     printf("\nAltura: %s", ctime(&dataCara));
      }
 fclose(fp);
}
