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

void remove_Primeiro(plista *lista){
  plista auxPonteiro= *lista;

  *lista=(*lista)->prox;
  free(auxPonteiro);
}

plista limpa_Lista_Iterativo(plista *lista){
  while(*lista!=NULL){
    remove_Primeiro(lista);
  }
}

plista limpa_Lista_Recursivo(plista *lista){
  plista auxPonteiro=*lista;

  while(*lista !=NULL){
    (*lista)=(*lista)->prox;
    free(auxPonteiro);
    limpa_Lista_Recursivo(lista);
  }
}

int main()
{
  char opcao;
  float elemento;
  plista auxCria;
  auxCria=cria_lista_Vazia();

  do{
    printf("\nMenu de subprogramas:\n");
    printf("1.Escreve lista\n");
    printf("2.Acrescentar um elemento no inicio da lista\n");
    printf("3.Limpa lista recursivo\n");
    printf("4.Limpa lista iterativo\n");
    printf("5.Sair\n");
    printf("Escolha a opcao que deseja selecionar:");
    fflush(stdin);
    scanf("%c",&opcao);

    switch(opcao){
      case '1':
      escreve_Lista(auxCria);break;
      case '2':
      printf("Introduza o elemento a inserir:\n");
      scanf("%f",&elemento);
      acrescenta_Inicio(elemento,&auxCria);break;
      case '3':
      limpa_Lista_Recursivo(&auxCria);break;
      case '4':
      limpa_Lista_Iterativo(&auxCria);break;
      case '5':
      printf("bye bye!");break;
      default:
      printf("Opcao invalida!");
    }
  }while(opcao != '5');

  return 0;
}