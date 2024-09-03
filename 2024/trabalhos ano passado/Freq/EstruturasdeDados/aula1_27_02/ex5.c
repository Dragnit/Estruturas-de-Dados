#include<stdio.h>

 /*--------------------------------------------------------------
 --------------------------------------------------------------
 Proprietário: Jorge Miguel dos Santos Martins
 Curso: Licenciatura Sistemas Tecnologias de Informação
 Disciplina: Programação II / Estruturas Dados
 Data:25 Fevereiro 2020
 Programa/Exercicio: ficha 1 / Exercicio 5
 --------------------------------------------------------------
 --------------------------------------------------------------
 */
 void writeArray(int vet[][7]){// subprograma que escreve uma matriz

   for(int i=0; i<5; ++i){
     for(int t=0; t<7; ++t){
       printf(" %d ", vet[i][t]);
     }
   }
 return;
 }

 void matriz_1(int m1[5][7]){
   int i,j;

   for(i=0;i<5;i++){
     for (j=0;j<7;j++){
       m1[i][j]=j;
     }
   }
   writeArray(m1);// escrever matriz mat1
   return;
 }

 void matriz_2(int m2[][7]){
   int i,j;
   for(i=0;i<5;i++){
     for (j=0;j<7;j++)
     m2[i][j]=i;
     }
   writeArray(m2);// escrever matriz mat2
   return;
 }

 int main(){

   int mat1[5][7],mat2[5][7];
   printf("Mat1 escrita: ");
   matriz_1(mat1);
   printf("\nMat2 escrita: ");
   matriz_2(mat2);
   printf("\nClique alguma tecla para terminar..");
   getchar();
   return 0;
   }
