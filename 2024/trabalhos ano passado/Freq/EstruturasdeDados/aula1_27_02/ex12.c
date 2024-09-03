#include<stdio.h>

 /*--------------------------------------------------------------
 --------------------------------------------------------------
 Proprietário: Jorge Miguel dos Santos Martins
 Curso: Licenciatura Sistemas Tecnologias de Informação
 Disciplina: Programação II / Estruturas Dados
 Data:5 de Março de 2020
 Programa/Exercicio: Ficha 1/ exercicio 12
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

  void removeClones(int tamanho, int vet[tamanho]){
    int aux;

    printf("Antes da remoção de números clones\n");
    for(int d=0; d<tamanho; ++d){
      printf(" %d ", vet[d]);
    }

    for(int a=0; a<tamanho; ++a){ //comparo um indice com o resto do ciclo até ao indice final
      for(int b=0; b<tamanho; ++b){ //aqui tem de ir até ao fim do ciclo a ver se é igual..
        if(a==b){
          continue;
        }
        else{
          if(vet[a]==vet[b]){
            for(int c=b; c<(tamanho-1); ++c){ //tamanho -1 para ele não ir buscar algo que está fora da memoria..
              vet[c]=vet[c+1];
            }
            tamanho--; //visto retirar um valor do vetor para parecer que o apaguei, depois de copiar(arrastar valores), diminuo o vetor.
          }
          else{
            continue; //sei que parece desnecessário usar este else, mas não sei porque se não usar às vezes ele pára.
          }
        }
      }
    }
    printf("\nApos remoção de números clones\n");
    for(int d=0; d<tamanho; ++d){
      printf(" %d ", vet[d]);
    }
    printf("\nClique para terminar\n");
    getchar();
    return;
  }

 int main(){
   int tamanho;

   printf("Insira o tamanho do vetor: "); scanf("%d", &tamanho);
   int vet[tamanho];
   addvet(tamanho, vet);
   removeClones(tamanho, vet);

	return 0;
}
