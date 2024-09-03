#include<stdio.h>
#include<stdlib.h>
 /*--------------------------------------------------------------
 --------------------------------------------------------------
 Proprietário: Jorge Miguel dos Santos Martins
 Curso: Licenciatura Sistemas Tecnologias de Informação
 Disciplina: Programação II / Estruturas Dados
 Data: 11 de Março de 2020
 Programa/Exercicio: Ficha 2.1 / Exercicio 4
 --------------------------------------------------------------
 --------------------------------------------------------------
 */

 void rad100(int vet[1000]){
   FILE *random100;
   int aux, a, efi=0; //eu inicio aqui o a para depois puder usar o valor dele fora do vetor..

   random100=fopen("aleat100.txt", "w");
   if(random100==NULL){
     printf("Erro ao abrir ficheiro");
     return;
   }
   else{
     int val;
     for(int i=0; i<100; ++i){
       val = rand() % 100; // assim faz de 0 a 100..
       if(val >= 1){ // condiçao pelo qual se for menor que 1 ele volta a repetir esta volta..
         fprintf(random100, "%d\n", val);
         vet[i]=val;
       }
       else{
         --i;
       }
     }
     fclose(random100);
   }
   //ordenacao do vetor com inserçao linear, usada na ficha 1 exercicio 10.
     for(int i=1; i<100; ++i){
       aux=vet[i];
       for(a=(i-1); a>=0 && vet[a]>aux; --a){ //a é igual a i-1 assim é sempre o valor que está a esquerda
         vet[a+1]=vet[a]; // como em cima o aux já pegou no valor de i, a+1 é o valor de i, por isso pego no valor de a e o puxo para a direita..
       }
        vet[a+1]=aux; //como iniciei o a fora do vetor posso usar aqui para ser inserido o número no seu local correto..
     }
     //com este vetor já ordenado então posso criar um ficheiro com os elementos já ordenados de ordem crescente.

     random100=fopen("cresc100.txt", "w");

     if(random100==NULL){
       printf("Erro ao abrir ficheiro");
       return;
     }
     else{
       for(int i=0; i<100; ++i){
          fprintf(random100, "%d\n", vet[i]);
       }
       fclose(random100);
     }
     //como já está em ordem crescente para escrever em ordem Descrescente basta escrever o vetor no ficheiro ao contrário.
     random100=fopen("decresc100.txt", "w");

     if(random100==NULL){
       printf("Erro ao abrir ficheiro");
       return;
     }
     else{
       for(int i=99; i>=0; --i){
          fprintf(random100, "%d\n", vet[i]);
       }
       fclose(random100);
     }
  return;
 }

 void rad500(int vet[1000]){
   FILE *random500;
   int aux, a, efi=0; //eu inicio aqui o a para depois puder usar o valor dele fora do vetor..

   random500=fopen("aleat500.txt", "w");
   if(random500==NULL){
     printf("Erro ao abrir ficheiro");
     return;
   }
   else{
     int val;
     for(int i=0; i<500; ++i){
       val = rand() % 500; // assim faz de 0 a 500..
       if(val >= 1){ // condiçao pelo qual se for menor que 1 ele volta a repetir esta volta..
         fprintf(random500, "%d\n", val);
         vet[i]=val;
       }
       else{
         --i;
       }
     }
     fclose(random500);
   }
   //ordenacao do vetor com inserçao linear, usada na ficha 1 exercicio 10.
     for(int i=1; i<500; ++i){
       aux=vet[i];
       for(a=(i-1); a>=0 && vet[a]>aux; --a){ //a é igual a i-1 assim é sempre o valor que está a esquerda
         vet[a+1]=vet[a]; // como em cima o aux já pegou no valor de i, a+1 é o valor de i, por isso pego no valor de a e o puxo para a direita..
       }
        vet[a+1]=aux; //como iniciei o a fora do vetor posso usar aqui para ser inserido o número no seu local correto..
     }
     //com este vetor já ordenado então posso criar um ficheiro com os elementos já ordenados de ordem crescente.

     random500=fopen("cresc500.txt", "w");

     if(random500==NULL){
       printf("Erro ao abrir ficheiro");
       return;
     }
     else{
       for(int i=0; i<500; ++i){
          fprintf(random500, "%d\n", vet[i]);
       }
       fclose(random500);
     }
     //como já está em ordem crescente para escrever em ordem Descrescente basta escrever o vetor no ficheiro ao contrário.
     random500=fopen("decresc500.txt", "w");

     if(random500==NULL){
       printf("Erro ao abrir ficheiro");
       return;
     }
     else{
       for(int i=499; i>=0; --i){
          fprintf(random500, "%d\n", vet[i]);
       }
       fclose(random500);
     }
  return;
 }

 void rad1000(int vet[1000]){ //criaçao de ficheiros com números de 1 a 1000
   FILE *random1000;
   int aux, a, efi=0; //eu inicio aqui o a para depois puder usar o valor dele fora do vetor..

   random1000=fopen("aleat1000.txt", "w");
   if(random1000==NULL){
     printf("Erro ao abrir ficheiro");
     return;
   }
   else{
     int val;
     for(int i=0; i<1000; ++i){
       val = rand() % 1000; // assim faz de 0 a 100..
       if(val >= 1){ // condiçao pelo qual se for menor que 1 ele volta a repetir esta volta..
         fprintf(random1000, "%d\n", val);
         vet[i]=val;
       }
       else{
         --i;
       }
     }
     fclose(random1000);
   }
   //ordenacao do vetor com inserçao linear, usada na ficha 1 exercicio 10.
     for(int i=1; i<1000; ++i){
       aux=vet[i];
       for(a=(i-1); a>=0 && vet[a]>aux; --a){ //a é igual a i-1 assim é sempre o valor que está a esquerda
         vet[a+1]=vet[a]; // como em cima o aux já pegou no valor de i, a+1 é o valor de i, por isso pego no valor de a e o puxo para a direita..
       }
        vet[a+1]=aux; //como iniciei o a fora do vetor posso usar aqui para ser inserido o número no seu local correto..
     }
     //com este vetor já ordenado então posso criar um ficheiro com os elementos já ordenados de ordem crescente.

     random1000=fopen("cresc1000.txt", "w");

     if(random1000==NULL){
       printf("Erro ao abrir ficheiro");
       return;
     }
     else{
       for(int i=0; i<1000; ++i){
          fprintf(random1000, "%d\n", vet[i]);
       }
       fclose(random1000);
     }
     //como já está em ordem crescente para escrever em ordem Descrescente basta escrever o vetor no ficheiro ao contrário.
     random1000=fopen("decresc1000.txt", "w");

     if(random1000==NULL){
       printf("Erro ao abrir ficheiro");
       return;
     }
     else{
       for(int i=999; i>=0; --i){
          fprintf(random1000, "%d\n", vet[i]);
       }
       fclose(random1000);
     }
  return;
 }

 int main(){
   int vet[1000];

   rad100(vet);
   printf("Ficheiro com nome aleat100.txt foi criado com números aleatórios de 1 a 100\n");
   printf("Ficheiro com nome cresc100.txt foi criado com números ordenados por ordem crescente do intervalo de 1 a 100, numeros não sequenciais\n");
   printf("Ficheiro com nome decresc100.txt foi criado com números ordenados por ordem decrescente do intervalo de 1 a 100, numeros não sequenciais\n");

   rad500(vet);
   printf("\nFicheiro com nome aleat500.txt foi criado com números aleatórios de 1 a 500\n");
   printf("Ficheiro com nome cresc500.txt foi criado com números ordenados por ordem crescente do intervalo de 1 a 500, numeros não sequenciais\n");
   printf("Ficheiro com nome decresc500.txt foi criado com números ordenados por ordem decrescente do intervalo de 1 a 500, numeros não sequenciais\n");

   rad1000(vet);
   printf("\nFicheiro com nome aleat1000.txt foi criado com números aleatórios de 1 a 1000\n");
   printf("Ficheiro com nome cresc1000.txt foi criado com números ordenados por ordem crescente do intervalo de 1 a 1000, numeros não sequenciais\n");
   printf("Ficheiro com nome decresc1000.txt foi criado com números ordenados por ordem decrescente do intervalo de 1 a 1000, numeros não sequenciais\n");

   printf("\n\nClique para terminar\n");
   getchar();

	return 0;
}
