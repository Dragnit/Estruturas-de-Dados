#include<stdio.h>

 /*--------------------------------------------------------------
 --------------------------------------------------------------
 Proprietário: Jorge Miguel dos Santos Martins
 Curso: Licenciatura Sistemas Tecnologias de Informação
 Disciplina: Programação II / Estruturas Dados
 Data: 4 de Março de 2020
 Programa/Exercicio: Ficha 1 / exercicio 10
 --------------------------------------------------------------
 --------------------------------------------------------------
 */
 void insertValue(int tamanho, int arr[tamanho]){
   int insert, aux;
   printf("Vetor Ordenado\n");
   for(int a=0; a<(tamanho-1); ++a){
     arr[a]=a;
     printf(" %d  ", arr[a]);
   }

   printf("\nInsira o valor que quer inserir no vetor: "); scanf("%d", &insert);

   for(int b=0; b<(tamanho-1); ++b){ //comecei este exercicio pelo fim então para não usar o que tinha aprendido tentei usar algo completamente diferente e funcional..
     if(insert<arr[b]){
       aux=arr[b];
       arr[b]=insert;
       for(int c=(tamanho-1); c>b; --c){ //aqui como começo a copiar todos os indices para o seu "irmao" à sua direita dando chance de alterar o espaço que quero sem perder info
         arr[c]=arr[c-1]; //metodo da copia, aprendido no uso de strings para as "apagar" no caso de uma coluna..
       }
       arr[b+1]=aux; // como no indice b já está o valor inserido agora que já abri espaço é só alterar no valor que está à direita do valor inserido b+1..
       break;
     }
     else{
       arr[tamanho-1]=insert; // aqui é caso ele seja maior de todos é escrito no fim..
     }
   }
   printf("\nVetor Ordenado com valor Inserido\n");
   for(int g=0; g<tamanho; ++g){
     printf(" %d ", arr[g]);
   }
   return;
 }


 void insertSelec(int tamanho, int vet[tamanho]){
   int aux, a; //eu inicio aqui o a para depois puder usar o valor dele fora do vetor..
   printf("Vetor Incial\n");
   for(int f=0; f<tamanho; ++f){
     printf(" %d ", vet[f]);
   }

   for(int i=1; i<tamanho; ++i){
     aux=vet[i];
     for(a=(i-1); a>=0 && vet[a]>aux; --a){ //a é igual a i-1 assim é sempre o valor que está a esquerda
       vet[a+1]=vet[a]; // como em cima o aux já pegou no valor de i, a+1 é o valor de i, por isso pego no valor de a e o puxo para a direita..
     }
      vet[a+1]=aux; //como iniciei o a fora do vetor posso usar aqui para ser inserido o número no seu local correto..
   }

   printf("\nVetor Ordenado \n");
   for(int c=0; c<tamanho; ++c){
     printf(" %d ", vet[c]);
   }
   printf("\nClique para continuar\n");
   getchar();
   return;
 }

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

 int main(){

   int tamanho=0;

   printf("Insira o tamanho do vetor: "); scanf("%d", &tamanho);
   tamanho=tamanho+1;
   int arr[tamanho];
   insertValue(tamanho, arr);

   printf("\nInsira o tamanho do vetor: "); scanf("%d", &tamanho);

   int vet[tamanho];

   addvet(tamanho, vet);
   insertSelec(tamanho, vet);

	return 0;
}
