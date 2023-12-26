#include<stdio.h>

 /*--------------------------------------------------------------
 --------------------------------------------------------------
 Proprietário: Jorge Miguel dos Santos Martins
 Curso: Licenciatura Sistemas Tecnologias de Informação
 Disciplina: Programação II / Estruturas Dados
 Data: 31 de Março 2020
 Programa/Exercicio: Exercicio 2 / ficha 3
 --------------------------------------------------------------
 --------------------------------------------------------------
 */

 int main(){
   char * ptc;
   int * pti;
   float * ptf;
   double *ptd;

   printf("|Tipo    |"); printf("\t Tamanho em bytes  |\t"); printf("\t Tamanho do Ponteiro e bytes |\n");
   printf("|Char    |"); printf("\t\t\t %lu |\t", sizeof(char));  printf("\t\t\t\t   %lu |\n", sizeof(ptc));
   printf("|Inteiro |"); printf("\t\t\t %lu |\t", sizeof(int));  printf("\t\t\t\t   %lu |\n", sizeof(pti));
   printf("|Real    |"); printf("\t\t\t %lu |\t", sizeof(float));  printf("\t\t\t\t   %lu |\n", sizeof(ptf));
   printf("|Double  |"); printf("\t\t\t %lu |\t", sizeof(double));  printf("\t\t\t\t   %lu |\n", sizeof(ptd));
   getchar();
	return 0;
}
