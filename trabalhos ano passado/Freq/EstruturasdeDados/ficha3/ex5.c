#include<stdio.h>
#include<string.h>
#include<stdlib.h>


 /*--------------------------------------------------------------
 --------------------------------------------------------------
 Proprietário: Jorge Miguel dos Santos Martins
 Curso: Licenciatura Sistemas Tecnologias de Informação
 Disciplina: Programação II / Estruturas Dados
 Data:2 de abril de 2020
 Programa/Exercicio:Exercicio 5 / ficha 3
 --------------------------------------------------------------
 --------------------------------------------------------------
 */

 void flush_in(){ // codigo para limpeza de buffer do teclado..
    int ch;
    while( (ch = fgetc(stdin)) != EOF && ch != '\n' ){}
    return;
  }

 int adaptStrlen(char *ps){
   int count=0;
   while(*ps!='\0'){
       ps++;
       count++;
     }
   return count;
 }

 char * copyString(char *src, int i, int len){
   char * auxstr=malloc(len+1), *pa=NULL;

   pa=&auxstr[0];
   src=src+i; // apontar para o indice de começo da gravação.

   for(int a=0; a<len; ++a){
     if(*src=='\0'){
       break;
     }
     else{
       *pa = *src;
       src++;
       pa++; // antes do ciclo acabar estes são sempre incrementados
     }
   }
   *pa='\0'; // estou a sinalizar o final da string com '\0' visto que ele estava a escrever depois lixo..
return auxstr;
 }

 int main(){
   int tamanho=100, i, len, count;
   char str[tamanho];

   printf("Insira uma string: "); scanf("%98[^\n]", str);

   count=adaptStrlen(&str[0]);
   flush_in();
   printf("\nTamanho da String é %d \n\n", count);
   printf("Insira em que indice da string quer começar a copiar\n"); scanf("%d", &i);
   printf("\nInsira quantos caracteres para a frente quer copiar da string utilizada anteriormente\n"); scanf("%d", &len);
   char * dst=copyString(&str[0], i, len);
   printf("String copiada %s\n", dst);
   free(dst);
   flush_in();
   getchar();

	return 0;
}
