#include <stdio.h>
#include <stdlib.h>

typedef struct lno *plista;

typedef struct lno{
  float valor;
  plista prox;
}listano;

plista cria_lista_Vazia(){
  plista vazia=NULL;
  return vazia;
}

int verifica_Lista(plista lista){
  if(lista==NULL){
    return 1;
  }else{
    return 0;
  }
}

void escreve_Lista(plista lista){
  if(verifica_Lista(lista)){
    printf("Lista e vazia!\n");
  }else{
    printf("[");
    do{
      printf("%0.1f,",lista->valor);
      lista=lista->prox;
    }while(lista != NULL);
    printf("\b ] \n");
  }
}

void acrescenta_Inicio(float elemento,plista *lista){
  plista no = (plista)malloc(sizeof(listano));

  if(no==NULL){
    printf("Erro!! Memoria indisponivel....\n");
  }else{
    no->valor=elemento;
    no->prox= *lista;
    *lista=no;
  }
}

void acrescenta_Fim(float elemento,plista *lista){
  plista no = (plista)malloc(sizeof(listano));
  plista auxPonteiro= *lista;

  if(no==NULL){
    printf("Erro!! Memoria indisponivel....\n");
  }else{
    no->valor=elemento;
    no->prox=NULL;
    if(*lista==NULL){
      *lista=no;
    }else{
      while(auxPonteiro->prox != NULL){
        auxPonteiro=auxPonteiro->prox;
      }
      auxPonteiro->prox=no;
    }
  }
}

void remove_Primeiro(plista *lista){
  plista auxPonteiro= *lista;

  *lista=(*lista)->prox;
  free(auxPonteiro);
}

void remove_Ultimo(plista *lista){
  plista auxPonteiro= *lista;
  plista auxRemove=NULL;

  while(auxPonteiro->prox != NULL){
    auxRemove=auxPonteiro;
    auxPonteiro=auxPonteiro->prox;
  }
  free(auxPonteiro);

  if(auxRemove !=NULL){
    auxRemove->prox=NULL;
  }else{
    *lista=NULL;
  }
}

void insereNovamente(int posicao){
  printf("Posicao Invalida!!Indique a posicao do elemento que deseja remover novamente:\n");
  scanf("%d",&posicao);
}

void remove_Elemento(plista *lista,int posicao){
  int contaPos=0;
  plista auxPonteiro= *lista;
  plista auxRemove=NULL;

  while(posicao<0){
    insereNovamente(posicao);
  }

  while(auxPonteiro->prox != NULL && contaPos!=posicao){
    contaPos++;
    auxRemove=auxPonteiro;
    auxPonteiro=auxPonteiro->prox;
  }

  if(auxRemove !=NULL){
    auxRemove->prox=auxPonteiro->prox;
  }else{
    *lista=(*lista)->prox;
  }
  free(auxPonteiro);
}

void remove_Primeira_Ocorrencia(plista *lista,float elemento){
  plista auxPonteiro= *lista;
  plista auxRemove=NULL;


  while(auxPonteiro->valor != elemento && auxPonteiro->prox != NULL){
    auxRemove=auxPonteiro;
    auxPonteiro=auxPonteiro->prox;
  }

  if(auxPonteiro->valor == elemento){
    if(auxRemove != NULL){
      auxRemove->prox=auxPonteiro->prox;
    }else{
      *lista=(*lista)->prox;
    }
    free(auxPonteiro);
  }
}

void remove_Todas_Ocorrencias(plista *lista,float elemento){
  plista auxPonteiro= *lista;
  plista auxRemove=NULL;

  while(auxPonteiro != NULL)
  {
    if(auxPonteiro->valor == elemento)
    if(*lista == auxPonteiro)// esta no inicio da lista
    {
      *lista=(*lista)->prox;
      free(auxPonteiro);
      auxPonteiro = *lista;
    }
    else // nao esta no inicio da lista
    {
      auxRemove->prox=auxPonteiro->prox;
      free(auxPonteiro);
      auxPonteiro = auxRemove->prox;
    }
    else
    {
      auxRemove = auxPonteiro;
      auxPonteiro = auxPonteiro->prox;
    }
  }
}

void conta_Elementos(plista lista){
  int contagem=0;

  while(lista != NULL){
    contagem++;
    lista=lista->prox;
  }
  printf("Comprimento da lista:%d\n",contagem);
}

plista encontra_Elemento(plista lista, float elemento){
  plista auxPonteiro=NULL;
  while(lista!=NULL){
    if(elemento==lista->valor){
      return lista;
    }else{
      lista=lista->prox;
    }
  }
}

plista cria_Lista_User(int tamanhoLista,plista *lista){
  float valor;

  for(int i=0;i<tamanhoLista;i++){
    printf("Introduza o elemento a inserir:\n");
    scanf("%f",&valor);
    acrescenta_Inicio(valor,lista);
  }
}

plista limpa_Lista(plista *lista){
  while(*lista!=NULL){
    remove_Primeiro(lista);
  }
}

void mostra_Primeiro(plista lista){
  printf("Primeiro elemento da lista:%0.1f\n",lista->valor);
}

void mostra_Ultimo(plista lista){
  while(lista->prox!=NULL){
    lista=lista->prox;
  }
  printf("Ultimo elemento da lista:%0.1f\n ",lista->valor);
}

void mostra_Cauda(plista lista){
  printf("Cauda da lista:\n");
  while(lista=lista->prox){
    printf("%0.1f,",lista->valor);
  }
}

void junta_Listas(plista *listaA, plista *listaB){
  plista auxPonteiro=*listaA;
  if(*listaA==NULL){
    *listaA=*listaB;
  }else{
    while(auxPonteiro->prox !=NULL){
      auxPonteiro=auxPonteiro->prox;
    }
    auxPonteiro->prox=*listaB;
  }
}

void copia_Lista(plista *listaA,plista *listaB){
  plista auxPonteiro=*listaA;
  plista auxPonteiro2=NULL;
  if(*listaA==NULL){
    *listaB=*listaA;
  }else{
    while(auxPonteiro !=NULL){
      plista no=(plista)malloc(sizeof(listano));
      no->valor=auxPonteiro->valor;
      no->prox=NULL;
      if(*listaB==NULL){
        *listaB=no;
      }else{
        auxPonteiro2=*listaB;
        while(auxPonteiro2->prox!=NULL){
          auxPonteiro2=auxPonteiro2->prox;
        }
        auxPonteiro2->prox=no;
      }
      auxPonteiro=auxPonteiro->prox;
    }
  }
}

void troca_Elementos(plista *lista,float valorA,float valorB){
  plista auxPonteiro=*lista;
  plista auxPonteiro2=*lista;

  while(auxPonteiro!=NULL && (auxPonteiro->valor)!=valorA){
    auxPonteiro=auxPonteiro->prox;
  }

  while(auxPonteiro2!=NULL && (auxPonteiro2->valor)!=valorB){
    auxPonteiro2=auxPonteiro2->prox;
  }

  auxPonteiro2->valor=valorA;
  auxPonteiro->valor=valorB;
}

void ordem_Crescente(plista *lista){
  plista auxPonteiro=*lista;
  float auxElemento;

  while(auxPonteiro->prox !=NULL){
    if(auxPonteiro->valor > (auxPonteiro->prox)->valor){
      auxElemento=(auxPonteiro->prox)->valor;
      (auxPonteiro->prox)->valor=auxPonteiro->valor;
      auxPonteiro->valor=auxElemento;
    }
    auxPonteiro=auxPonteiro->prox;
  }
}

void ordem_Decrescente(plista *lista){
  plista auxPonteiro=*lista;
  float auxElemento;
  while(auxPonteiro->prox !=NULL){
    if(auxPonteiro->valor < (auxPonteiro->prox)->valor){
      auxElemento=(auxPonteiro->prox)->valor;
      (auxPonteiro->prox)->valor=auxPonteiro->valor;
      auxPonteiro->valor=auxElemento;
    }
    auxPonteiro=auxPonteiro->prox;
  }
}

int main()
{
  float elemento,valorA,valorB;
  plista auxCria,auxCriaB;
  int posicao,tamanhoLista;
  char opcao;
  auxCria=cria_lista_Vazia();
  auxCriaB=cria_lista_Vazia();

  do{
    printf("\nMenu de subprogramas:\n");
    printf("b.Indica se a lista e vazia\n");
    printf("c.Escreve lista\n");
    printf("d.Acrescentar um elemento no inicio da lista\n");
    printf("e.Acrescentar um elemento no fim da lista\n");
    printf("f.Remover o elemento do inicio da lista\n");
    printf("g.Remover o elemento do fim da lista\n");
    printf("h.Remover o n-esimo elemento da lista\n");
    printf("i.Remover a primeira ocorrencia de um elemento\n");
    printf("j.Remover todas as ocorrencias de um elemento\n");
    printf("k.Comprimento da lista\n");
    printf("l.Pesquisa um elemento na lista\n");
    printf("m.Constroi uma lista\n");
    printf("n.Limpa lista\n");
    printf("o.Mostra primeiro elemento da lista\n");
    printf("p.Mostra ultimo elemento da lista\n");
    printf("q.Mostra cauda da lista\n");
    printf("r.Juntas listas\n");
    printf("s.Copia uma lista para outra\n");
    printf("t.Troca dois elementos de uma lista\n");
    printf("u.Ordem Crescente de uma lista\n");
    printf("v.Ordem Decrescente de uma lista\n");
    printf("w.Sair\n");
    printf("Escolha a opcao que deseja selecionar:");
    fflush(stdin);
    scanf("%c",&opcao);

    switch (opcao) {
      case 'b':
      verifica_Lista(auxCria);
      if(verifica_Lista(auxCria)==1){
        printf("A lista esta vazia!!\n");
      }else{
        printf("A lista contem informacao!\n");
      }break;
      case 'c':
      escreve_Lista(auxCria);break;
      case 'd':
      printf("Introduza o elemento a inserir:\n");
      scanf("%f",&elemento);
      acrescenta_Inicio(elemento,&auxCria);break;
      case 'e':
      printf("Introduza o elemento a inserir:\n");
      scanf("%f",&elemento);
      acrescenta_Fim(elemento,&auxCria);break;
      case 'f':
      remove_Primeiro(&auxCria);break;
      case 'g':
      remove_Ultimo(&auxCria);break;
      case 'h':
      printf("Indique a posicao do elemento que deseja remover(a comecar do 0):\n");
      scanf("%d",&posicao);
      remove_Elemento(&auxCria,posicao);break;
      case 'k':
      conta_Elementos(auxCria);break;
      case 'i':
      printf("Introduza o elemento o qual pretende remover a sua primeira ocorrencia:\n");
      scanf("%f",&elemento);
      remove_Primeira_Ocorrencia(&auxCria,elemento);break;
      case 'j':
      printf("Introduza o elemento o qual pretende remover todas as suas ocorrencias:\n");
      scanf("%f",&elemento);
      remove_Todas_Ocorrencias(&auxCria,elemento);break;
      case 'l':
      printf("Introduza o elemento pelo qual pretende pesquisar:\n");
      scanf("%f",&elemento);
      plista auxValor=encontra_Elemento(auxCria,elemento);
      printf("Elemento %0.1f encontrado!\n",auxValor->valor);break;
      case 'm':
      printf("Introduza o tamanho da lista:\n");
      scanf("%d",&tamanhoLista);
      cria_Lista_User(tamanhoLista,&auxCria);break;
      case 'n':
      limpa_Lista(&auxCria);
      printf("Lista limpa com sucesso!!!\n");break;
      case 'o':
      mostra_Primeiro(auxCria);break;
      case 'p':
      mostra_Ultimo(auxCria);break;
      case 'q':
      mostra_Cauda(auxCria);break;
      case 'r':
      printf("Introduza o tamanho da lista B:\n");
      scanf("%d",&tamanhoLista);
      cria_Lista_User(tamanhoLista,&auxCriaB);
      junta_Listas(&auxCria,&auxCriaB);
      escreve_Lista(auxCria);break;
      case 's':
      copia_Lista(&auxCria,&auxCriaB);
      escreve_Lista(auxCriaB);break;
      case 't':
      printf("Insira o primeiro elemento que pretende trocar:\n");
      scanf("%f",&valorA);
      printf("Insira o segundo elemento que pretende trocar:\n");
      scanf("%f",&valorB);
      troca_Elementos(&auxCria,valorA,valorB);
      escreve_Lista(auxCria);break;
      case 'u':
      ordem_Crescente(&auxCria);
      escreve_Lista(auxCria);break;
      case 'v':
      ordem_Decrescente(&auxCria);
      escreve_Lista(auxCria);break;
      case 'w':
      printf("Bye bye!\n");break;
      default:
      printf("A opcao e invalida !!");
    }
  }while(opcao !='w');

  return 0;
}
