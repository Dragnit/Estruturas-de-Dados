#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAMANHO 100

int qtdAlunos,totalAlunos=0,qtdAdicionalAlunos,removeEncontrado;
int numeroAluno[TAMANHO];
char nomesAlunos[TAMANHO][TAMANHO],tecla;
//variaveis usados no Remove
int auxPosAluno=0;
int auxNumAluno[TAMANHO];
char auxNomesAlunos[TAMANHO][TAMANHO];

void insereAlunos()
{
int i;
  printf("Insira a quantidade de alunos da turma: ");
  scanf("%d",&qtdAlunos);
  for(i=0;i<qtdAlunos;i++)
    {
      printf("Nome do Aluno: ");
      fflush(stdin);
      fgets(nomesAlunos[i],TAMANHO,stdin);
      printf("Numero do Aluno: ");
      fflush(stdin);
      scanf("%d",&numeroAluno[i]);
      totalAlunos=qtdAlunos;
    }
    printf("Alunos inseridos na Turma com sucesso!\n");
}

void inscreveAlunos(){
  int i;
  printf("Numero de alunos a adicionar: ");
  scanf("%d",&qtdAdicionalAlunos);
  totalAlunos=qtdAlunos+qtdAdicionalAlunos;
  for(i=qtdAlunos;i<totalAlunos;i++)
    {
      printf("Nome do Aluno: ");
      fflush(stdin);
      fgets(nomesAlunos[i],TAMANHO,stdin);
      printf("Numero do Aluno: ");
      fflush(stdin);
      scanf("%d",&numeroAluno[i]);
    }
}


int encontraPosicaoAluno(int pesquisaNumero){
  int i;
  for(i=0;i<totalAlunos;i++){
    if(pesquisaNumero==numeroAluno[i]){
      return i;
    }
  }
  return -1;
}

void atualizaArraysAluno(int novoNumAlunos[TAMANHO], char novoNomesAlunos[TAMANHO][TAMANHO],int qtdAlunosRemovida){
  int i,j;
  totalAlunos = totalAlunos - qtdAlunosRemovida;
  for(i=0;i<totalAlunos;i++){
    strcpy(nomesAlunos[i],novoNomesAlunos[i]);
    numeroAluno[i]=novoNumAlunos[i];
  }

  for(i=0;i<totalAlunos;i++){
    printf("%s\n",nomesAlunos[i]);
    printf("%d\n",numeroAluno[i]);
  }
}

void removeAluno(){
  int i,pesquisaNumero;

  printf("Introduza o numero do aluno que pretende remover: ");
  fflush(stdin);
  scanf("%d",&pesquisaNumero);

  int posicaoAluno= encontraPosicaoAluno(pesquisaNumero);

  if(posicaoAluno==-1){
    printf("Aluno nao encontrado!");
    return;
  }else{
    for(i=0;i<totalAlunos;i++){
      if(i!=posicaoAluno){
        strcpy(auxNomesAlunos[auxPosAluno],nomesAlunos[i]);
        auxNumAluno[auxPosAluno]= numeroAluno[i];
        auxPosAluno++;
      }
    }
  }
  atualizaArraysAluno(auxNumAluno,auxNomesAlunos,1);
  printf("Aluno removido com sucesso!\n");
}

void listaAlunos(){
  int i;

    printf("Numero total de alunos: %d\n",totalAlunos);
    for(i=0;i<totalAlunos;i++){
      printf("Aluno: %s\n",nomesAlunos[i]);
      printf("\nNumero: %d\n",numeroAluno[i]);
    }
}

void guardaDados(){
  int i;
  FILE * dadosAluno;

  dadosAluno=fopen("dadosAlunos.txt","w+");

  for(i=0;i<totalAlunos;i++){
    fprintf(dadosAluno,"%d %s",numeroAluno[i],nomesAlunos[i]);
  }
}

void carregaDados(){
  FILE * dadosAlunos;
  char auxNomeAluno[TAMANHO];
  char linhaAluno[TAMANHO];
  int auxNumeroAluno;
  int i=0,j=0,k;
  char numero[10];
  dadosAlunos=fopen("dadosAlunos.txt","r");

  while((fgets(linhaAluno,TAMANHO, dadosAlunos)) != NULL) {
    j=0;
    while(linhaAluno[j]!=' '){
      numero[j]=linhaAluno[j];
      j++;
    }
    if(linhaAluno[j]==' '){
      numero[j]='\0';
    }
    numeroAluno[i]=atoi(numero);
    k=0;
    while(linhaAluno[j]!='\0'){
      nomesAlunos[i][k]=linhaAluno[j];
      j++;
      k++;
    }
    if(linhaAluno[j]=='\0'){
      nomesAlunos[i][k]='\0';
    }
     totalAlunos++;
     i++;
  }
  fclose(dadosAlunos);
}

int main()
{
char opcao;
carregaDados();
do
{
  printf("Menu:\n");
  printf("1-Inserir Alunos na Turma\n");
  printf("2-Inscrever mais Alunos na Turma\n");
  printf("3-Remover alunos da Turma\n");
  printf("4-Listar alunos da Turma\n");
  printf("5-Sair\n");
  fflush(stdin);
  scanf("%c",&opcao);

switch (opcao)
{
  case '1': insereAlunos();break;
  case '2': inscreveAlunos();break;
  case '3': removeAluno();break;
  case '4': listaAlunos();break;
  case '5': guardaDados();
            printf("Goodbye!");break;
  default:  printf("Opcao invalida\n");
}
}while(opcao!='5');
return 0;
}
