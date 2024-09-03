#include <stdio.h>
#define TAMANHO 10

void counter(){
  int lineCount=0,charCount=0,wordCount=0,count=0;
  char txt,searchChar;
  FILE * Exercicio2;
  Exercicio2=fopen("players.txt","r");

  printf("Introduza o carater que pretende pesquisar: ");
  scanf("%c",&searchChar);
  while((txt=fgetc(Exercicio2))!=EOF){
    if(txt =='\n'){
      lineCount++;
    }
    if(txt>64 && txt<91 || txt>96 && txt<123 || txt>127 && txt<166){
      charCount++;
    }
    if(txt == ' ' || txt == '\n'){
      wordCount++;
    }
    if(searchChar==txt){
      count++;
    }
  }
  printf("Total de linhas: %d\n",lineCount);
  printf("Total de carateres: %d\n",charCount);
  printf("Total de palavras: %d\n",wordCount);
  printf("Total de ocorrencias da letra %c: %d",searchChar,count);
  fclose(Exercicio2);
}
int main()
{
counter();

	return 0;
}