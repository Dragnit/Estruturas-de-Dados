#include <stdio.h>
#define TAM 2000

int inserir(long long int data[TAM], float hora[TAM], float temperatura[TAM]){
  int qntregistos;

  printf("Quantos registos pretendes fazer: ");
  scanf("%d",&qntregistos);
  for (int i=0;i<qntregistos;i++){
    printf("Data: ");
    scanf("%lld",&data[i]);
    printf("Hora: ");
    scanf("%f",&hora[i]);
    printf("Temperatura: ");
    scanf("%f",&temperatura[i]);
  }
}


float amplitudetermica(long long int data[TAM], float temperatura[TAM], int tregistos){

  long long int procurar;
  float maior=0,menor,amplitude;
  int achou=0;

  while(achou==0){
    printf("Data para calcular a amplitude termica: ");
    scanf("%lld", &procurar);
    for(int i=0; i<tregistos;i++){
      if (procurar==data[i]){
        achou=1;
        if(temperatura[i]>maior)
        maior=temperatura[i];
      }
    }
    menor=maior;
    for(int i=0;i<tregistos;i++){
      if (procurar==data[i]){
        if( temperatura[i]<menor)
        menor=temperatura[i];
      }
    }
  }
  amplitude=maior-menor;
  printf("Amplitude Termica: %0.1f\n",amplitude);
  return amplitude;
}


float mediatemperatura(long long int data[TAM], float temperatura[TAM], int tregistos){

  int achou=0,auxmedia=0;
  float soma=0,media;
  long long int procurar;

  while(achou==0){
    printf("Data para calcular a media das temperaturas: ");
    scanf("%lld",&procurar);
    for(int i=0;i<tregistos;i++){
      if (procurar==data[i]){
        achou=1;
        soma=soma+temperatura[i];
        auxmedia++;
        media=soma/auxmedia;
      }
    }
  }
  printf("Media da temperatura: %0.1f\n",media);
  return media;
}


void guardar(long long int data[TAM], float hora[TAM], float temperatura[TAM], int tregistos){

  FILE *dados=fopen("temperaturas.dat","ab");

  for (int i=0;i<tregistos; i++){
    fwrite(data,sizeof(long long int[TAM]),1,dados);
    fwrite(hora,sizeof(float[TAM]),1,dados);
    fwrite(temperatura,sizeof(float[TAM]),1,dados);
  }
  fclose(dados);
}


int carregar(long long int data[], float hora[], float temperatura[]){

  FILE *dados=fopen("temperaturas.dat","rb");
  int q=0;

  while (fread(data,sizeof(long long int[TAM]),1,dados) != 0){
    fread(hora, sizeof(float[TAM]),1,dados);
    fread(temperatura,sizeof(float[TAM]),1,dados);
    q++;
  }
  fclose(dados);
  return q;
}


int main(){

  int  opcao,tregistos = 0;
  long long int data[TAM];
  float hora[TAM],temperatura[TAM];
  tregistos=carregar(data,hora,temperatura);

  do{
    printf("Menu do Programa\n");
    printf("1. Inserir Registos\n");
    printf("2. Calcular Amplitude Termica\n");
    printf("3. Calcular Media de Temperaturas\n");
    printf("4. Gravar dados \n");
    printf("5. Sair\n");
    fflush(stdin);
    scanf("%d", &opcao);

    switch(opcao){
      case 1: tregistos = inserir(data,hora,temperatura);break;
      case 2:  amplitudetermica(data,temperatura, tregistos);break;
      case 3: mediatemperatura(data,temperatura,tregistos);break;
      case 4: guardar(data,hora,temperatura,tregistos); break;
      case 5: printf("Bye Bye\n"); break;
      default: printf("Opcao invalida\n");
    }
  }
  while(opcao !=5);
}
