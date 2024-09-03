#include <stdio.h>
#include <string.h>
#define TAMANHO 100

int nnomes;
char nomes[TAMANHO][TAMANHO];

void nomestabela(){
  int i;

  printf("Quantos nomes pretende introduzir?:");
  scanf("%d",&nnomes);
  for(i=0;i<nnomes;i++){
    printf("Nome: ");
    fflush(stdin);
    fgets(nomes[i],TAMANHO,stdin);
  }
}

void ficheironomes(){

  int i;
  FILE * fnomes;

  fnomes=fopen("nomes.txt","w+");

  for(i=0;i<nnomes;i++){
    fprintf(fnomes,"%s",nomes[i]);
  }
  fclose(fnomes);
}

void escreverterminal(){
  int i;
  FILE * lertxt;

  lertxt=fopen("nomes.txt","r");

  printf("\nFicheiro nomes.txt conteudo:\n");
  for(i=0;i<nnomes;i++){
    fgets(nomes[i],sizeof(nomes),lertxt);
    printf("%s",nomes[i]);
  }
  fclose(lertxt);
}

void tabelabin(){
  FILE *f=fopen("tabelaNomes.dat","wb");
  int i=0;

  fwrite(nomes[i], sizeof(nomes[i]),nnomes, f);
  i++;

  fclose(f);
}

void nomesbin(){

  FILE *f=fopen("nomesBinario.dat","wb");

  for(int i=0; i<nnomes;i++){
    fwrite(nomes[i], sizeof(nomes[i]),1, f);
  }
  fclose(f);
}

void escrevertabelabin(){
  FILE *fp=fopen("tabelaNomes.dat","rb");
  int i = 0;

  while(fread(nomes[i], sizeof(nomes[i]),1, fp)!=0){
    i++;
  }
  printf("\nFicheiro tabelaNomes.dat conteudo:\n ");
  for (int j = 0; j < i; j++){
    printf("%s", nomes[j]);
  }
  fclose(fp);
}

void escrevernomesbin(){
  FILE *fp=fopen("nomesBinario.dat","rb");
  int i = 0;

  while(fread(nomes[i], sizeof(nomes[i]),1, fp) != 0){
    i++;
  }
  printf("\nFicheiro nomesBinario.dat conteudo:\n");
  for (int j = 0; j < i; j++){
    printf("%s", nomes[j]);
  }
  fclose(fp);
}


int main(){
  nomestabela();
  ficheironomes();
  escreverterminal();
  tabelabin();
  nomesbin();
  escrevertabelabin();
  escrevernomesbin();

}
