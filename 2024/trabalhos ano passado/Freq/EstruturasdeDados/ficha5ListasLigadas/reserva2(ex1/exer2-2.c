#include<stdio.h>
#include<stdlib.h>
 /*--------------------------------------------------------------
 --------------------------------------------------------------
 Proprietario: Jorge Miguel dos Santos Martins
 Curso: Licenciatura Sistemas Tecnologias de Informacao
 Disciplina: Programacao II / Estruturas Dados Data:
 Programa/Exercicio: Ficha 5 / Exercicio 2
 --------------------------------------------------------------
 --------------------------------------------------------------
 */
typedef struct lno * plista;
typedef struct lno {
  float valor; // campo valor é um real
  plista prox; // campo prox é um ponteiro para um nó da lista
} listano;

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

void junta_valor(float x, plista * lstAux){
  if(*lstAux==NULL){
    *lstAux = (plista)malloc(sizeof(listano));
    if (*lstAux == NULL){
      perror("ERRO!!! Nao ha memoria disponivel...");
      exit(-1);
    }
    else{
      (*lstAux)->valor = x; //recebe o valor dado pelo utilizador
      (*lstAux)->prox = NULL; // o ponteiro desta estrutura fica com valor null (ficando a ser o ultimo da lista)
    }
  }
  else
    junta_valor(x, & (**lstAux).prox);
}

plista ordemCrescente(plista lst){ //questao u CODIGO QUE ESTAVA A USAR ANTES DE INSERIR UM BUBLESTORT
    plista cont, ant, atual, lst2;
    lst2=crialista();
    int contador=0;
    float x;
    cont=lst;
    ant=lst;
    atual=lst;
    while(cont != NULL){ /* contar quantos elementos tem a lista*/
      contador++;
      cont = cont->prox;
      printf("%d \n", contador);
    }
    if(contador < 2){
      puts("Lista esta vazia ou tem apenas um elemento");
      return lst;
    }
    contador=0;
    while(ant != NULL){
      while(atual != NULL){
        atual=atual->prox;
        if(ant->valor > atual->valor){
          x=atual->valor;
          puts("aqui1");
        }
        else{
          x=ant->valor;
          puts("aquielse");
        }
        puts("aqui2");
      }

      puts("aqui");
      if(contador==0){
        junta_no_ini_lista(x, &lst2);
      }
      else{
        junta_valor(x, &lst2);
      }
      contador++;
      ant=ant->prox;
      atual=lst;
    }

    printf("\n\nAVISO -> TABELA ORDENADA COM SUCESSO!!\n\n");
    return lst2;
  }


 int main(){
    int opcao, verifica;
    float valor;
    plista lst, lstAux;
    lst=crialista(); //simplesmente inicia um ponteiro de lista em NULL
    printf("1 - Inserir valor em lista\n");
    printf("2 - Verificar se a lista está vazia\n");
    printf("3 - Escrever a lista\n");
    do{
      puts("Opcao");
      scanf("%d", &opcao);
      switch (opcao){
        case 1: verifica=listavazia(lst);
                if(verifica==1){ //caso seja vazia inicialmente ele coloca no inicio
                  printf("Indique o valor a inserir: ");
                  scanf("%f", &valor);
                  junta_no_ini_lista(valor, &lst);
                }
                else{ //aqui coloca no que está para ser usado.
                  printf("Indique o valor a inserir: ");
                  scanf("%f", &valor);
                  junta_valor(valor, & (*lst).prox);//subprograma para inserir o valor no pós ultimo da lista
                }

                  break;
        case 2: verifica=listavazia(lst);
                if(verifica==1)
                  printf("Lista está vazia\n");
                else
                  printf("A Lista encontra-se com valores\n");
                  break;
        case 3: escrevelista(lst); flush_in(); break;

        case 9: break;

        default: printf("\nOpcao nao valida volte a tentar\n\n"); break;
      }


    }while(opcao != 9);


 return 0;
 }
