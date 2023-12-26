#include<stdio.h>

 /*--------------------------------------------------------------
 --------------------------------------------------------------
 Proprietário: Jorge Miguel dos Santos Martins
 Curso: Licenciatura Sistemas Tecnologias de Informação
 Disciplina: Programação II / Estruturas Dados
 Data: 31 de Março de 2020
 Programa/Exercicio: Exercicio 3 / ficha 3
 --------------------------------------------------------------
 --------------------------------------------------------------
 */

 int main(){

   long long int a = 2, b = 3;
   long long int *p=NULL, *q=NULL;
   p = &a;
   q = &b;

   printf("%u\n", p);
   printf("%lli\n", &a);
   printf("%d\n", *p-*q);
   printf("%lli\n", **&p);
   printf("%d\n", *p+1);
   printf("%lli\n", q);
   printf("%lli\n", *(q-2));


   printf("%p %u %u %d %d %d %d\n",p,p,&p,*p+4,**&p,5**p,**&p+6);

getchar();

	return 0;
}
