#include <stdio.h>
#include <time.h>

void counter(){
  int lineCount=0,charCount=0,wordCount=0,count=0;
  char txt,searchChar;
  time_t currentTime;
  FILE * Exercicio2;
  Exercicio2=fopen("players.txt","r+");

  time(&currentTime);

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
  fprintf(Exercicio2,"Total de Linhas: %d\n",lineCount);
  fprintf(Exercicio2,"Total de Palavras: %d\n",wordCount);
  fprintf(Exercicio2,"Total de carateres: %d\n",charCount);
  fprintf(Exercicio2,"Total de ocorrencias da letra %c: %d\n",searchChar,count);
  fprintf(Exercicio2,"Tempo de Registo da informacao: %s",ctime(&currentTime));
  fclose(Exercicio2);
}
int main()
{
counter();
printf("Informacao adicionada com sucesso no final do ficheiro!");
	return 0;
}