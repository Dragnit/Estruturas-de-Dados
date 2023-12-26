#include <stdio.h>
#include <stdlib.h>

typedef struct lno *plista;

typedef struct lno{
  float valor;
  plista prox;
}listano;

plista cria_lista_Vazia(plista tab[2]){
  tab[0]=NULL;
  tab[1]=NULL;
}

int verifica_Lista(plista tab[2]){
  if(tab[0]==NULL && tab[1]==NULL){
    return 1;
  }else{
    return 0;
  }
}

void escreve_Lista(plista tab[2]){
  plista auxPonteiro=tab[0];

  if(verifica_Lista(tab)){
    printf("A lista esta vazia!!\n");
  }else{
    printf("[");
    while(auxPonteiro!=NULL){
      printf("%0.1f,",auxPonteiro->valor);
      auxPonteiro=auxPonteiro->prox;
    }
    printf("\b ] \n");
  }
}

void acrescenta_Fim(float elemento,plista tab[2]){
  plista no = (plista)malloc(sizeof(listano));
  plista auxPonteiro= tab[0];

  if(no==NULL){
    printf("Erro!! Memoria indisponivel....\n");
  }else{
    no->valor=elemento;
    no->prox=NULL;
      tab[1]=no;
      if(tab[0]!=NULL){
        while(auxPonteiro->prox != NULL){
          auxPonteiro=auxPonteiro->prox;
        }
        auxPonteiro->prox=no;
      }else{
        tab[0]=no;
      }
  }
}

void remove_Ultimo(plista tab[2]){
  plista auxPonteiro=tab[0];
  plista auxRemove=NULL;

  if(verifica_Lista(tab)){
    printf("A lista esta vazia!!\n");
  }else{
    while(auxPonteiro->prox!=NULL){
      auxRemove=auxPonteiro;
      auxPonteiro=auxPonteiro->prox;
    }
    free(auxPonteiro);

    if(auxRemove!=NULL){
      auxRemove->prox=NULL;
    }else{
      tab[0]=NULL;
      tab[1]=NULL;
    }
    tab[1]=auxRemove;
  }
}

void remove_Todas_Ocorrencias(plista tab[2],float elemento){
  plista auxPonteiro=tab[0];
  plista auxRemove=NULL;

  while(auxPonteiro!=NULL){
    if(auxPonteiro->prox==NULL){
      tab[1]=auxPonteiro;
    }
    if(auxPonteiro->valor == elemento){
      if(tab[0]==auxPonteiro){
        tab[0]=tab[0]->prox;
        free(auxPonteiro);
        auxPonteiro=tab[0];
      }else{
        auxRemove->prox=auxPonteiro->prox;
        free(auxPonteiro);
        if(auxRemove!=NULL){
          if(auxRemove->prox==NULL){
            tab[1]=auxRemove;
          }
          auxPonteiro=auxRemove->prox;
        }else{
          auxPonteiro=NULL;
        }
      }
    }else{
      auxRemove=auxPonteiro;
      auxPonteiro=auxPonteiro->prox;
    }
  }
}

plista limpa_Lista(plista tab[2]){
  while(tab[0]!=NULL){
    remove_Ultimo(tab);
  }
}

void mostra_Ultimo(plista tab[2]){
  while(tab[1]->prox!=NULL){
    tab[1]=tab[1]->prox;
  }
  printf("Ultimo elemento da lista:%0.1f\n",tab[1]->valor);
}

void troca_Elementos(plista tab[2],float valorA,float valorB){
  plista auxPonteiro=tab[0];
  plista auxPonteiro2=tab[0];
  float auxNumero;
  while(auxPonteiro!=NULL   && (auxPonteiro->valor)!=valorA){
    auxPonteiro=auxPonteiro->prox;
  }

  while(auxPonteiro2!=NULL && (auxPonteiro2->valor)!=valorB){
    auxPonteiro2=auxPonteiro2->prox;
  }
  if(auxPonteiro!=NULL && auxPonteiro2!=NULL){
    auxNumero=auxPonteiro->valor;
    auxPonteiro->valor=auxPonteiro2->valor;
    auxPonteiro2->valor=auxNumero;
  }
}

int main()
{
char auxVerifica,opcao;
float elemento,valorA,valorB;
plista auxCria;
plista tab[2];
plista head=NULL,tail=NULL;
tab[0]=head;
tab[1]=tail;
auxCria=cria_lista_Vazia(tab);

do{
  printf("\nMenu de subprogramas:\n");
  printf("b.Indica se a lista e vazia\n");
  printf("c.Apresenta lista\n");
  printf("e.Acrescentar um elemento no fim da lista\n");
  printf("g.Remover o elemento do fim da lista\n");
  printf("j.Remover todas as ocorrencias de um elemento\n");
  printf("n.Limpa lista\n");
  printf("p.Mostra ultimo elemento da lista\n");
  printf("t.Troca dois elementos de uma lista\n");
  printf("w.Sair\n");
  printf("Escolha a opcao que deseja selecionar:");
  fflush(stdin);
  scanf("%c",&opcao);

  switch(opcao){
    case 'b':
      auxVerifica=verifica_Lista(tab);
      if(auxVerifica==1){
        printf("A lista e vazia!!");
      }else{
        printf("A lista contem informacao!!");
      }break;
    case 'c':
    escreve_Lista(tab);break;
    case 'e':
    printf("Introduza o elemento a inserir:\n");
    scanf("%f",&elemento);
    acrescenta_Fim(elemento,tab);break;
    case 'g':
    remove_Ultimo(tab);break;
    case 'j':
    printf("Introduza o elemento o qual pretende remover todas as suas ocorrencias:\n");
    scanf("%f",&elemento);
    remove_Todas_Ocorrencias(tab,elemento);break;
    case 'n':
    limpa_Lista(tab);break;
    case 'p':
    mostra_Ultimo(tab);break;
    case 't':
    printf("Insira o primeiro elemento que pretende trocar:\n");
    scanf("%f",&valorA);
    printf("Insira o segundo elemento que pretende trocar:\n");
    scanf("%f",&valorB);
    troca_Elementos(tab,valorA,valorB);break;
    case 'w':
    printf("Bye bye!");break;
    default:
    printf("Opcao Invalida!");
  }
}while(opcao !='w');

	return 0;
}