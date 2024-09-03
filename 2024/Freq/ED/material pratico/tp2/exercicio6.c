#include <stdio.h>
#include <string.h>
#define TAM 100

int inserir(char numero[][TAM], char nome[][TAM]){
  int qntalunos;

  printf("Quantos alunos pretendes inserir: ");
  scanf("%d", &qntalunos);

  for (int i=0;i<qntalunos;i++){
    char auxnome[TAM];
    char auxnumero[TAM];
    printf("Nome: ");
    fflush(stdin);
    fgets(auxnome, TAM, stdin);
    printf("Numero: ");
    fflush(stdin);
    scanf("%s", auxnumero);
    strcpy(nome[i], auxnome);
    strcpy(numero[i],auxnumero);
  }
}

void listar(char numero[][TAM], char nome[][TAM], int talunos){

  for(int i=0;i<talunos;i++){
    printf("Nome: %s", nome[i]);
    printf("Numero: %s\n", numero[i]);
  }
}

void guardar(char nome[][TAM], char numero[][TAM],int talunos){
  FILE *dados=fopen("dados.txt","a");

  for (int i=0;i<talunos;i++){
    fprintf(dados,"%s\n%s",numero[i],nome[i]);
  }
  fclose(dados);
  printf("Gravado com sucesso!\n");
}

int carregar(char nome[][TAM], char numero[][TAM]){

  FILE *dados=fopen("dados.txt","r");
  int q=0;

  while(fgets(numero[q],TAM,dados)!=NULL){
    if(numero[q][strlen(numero[q])-1]!='\0')
    numero[q][strlen(numero[q])-1]='\0';
    fgets(nome[q],TAM,dados);
    q++;
  }
  fclose(dados);
  return q;
}

int main(){

  int opcao,talunos=0;
  char numero[TAM][TAM];
  char nome[TAM][TAM];
  talunos = carregar(nome,numero);

  do{
    printf("Menu de opcoes\n");
    printf("1-Inscrever Alunos\n");
    printf("2-Remover Alunos(Nao Elaborado...)\n");
    printf("3-Listar Alunos\n");
    printf("4-Gravar Dados\n");
    printf("5-Sair\n");
    fflush(stdin);
    scanf("%d",&opcao);

    switch (opcao){
      case 1:  talunos= inserir(numero, nome);break;
      case 2:  break;
      case 3: listar(numero, nome, talunos); break;
      case 4: guardar(nome,numero,talunos); break;
      case 5: printf("Bye Bye\n"); break;
      default:printf("Opcao invalida\n");
    }
  }while(opcao!=5);
}
