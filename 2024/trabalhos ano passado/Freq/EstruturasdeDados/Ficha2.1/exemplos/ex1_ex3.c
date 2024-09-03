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
  struct tm *date; // para o Exercicio 3, usar uma estrutura da biblioteca para dar o tempo real. Este é o ponteiro que armazena..
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
  date = localtime(&memorySec); //o ponteiro fica igual ao que é dado pelo endereço do memorySec que está em segundos, o localtime serve para converter.

  //para acessar os membros de uma struct usando o ponteiro
  //utilizamos o operador -> no nosso caso temos:
  //date->membro_da_struct
  //retirei isto acima do site que depois vou deixar no relatório, mas assim percebe porque estou a utilizar algo que não aprendemos..

  fprintf(saveS, "Registado no dia %d / %d / %d \n\n", date->tm_mday, date->tm_mon+1, date->tm_year+1900);
  fprintf(saveS, "Registado na hora %d: %d: %d \n\n", date->tm_hour, date->tm_min, date->tm_sec);
  fclose(saveS);
  return;
}

void saveTextFile(char textFile[5000]){
  struct tm *date; // para o Exercicio 3, usar uma estrutura da biblioteca para dar o tempo real. Este é o ponteiro que armazena..
  time_t memorySec; //variavel usada para guardar o tempo dado pela estrutura em segundos.
  char test2;
  FILE * saveData;
  do{
    printf("Ao clicar enter para mudar de linha o conteudo será gravado em Ficheiro.txt\n");
    fgets(textFile, 5000, stdin);
    saveData=fopen("Ficheiro.txt", "a");

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
saveData=fopen("Ficheiro.txt", "a");
time(&memorySec);
date = localtime(&memorySec); //o ponteiro fica igual ao que é dado pelo endereço do memorySec que está em segundos, o localtime serve para converter.
fprintf(saveData, "Escrito no dia %d / %d / %d \n\n", date->tm_mday, date->tm_mon+1, date->tm_year+1900);
fprintf(saveData, "Escrito na hora %d: %d: %d \n\n", date->tm_hour, date->tm_min, date->tm_sec);
fclose(saveData);
return;
}

void writeFile(char textFile[5000]){
   struct tm *date; // para o Exercicio 3, usar uma estrutura da biblioteca para dar o tempo real. Este é o ponteiro que armazena..
   time_t memorySec; //variavel usada para guardar o tempo dado pela estrutura em segundos.
   char gety;
   FILE * write;

    write=fopen("Ficheiro.txt", "r");
    if(write==NULL){
      printf("Ficheiro não foi possivel ser criado\n");
      printf("Clique para continuar\n");
      getchar();
      return;
    }
    else{
      printf("Ficheiro com o nome ficheiro.txt aberto com sucesso\n");
      printf("Clique para continuar\n");
      getchar();
    }

      while( fgets(textFile, 100, write) != NULL ){
        fputs(textFile, stdout);
      }
      printf("Clique para terminar\n");
      getchar();

      time(&memorySec);
      date = localtime(&memorySec); //o ponteiro fica igual ao que é dado pelo endereço do memorySec que está em segundos, o localtime serve para converter.

      fprintf(write, "Escrito no monitor no dia %d / %d / %d \n\n", date->tm_mday, date->tm_mon+1, date->tm_year+1900);
      fprintf(write, "Escrito no monitor as %d: %d: %d \n\n", date->tm_hour, date->tm_min, date->tm_sec);
      fclose(write);
    return;
}

 int main(){

char ficheiro [100], textFile[5000];


printf("Insira o nome do ficheiro a criar\n"); scanf("%s", ficheiro);

createFile(ficheiro);
saveTextFile(textFile);
writeFile(textFile);


	return 0;
}
