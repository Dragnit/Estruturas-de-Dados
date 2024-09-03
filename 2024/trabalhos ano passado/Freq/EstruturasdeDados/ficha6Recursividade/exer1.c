#include<stdio.h>
 /*--------------------------------------------------------------
 --------------------------------------------------------------
 Proprietario: Jorge Miguel dos Santos Martins
 Curso: Licenciatura Sistemas Tecnologias de Informacao
 Disciplina: Programacao II / Estruturas Dados Data:
 Programa/Exercicio: Ficha 6 / Exercicio 1
 --------------------------------------------------------------
 --------------------------------------------------------------
 */

 void interactivo(int n){
   int fat;
   for(fat = 1; n > 1; n--){ // assim faz o 1x4x3x2 apenas faz a multiplicaçao do 1 primeiro mas que não modifica nada no resultado
      fat = fat * n;
    }
   printf("Fatorial interativo e %d \n", fat);
 }

//Função recursiva do fatorial
//de um numero inteiro n
int fatorialrecursivo(int n)
{
  int aux;

  if ( n <= 1 )
    //Caso n <= 1 retorna 1
    return (1);
  else
  {
    //recursividade
    aux = n * fatorialrecursivo(n - 1); // irá fazer tipo 3 x 2 x 1 se eu meter o 3 porque ira sempre recursivamente fazer os calculos..
    return (aux);
  }
}

 int main(){
   int valor, f;


   printf("Insira o valor inteiro a para descobrir o seu fatorial \n"); scanf("%d", &valor);

   puts("Interactiva");
   interactivo(valor);

   f = fatorialrecursivo(valor);

   printf("Fatorial recursivo de %d = %d \n", valor, f);

 return 0;
 }
