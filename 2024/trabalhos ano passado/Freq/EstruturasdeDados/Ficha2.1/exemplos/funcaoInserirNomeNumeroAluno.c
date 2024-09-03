#include"headers.h"
#include<stdio.h>
#include<stdio_ext.h> 
#include<string.h>
#include<stdlib.h> 
#include <ctype.h>

//Jorge Miguel dos Santos Martins
//Nº2019100813 - Programaçao I
//Programa com funcao para inserir nome de aluno completo e o seu numero, e o verificar.
//
  


void inserir() 
{
  
  char aluno[51];
  unsigned int numero;
  
  if(contador<50){
    printf("Nome de Aluno: ");
    __fpurge(stdin);
    fflush(stdin);
    scanf("%50[^\n]", aluno);//usando o %[^\n] já se pode usar espaços no nome que ele lê. 
     for(int i=0; aluno[i]!='\0'; ++i){
       if(aluno[i]==' ' || isalpha(aluno[i])){
         continue;
       }
       else{
         system("clear");
         printf("Erro, nome de aluno contem algo diferente de caracteres\n");
         printf("Clique enter para voltar ao menu.."); 
         __fpurge(stdin); 
         fflush(stdin);
         scanf("%1[\n]", pausa); /* esta foi a opção para fazer o sistema pausar, em linux o system pause, getch, não funcionam */
         system("clear");
         return;
       }     
     }
    system("clear"); //assim limpa sempre o que foi escrito
    printf("Nome do aluno inserido correctamente na memoria...\n");
    printf("%s", aluno);
    for(int z=0; z<50; ++z){
      memoriaAluno[contador][z]=aluno[z];
    }    
    __fpurge(stdin);
    fflush(stdin);
    printf("\nNumero de aluno: ");
    if((scanf("%u", &numero))){
      for(int i=0; i<50; ++i){
        if(memoriaNumero[i]==numero){ // cada aluno tem o seu número de aluno, assim na pesquisa por número não há erros..
          system("clear");
          printf("Numero de aluno já existe\n");
          printf("Clique enter para voltar ao menu.."); 
          __fpurge(stdin);
          fflush(stdin);
          scanf("%1[\n]", pausa);
          system("clear");
          return;
        }
        else{
          continue;
        }
      }
      system("clear");
      printf("Numero de aluno inserido correctamente na memoria...\n");
      memoriaNumero[contador]=numero;
      
      printf("Clique enter para voltar ao menu.."); 
      __fpurge(stdin);
      fflush(stdin);
      scanf("%1[\n]", pausa);
      system("clear");
    }
    else{
      system("clear");
      printf("Erro, numero de aluno algo diferente de digitos ou menor que 0\n");
      printf("Clique enter para voltar ao menu.."); 
      __fpurge(stdin);
      fflush(stdin);
      scanf("%1[\n]", pausa);
      system("clear");
      return;      
      }  
    system("clear");
    contador++;
    return;
    }
  else{
    system("clear");
    printf("Erro, numero maximo de alunos\n");
    printf("Clique enter para voltar ao menu.."); 
    __fpurge(stdin);
    fflush(stdin);
    scanf("%1[\n]", pausa);
    system("clear");
    return; 
  }
}