#include<stdio.h>

 /*--------------------------------------------------------------
 --------------------------------------------------------------
 Proprietário: Jorge Miguel dos Santos Martins
 Curso: Licenciatura Sistemas Tecnologias de Informação
 Disciplina: Programação II / Estruturas Dados
 Data:27 de fevereiro 2020
 Programa/Exercicio:Ficha 1 / exercicio 4
 --------------------------------------------------------------
 --------------------------------------------------------------
 */

 void medias(int vetor[], int tamanho){

   int par=0, impar=0, contaPar=0, contaImpar=0, valor=0;

   for(int a=0; a<tamanho; ++a){
     printf("Insira valor a alocar no vetor: ");
     scanf("%d", &valor);
     vetor[a]=valor;
   }

   for(int i=0; i<tamanho; ++i){
     if((vetor[i]%2)>0){
       impar=(vetor[i]+impar);
       contaImpar++;
     }
     else{
       par=(vetor[i]+par);
       contaPar++;
     }
   }
   printf("Números em Vetor: "); // apenas para printar os valores e assim confirmar..
   for(int t=0; t<tamanho; ++t){
     printf("%d", vetor[t]);
   }
   printf("\nMedia números pares: %d\n", (par/contaPar));
   printf("Media numeros impares: %d\n", (impar/contaImpar));
   printf("\nInsira uma tecla para terminar\n");
   getchar();
   getchar();

   return;
 }


 int main(){

   int tamanho=0;
   printf("Insira o tamanho do vetor \n");
   scanf("%d", &tamanho);
   int vetor[tamanho];

   medias(vetor, tamanho);

	return 0;
}
