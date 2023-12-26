#include<stdio.h>

 /*--------------------------------------------------------------
 --------------------------------------------------------------
 Proprietário: Jorge Miguel dos Santos Martins
 Curso: Licenciatura Sistemas Tecnologias de Informação
 Disciplina: Programação II / Estruturas Dados
 Data:12 de Março de 2020
 Programa/Exercicio: Ficha 2.1 / exercicio 5
 --------------------------------------------------------------
 --------------------------------------------------------------
 */

 void writerFiles(){
   int aux, i=0;

   FILE *penFile, *readFile;
//para retirar os 50 primeiros do ficheiro aleat100.
   readFile=fopen("aleat100.txt", "r"); // ponteiro de leitura
   penFile=fopen("ficheiroTotal.txt", "a"); //ponteiro de escrita

   if(penFile==NULL){
     printf("Não foi possivel abrir ficheiro");
     printf("Clique para terminar\n");
     getchar();
     return;
   }
   else{
     if(readFile==NULL){
       printf("Não foi possivel abrir ficheiro");
       printf("Clique para terminar\n");
       getchar();
       return;
     }
     else{
       while(i<50){
         fscanf(readFile, "%d", &aux); //enquanto faz leitura para a variavel ela em seguida é escrita..
         fprintf(penFile, "%d\n", aux);
         ++i;
       }
       fclose(readFile);
       fclose(penFile);
     }
   }
   i=0;
//para os primeiros 100 números do ficheiro aleat500.txt..
   readFile=fopen("aleat500.txt", "r");
   penFile=fopen("ficheiroTotal.txt", "a");

   if(penFile==NULL){
     printf("Não foi possivel abrir ficheiro");
     printf("Clique para terminar\n");
     getchar();
     return;
   }
   else{
     if(readFile==NULL){
       printf("Não foi possivel abrir ficheiro");
       printf("Clique para terminar\n");
       getchar();
       return;
     }
     else{
       while(i<100){
         fscanf(readFile, "%d", &aux);
         fprintf(penFile, "%d\n", aux);
         ++i;
       }
       fclose(readFile);
       fclose(penFile);
     }
   }
   i=0;
//aqui para os primeiros 500 números do ficheiro aleat1000.txt..

  readFile=fopen("aleat1000.txt", "r");
  penFile=fopen("ficheiroTotal.txt", "a");

  if(penFile==NULL){
    printf("Não foi possivel abrir ficheiro");
    printf("Clique para terminar\n");
    getchar();
    return;
  }
  else{
    if(readFile==NULL){
      printf("Não foi possivel abrir ficheiro");
      printf("Clique para terminar\n");
      getchar();
      return;
    }
    else{
      while(i<500){
        fscanf(readFile, "%d", &aux);
        fprintf(penFile, "%d\n", aux);
        ++i;
      }
      fclose(readFile);
      fclose(penFile);
    }
  }
   return;
 }

 void parImpar(){

   int aux, countImpar=0, countPar=0;
   FILE *readFile, *par, *impar;

   readFile=fopen("ficheiroTotal.txt", "r");
   par=fopen("pares.txt", "a");
   impar=fopen("impares.txt", "a");

   if(readFile!=NULL && par!=NULL && impar!=NULL){

     while((fscanf(readFile, "%d", &aux))!=EOF){
       if((aux%2)>0){
         fprintf(impar, "%d\n", aux);
         countImpar++; //aproveito enquanto estou a separar os impares e os pares nos ficheiros de os contar e assim sei quantos havia no ficheirototal
       }
       else{
         fprintf(par, "%d\n", aux);
         countPar++;
       }
     }
     printf("No ficheiro total número de pares %d e número de impares %d \n\n", countPar, countImpar);
   }
   else{
     printf("Problemas na abertura de ficheiros, clique para terminar\n");
     getchar();
     return;
   }
   fclose(readFile);
   fclose(par);
   fclose(impar);
   return;
 }

 int main(){

   writerFiles();
   parImpar();
   printf("Programa realizou as suas tarefas, clique para terminar\n");
   getchar();
	return 0;
}
