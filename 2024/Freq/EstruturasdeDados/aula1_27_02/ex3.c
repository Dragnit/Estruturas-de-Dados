#include<stdio.h>

 /*--------------------------------------------------------------
 --------------------------------------------------------------
 Proprietário: Jorge Miguel dos Santos Martins
 Curso: Licenciatura Sistemas Tecnologias de Informação
 Disciplina: Programação II / Estruturas Dados
 Data: 27 fevereiro 2020
 Programa/Exercicio: ficha1/exercicio 3
 --------------------------------------------------------------
 --------------------------------------------------------------
 */
 void turn(){

   int tamanho=0, aux, numero;
   printf("Insira o tamanho do vetor: ");
   scanf("%d", &tamanho);
   int vet[tamanho];
   for(int i=0; i<tamanho; ++i){
     printf("Insira numero: ");
     scanf("%d", &numero);
     vet[i]=numero;
   }

   printf("Antes\n");
   for(int t=0; t<tamanho; ++t){
     printf("%d ", vet[t]);
   }
   aux=vet[0]; // apenas guardo o primeiro para o copiar no fim..
   for(int a=0; a<=tamanho; ++a){ //apenas copio o segundo para primeiro e assim sucessivamente..
     vet[a]=vet[a+1];
   }
   vet[tamanho-1]=aux;
   printf("\nDepois\n");
   for(int b=0; b<tamanho; ++b){
     printf("%d ", vet[b]);
 }
 printf("\nClique numa tecla para sair");
 getchar();
 getchar();
 return ;
 }

 int main(){

   turn();

	return 0;
}
