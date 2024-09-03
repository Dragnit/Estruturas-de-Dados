#include <stdio.h>
#include <string.h>
#define TAMANHO 100

typedef struct estrutura_funcionarios{
  int numero;
  char tarefa[TAMANHO];
  char nome[TAMANHO];
  float salario;
}empresa;

void dados_funcionarios(empresa funcionario[TAMANHO], int qtdFuncionarios){
  int i;

  for(i=0;i<qtdFuncionarios;i++){
    printf("Insira o nome do funcionario:\n");
    fflush(stdin);
    gets(funcionario[i].nome);
    printf("Insira o numero do funcionario:\n");
    scanf("%d",&funcionario[i].numero);
    printf("Insira a tarefa do funcionario:\n");
    fflush(stdin);
    gets(funcionario[i].tarefa);
    printf("Insira o salario do funcionario:\n");
    scanf("%f",&funcionario[i].salario);
  }
}

void lista_dados(empresa funcionario[TAMANHO],int qtdFuncionarios){
  int i;

  for(i=0;i<qtdFuncionarios;i++){
    printf("Nome do Funcionario: %s\n",funcionario[i].nome);
    printf("Numero do Funcionario: %d\n",funcionario[i].numero);
    printf("Tarefa do Funcionario: %s\n",funcionario[i].tarefa);
    printf("Salario do Funcionario: %0.1f\n",funcionario[i].salario);
  }
}

void lista_salarios(empresa funcionario[TAMANHO],int qtdFuncionarios){
  int i;

  for(i=0;i<qtdFuncionarios;i++){
    if(funcionario[i].salario>500){
      printf("Nome do funcionario com salario superior a 500: %s\n",funcionario[i].nome);
    }
  }
}

empresa pesquisa_FuncNome(empresa funcionario[TAMANHO],char pesquisaNome[TAMANHO],int qtdFuncionarios){
  int i;
  empresa vazia;
  vazia.numero=0;
  vazia.salario=0;
  strcpy(vazia.nome,"");
  strcpy(vazia.tarefa,"");

  for(i=0;i<qtdFuncionarios;i++){
    if(strcmp(pesquisaNome,funcionario[i].nome)==0){
      printf("Nome do Funcionario: %s\n",funcionario[i].nome);
      printf("Numero do Funcionario: %d\n",funcionario[i].numero);
      printf("Tarefa do Funcionario: %s\n",funcionario[i].tarefa);
      printf("Salario do Funcionario: %0.1f\n",funcionario[i].salario);
    }
    }
      return vazia;
  }

void pesquisa_FuncNumero(empresa funcionario[TAMANHO],int pesquisaNumero,int qtdFuncionarios){
  int i;

  for(i=0;i<qtdFuncionarios;i++){
    if(pesquisaNumero==funcionario[i].numero){
      printf("Insira o novo salario do funcionario:\n");
      scanf("%f",&funcionario[i].salario);
      printf("Insira a nova tarefa do funcionario:\n");
      fflush(stdin);
      gets(funcionario[i].tarefa);
      printf("Insira o novo nome do funcionario:\n");
      fflush(stdin);
      gets(funcionario[i].nome);
    }
  }
}

void ordena_FuncNumero(empresa funcionario[TAMANHO],int qtdFuncionarios){
  int i,j,auxCopiaInt;
  char auxCopiaStrings[TAMANHO];
  for(i=0;i<qtdFuncionarios;i++){
    for(j=i+1;j<qtdFuncionarios;j++){
      if(funcionario[i].numero>funcionario[j].numero){
        auxCopiaInt=funcionario[i].numero;
        funcionario[i].numero=funcionario[j].numero;
        funcionario[j].numero=auxCopiaInt;
        auxCopiaInt=funcionario[i].salario;
        funcionario[i].salario=funcionario[j].salario;
        funcionario[j].salario=auxCopiaInt;
        strcpy(auxCopiaStrings,funcionario[i].nome);
        strcpy(funcionario[i].nome,funcionario[j].nome);
        strcpy(funcionario[j].nome,auxCopiaStrings);
        strcpy(auxCopiaStrings,funcionario[i].tarefa);
        strcpy(funcionario[i].tarefa,funcionario[j].tarefa);
        strcpy(funcionario[j].tarefa,auxCopiaStrings);
      }
    }
  }
}

void ordena_FuncNome(empresa funcionario[TAMANHO],int qtdFuncionarios){
  int i,j,auxCopiaInt;
  char auxCopiaStrings[TAMANHO];

  for(i=0;i<qtdFuncionarios;i++){
    for(j=i+1;j<qtdFuncionarios;j++){
      if(strcmp(funcionario[i].nome,funcionario[j].nome)>0){
        auxCopiaInt=funcionario[i].numero;
        funcionario[i].numero=funcionario[j].numero;
        funcionario[j].numero=auxCopiaInt;
        auxCopiaInt=funcionario[i].salario;
        funcionario[i].salario=funcionario[j].salario;
        funcionario[j].salario=auxCopiaInt;
        strcpy(auxCopiaStrings,funcionario[i].nome);
        strcpy(funcionario[i].nome,funcionario[j].nome);
        strcpy(funcionario[j].nome,auxCopiaStrings);
        strcpy(auxCopiaStrings,funcionario[i].tarefa);
        strcpy(funcionario[i].tarefa,funcionario[j].tarefa);
        strcpy(funcionario[j].tarefa,auxCopiaStrings);
      }
    }
  }
}

int main()
{
empresa funcionario[TAMANHO];
int qtdFuncionarios,pesquisaNumero;
char pesquisaNome[TAMANHO];
printf("Insira a quantidade de funcionarios na empresa:\n");
scanf("%d",&qtdFuncionarios);

dados_funcionarios(funcionario,qtdFuncionarios);
lista_dados(funcionario,qtdFuncionarios);
lista_salarios(funcionario,qtdFuncionarios);

printf("Insira o nome do funcionario pelo qual pretende pesquisar:\n");
fflush(stdin);
gets(pesquisaNome);

pesquisa_FuncNome(funcionario,pesquisaNome,qtdFuncionarios);

printf("Insira o numero de um funcionario para atualizar os seus dados:\n");
fflush(stdin);
scanf("%d",&pesquisaNumero);

pesquisa_FuncNumero(funcionario,pesquisaNumero,qtdFuncionarios);
printf("Dados atualizados:\n");
lista_dados(funcionario,qtdFuncionarios);

ordena_FuncNumero(funcionario,qtdFuncionarios);
printf("Lista de Dados por ordem crescente:\n");
lista_dados(funcionario,qtdFuncionarios);

ordena_FuncNome(funcionario,qtdFuncionarios);
printf("Lista de Dados por ordem alfabetica:\n");
lista_dados(funcionario,qtdFuncionarios);
	return 0;
}
