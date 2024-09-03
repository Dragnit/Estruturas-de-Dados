#include<stdio.h>
#include<string.h>
#include<time.h> //para o Exercicio 3

 /*--------------------------------------------------------------
 --------------------------------------------------------------
 Proprietário: Jorge Miguel dos Santos Martins
 Curso: Licenciatura Sistemas Tecnologias de Informação
 Disciplina: Programação II / Estruturas Dados
 Data:10 de Março 2020
 Programa/Exercicio: Ficha 2.1 / Exercicio 1 / 3
 --------------------------------------------------------------
 --------------------------------------------------------------
 */
void createFile(char ficheiro[100]){
  time_t memorySec; //variavel usada para guardar o tempo dado pela estrutura em segundos.
  FILE *saveS;

  saveS = fopen(ficheiro, "a");

  if(saveS==NULL){
    printf("Ficheiro não foi possivel ser criado\n");
    printf("Clique para continuar\n");
    getchar();
    getchar();
    return;
  }
  else{
    printf("Ficheiro com o nome %s criado com suscesso\n", ficheiro);
    printf("Clique para continuar\n");
    getchar();
    getchar();
  }
  time(&memorySec);
  fprintf(saveS, "Registado no dia %s \n\n", ctime(&memorySec));
  fclose(saveS);
  return;
}

void saveTextFile(char textFile[5000], char ficheiro[100]){
  time_t memorySec; //variavel usada para guardar o tempo dado pela estrutura em segundos.
  char test2;
  FILE * saveData;
  do{
    printf("Ao clicar enter para mudar de linha o conteudo será gravado em %s\n", ficheiro);
    fgets(textFile, 5000, stdin);
    saveData=fopen(ficheiro, "a");

    if(saveData==NULL){
      printf("Ficheiro não foi possivel ser criado\n");
      printf("\nClique para continuar\n");
      getchar();
      getchar();
      return;
    }
    else{
      fprintf(saveData, "%s", textFile);
    }

    fclose(saveData);

  printf("\nPara continuar a escrever para ficheiro digite S para sair escreva N\n");
  scanf("%c", &test2);
  getchar();

}while(test2!='N');
saveData=fopen(ficheiro, "a");
time(&memorySec);
fprintf(saveData, "Escrito no dia %s \n\n", ctime(&memorySec));
fclose(saveData);
return;
}

void writeFile(char textFile[5000], char ficheiro[100]){
   time_t memorySec; //variavel usada para guardar o tempo dado pela estrutura em segundos.
   char gety;
   FILE * write;

    write=fopen(ficheiro, "r");
    if(write==NULL){
      printf("Ficheiro não foi possivel ser criado\n");
      printf("Clique para continuar\n");
      getchar();
      return;
    }
    else{
      printf("Ficheiro com o nome %s aberto com sucesso\n", ficheiro);
      printf("Clique para continuar\n");
      getchar();
    }

      while( fgets(textFile, 100, write) != NULL ){
        fputs(textFile, stdout);
      }
      printf("Clique para terminar\n");
      getchar();

      time(&memorySec);
      fprintf(write, "Escrito no monitor no dia %s \n\n", ctime(&memorySec));
      fclose(write);
    return;
}

 int main(){

char ficheiro [100], textFile[5000];


printf("Insira o nome do ficheiro a criar\n"); scanf("%s", ficheiro);

createFile(ficheiro);
saveTextFile(textFile, ficheiro);
writeFile(textFile, ficheiro);


	return 0;
}
