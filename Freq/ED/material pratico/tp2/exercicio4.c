#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ndecrescente(int qnt){
  FILE * fp;

  if(qnt==100){
    fp = fopen("decres100.txt", "w");
    if (fp==NULL){
      printf("Erro\n");
    }
    else{
      for(int i=qnt;i>0; i--)
      fprintf(fp, "%d ", i);
    }
    fclose(fp);
  }

  if(qnt==500){
    fp = fopen("decres500.txt", "w");
    if (fp==NULL){
      printf("Erro\n");
    }
    else{
      for(int i=qnt;i>0; i--)
      fprintf(fp, "%d ", i);
    }
    fclose(fp);
  }

  if(qnt==1000){
    fp = fopen("decres1000.txt", "w");
    if (fp == NULL){
      printf("Erro\n");
    }
    else{
      for(int i=qnt;i>0; i--)
      fprintf(fp, "%d ", i);
    }
    fclose(fp);
  }
}

int ncrescente(int qnt){
  FILE * fp;

  if(qnt==100){
    fp = fopen("cresc100.txt", "w");
    if (fp == NULL){
      printf("Erro\n");
    }
    else{
      for(int i=1;i<qnt+1;i++)
      fprintf(fp, "%d ", i);
    }
    fclose(fp);
  }

  if(qnt==500){
    fp = fopen("cresc500.txt", "w");
    if (fp == NULL){
      printf("Erro\n");
    }
    else{
      for(int i=1;i<qnt+1;i++)
      fprintf(fp, "%d ", i);
    }
    fclose(fp);
  }

  if(qnt==1000){
    fp = fopen("cresc1000.txt", "w");
    if (fp == NULL){
      printf("Erro\n");
    }
    else{
      for(int i=1;i<qnt+1;i++)
      fprintf(fp, "%d ", i);
    }
    fclose(fp);
  }
}

int naleatorio(int qnt){
  FILE * fp;

  if(qnt==100){
    fp = fopen("aleat100.txt", "w+");
    if (fp == NULL){
      printf("Erro\n");
    }
    else{
      for(int i=1;i<qnt; i++){
        fprintf(fp, "%d ",rand()%qnt+1);
      }
    }
    fclose(fp);
  }

  if(qnt==500){
    fp = fopen("aleat500.txt", "w+");
    if (fp == NULL){
      printf("Erro\n");
    }
    else{
      for(int i=1;i<qnt; i++){
        fprintf(fp,"%d ",rand()%qnt+1);
      }
    }
    fclose(fp);
  }

  if(qnt==1000){
    fp = fopen("aleat1000.txt", "w+");
    if (fp == NULL){
      printf("Erro\n");
    }
    else{
      for(int i=1;i<qnt; i++){
        fprintf(fp,"%d ",rand()%qnt+1);
      }
    }
    fclose(fp);
  }
}
int main(){
  int qnt;
  printf("Insira os numeros que quer ter no seu ficheiro (100||500||1000)?");
  scanf("%d", &qnt);
  ndecrescente(qnt);
  ncrescente(qnt);
  naleatorio(qnt);
  printf("Sucesso!\n");
}
