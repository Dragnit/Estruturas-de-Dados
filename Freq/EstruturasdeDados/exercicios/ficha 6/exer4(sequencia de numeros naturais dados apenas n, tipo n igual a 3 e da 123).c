#include<stdio.h>
 /*--------------------------------------------------------------
 --------------------------------------------------------------
 Proprietario: Jorge Miguel dos Santos Martins
 Curso: Licenciatura Sistemas Tecnologias de Informacao
 Disciplina: Programacao II / Estruturas Dados Data:
 Programa/Exercicio: Ficha 6 / Exercicio 4
 --------------------------------------------------------------
 --------------------------------------------------------------
 */
 void interativaseq(int v){
   int aux=v;
   while(aux <= v){
     printf("%d", aux);
     aux--;
     if(aux == 1){
       while(aux <= v){
         printf("%d", aux);
         aux++;
       }
     }
     if(aux == v)
      break;
   }
 }

 void recursivoseq(int v, int limit, int ancora){
   printf("%d", v);
   if(ancora == v){
    if(limit > v){
      ancora++;
      recursivoseq(v+1, limit, ancora); // após a ancora ser somada em 1 segue para dentro da função de modo recursivo para printar o proximo valor..
    }
    }
    else{
      if(v > 1){
        recursivoseq(v-1, limit, ancora);
      }
      else{
        recursivoseq(v, limit, ancora);
      }
   }
 }

 int main(){
   int valor;
   puts("Insira o numero inteiro"); scanf("%d", &valor);

   puts("Versao interativa");
   interativaseq(valor);
   puts("\n Versao Recursiva");
   recursivoseq(valor, valor, 1); //um ser o valor e outro ser o limite para quando for para crescer a sequencia e o 1 vai para a ancora que depois dentro da função só é acionada quando esta está a crescer para condicionar a não ir parar à recursividade usada para a função decrescer

 return 0;
 }
