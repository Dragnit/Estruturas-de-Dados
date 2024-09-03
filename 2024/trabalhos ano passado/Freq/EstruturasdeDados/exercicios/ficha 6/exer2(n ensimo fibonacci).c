#include<stdio.h>
 /*--------------------------------------------------------------
 --------------------------------------------------------------
 Proprietario: Jorge Miguel dos Santos Martins
 Curso: Licenciatura Sistemas Tecnologias de Informacao
 Disciplina: Programacao II / Estruturas Dados Data:
 Programa/Exercicio: Ficha 6 / Exercicio 2
 --------------------------------------------------------------
 --------------------------------------------------------------
 */

 int fibintera(int n){     //interativo
    int i, fb1 = 1, fb2 = 1, soma;
    for (i = 3; i <= n; i++)
    {
      soma = fb1 + fb2;
      fb1 = fb2;
     fb2 = soma;
   }
   return fb2;
 }

   int fibrecursa(int n){     //recursivo
     if (n == 1)
      return 1;
     else
       if (n == 2)
          return 1;
       else
          return fibrecursa(n - 1) + fibrecursa(n - 2);
   }


 int main(){
   int n;
     puts("Insira o elemento a descobrir da sequencia");
     scanf("%d", &n);
     printf("interativo %d\n", fibintera(n));
     printf("Recursivo %d \n", fibrecursa(n));

 return 0;
 }
