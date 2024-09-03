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
  else
    puts("Lista Vazia");
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

void removeUltimo(plista lst){
  plista ant, atual;
  int v;
  if((v=listavazia(lst))==0){
    atual = lst;
    while(atual != NULL){
      ant = atual;
      atual = atual->prox;
    }
    ant->prox = NULL; // como o atual é o ultimo da lista então no penultimo passo o nó para NULL
  }
  else
    puts("Lista Vazia");

}

void removerN(plista lst, int n){ //questao h)
  plista ant, atual;
  int v;
  if((v=listavazia(lst))==0){
    n=n-1; // o anterior vai ficar a apontar para o seguinte endereço da ligação à frente
    atual=lst;
    for(int i=0; i<n; ++i){ // ciclo para chegar à lista anterior a que queremos eliminar
      ant=atual; //anterior passa a ter endereço do atual
      atual=atual->prox; // atual do que está a frente
    }
    ant->prox=atual->prox; // a lista anterior fica com o seu campo de apontador com o endereço do campo apontador da lista seguinte, esta fica sem ligação na corrente de nós..
  }
  else
    puts("Lista vazia");
}

void removerPrimeiraOcorrencia(plista lst, float n){ // questao i)
  int v;
  plista ant, atual;
  if((v=listavazia(lst))==0){
    atual=lst;
    if(atual->valor == n){
      atual=atual->prox;
      lst=atual;
    }
    else{
      while(atual != NULL){
        ant=atual;
        atual=atual->prox;
        if(atual->valor == n){ // caso seja igual é só ligar o anterior ao posterior, deixando este valor sem ligação.
          ant->prox = atual->prox;
          break;
        }
      }
      puts("Valor não encontrado");
    }
  }
  else
    puts("Lista encontra-se vazia");
}

void removerOcorrencia(plista lst, float n){ // questao j
  int v;
  plista ant, atual;
  if((v=listavazia(lst))==0){
    atual=lst;
    if(atual->valor == n){
      atual=atual->prox;
      lst=atual;
    }
    while(atual != NULL){
      ant=atual;
      atual=atual->prox;
      if(atual->valor == n){ // caso seja igual é só ligar o anterior ao posterior, deixando este valor sem ligação.
        ant->prox = atual->prox;
      }
    }
  }
  else
    puts("Lista encontra-se vazia");
}

void tamanhoLista(plista lst){ // questao k

  int contador=0, v;
  if((v=listavazia(lst))==0){
    while(lst != NULL){
      lst=lst->prox;
      contador++;
    }
    printf("O tamanho da lista é %d \n\n", contador);
  }
  else
    puts("A lista está vazia");
}

plista devolvePonteiroValor(plista lst, float n){ //questao l
  int contador=0, v;
  plista aux=NULL;
  if((v=listavazia(lst))==0){
    while(lst != NULL){
      if(lst->valor == n)
        return lst;
      lst=lst->prox;
    }
    if(lst == NULL){
      puts("Valor não encontrado");
      return lst;
    }
  }
  else
    return aux;
}

plista limparLista(plista lst){ //questao n
  plista temp_ptr;
    while (listavazia(lst) == 0) {
        temp_ptr = lst;
        lst = lst->prox;
        free (temp_ptr); // a cada vez que o lst para para o proximo o anterior é libertado...
    }
    puts("Lista eliminada");
    return NULL; //retorna null para o lst que é o ponteiro ao qual aponta para o inicio da lista.
}

void mostrarPrimeiro(plista lst){ //questao o
  int v;
  if((v=listavazia(lst)) == 0)
    printf("Valor %d \n");
  else
    printf("Lista vazia\n");
}

void mostrarUtimo(plista lst){ //questao p
  int v;
  plista ant, atual;
  atual = lst;
  if((v=listavazia(lst)) == 0){
    while(atual != NULL){
      ant = atual;
      atual=atual->prox;
    }
    printf("%f \n", ant->valor);
  }
}

void mostraCauda(plista lst){ //questao q
  int v;
  plista ant, atual;
  if((v=listavazia(lst)) == 0){
    atual = lst->prox;
    while(atual != NULL){
      ant = atual;
      atual=atual->prox;
      printf(" %f ", ant->valor);
    }
  }
}

plista copiarDuaslistas(plista lst, plista lst2){
  plista ant, atual, novo;
  int v;
  if((v=listavazia(lst))==0){
    ant=NULL;
    atual=lst; //para dar os valores do primeiro elemento da lista
    novo = (plista) malloc(sizeof(listano));
    novo->valor = atual->valor;
    novo->prox = atual->prox;
    lst2 = novo; //quem fica a apontar para a lista será lst2
    atual = lst2;
    lst=lst->prox;
    while(lst != NULL){ // enquanto não percorrer a lista ligada do lst o ciclo continua a copiar para lst2
      novo = (plista) malloc(sizeof(listano));
      novo->valor = lst->valor;
      ant=atual;
      atual=atual->prox;
      novo->prox = ant;


    }


  }



}

 int main(){
    int opcao, verifica;
    float valor=0;
    plista lst, auxiliar, lst2;
    int n=0;
    lst=crialista(); //simplesmente inicia um ponteiro de lista em NULL
    do{
    printf("\n1 - Inserir valor no inicio da lista\n");
    printf("2 - Inserir valor no fim da lista\n");
    printf("3 - Verificar se a lista esta vazia\n");
    printf("4 - Escrever a lista\n");
    printf("5 - Remover primeiro da lista\n");
    printf("6 - Remover ultimo da lista\n");
    printf("7 - Remover o n-esimo elemento de uma lista\n");
    printf("8 - Remover a primeira ocorrencia de um valor na lista\n");
    printf("9 - Remover todas as ocorrências do elemento x de uma lista\n");
    printf("10 - Tamanho da lista\n");
    printf("11 - Procurar um valor x numa lista devolvendo um ponteiro para este elemento\n");
    printf("12 - Ler valores e construir lista\n"); //duvida aqui no que realmene significa
    printf("13 - Limpar uma lista \n");
    printf("14 - Mostrar o primeiro elemento de uma lista \n");
    printf("15 - Mostrar o ultimo elemento de uma lista\n", );
    printf("16 - Mostrar a cauda (todos os elementos excepto o primeiro) de uma lista\n");
    printf("17 - Copia uma lista para outra\n");
    printf("20 - Sair\n");

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
        case 4: escrevelista(lst); flush_in(); break;

        case 5: lst=removerprimeiro(lst); break;// ele fica a apontar para o segundo e assim indica que o primeiro deixou se ser acessivel.

        case 6: removeUltimo(lst); break; // remover o que está na ponta da cauda da lista..

        case 7: puts("Insira o numero da lista a eliminar"); scanf("%d", &n);
                removerN(lst, n); break;

        case 8: puts("Insira o elemento a eliminar na primeira ocorrencia"); scanf("%f", &valor);
                removerPrimeiraOcorrencia(lst, valor); break;

        case 9: puts("Insira a ocorrencia a apagar da lista"); scanf("%f", &valor);
                removerOcorrencia(lst, valor); break;

        case 10: tamanhoLista(lst);

        case 11: puts("Indique o valor a procurar para devolver"); scanf("%f", &valor);
                 auxiliar=devolvePonteiroValor(lst, valor);
                 if(auxiliar != NULL){
                   printf("Atraves do ponteiro recebido apontamos para a lista mostrando o seu valor que e %f \n", auxiliar->valor);
                 }
                 else{
                   puts("Erro, ou valor nao existente na lista ou lista simplesmente vazia");
                 }break;

        case 12: break;

        case 13: lst=limparLista(lst); break;

        case 14: mostrarPrimeiro(lst); break;

        case 15: mostrarUtimo(lst); break;

        case 16: mostraCauda(lst); break;

        case 17: lst2=crialista(); lst2 = copiarDuaslistas(lst, lst2); break;


        case 20: break;

        default: printf("\nOpcao nao valida volte a tentar\n\n"); break;
      }


    }while(opcao != 20);


 return 0;
 }
