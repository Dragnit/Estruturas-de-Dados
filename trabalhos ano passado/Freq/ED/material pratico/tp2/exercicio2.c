#include<stdio.h>

int main(){
  int contarlinha=0,contarchar=0,contarpalavra=0,ocorrencias=0;
  char aux,pesquisachar;
  char arquivo[50];

  FILE * fp;

  printf("Digite o arquivo que deseja abrir: ");
  gets(arquivo);
  fp = fopen(arquivo, "r");

  printf("Introduza o carater que pretende pesquisar: ");
  scanf("%c",&pesquisachar);
  while((aux=fgetc(fp))!=EOF){
    if(aux=='\n'){
      contarlinha++;
    }
    if(aux>64&&aux<91 || aux>96&&aux<123 || aux>127&&aux<166){
      contarchar++;
    }
    if(aux==' ' || aux=='\n'){
      contarpalavra++;
    }
    if(pesquisachar==aux){
      ocorrencias++;
    }
  }
  printf("Total de linhas: %d\n",contarlinha);
  printf("Total de carateres: %d\n",contarchar);
  printf("Total de palavras: %d\n",contarpalavra);
  printf("Total de ocorrencias da letra %c: %d",pesquisachar,ocorrencias);
  fclose(fp);
}
