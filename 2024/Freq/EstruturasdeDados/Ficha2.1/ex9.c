#include<stdio.h>

 /*--------------------------------------------------------------
 --------------------------------------------------------------
 Proprietário: Jorge Miguel dos Santos Martins
 Curso: Licenciatura Sistemas Tecnologias de Informação
 Disciplina: Programação II / Estruturas Dados
 Data:22 de Março 2020
 Programa/Exercicio: Exercicio 9 / ficha 2
 --------------------------------------------------------------
 --------------------------------------------------------------
 */

 void flush_in(){ // codigo para limpeza de buffer do teclado..
    int ch;
    while( (ch = fgetc(stdin)) != EOF && ch != '\n' ){}
    return;
 }

 void insertData(long long int date, float hour, float temp){

   FILE *saveBin;

   saveBin=fopen("temperaturas.dat", "ab");

   if(saveBin==NULL){
     printf("Erro ao abrir ficheiro, clique para sair\n"); getchar();
     return;
   }
   else{
     printf("Insira data, ano, mes, dia (exemplo 20200201): "); scanf("%lli", &date);
     printf("\nInsira hora, hora e depois minutos (exemplo 00.15, 12.05): "); scanf("%f", &hour);
     printf("\nInsira a temperatura (exemplo 13.3, 19.8): "); scanf("%f", &temp);
     flush_in();

     fwrite(&date, sizeof(date), 1, saveBin);
     fwrite(&hour, sizeof(hour), 1, saveBin);
     fwrite(&temp, sizeof(hour), 1, saveBin);

     fclose(saveBin);
   }
   return;
 }

 float calcamp(long long int date, float amp){ // calcula a amplitude

   long long int auxDate;
   float auxhour, auxtemp, max=0, min=0;
   int counter=0;

   FILE *searchBin;

   searchBin=fopen("temperaturas.dat", "rb");

   if(searchBin==NULL){
     printf("Erro ao abrir ficheiro, clique para voltar ao menu\n"); getchar();
     return amp;
   }
   else{
     while((fread(&auxDate, sizeof(auxDate), 1, searchBin))!=0){ // usei assim a leitura da mesma forma como foi escrita para que os dados guardados sejam os mesmo e não trocar posiçoes
       fread(&auxhour, sizeof(auxhour), 1, searchBin);
       fread(&auxtemp, sizeof(auxtemp), 1, searchBin);
       if(auxDate==date){ //encontrar a data que o utilizador quer para ver a aplitude
         if(counter==0){ //ponto de partida em que dou ao minimo e ao maximo o valor da primeira temperatura recolhida
           max=auxtemp;
           min=auxtemp;
         }
         else{
           if(auxtemp>max){ // após ler mais que uma temperatura do ficheiro começo a fazer as comparações assim achando o ponto maximo
             max=auxtemp;
           }
           if(auxtemp<min){ // e aqui achando o ponto minimo absoluto daquela data..
             min=auxtemp;
           }
        }
        counter++;
       }
     }
     if(counter==0){
       flush_in();
       printf("Data sem dados a dar clique para continuar\n"); getchar();
       fclose(searchBin);
       return amp;
     }
     if(min<0 && max>=0){
       amp=(max+min); //caso o minimo seja menor que 0 então para que o sinal fique para subtração meti assim a somar..
     }
     else{
       amp=(max-min);
     }
   }
   fclose(searchBin);
   return amp;
 }

 float calcmed(long long int date, float med){ // calcula a media

   long long int auxDate;
   float auxhour, auxtemp, counter=0;


   FILE *searchBin;

   searchBin=fopen("temperaturas.dat", "rb");

   if(searchBin==NULL){
     printf("Erro ao abrir ficheiro, clique para voltar ao menu\n"); getchar();
     return med;
   }
   else{
     while((fread(&auxDate, sizeof(auxDate), 1, searchBin))!=0){
       fread(&auxhour, sizeof(auxhour), 1, searchBin);
       fread(&auxtemp, sizeof(auxtemp), 1, searchBin);
       if(auxDate==date){
         med=(med+auxtemp);
         counter++;
       }
     }
     if(counter==0){
       flush_in();
       printf("Data sem dados, clique para continuar\n"); getchar();
       fclose(searchBin);
       return med;
     }
     med=(med/counter);
   }
   fclose(searchBin);
   return med;
 }

 int main(){
   //arrayTemp[97];
   int option;
   long long int date;
   float hour, temp, amp=0, med=0;

   do{ // menu para o utilizador inserir os dados e verificar dados..
     printf("Opcao 1 - Inserir temperatura manualmente\n");
     printf("Opcao 2 - Calcular amplitude Termica\n");
     printf("Opcao 3 - Calcular media de uma data\n");
     printf("Opcao 4 - Sair\n");
     printf("Insira a sua opcao: "); scanf("%d", &option);
     switch(option){
       case 1: insertData(date, hour, temp); break;
       case 2: printf("Insira a data a calcular amplitude (ex, ano, mes, dia 20200201): "); scanf("%lli", &date);
       amp=calcamp(date, amp); printf("Amplitude é: %.2f\n", amp); break;
       case 3: printf("Insira a data a calcular amplitude (ex, ano, mes, dia 20200201): "); scanf("%lli", &date);
       med=calcmed(date, med); printf("A media é: %.2f\n", med); break;
       case 4: break;
       default: printf("Opcao não valida volte a tentar\n\n"); break;
     }
   }while(option!=4);

	return 0;
}
