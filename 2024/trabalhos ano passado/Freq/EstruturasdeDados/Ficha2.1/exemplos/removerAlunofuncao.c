#include <stdio.h>
#include <string.h>
#include "headers.h"
#include <stdio_ext.h>
#include <stdlib.h>
#include <ctype.h>
//Jorge Martins Nº2019100813 LSTI 

//funcao de remover aluno


void removerAluno(){
  char strAux[50], strAluno[50];
  int contAux=0;
  printf("Insira o Aluno a remover, use letras pequenas e maiusculas correctamente\n");
  __fpurge(stdin);
  fflush(stdin);
  scanf("%[^\n]", strAluno);
  do{

    for(int i=0; i<50; i++){
        if(strcmp(memoriaAluno[i], strAluno)){ // enquanto forem diferentes as palavras o strcmp dá +1 ou -1 mas quando forem iguais ele dá 0 ou seja o if passa para else
          contAux++;
          continue;
        }
        else{
          for(int t=i; t<50; ++t){
            for(int q=0; q<50; ++q){
              memoriaAluno[t][q]='\0'; // caso o nome que venha a seguir seja maior e assim tenho a certeza que não ficam lá caracteres desse nome.
            }
            strcpy(memoriaAluno[t], memoriaAluno[t+1]);
            memoriaNumero[t]=memoriaNumero[t+1]; //uso este ciclo para logo não deixar espaços em branco na lista de alunos
            memoriaNumero[t+1]=-1;
          }
          system("clear");
          printf("Aluno e seu numero removido\n");
          contador--; // assim retiro um valor ao total da lista de alunos.. serve depois para dar load no inicio do programa ao que já está gravado e assim preencher tudo na memoriaAluno
          printf("Clique enter para voltar ao menu.."); 
          __fpurge(stdin);
          fflush(stdin);
          scanf("%1[\n]", pausa);
          system("clear");
          return;
        }
    }
    system("clear");
    printf("Aluno não existe\n");
    printf("Clique enter para voltar ao menu.."); 
    __fpurge(stdin);
    fflush(stdin);
    scanf("%1[\n]", pausa);
    system("clear");
    return;
  
  }while(1);
  
}