#include<stdio.h>

 /*--------------------------------------------------------------
 --------------------------------------------------------------
 Proprietário: Jorge Miguel dos Santos Martins
 Curso: Licenciatura Sistemas Tecnologias de Informação
 Disciplina: Programação II / Estruturas Dados
 Data:2 Março 2020
 Programa/Exercicio: Ficha 1 / Exercicio 9
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

  void nBigger(int tamanho, int vet[tamanho]){
    int n=0, aux=vet[0], counter;
    printf("Insira até que indice do vetor quer saber qual é o número maior inserido:  "); scanf("%d", &n);
    if(n>=tamanho){
      printf("Vetor construído não tem este indice\n");
      printf("Clique numa tecla para continuar\n");
      getchar();
      getchar();
    }
    else{
      for(int a=0; a<=n; ++a){
        if(aux<=vet[a]){
          aux=vet[a];
          counter=a;
        }
        else{
          continue;
        }
      }
      printf("O maior número encontra-se no indice %d e é o número %d\n", counter, aux);
      printf("Clique numa tecla para continuar\n");
      getchar();
      getchar();
      return;
    }
  }


  void changeValue(int tamanho, int vet[tamanho]){
    int valor1, valor2, aux;

    printf("Insira o primeiro indice a trocar: "); scanf("%d", &valor1);
    printf("\nInsira o segundo indice a trocar: "); scanf("%d", &valor2);
    if(valor1>=tamanho && valor2>=tamanho){
      printf("Valores inseridos fora do maximo de indices do vetor\n");
      printf("Clique numa tecla para sair..\n");
      getchar();
      getchar();
      return;
    }
    else{
        printf("\nValores inseridos com sucesso\n");
        printf("Antes da troca\n");
        for(int i=0; i<tamanho; ++i){
          printf(" %d ", vet[i]);
        }
        aux=vet[valor1];
        vet[valor1]=vet[valor2];
        vet[valor2]=aux;
        printf("\nValor dos indices %d e %d foram trocados\n", valor1, valor2);
        for(int i=0; i<tamanho; ++i){
          printf(" %d ", vet[i]);
        }
        printf("\nClique numa tecla para continuar..\n");
        getchar();
        getchar();
      }
    return;
    }

 void linearSelection(int tamanho, int vet[tamanho]){
   int aux=vet[0], counter=0, auxi=0;
   printf("Antes de ordenação\n");
   for(int t=0; t<tamanho; ++t){
     printf(" %d ", vet[t]);
   }
   for(int a=(tamanho-1); a>=0; --a){
     for(int b=0; b<=a; ++b){
       if(aux<=vet[b]){
         aux=vet[b];
         counter=b;
       }
       else{
         continue;
       }
     }
     auxi=vet[a];
     vet[a]=aux;
     vet[counter]=auxi; // passa a ter o valor mais a esquerda..
     aux=vet[0];
   }

   printf("\n Depois da ordenação\n");
   for(int d=0; d<tamanho; ++d){
     printf(" %d ", vet[d]);
   }
   printf("\nClique numa tecla para continuar..\n");
   getchar();
   return;
  }

 int main(){
   int tamanho=0;

   printf("Insira o tamanho do vetor: "); scanf("%d", &tamanho);

   int vet[tamanho];

   addvet(tamanho, vet);
   nBigger(tamanho, vet);
   changeValue(tamanho, vet);
   linearSelection(tamanho, vet);


	return 0;
}
