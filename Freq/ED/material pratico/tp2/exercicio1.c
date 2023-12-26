#include <stdio.h>
#define TAMANHO 500

int main(int argc, char *argv[]){

  FILE*fp;
  char nomeficheiro[TAMANHO];
  char conteudo[TAMANHO];

  printf("Nome do ficheiro:");
  scanf("%s",nomeficheiro);

  fp=fopen(nomeficheiro,"a");

  printf("Introduza conteudo no ficheiro:");
  fflush(stdin);
  fgets(conteudo,TAMANHO,stdin);

  if(fp == NULL){
    printf("Erro: o ficheiro nao existe ou nao pode ser lido...\n");
  }
  else
  fprintf(fp,"%s",conteudo);
  printf("\nConteudo do ficheiro: %s",conteudo);

  fclose(fp);
  return 0;
}
