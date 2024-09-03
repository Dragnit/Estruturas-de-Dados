#include<stdio.h>

 /*--------------------------------------------------------------
 --------------------------------------------------------------
 Proprietário: Jorge Miguel dos Santos Martins
 Curso: Licenciatura Sistemas Tecnologias de Informação
 Disciplina: Programação II / Estruturas Dados
 Data:4 de Março de 2020
 Programa/Exercicio: Ficha 1/ Exercicio 11
 --------------------------------------------------------------
 --------------------------------------------------------------
 */

 void addvet(int tamanho, int vet[tamanho]){
   int indice=0;
   printf("\nInserir valores inteiros no vetor\n");
   for(int a=0; a<tamanho; ++a){
     printf("\nInsira um valor inteiro para o indice %d : ", a);
     scanf("%d", &indice);
     vet[a]=indice;
   }
   printf("Vetor completamente preenchido\n");
   printf("Clique para continuar\n");
   getchar();
   getchar();
   return;
}

  void sortBubbleDesne(int tamanho, int vet[tamanho]){
    int aux;
    printf("\nVetor inicial\n");
    for(int f=0; f<tamanho; ++f){
      printf(" %d ", vet[f]);
    }
    for(int a=0; a<tamanho; ++a){
      for(int b=0; b<(tamanho-1); ++b){
        if(vet[b]<vet[b+1]){ //vai fazendo comparação dois a dois até ordenar por completo o vetor.
          aux=vet[b];
          vet[b]=vet[b+1];
          vet[b+1]=aux;
        }
        else{
          continue;
        }
      }
    }
    printf("\n\nVetor Ordenado Descrescente em algoritmo Sort Bubble com ciclos desnecessários\n\n");
    printf("Vetor em Ordem Descrescente\n");
    for(int f=0; f<tamanho; ++f){
      printf(" %d ", vet[f]);
    }
    printf("\nClique para continuar\n");
    getchar();

    return;
  }

  void sortBubble(int tamanho, int vet[tamanho]){ //tentativa de tornar mais eficiente cortando ciclos desnecessários..
    printf("\nVolte a inserir valores para ordenar no vetor com o tamanho já anteriormente escolhido\n");
    printf("\nAlinea b do exercicio proposto, tentativa de eficiencia do algoritmo");
    addvet(tamanho, vet);
    int aux, efi=0;
    printf("\nVetor inicial\n");
    for(int f=0; f<tamanho; ++f){
      printf(" %d ", vet[f]);
    }
    for(int a=0; a<tamanho && efi!=-1; ++a){
      efi=-1;
      for(int b=0; b<(tamanho-1); ++b){
        if(vet[b]<vet[b+1]){
          efi++;
          aux=vet[b];
          vet[b]=vet[b+1];
          vet[b+1]=aux;
        }
        else{
          continue;
        }
      }
    }
    printf("\n\nVetor Ordenado Descrescente em algoritmo Sort Bubble mais eficiente\n\n");
    printf("Vetor em Ordem Descrescente\n");
    for(int f=0; f<tamanho; ++f){
      printf(" %d ", vet[f]);
    }
    printf("\nClique para continuar\n");
    getchar();

    return;
  }

 int main(){

   int tamanho=0;

   printf("Insira o tamanho do vetor: "); scanf("%d", &tamanho);

   int vet[tamanho];

   addvet(tamanho, vet);
   sortBubbleDesne(tamanho, vet);
   sortBubble(tamanho, vet);

	return 0;
}
