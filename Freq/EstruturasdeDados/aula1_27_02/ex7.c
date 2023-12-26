#include<stdio.h>

 /*--------------------------------------------------------------
 --------------------------------------------------------------
 Proprietário: Jorge Miguel dos Santos Martins
 Curso: Licenciatura Sistemas Tecnologias de Informação
 Disciplina: Programação II / Estruturas Dados
 Data:1 de Março de 2020
 Programa/Exercicio: Ficha 1 / Exercicio 7
 --------------------------------------------------------------
 --------------------------------------------------------------
 */

 void writterVet(int tamanho, int vet[tamanho]){
    int vetAux[tamanho], position, valor;

    for(int b=0; b<tamanho; ++b){ //iniciar vetor com -1 para depois o usar em teste de posiçoes..
      vetAux[b]=-1;
    }

    for(int a=0; a<tamanho; ++a){
      printf("\tAviso o vetor começa em 0 sendo a primeira POSIÇÃO 0, e não pode modificar posição após escolhida\n");
      printf("Insira o numero inteiro da posição do vetor onde quer inserir o numero: "); scanf("%d", &position);
      if(position>=0 && position<tamanho){
        for(int i=0; i<tamanho; ++i){
          if(vetAux[i]==position){
            printf("\nPosição já preenchida volte a inserir\n");
            --a;
          }
          else{
            continue;
          }
        }
        printf("\nInsira o inteiro a guardar na posiçao escolhida: "); scanf("%d", &valor);
        vet[position]=valor;
        vetAux[a]=position; //guardar a posição escolhida para depois por em testes caso já tenha sido preenchida..
        printf("Foi guardado com sucesso\n\n");
      }
      else{
        printf("Posição fora do vetor criado volte a tentar\n\n\n"); // dar uma segunda chance ao utilizador..
        --a;
      }
    }
  return;
 }
 int findTimes(int tamanho, int vet[tamanho]){
   int valor, counter=0;
   printf("Insira o valor inteiro a procurar: "); scanf("%d", &valor);
   for(int i=0; i<tamanho; ++i){
     if(vet[i]==valor){
       counter++;
     }
     else{
       continue;
     }
   }
   return counter;
 }

 int lastTimes(int tamanho, int vet[tamanho]){
   int valor=-1, position=-1;
   printf("Insira o inteiro a procurar pela sua ultima ocorrencia: "); scanf("%d", &valor);
   for(int a=tamanho; a>=0; --a){
     if(vet[a]==valor){
       position=a;
       break;
     }
     else{
       continue;
     }
   }
   return position;
 }

 int firstTime(int tamanho, int vet[tamanho]){
   int valor=-1, position=-1;
   printf("Insira o inteiro a procurar pela sua primeira ocorrencia: "); scanf("%d", &valor);
   for(int a=0; a<tamanho; --a){
     if(vet[a]==valor){
       position=a;
       break;
     }
     else{
       continue;
     }
   }
   return position;
 }

 }

 int main(){
   int tamanho=0, times=0, last=0; //na linha de comandos caso seja real ele termina logo mas se em outros não terminar inicio a 0 para ter a certeza que termina..
   printf("\t INSIRA NUMERO INTEIRO POSITIVO\n\n"); // Termino o programa caso não seja inteiro positivo para dar importancia a não repetir testes..
   printf("Insira o tamanho do vetor: ");
   scanf("%d", &tamanho);
   if(tamanho>0){
     printf("Vetor criado\n\n");
   }
   else{
     printf("Numero não inteiro positivo \n");
     printf("Clique numa tecla para terminar..");
     getchar();
     getchar();
     return 0;
   }
   int vet[tamanho];

   writterVet(tamanho, vet);
   times=(findTimes(tamanho, vet));
   printf("\nOcorrencias no vetor do numero escolhido foram: %d \n", times);
   printf("Clique numa tecla para continuar..\n");
   getchar();
   getchar();
   last=lastTimes(tamanho, vet); //descobrir a ultima ocorrencia do valor dando a posição de onde esta em ultimo..
   if(last>0){
     printf("Ultima ocorrencia na posição %d\n", last);
     printf("Clique numa tecla para continuar\n");
     getchar();
     getchar();
   }
   else{
     printf("Não foram encontradas ocorrencias do inteiro no vetor\n");
     printf("Clique numa tecla para continuar\n");
     getchar();
     getchar();
   }
   times = firstTime(tamanho, vet); //reutilizar a variavel..
   if(last>0){
     printf("Primeira ocorrencia na posição %d\n", times);
     printf("Clique numa tecla para continuar\n");
     getchar();
     getchar();
   }
   else{
     printf("Não foram encontradas ocorrencias do inteiro no vetor\n");
     printf("Clique numa tecla para continuar\n");
     getchar();
     getchar();
   }

	return 0;
}
