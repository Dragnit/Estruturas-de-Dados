#include<stdio.h>
#include <time.h>

void contador(){
  int contarlinha=0,contarchar=0,contarpalavra=0,ocorrencias=0;
  char aux,pesquisachar;
  char arquivo[50];
  time_t hora;
  FILE * fp;

  printf("Digite o arquivo que deseja abrir: ");
  gets(arquivo);
  fp = fopen(arquivo, "r+");

  time(&hora);

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
  fprintf(fp,"Total de linhas: %d\n",contarlinha);
  fprintf(fp,"Total de carateres: %d\n",contarchar);
  fprintf(fp,"Total de palavras: %d\n",contarpalavra);
  fprintf(fp,"Total de ocorrencias da letra %c: %d\n",pesquisachar,ocorrencias);
  fprintf(fp,"Resgisto de alterações: %s",ctime(&hora));
  fclose(fp);
}
int main(){
  contador();
}
