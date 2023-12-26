#include <stdio.h>
#define TAMANHO 8000

void primeirosn(){
  int i;
  int numeros[TAMANHO];
  FILE * aleat100;
  FILE * aleat500;
  FILE * aleat1000;
  FILE * primeirosnum;

  aleat100=fopen("aleat100.txt","r");
  aleat500=fopen("aleat500.txt","r");
  aleat1000=fopen("aleat1000.txt","r");
  primeirosnum=fopen("primeirosnum.txt","w+");

  for(i=0;i<50;i++){
    fscanf(aleat100,"%d ",&numeros[i]);
    fprintf(primeirosnum,"%d ",numeros[i]);
  }
  for(i=0;i<100;i++){
    fscanf(aleat500,"%d ",&numeros[i]);
    fprintf(primeirosnum,"%d ",numeros[i]);
  }
  for(i=0;i<500;i++){
    fscanf(aleat1000,"%d ",&numeros[i]);
    fprintf(primeirosnum,"%d ",numeros[i]);
  }
  fclose(aleat100);
  fclose(aleat500);
  fclose(aleat1000);
  fclose(primeirosnum);
}

void impares(){
  int i;
  int nimpares[TAMANHO];
  FILE * primeirosn;
  FILE * imparesn;

  primeirosn=fopen("primeirosnum.txt","r");
  imparesn=fopen("impares.txt","w+");

  for(i=0;i<650;i++){
    fscanf(primeirosn,"%d ",&nimpares[i]);
    if(nimpares[i]%2!=0){
      fprintf(imparesn,"%d ",nimpares[i]);
    }
  }
  fclose(imparesn);
  fclose(primeirosn);
}

void pares(){
  int i;
  int npares[TAMANHO];
  FILE * primeirosn;
  FILE * paresn;

  primeirosn=fopen("primeirosnum.txt","r");
  paresn=fopen("pares.txt","w+");

  for(i=0;i<650;i++){
    fscanf(primeirosn,"%d ",&npares[i]);
    if(npares[i]%2==0){
      fprintf(paresn,"%d ",npares[i]);
    }
  }
  fclose(paresn);
  fclose(primeirosn);
}


int main(){
  primeirosn();
  impares();
  pares();
  printf("Sucesso\n");
}
