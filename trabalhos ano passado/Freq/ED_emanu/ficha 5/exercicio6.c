#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAMANHO 50

typedef struct lno *plista;

typedef struct lno
{
  int numero;
  char nome[TAMANHO];
  char tarefa[TAMANHO];
  float salario;
  plista prox;
}listano;

plista cria_lista_Vazia(){
  plista vazia=NULL;
  return vazia;
}

void dados_funcionarios(int qtdFuncionarios,plista *lst)
{

  for(int i=0;i<qtdFuncionarios;i++)
  {
    plista no = (plista)malloc(sizeof(listano));
    plista auxPonteiro=*lst;
    printf("Nome do funcionario:\n");
    fflush(stdin);
    gets(no->nome);
    printf("Numero do funcionario:\n");
    scanf("%d",&no->numero);
    printf("Tarefa que executa:\n");
    fflush(stdin);
    gets(no->tarefa);
    printf("Salario do funcionario:\n");
    scanf("%f",&no->salario);
    no->prox=NULL;
    if(*lst==NULL){
      *lst=no;
    }else{
      while(auxPonteiro->prox !=NULL){
        auxPonteiro=auxPonteiro->prox;
      }
      auxPonteiro->prox=no;
    }
  }
}

void ApresentarDados(int qtdFuncionarios,plista *lst)
{
  plista auxPonteiro=*lst;
  for(int i=0;i<qtdFuncionarios;i++)
  {
    printf("Nome do funcionario/a: %s\n",auxPonteiro->nome);
    printf("Numero do funcionario/a: %d\n",auxPonteiro->numero);
    printf("Tarefa do funcionario/a: %s\n",auxPonteiro->tarefa);
    printf("Salario do funcionario/a: %0.1f\n",auxPonteiro->salario);
    auxPonteiro=auxPonteiro->prox;
  }
}

void Salario500(int qtdFuncionarios,plista *lst)
{
  plista auxPonteiro=*lst;
  while(auxPonteiro!=NULL){
    if(auxPonteiro->salario>500)
    {
      printf("Funcionario/a com salario superior a 500: %s\n",auxPonteiro->nome);
    }
    auxPonteiro=auxPonteiro->prox;
  }
}

plista pesquisa_nome(int qtdFuncionarios,plista *lst,char pesquisaNome[TAMANHO])
{
  plista auxPonteiro=*lst;
  while(auxPonteiro!=NULL){
    if(strcmp(pesquisaNome,auxPonteiro->nome)==0)
    {
      return auxPonteiro;break;
    }else{
      return NULL;
    }
    auxPonteiro=auxPonteiro->prox;
  }
}

void pesquisa_numero(int qtdFuncionarios,plista *lst,int pesquisaNumero)
{
  plista auxPonteiro=*lst;
  while(auxPonteiro!=NULL){
    if(pesquisaNumero==auxPonteiro->numero)
    {
      printf("Insira o novo salario do funcionario/a:\n");
      scanf("%f",&auxPonteiro->salario);
      printf("Insira a nova tarefa do funcionario/a:\n");
      fflush(stdin);
      gets(auxPonteiro->tarefa);
      printf("Insira o novo nome do funcionario/a:\n");
      fflush(stdin);
      gets(auxPonteiro->nome);
      printf("Insira o novo numero do funcionario/a:\n");
      scanf("%d",&auxPonteiro->numero);
    }
    auxPonteiro=auxPonteiro->prox;
  }
}

void ordena_nomes_funcionarios(plista *lst){
  int auxOrdena;
  plista auxPonteiro=*lst;
  char auxCopia[TAMANHO];
    while(auxPonteiro->prox!=NULL){
      if(strcmp(auxPonteiro->nome,(auxPonteiro->prox)->nome)>0){
        strcpy(auxCopia,(auxPonteiro->prox)->nome);
        strcpy((auxPonteiro->prox)->nome,auxPonteiro->nome);
        strcpy(auxPonteiro->nome,auxCopia);

        auxOrdena = (auxPonteiro->prox)->salario;
        (auxPonteiro->prox)->salario = auxPonteiro->salario;
        auxPonteiro->salario = auxOrdena;

        auxOrdena = (auxPonteiro->prox)->numero;
        (auxPonteiro->prox)->numero = auxPonteiro->numero;
        auxPonteiro->numero = auxOrdena;

        strcpy(auxCopia, (auxPonteiro->prox)->tarefa);
        strcpy((auxPonteiro->prox)->tarefa, auxPonteiro->tarefa);
        strcpy(auxPonteiro->tarefa, auxCopia);
      }
      auxPonteiro=auxPonteiro->prox;
    }
}

int main()
{
  int qtdFuncionarios,auxNumero;
  char auxNome[TAMANHO];
  plista auxCria;
  auxCria=cria_lista_Vazia();
  char x;
  do
  {
    printf("Menu:\n");
    printf("1.Inserir dados dos funcionario\n");
    printf("2.Apresentar funcionarios na lista\n");
    printf("3.Apresentar funcionarios com salario superior a 500 euros\n");
    printf("4.Procurar funcionario\n");
    printf("5.Atualizar dados\n");
    printf("6.Ordenar por ordem alfabetica\n");
    printf("7.Sair\n");
    printf("Entre com a opcao: ");
    fflush(stdin);
    scanf("%c", &x);

    switch(x)
    {
      case '1':
      printf("Numero de funcionarios a inserir:\n");
      scanf("%d",&qtdFuncionarios);
      dados_funcionarios(qtdFuncionarios,&auxCria);break;
      case '2':
      ApresentarDados(qtdFuncionarios,&auxCria);break;
      case '3':
      Salario500(qtdFuncionarios,&auxCria);break;
      case '4':
      printf("Insira o nome a pesquisar:\n");
      fflush(stdin);
      gets(auxNome);
      pesquisa_nome(qtdFuncionarios,&auxCria,auxNome);
      plista auxEncontra=pesquisa_nome(qtdFuncionarios,&auxCria,auxNome);
      if(auxEncontra==NULL){
        printf("Funcionario nao existe!\n");
      }else{
        printf("Funcionario %s encontrado\n",auxEncontra->nome);
      }
      break;
      case '5':
      printf("Insira o numero do funcionario a atualizar:\n");
      scanf("%d",&auxNumero);
      pesquisa_numero(qtdFuncionarios,&auxCria,auxNumero);break;
      case '6':
      ordena_nomes_funcionarios(&auxCria);break;
      case '7':
      printf("Goodbye!");break;
      default:
      printf("Opcao Invalida\n");
    }
  }while(x!='7');
  return 0;
}
