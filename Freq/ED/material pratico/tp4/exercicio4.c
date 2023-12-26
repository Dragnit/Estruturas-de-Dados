#include <stdio.h>
#include <stdlib.h>
#include<string.h>

struct dadosfunc{

  int numero;
  char nome[200];
  char tarefa[200];
  float salario;

};

typedef struct dadosfunc dados;

void inserir(int qntfunc,dados dadostabela[qntfunc]){

  printf("\n");
  for(int i=0;i<qntfunc;i++)
  {
    printf("Numero: ");
    scanf("%d",&dadostabela[i].numero);
    printf("Nome: ");
    fflush(stdin);
    gets(dadostabela[i].nome);
    printf("Tarefa: ");
    fflush(stdin);
    gets(dadostabela[i].tarefa);
    printf("Salario: ");
    scanf("%f",&dadostabela[i].salario);

  }
  printf("\n");
}

void listarfunc(int qntfunc,dados dadostabela[qntfunc]){

  printf("\n");
  for(int i=0;i<qntfunc;i++)
  {
    printf("Numero: %d\n",dadostabela[i].numero);
    printf("Nome: %s\n",dadostabela[i].nome);
    printf("Tarefa: %s\n",dadostabela[i].tarefa);
    printf("Salario: %0.2f\n",dadostabela[i].salario);
  }
  printf("\n");
}

void salariosup(int qntfunc,dados dadostabela[qntfunc]){

  printf("\n");
  for(int i=0;i<qntfunc;i++)
  {
    if(dadostabela[i].salario>500){
      printf("Numero: %d\n",dadostabela[i].numero);
      printf("Nome: %s\n",dadostabela[i].nome);
      printf("Tarefa: %s\n",dadostabela[i].tarefa);
      printf("Salario: %0.2f\n",dadostabela[i].salario);
    }
  }
  printf("\n");
}

dados procurar(int qntfunc,dados dadostabela[qntfunc]){

  char auxnome[200];

  dados aux;
  strcpy(aux.nome,"");
  strcpy(aux.tarefa,"");
  aux.numero=0;
  aux.salario=0;
  printf("\n");
  printf("Nome de quem procurar:");
  fflush(stdin);
  gets(auxnome);

  for(int i=0;i<qntfunc;i++){
    if(strcmp(dadostabela[i].nome,auxnome)==0)
    return dadostabela[i];
  }
  return aux;
  printf("\n");
}

void atualizar(int qntfunc,dados dadostabela[qntfunc]){

  int auxnumero;

  printf("\nNumero de quem procurar:");
  scanf("%d",&auxnumero);
  for(int i=0;i<qntfunc;i++){
    if(auxnumero==dadostabela[i].numero){
      printf("Novo numero: ");
      scanf("%d",&dadostabela[i].numero);
      printf("Novo nome: ");
      fflush(stdin);
      gets(dadostabela[i].nome);
      printf("Nova tarefa: ");
      fflush(stdin);
      gets(dadostabela[i].tarefa);
      printf("Novo salario: ");
      scanf("%f",&dadostabela[i].salario);

    }
  }
}

void ordenarcrescente(int qntfunc,dados dadostabela[qntfunc]){

  int i, j;
  dados aux;

  for (i=0;i<qntfunc;i++){
    for (j =0;j<qntfunc;j++)
    if (dadostabela[j+1].numero<dadostabela[j].numero){
      aux = dadostabela[j];
      dadostabela[j]= dadostabela[j+1];
      dadostabela[j+1]= aux;
    }
  }
}

void ordemalfabetica(int qntfunc,dados dadostabela[qntfunc]){


  int i, j;
  dados ajuda;

  for (i = 0; i < qntfunc; i++) {
    for (j=0; j < qntfunc; j++)
    if (strcmp(dadostabela[j].nome,dadostabela[j+1].nome)>0) {
      ajuda=dadostabela[j];
      dadostabela[j]=dadostabela[j+1];
      dadostabela[j+1]=ajuda;
    }
  }
}

int main(){

  int qntfunc,opcao;
  dados auxprocurar;
  printf("Quantos funcionarios pretende inserir:");
  scanf("%d",&qntfunc);

  dados dadostabela[qntfunc];

  do{
    printf("**********");
    printf("\n Menu \n");
    printf("**********\n");
    printf("1.Inserir\n");
    printf("2.Listar funcionarios\n");
    printf("3.Salarios superiores a 500 eur\n");
    printf("4.Procurar funcionario por nome\n");
    printf("5.Atualizar dados pelo numero\n");
    printf("6.Ordenar numeros crescente\n");
    printf("7.Ordem alfabetica nomes\n");
    printf("8.Sair\n");
    printf("Qual a sua opcao:");
    fflush(stdin);
    scanf("%d",&opcao);


    switch(opcao){
      case 1:
      printf("opcao 1 selecionada\n");
      inserir(qntfunc,dadostabela);
      break;
      case 2:
      printf("opcao 2 selecionada\n");
      listarfunc(qntfunc,dadostabela);
      break;
      case 3:
      printf("opcao 3 selecionada\n");
      salariosup(qntfunc,dadostabela);
      break;
      case 4:
      printf("opcao 4 selecionada\n");
      auxprocurar=procurar(qntfunc,dadostabela);
      printf("Numero: %d\n",auxprocurar.numero);
      printf("Nome: %s\n",auxprocurar.nome);
      printf("Tarefa: %s\n",auxprocurar.tarefa);
      printf("Salario: %0.2f\n",auxprocurar.salario);
      break;
      case 5:
      printf("opcao 5 selecionada\n");
      atualizar(qntfunc,dadostabela);
      break;
      case 6:
      printf("opcao 6 selecionada\n");
      ordenarcrescente(qntfunc,dadostabela);
      listarfunc(qntfunc,dadostabela);
      break;
      case 7:
      printf("opcao 7 selecionada\n");
      ordemalfabetica(qntfunc,dadostabela);
      listarfunc(qntfunc,dadostabela);
      break;
      case 8:
      printf("opcao 8 selecionada\n");
      break;
      default:
      printf("opcao invalida\n");
    }
  }while(opcao!=8);

  return 0 ;
}
