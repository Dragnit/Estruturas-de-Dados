#include<stdio.h>
#include<string.h>
#include<time.h> //para o Exercicio 3
 /*--------------------------------------------------------------
 --------------------------------------------------------------
 Proprietário: Jorge Miguel dos Santos Martins
 Curso: Licenciatura Sistemas Tecnologias de Informação
 Disciplina: Programação II / Estruturas Dados
 Data: 11 de Março 2020
 Programa/Exercicio: Ficha 2.1 / ex2 / Exercicio 3
 --------------------------------------------------------------
 --------------------------------------------------------------
 */

 void useFile(char file[100]){
   struct tm *dat;
   time_t sec;
   char c;
   int counterlines=0, counterWords=0, counterCharacter=0, numberCac=0;
   FILE * keyOpen;

   keyOpen=fopen(file, "a+");
   if(keyOpen==NULL){
     printf("Ficheiro não encontrado\n");
     printf("Clique para terminar o programa\n");
     getchar();
     getchar();
     return;
   }
   else{
     printf("Ficheiro com nome %s aberto com sucesso\n", file);
     printf("Clique para continuar o programa\n");
     getchar();
     getchar();
   }

   printf("Indique um caracter para contabilizar no documento: "); scanf("%c", &c);

   while(fgets(file, 100, keyOpen)!=NULL){
     counterlines++;
     for(int i=0; file[i]!='\0'; ++i){
       if(file[i] == ' ' || file[i] == '\n'){ // pode existir uma palavra apenas numa linha e assim ele contabiliza, tal como a ultima palavra de uma frase.
         counterWords=(counterWords+1);
       }
     }
     counterCharacter=((strlen(file)-1)+counterCharacter); // de notar que o '\0' é na string que está e não no ficheiro de texto por isso não o contei como caracter
     for(int a=0; file[a]!='\0'; ++a){
       if(file[a] == c){
         numberCac=(numberCac+1);
       }
     }
   }
   printf("\nNumero de linhas é %d\n", counterlines);
   printf("Numero de palavras é %d\n", counterWords);
   printf("Numero de caracteres é %d\n", counterCharacter);
   printf("Numero de ocorrencias do caracter %c é de %d \n", c, numberCac);
   printf("Clique para terminar o programa\n");
   getchar();
   getchar();

   time(&sec);
   dat = localtime(&sec); //o ponteiro fica igual ao que é dado pelo endereço de Sec que está em segundos, o localtime serve para converter.

   fprintf(keyOpen, "Escrito no monitor no dia %d / %d / %d \n\n", dat->tm_mday, dat->tm_mon+1, dat->tm_year+1900);
   fprintf(keyOpen, "Escrito no monitor as %d: %d: %d \n\n", dat->tm_hour, dat->tm_min, dat->tm_sec);

   fclose(keyOpen);
   return;
 }


 int main(){
   char file[100];

   printf("Indique o ficheiro a contabilizar: "); scanf("%s", file);

   useFile(file);

	return 0;
}
