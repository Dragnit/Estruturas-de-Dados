#include <stdio.h>
#include <stdlib.h>

typedef struct lno *plista;

typedef struct lno{
  float valor;
  plista prox;
}listano;


plista criarPilhavazia()
{
  plista p=NULL;
  return p;
}

int verificarlista(plista lst)
{
  if(lst==NULL)
  return 1;
  else
  return 0;
}

void Push(float y,plista *lst)
{
  plista no = (plista)malloc(sizeof(listano));

  if(no==NULL)
  {
    printf("Erro!! Memoria indisponivel....\n");
  }
  else
  {
    no->valor=y;
    no->prox= *lst;
    *lst=no;
  }
}

void escreveLista(plista lst)
{
  if(verificarlista(lst))
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

void Pop(plista *lst){
  plista auxiliarPont= *lst;

  *lst=(*lst)->prox;
  free(auxiliarPont);
}

void Top(plista lst)
{
  while(lst->prox!=NULL)
    {
      lst=lst->prox;
    }
  printf("Ultimo elemento da lista:%0.1f\n ",lst->valor);
}

int main()
{
  char x;
  float y;
  plista criaVazia;
  criaVazia=criarPilhavazia();

  do
  {
    printf("Menu:\n");
    printf("1.Indicar se a pilha esta vazia\n");
    printf("2.Push\n");
    printf("3.Mostrar lista\n");
    printf("4.Pop\n");
    printf("5.Top\n");
    fflush(stdin);
    scanf("%c", &x);

    switch(x)
    {
      case '1':
      verificarlista(criaVazia);
      if(verificarlista(criaVazia)==1)
      printf("A lista esta vazia!\n");
      else
      printf("A lista tem informacao\n");
      break;
      case '2':
      printf("Insira um elemento:\n");
      scanf("%f",&y);
      Push(y,&criaVazia);break;
      case '3':
      escreveLista(criaVazia);break;
      case '4':
      Pop(&criaVazia);break;
      case'5':
      Top(criaVazia);break;
      case '6':
      printf("Bye bye\n");break;
      default:
      printf("Opcao Invalida!");
    }
  }while(x!='6');
  return 0;
}
