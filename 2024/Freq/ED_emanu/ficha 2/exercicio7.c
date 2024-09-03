#include <stdio.h>
#define SIZE 100

int numberOfPersons;
char names[SIZE][SIZE];

void insertNamesTable(){
  int i;

  printf("Introduza o numero de pessoas a colocar na tabela: ");
  scanf("%d",&numberOfPersons);

  for(i=0;i<numberOfPersons;i++){
    printf("Introduza o nome da pessoa: ");
    fflush(stdin);
    fgets(names[i],SIZE,stdin);
  }

  printf("Nomes:\n");
  for(i=0;i<numberOfPersons;i++){
    printf("%s",names[i]);
  }
}

void writeNamesTextFile(){
  int i;
  FILE * namesFile;

  namesFile=fopen("nomes.txt","w+");
  for(i=0;i<numberOfPersons;i++){
    fprintf(namesFile,"%s",names[i]);
  }
  fclose(namesFile);
}

void readNamesTextFile(){
  int i;
  FILE * readNamesFile;

  readNamesFile=fopen("nomes.txt","r");

  printf("Conteudo do ficheiro nomes:\n");
  for(i=0;i<numberOfPersons;i++){
    fgets(names[i],sizeof(names),readNamesFile);
    printf("%s",names[i]);
  }

  fclose(readNamesFile);
}

void writeTableNamesBinaryFile(){
  FILE * tableNamesBinaryFile;

  tableNamesBinaryFile=fopen("tabelanomes.dat","w+b");

  fwrite(names,sizeof(names),1,tableNamesBinaryFile);

  fclose(tableNamesBinaryFile);
}

void writeNamesBinaryFile(){
  int i;
  FILE * namesBinaryFile;

  namesBinaryFile=fopen("nomesBinario.dat","w+b");

  for(i=0;i<numberOfPersons;i++){
    fwrite(names[i],sizeof(names[i]),1,namesBinaryFile);
  }

  fclose(namesBinaryFile);
}

void readBinaryFiles(){
  int i;
  FILE * readNames;
  FILE * readTable;

  readNames=fopen("nomesBinario.dat","r+b");
  readTable=fopen("tabelanomes.dat","r+b");

  rewind(readTable);
  fread(names,sizeof(names),1,readTable);

  printf("Conteudo do ficheiro tabelanomes:\n");
  for(i=0;i<numberOfPersons;i++){
    printf("%s",names[i]);
  }

  rewind(readNames);
  for(i=0;i<numberOfPersons;i++){
    fread(names[i],sizeof(names[i]),1,readNames);
  }
  printf("Conteudo do ficheiro nomesBinario:\n");
  for(i=0;i<numberOfPersons;i++){
    printf("%s",names[i]);
  }
}

int main()
{
  insertNamesTable();
  writeNamesTextFile();
  readNamesTextFile();
  writeTableNamesBinaryFile();
  writeNamesBinaryFile();
  readBinaryFiles();
  return 0;
}
