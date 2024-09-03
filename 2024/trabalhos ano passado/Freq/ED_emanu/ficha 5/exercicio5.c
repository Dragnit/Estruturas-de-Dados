#include <stdio.h>
#include <stdlib.h>

typedef struct lno *plista;

typedef struct lno{
  float valor;
  plista prox;
}listano;


  plista criarFilavazia()
{
  plista p=NULL;
  return p;
}

  int verificarfila(plista lst)
{
  if(lst==NULL)
  return 1;
  else
  return 0;
}
  void Juntar(float y,plista *lst)
{
  plista no = (plista)malloc(sizeof(listano));
  plista auxiliarPont= *lst;

  if(no==NULL)
    {
      printf("Erro!! Memoria indisponivel....\n");
    }
  else
    {
      no->valor=y;
      no->prox=NULL;
  if(*lst==NULL)
    {
      *lst=no;
    }
  else
    {
      while(auxiliarPont->prox != NULL)
        {
          auxiliarPont=auxiliarPont->prox;
        }
      auxiliarPont->prox=no;
    }
  }
}
  void escreveLista(plista lst)
{
  if(verificarfila(lst))
  {
    printf("Lista esta vazia!\n");
  }
  else
  {
    printf("[");
    do
    {
      printf("%0.1f,",lst->valor);
      lst=lst->prox;
    }
    while(lst != NULL);
    printf("\b ] \n");
  }
}

  void Remover(plista *lst)
{
  plista auxiliarPont= *lst;

  *lst=(*lst)->prox;
  free(auxiliarPont);
}

void Mostrar(plista lst)
{
  printf("Primeiro elemento da lista:%0.1f\n",lst->valor);
}

int main()
{
  char x;
  float y;
  plista criaVazia;
  criaVazia=criarFilavazia();

  do
  {
    printf("Menu:\n");
    printf("1.Indicar se a fila esta vazia\n");
    printf("2.Juntar\n");
    printf("3.Mostrar lista\n");
    printf("4.Remover\n");
    printf("5.Mostrar\n");
    fflush(stdin);
    scanf("%c", &x);

    switch(x)
    {
      case '1':
      verificarfila(criaVazia);
      if(verificarfila(criaVazia)==1)
      printf("A fila esta vazia!\n");
      else
      printf("A fila tem informacao\n");
      break;
      case '2':
      printf("Insira um elemento:\n");
      scanf("%f",&y);
      Juntar(y,&criaVazia);break;
      case '3':
      escreveLista(criaVazia);break;
      case '4':
      Remover(&criaVazia);break;
      case'5':
      Mostrar(criaVazia);break;
      case '6':
      printf("Bye bye\n");break;
      default:
      printf("Opcao Invalida!");
    }
  }while(x!='6');
  return 0;
}
