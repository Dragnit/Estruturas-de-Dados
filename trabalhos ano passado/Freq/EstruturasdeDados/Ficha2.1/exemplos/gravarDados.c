#include<stdio.h>
#include"headers.h"
#include<string.h> //esta biblioteca é para as strings.
#include<stdio_ext.h> /* inseri este include porque me estava a dar problemas com o fpurge*/
#include<stdlib.h> /*inseri este por causa do system("clear") */
#include <ctype.h>

// Jorge Miguel dos Santos Martins Nº2019100813 LSTI 
// neste ficheiro contem as funçoes para gravar os dados da memoria em ficheiro de texto..

void gravarDados(){
  FILE *gravadorNotas, *gravadorAlunos, *gravadorNumeros, *gravadorTrabalhos, *gravadorPesos;
  
  gravadorNotas = fopen("SaveNotas.txt", "w"); // gravaçao de notas
  
  if(gravadorNotas==NULL){
		printf("Nao foi possivel gravar Notas\n");
	}
	else{
		for(int contador1=0; contador1 < 50; contador1++){
      for(int contador2=0; contador2 < 20; contador2++){
			     fprintf(gravadorNotas, "%.1f ", notas[contador1][contador2]);
           if(contador2==19){
             fprintf(gravadorNotas, "\n");
           }
			}
    }
  }
	fclose(gravadorNotas);
	
  
  gravadorPesos = fopen("SavePesos.txt", "w"); // gravação de pesos associados a trabalhos
  
  if(gravadorPesos==NULL){
    printf("Não foi possivel gravar Pesos\n");
  }
  else{
    for(int contador3=0; contador3 < 20; ++contador3){
      fprintf(gravadorPesos, "%d ", vetorPesosAssociados[contador3]);
    }
  }
  fclose(gravadorPesos);
  
  gravadorAlunos = fopen("SaveAlunos.txt", "w"); //gravação de alunos associados
  
  if(gravadorAlunos==NULL){
    printf("Nao foi possivel gravar Alunos\n");
  }
  else{
    for(int contador4=0; contador4 < 50; contador4++){
        fprintf(gravadorAlunos, "%s\n", memoriaAluno[contador4]);
      }
    }
  fclose(gravadorAlunos);
  
  gravadorNumeros = fopen("SaveNumeros.txt", "w"); //gravação de numeros de alunos
  
  if(gravadorNumeros==NULL){
    printf("Nao foi possivel gravar Numeros\n");
  }
  else{
    for(int contador6=0; contador6 < 50; contador6++){
        fprintf(gravadorNumeros, "%d\n", memoriaNumero[contador6]);
        }
  }
  fclose(gravadorNumeros);
  
  gravadorTrabalhos = fopen("SaveTrabalhos.txt", "w"); //gravação de trabalhos a ser avaliados 
  
  if(gravadorTrabalhos==NULL){
    printf("Nao foi possivel gravar trabalhos\n");
  }
  else{
    for(int contador7=0; contador7 < 20; contador7++){
        fprintf(gravadorTrabalhos, "%d ", trabalhosPraticos[contador7]);
        }
  }
  fclose(gravadorTrabalhos);
  
  system("clear");
  printf("Trabalhos gravados no ficheiro SaveTrabalhos.txt\n");
  printf("Numeros gravados no ficheiro SaveNumeros.txt\n");
  printf("Alunos gravados no ficheiro SaveAlunos.txt\n");
  printf("Pesos Associados foram gravados em SavePesos.txt\n");
	printf("Notas foram gravadas em SaveNotas.txt\n");
  printf("Clique enter para voltar ao menu.."); 
  __fpurge(stdin); 
  fflush(stdin);
  scanf("%1[\n]", pausa); /* esta foi a opção para fazer o sistema pausar, em linux o system pause, getch, não funcionam */
  system("clear");
  return;
}