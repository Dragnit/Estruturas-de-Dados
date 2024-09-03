#include<stdio.h>
#include<string.h>
#include<stdlib.h>
 /*--------------------------------------------------------------
 --------------------------------------------------------------
 Proprietario: Jorge Miguel dos Santos Martins
 Curso: Licenciatura Sistemas Tecnologias de Informacao
 Disciplina: Programacao II / Estruturas Dados Data:
 Programa/Exercicio: Ficha  / Exercicio
 --------------------------------------------------------------
 --------------------------------------------------------------
 */

 int main(){

   char c[100];
   int v;

   fgets(c, 98, stdin);
   c[strlen(c)-1]='\0';

   printf("%s\n", c);

   v=strtol(c, NULL, 10);
   printf("%d %d %d", v);


 return 0;
 }
