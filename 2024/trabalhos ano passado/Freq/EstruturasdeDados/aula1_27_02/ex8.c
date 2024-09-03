#include<stdio.h>

 /*--------------------------------------------------------------
 --------------------------------------------------------------
 Proprietário: Jorge Miguel dos Santos Martins
 Curso: Licenciatura Sistemas Tecnologias de Informação
 Disciplina: Programação II / Estruturas Dados
 Data: 2 de Março de 2020
 Programa/Exercicio: Ficha 1 / Exercicio 8
 --------------------------------------------------------------
 --------------------------------------------------------------
 */
 void ordemVet(int tamanho, int vet[tamanho]){

   for(int a=0; a<tamanho; ++a){ //não consegui fazer com o vetor desordenado pensei em ordenar mas penso que isso é para o exercicio seguinte..
     vet[a]=a;
     printf(" %d ", vet[a]);
   }
   printf("\nVetor criado de forma sequencial iniciando em 0\n");

   return;
 }

 int searchBin(int tamanho, int vet[tamanho]){
   int procura=0, minimo=0, maximo=0, mid=0;
   printf("Insira valor a procurar: "); scanf("%d", &procura);
   maximo=(tamanho-1);
   while(minimo<=maximo){ //para procurar quando o lado mais maximo do vetor
     mid=((minimo+maximo)/2); // assim encontra um ponto medio de pesquisa (mediana) e poupa nos ciclos de busca..
     if(procura==vet[mid]){
       return mid;
     }
     else{
       if(procura<vet[mid]){ //caso seja maior assim limitamos logo o minimo..
         maximo=(mid-1);
         continue;        //caso seja o medio maior que o valor que queremos então o maximo passa a ser o ponto medio que tinhamos anteriormente e fica com menos 1..
       }
       else{
         minimo=(mid+1); //soma e subtração é porque o ponto medio anterior não serviu ou seja fica de fora..
         continue;
       }
     }
   }
   return -1;
 }

 int main(){

   int tamanho=0, valor=0;

   printf("Insira o tamanho do vetor: ");
   scanf("%d", &tamanho);
   int vet[tamanho];

   ordemVet(tamanho, vet);

   valor=(searchBin(tamanho, vet));

   if(valor==-1){
     printf("Valor não encontrado..\n");
     printf("Clique numa tecla para terminar.. ");
     getchar();
     getchar();
   }
   else{
     printf("Valor encontra-se localizado no indice %d", valor);
     printf("\nClique numa tecla para terminar..");
     getchar();
     getchar();
   }


	return 0;
}
