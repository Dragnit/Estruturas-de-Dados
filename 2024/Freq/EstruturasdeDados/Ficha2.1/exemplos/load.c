#include<stdio.h>
#include"headers.h"
#include<string.h> //esta biblioteca é para as strings.
#include<stdio_ext.h> /* inseri este include porque me estava a dar problemas com o fpurge*/
#include<stdlib.h> /*inseri este por causa do system("clear") */
#include <ctype.h>

// Jorge Miguel dos Santos Martins Nº2019100813 LSTI 
// Este ficheiro contem a funçao de inicializador dos vetores, e contem as funçoes para carregar ficheiros na memoria..

void inicializador(){
  for(int i=0; i<50; ++i){
    for(int t=0; t<20; ++t){ //isto porque nao há notas -1 e assim é jeito para saber o que esta sem nota..
    notas[i][t]=start;
    }
  }
  for(int z=0; z<50; ++z){ // assim o numero a comparar nunca será um lixo aleatorio e ainda calha algum numero igual...
    memoriaNumero[z]=-1;
    }
  for(int y=0; y<=20; ++y){
    vetorPesosAssociados[y]=0;
  }
  for(int u=0; u<=20; ++u){  // para depois na apresentação ter a certeza que existe sempre 0 para o ciclo..
    trabalhosPraticos[u]=0;
  }  
}

void loadDados(){
  do{
  char strAux[50];
  float numNotas;
  int contas=0, contas2=0, i=0, numPesos, valor=0, apagaLinha;
    FILE *leitorNotas, *leitorAlunos, *leitorNumeros, *leitorTrabalhos, *leitorPesos;
    
    leitorNotas = fopen("SaveNotas.txt", "r"); // ler notas
    
    if(leitorNotas==NULL){
  		printf("Nao há dados guardados de  Notas\n");
      leitorNotas = fopen("SaveNotas.txt", "w"); // ler notas
  	}
  	else{
  		while((fscanf(leitorNotas, "%f", &numNotas)) != EOF){
          if(contas==20){
            i++;
            contas=0;
            notas[i][contas]=numNotas; //realizo estas codições para que ele meta certinho os valores no array
            ++contas;  
          }
          else{
            notas[i][contas]=numNotas;
            contas++;
          }
        }
      }
  	i=0;
    contas=0; //certificar que estas variaveis ficam a 0 no final.		
  	fclose(leitorNotas);
  	
    
    leitorPesos = fopen("SavePesos.txt", "r"); // ler pesos associados a trabalhos
    
    if(leitorPesos==NULL){
      printf("Não ha dados guardados sobre pesos associados a trabalhos \n");
      leitorPesos = fopen("SavePesos.txt", "w");
    }
    else{
      while((fscanf(leitorPesos, "%d", &numPesos)) != EOF){
        if(numPesos == 0){ 
          break;
        }
        else{
        vetorPesosAssociados[i]=numPesos;
        ++i;
        }
      }
    }
    i=0;
    fclose(leitorPesos);
    
    leitorAlunos = fopen("SaveAlunos.txt", "r");          //ler alunos associados
    
    if(leitorAlunos==NULL){
      printf("Nao ha dados sobre alunos anteriormente guardados\n");
      leitorAlunos = fopen("SaveAlunos.txt", "w"); 
    }
    else{
      for(i; i<50; ++i){
        fgets(strAux, 49, leitorAlunos); // tenho de usar o strcpy lol
        apagaLinha = strlen(strAux)-1;
        if(strAux[apagaLinha] == '\n'){
          strAux[apagaLinha] = '\0';
        }
        strcpy(memoriaAluno[i], strAux); //copiar para o destino, vindo da fonte. 
      }
        
      for(int f=0; f<50; ++f){          // estou a usar esta função para actualizar o contador logo no load..
        if(strlen(memoriaAluno[f])>1){
          valor++;
        }
        else{
          break;
        }
        }
      }
    
    i=0;
    fclose(leitorAlunos);
    
    leitorNumeros = fopen("SaveNumeros.txt", "r");      //ler numeros de alunos
    
    if(leitorNumeros==NULL){
      printf("Nao foi possivel encontrar dados sobre Numeros\n");
      leitorNumeros = fopen("SaveNumeros.txt", "w");
    }
    else{
      while((fscanf(leitorNumeros, "%d", &contas)) != EOF){
          memoriaNumero[i]=contas;
          ++i;
      }
    }
    i=0; 
    contas=0;
    fclose(leitorNumeros);
    
    leitorTrabalhos = fopen("SaveTrabalhos.txt", "r");    //ler trabalhos a ser avaliados 
    
    if(leitorTrabalhos==NULL){
      printf("Nao foi possivel encontrar dados sobre trabalhos\n");
      leitorTrabalhos = fopen("SaveTrabalhos.txt", "w");
    }
    else{
      while((fscanf(leitorTrabalhos, "%d", &contas2)) != EOF){ // tive de usar uma variavel nova porque ao usar o contas ele bloqueava..
        if(contas2>0){
          trabalhosPraticos[i]=contas2;
          ++i;
          contaTrabalhos++;
        }
        else{
          break;
        }
      }
    
    i=0;
    contas=0;
    fclose(leitorTrabalhos);
    
    contador=valor;
    
    printf("Numero de Trabalhos está a %d\n", contaTrabalhos);
    printf("Contador de alunos esta a  %d\n", contador);
    printf("Transferencia de dados concluída para o programa...\n");
    printf("Carregue enter para voltar ao menu...\n");
    __fpurge(stdin); 
    fflush(stdin);
    scanf("%1[\n]", pausa); /* esta foi a opção para fazer o sistema pausar, em linux o system pause, getch, não funcionam */
    system("clear");
  return;  
  }
}while(1);
} 