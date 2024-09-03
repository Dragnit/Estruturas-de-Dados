#include<stdio.h>
#include<malloc.h>
 /*--------------------------------------------------------------
 --------------------------------------------------------------
 Proprietario: Jorge Miguel dos Santos Martins
 Curso: Licenciatura Sistemas Tecnologias de Informacao
 Disciplina: Programacao II / Estruturas Dados Data:
 Programa/Exercicio: Ficha 5 / Exercicio 3
 --------------------------------------------------------------
 --------------------------------------------------------------
 */
 typedef struct node * plista;
 typedef struct node {
   float valor; // campo valor é um real
   plista prox; // campo prox é um ponteiro para um nó da lista
 } listano;

struct pointers{
  plista head;
  plista tail;
};typedef struct pointers point;

void flush_in(){ // codigo para limpeza de buffer do teclado..
   int ch;
   while( (ch = fgetc(stdin)) != EOF && ch != '\n' ){}
   return;
 }

plista crialista() {
   plista p = NULL;
   return p;
 }

 int listavazia(plista lst) {
    if (lst == NULL)
      return 1;
    else
      return 0;
  }

  void escrevelista(plista lst){
    if(listavazia(lst))
      printf("a lista e vazia!!!\n");
    else{
      printf("[");
      do{
        printf(" %.1f,",lst->valor);
        lst = lst->prox;
      }while(lst != NULL);
      printf("\b ]\n");
    }
  }

  void junta_valor(float x, plista * head, plista *tail){ //inserir no fim da fila
    plista novo; //inicio
    int v;
    if((v=listavazia(*head))==0){
      novo = (plista)malloc(sizeof(listano)); // o novo para alocar uma estrutura do tipo listano no determinado local de memoria

      novo->valor= x;
      novo->prox = NULL; // porque ele vai ficar no fim da fila..

      (*tail)->prox = novo;
      *tail = novo;

      }
    else{ //usei o que a professora tinha usado no subprograma de inserir no inicio
      plista no = (plista)malloc(sizeof(listano));
      if (no == NULL){
        perror("ERRO!!! Nao ha memoria disponivel...");
        exit(-1);
      }
      else{
        no->valor = x; //recebe o valor dado pelo utilizador
        no->prox = * head; // o ponteiro desta estrutura fica com valor null (ficando a ser o ultimo da lista)
        * head = no; //o valor apontado por lst passa a ser o valor que o no inicializou a lista
        * tail = *head;
      }
    }

  }

  void removeUltimo(plista *head, plista * tail){
    plista ant, atual;
    int v;
    if((v=listavazia(*head))==0){
      atual = *head;
      if(atual->prox == NULL){
        *head=NULL;
        *tail=NULL;
      }
      else{
        while(atual->prox != NULL){
          ant = atual;
          atual = atual->prox;
        }
        *tail=ant;
        (*tail)->prox = NULL; // como o atual é o ultimo da lista então no penultimo passo o nó para NULL
      }
    }
    else
      puts("Lista Vazia");

  }

  void removerOcorrencia(plista *head, plista *tail ,float n){ // questao j
    int v;
    plista ant, atual;
    if((v=listavazia(*head))==0){
      atual=*head;

      while(atual->valor == n && atual != NULL){
        puts("repete");
        atual=atual->prox;
        *head=atual;
          if(*head == NULL){
            *tail=NULL;

            break;
          }
      }
    
        while(atual != NULL){
          ant=atual;
          atual=atual->prox;
          if(atual->valor == n){ // caso seja igual é só ligar o anterior ao posterior, deixando este valor sem ligação.
            if(atual->prox == NULL){
              *tail = ant;
              ant->prox = atual->prox;
              atual=atual->prox;

            }
            else{
              //*head=ant;
              ant->prox = atual->prox;
              atual=atual->prox;
            }
          }
        }
    }
    else
      puts("Lista encontra-se vazia");
  }

  plista limparLista(plista lst){ //questao n
    plista ptr;
      while (listavazia(lst) == 0) {
          ptr = lst;
          lst = lst->prox;
          free (ptr); // a cada vez que o lst para para o proximo o anterior é libertado...
      }
      puts("Lista eliminada");
      return NULL; //retorna null para o lst que é o ponteiro ao qual aponta para o inicio da lista.
  }

  void mostrarUtimo(plista lst){ //questao p
    printf("%f", lst->valor);
  }

  void trocar(plista *a, plista *b){ //como anteriormente não criei uma função de troca de valores mas sim elementos fiz este pequeno subprograma para ordenar.

      float aux = (*a)->valor;
      (*a)->valor = (*b)->valor;
      (*b)->valor = aux;
  }

  void procura(plista *head, float a, float b){
    plista procura1, procura2;

    procura1=*head;
    procura2=*head;

    while(procura1 != NULL){
      if(procura1->valor == a){
        break;
      }
      else
        procura1=procura1->prox;
    }
    if(procura1 == NULL){
      puts("Valor não encontrado na lista");
      return;
    }
    while(procura2 != NULL){
      if(procura2->valor == b){
        break;
      }
      else
        procura2=procura2->prox;
    }
    if(procura2==NULL){
      puts("Valor não encontrado na lista");
      return;
    }

    trocar(&procura1, &procura2);

  }

 int main(){
   int opcao, v;
   float valor, procura1, procura2;
   point ptr;
   ptr.head=crialista();
   ptr.tail=crialista();

   do{
     puts("1 - Ver se lista está vazia");
     puts("2 - Inserir valores na lista");
     puts("3 - Remover ultimo valor");
     puts("4 - Remover ocorrencia");
     puts("5 - Limpar lista");
     puts("6 - Mostrar ultimo valor");
     puts("7 - Trocar dois valores");
     puts("8 - Escrever lista");
     puts("9 - Sair");
     puts("Indique a opcao");
     scanf("%d", &opcao);
     switch (opcao) {
       case 1: v=listavazia((ptr.head));
               if(v==0){
                 puts("Lista com elementos");
               }
               else{
                 puts("Lista vazia");
               }
               break;
       case 2: puts("Escreva o valor a inserir ");scanf("%f", &valor);
              junta_valor(valor, &ptr.head, &ptr.tail);
              break;

       case 3: removeUltimo(&ptr.head, &ptr.tail); break;

       case 4: puts("Indique o valor que quer remover"); scanf("%f", &valor);
               removerOcorrencia(&ptr.head, &ptr.tail, valor); break;

       case 5: ptr.head=limparLista(ptr.head); ptr.tail=crialista(); break;

       case 6: mostrarUtimo(ptr.tail); break;

       case 7: puts("Indique o primeiro valor a trocar"); scanf("%f", &procura1);
               puts("Indique o segundo valor a trocar"); scanf("%f", &procura2);
               procura(&ptr.head, procura1, procura2);
               break;

       case 8:
              escrevelista(ptr.head); break;

       case 9: break;

     }




   }while(opcao != 9);



 return 0;
 }
