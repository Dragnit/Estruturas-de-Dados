#include<stdio.h>
#include<malloc.h>
 /*--------------------------------------------------------------
 --------------------------------------------------------------
 Proprietario: Jorge Miguel dos Santos Martins
 Curso: Licenciatura Sistemas Tecnologias de Informacao
 Disciplina: Programacao II / Estruturas Dados Data:
 Programa/Exercicio: Ficha 5 / Exercicio 4
 --------------------------------------------------------------
 --------------------------------------------------------------
Neste exercicio apenas apliquei os subprograma já utilizados atrás, apenas compreendi o uso de uma pilha e pus em prática o seu funcionamento.


 */

typedef struct node * plista; //para reutilizar o que ja foi feito antes uso a mesma estrutura na poupança de tempo!
typedef struct node{
  float valor;
  plista prox;
} listano;



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

void junta_no_ini_lista(float x, plista * lst) {
  plista no = (plista)malloc(sizeof(listano));
  if (no == NULL){
    perror("ERRO!!! Nao ha memoria disponivel...");
    exit(-1);
  }
  else{
    no->valor = x; //recebe o valor dado pelo utilizador
    no->prox = * lst; // o ponteiro desta estrutura fica com valor null (ficando a ser o ultimo da lista)
    * lst = no; //o valor apontado por lst passa a ser o valor que o no inicializou a lista
  }
}

plista removerprimeiro(plista lst){
  int v;
  if((v=listavazia(lst))==0){
    lst=lst->prox;
  }
  else
    puts("Lista Vazia");

  return lst;
}

void mostrarPrimeiro(plista lst){
  int v;
  if((v=listavazia(lst)) == 0)
    printf("Valor %.1f \n", lst->valor);
  else
    printf("Lista vazia\n");
}

 int main(){
   int opcao, v;
   float valor;
   plista head;

   head=crialista();

   do{
     puts("1 - Ver se lista está vazia");
     puts("2 - Inserir valores na pilha");
     puts("3 - Last In first Out");
     puts("4 - Mostrar topo da pilha");
     puts("5 - Escrever lista"); //minha propria opção inserir este subprograma porque dá jeito para verificar o que se passa na pilha
     puts("6 - Sair");
     puts("Indique a opcao");
     scanf("%d", &opcao);
     switch (opcao) {
       case 1: v=listavazia(head);
               if(v==0){
                 puts("Lista com elementos");
               }
               else{
                 puts("Lista vazia");
               }
               break;

       case 2: puts("Insira o valor a inserir"); scanf("%f", &valor);
               junta_no_ini_lista(valor, &head);
               break;

       case 3: head=removerprimeiro(head); break;

       case 4: mostrarPrimeiro(head); break;

       case 5: escrevelista(head); break;

       case 6: break;

     }

   }while(opcao != 6);



 return 0;
 }
