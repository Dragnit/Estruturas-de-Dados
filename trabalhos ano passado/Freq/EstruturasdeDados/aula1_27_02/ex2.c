#include<stdio.h>
#include<stdlib.h>//devido a funcao rand

 /*--------------------------------------------------------------
 --------------------------------------------------------------
 Proprietário: Jorge Miguel dos Santos Martins
 Curso: Licenciatura Sistemas Tecnologias de Informação
 Disciplina: Programação II / Estruturas Dados
 Data:27 Fevereiro 2020
 Programa/Exercicio: Ficha 1/exercicio 2
 --------------------------------------------------------------
 --------------------------------------------------------------
 */
void rad(int vet[]){
  int val;
  for(int i=0; i<30; ++i){
    val = rand() % 50; // assim faz de 0 a 50..
    if(val >= 1){ // condiçao pelo qual se for menor que 1 ele volta a repetir esta volta..
      vet[i]=val;
    }
    else{
      --i;
    }
  }
  return ;
}

 void show(int vet[]){
   printf("Numeros aleatorios no vetor..\n");
   for(int i=0; i<30; ++i){
     printf("%d\n", vet[i]);
   }
   printf("\nClique numa tecla para sair..");
   getchar();
 }

 int main(){
int vet[30];

rad(vet);
show(vet);
	return 0;
}
