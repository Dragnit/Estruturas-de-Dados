#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define TAMANHO 100

typedef struct estrutura_funcionarios{
  int numero;
  char tarefa[TAMANHO];
  char nome[TAMANHO];
  float salario;
}empresa;

void dados_funcionarios(empresa *ptr, int qtdFuncionarios){
  int i;

  for(i=0;i<qtdFuncionarios;i++){
    printf("Insira o nome do funcionario:\n");
    fflush(stdin);
    gets((ptr+i)->nome);
    printf("Insira o numero do funcionario:\n");
    scanf("%d",&(ptr+i)->numero);
    printf("Insira a tarefa do funcionario:\n");
    fflush(stdin);
    gets((ptr+i)->tarefa);
    printf("Insira o salario do funcionario:\n");
    scanf("%f",&(ptr+i)->salario);
  }
}

void lista_dados(empresa *ptr, int qtdFuncionarios){
  int i;

  for(i=0;i<qtdFuncionarios;i++){
    printf("Nome do Funcionario: %s\n",(ptr+i)->nome);
    printf("Numero do Funcionario: %d\n",(ptr+i)->numero);
    printf("Tarefa do Funcionario: %s\n",(ptr+i)->tarefa);
    printf("Salario do Funcionario: %0.1f\n",(ptr+i)->salario);
  }
}

void lista_salarios(empresa *ptr,int qtdFuncionarios){
  int i;

  for(i=0;i<qtdFuncionarios;i++){
    if((ptr+i)->salario>500){
      printf("Nome do funcionario com salario superior a 500: %s\n",(ptr+i)->nome);
    }
  }
}

empresa pesquisa_FuncNome(empresa *ptr,char pesquisaNome[TAMANHO],int qtdFuncionarios){
  int i;

  for(i=0;i<qtdFuncionarios;i++){
    if(strcmp(pesquisaNome,(ptr+i)->nome)==0){
      printf("Nome do Funcionario: %s\n",(ptr+i)->nome);
      printf("Numero do Funcionario: %d\n",(ptr+i)->numero);
      printf("Tarefa do Funcionario: %s\n",(ptr+i)->tarefa);
      printf("Salario do Funcionario: %0.1f\n",(ptr+i)->salario);
    }
    }
  }

  void pesquisa_FuncNumero(empresa *ptr,int pesquisaNumero,int qtdFuncionarios){
    int i;

    for(i=0;i<qtdFuncionarios;i++){
      if(pesquisaNumero==(ptr+i)->numero){
        printf("Insira o novo salario do funcionario:\n");
        scanf("%f",&(ptr+i)->salario);
        printf("Insira a nova tarefa do funcionario:\n");
        fflush(stdin);
        gets((ptr+i)->tarefa);
        printf("Insira o novo nome do funcionario:\n");
        fflush(stdin);
        gets((ptr+i)->nome);
      }
    }
  }

int main()
{
empresa *ptr;
int qtdFuncionarios,pesquisaNumero;
char pesquisaNome[TAMANHO];


printf("Insira a quantidade de funcionarios na empresa:\n");
scanf("%d",&qtdFuncionarios);

ptr=(empresa*)malloc(qtdFuncionarios*sizeof(empresa));

dados_funcionarios(ptr,qtdFuncionarios);
lista_dados(ptr,qtdFuncionarios);
lista_salarios(ptr,qtdFuncionarios);

printf("Insira o nome do funcionario pelo qual pretende pesquisar:\n");
fflush(stdin);
gets(pesquisaNome);

pesquisa_FuncNome(ptr,pesquisaNome,qtdFuncionarios);

printf("Insira o numero de um funcionario para atualizar os seus dados:\n");
fflush(stdin);
scanf("%d",&pesquisaNumero);

pesquisa_FuncNumero(ptr,pesquisaNumero,qtdFuncionarios);
printf("Dados atualizados:\n");
lista_dados(ptr,qtdFuncionarios);

	return 0;
}