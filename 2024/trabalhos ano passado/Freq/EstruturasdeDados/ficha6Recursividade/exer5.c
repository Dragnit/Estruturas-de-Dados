#include<stdio.h>
#include<stdlib.h>
#include<malloc.h> /*--------------------------------------------------------------
 --------------------------------------------------------------
 Proprietario: Jorge Miguel dos Santos Martins
 Curso: Licenciatura Sistemas Tecnologias de Informacao
 Disciplina: Programacao II / Estruturas Dados Data:
 Programa/Exercicio: Ficha 6 / Exercicio 5
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

 void junta_no_ini_lista(float x, plista * lst) { // aliena d)
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

 void junta_valor(float x, plista * lstAux){ //inserir no fim da fila questao e)
   plista atual, ant, novo; //inicio 3 ponteiros
   int v;
   if((v=listavazia(*lstAux))==0){
     novo = (plista)malloc(sizeof(listano)); // o novo para alocar uma estrutura do tipo listano no determinado local de memoria

     novo->valor= x;
     novo->prox = NULL; // porque ele vai ficar no fim da fila..

     ant=NULL;
     atual=*lstAux; //o ponteiro atual começa no inicio da fila a apontar e vai seguindo enquanto o ant vai atrás deste

     while(atual != NULL){ //enquanto não chegar à lista que está no fim ele continua
           ant = atual; //a atual passa a ser a lista anterior(damos o valor da anterior)
           atual = atual->prox; // e aqui é quando se dá o proximo passo para a proxima lista
       }
           //*lstAux = novo; caso no main decidir enviar o & (**lst).prox
           ant->prox = novo;
     }
   else{
     junta_no_ini_lista(x, &(*lstAux));
   }

 }

 plista removerprimeiro(plista lst){ // questao f)
   int v;
   if((v=listavazia(lst))==0){
     lst=lst->prox;
   }
   else
     puts("Lista Vazia");

   return lst;
 }

 void removeUltimo(plista *lst){
   plista ant, atual;
   int v;
   if((v=listavazia(*lst))==0){
     atual = *lst;
     if(atual->prox == NULL){
       *lst=NULL;
     }
     else{
       while(atual != NULL){
         ant = atual;
         atual = atual->prox;
       }
       *lst=ant;
       (*lst)->prox = NULL; // como o atual é o ultimo da lista então no penultimo passo o nó para NULL
     }
   }
   else
     puts("Lista Vazia");

 }

 plista limparLista(plista lst){ //interativa
   plista ptr;
     while (lst != NULL) {
         ptr = lst;
         lst = lst->prox;
         free (ptr); // a cada vez que o lst para para o proximo o anterior é libertado...
     }
     puts("Lista eliminada");
     return NULL; //retorna null para o lst que é o ponteiro ao qual aponta para o inicio da lista.
 }

 plista limparListaRecursiva(plista lst){
   plista ptr;
   ptr=lst;
   lst=lst->prox;
   free(ptr);
   if(lst != NULL){
     lst=limparListaRecursiva(lst);
   }
   else{
     return lst;
   }

 }


  int main(){
     int opcao, verifica, v;
     float valor=0;
     plista lst;
     lst=crialista(); //simplesmente inicia um ponteiro de lista em NULL
     do{
     printf("\n1 - Inserir valor no inicio da lista\n");
     printf("2 - Inserir valor no fim da lista\n");
     printf("3 - Verificar se a lista esta vazia\n");
     printf("4 - Escrever a lista\n");
     printf("5 - Remover primeiro da lista\n");
     printf("6 - Remover ultimo da lista\n");
     printf("7 - Limpar uma lista interativamente\n");
     printf("8 - Limpar uma lista recursivamente\n");
     printf("9 - Sair\n");

       puts("Opcao");
       scanf("%d", &opcao);
       puts("\n");
       switch (opcao){
         case 1:   printf("Indique o valor a inserir: ");
                   scanf("%f", &valor);
                   junta_no_ini_lista(valor, &lst); break;

         case 2:   printf("Indique o valor a inserir: ");
                   scanf("%f", &valor);
                   junta_valor(valor, &lst);//subprograma para inserir o valor no pós ultimo da lista
                   break;

         case 3: verifica=listavazia(lst);
                 if(verifica==1)
                   printf("Lista esta vazia\n");
                 else
                   printf("A Lista encontra-se com valores\n");
                   break;

         case 4: escrevelista(lst);
                 break;

         case 5: lst=removerprimeiro(lst); break;// ele fica a apontar para o segundo e assim indica que o primeiro deixou se ser acessivel.

         case 6: removeUltimo(&lst); break; // remover o que está na ponta da cauda da lista..

         case 7: lst=limparLista(lst); break;

         case 8: lst=limparListaRecursiva(lst); break;

         case 9: break;

         default: printf("\nOpcao nao valida volte a tentar\n\n"); break;
       }


     }while(opcao != 9);


  return 0;
  }
