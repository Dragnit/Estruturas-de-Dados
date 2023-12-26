#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define ARRAY_SIZE 100

void fileNameContent(int playersQtt,char fileName[ARRAY_SIZE],char playersNames[ARRAY_SIZE][ARRAY_SIZE]){
  int i;
  FILE * contentFile;

  contentFile=fopen(fileName,"w+");

  printf("Escreva a quantidade de jogadores que pretende inserir: ");
  scanf("%d",&playersQtt);

  for(i=0;i<playersQtt;i++){
    printf("Escreva o nome de jogadores de futebol famosos: ");
    fflush(stdin);
    fgets(playersNames[i],ARRAY_SIZE,stdin);
  }

  for(i=0;i<playersQtt;i++){
    fprintf(contentFile,"%s",playersNames[i]);
  }
  fclose(contentFile);
}

void addInfo(char addicionalInfo[ARRAY_SIZE],char fileName[ARRAY_SIZE]){
  FILE * contentFile;
  contentFile=fopen(fileName,"a");

  printf("Escreva a informacao adicional que deseja: ");
  fflush(stdin);
  fgets(addicionalInfo,ARRAY_SIZE,stdin);

  fprintf(contentFile,"%s",addicionalInfo);
  fclose(contentFile);
}

void consoleText(char text[ARRAY_SIZE],char fileName[ARRAY_SIZE]){
  FILE * contentFile;
  contentFile=fopen(fileName,"r");
  rewind(contentFile);
  printf("Info:\n");
  while(fgets(text,ARRAY_SIZE,contentFile)!=NULL){
    printf("%s",text);
  }
  fclose(contentFile);
}

int main()
{
  int playersQtt;
  char text[ARRAY_SIZE],fileName[ARRAY_SIZE],addicionalInfo[ARRAY_SIZE];
  char playersNames[ARRAY_SIZE][ARRAY_SIZE];

  printf("Introduza o nome do ficheiro: ");
  gets(fileName);

  fileNameContent(playersQtt,fileName,playersNames);
  addInfo(addicionalInfo,fileName);
  consoleText(text,fileName);

  return 0;
}
