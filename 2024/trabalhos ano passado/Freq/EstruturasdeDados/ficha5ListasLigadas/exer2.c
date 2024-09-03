#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
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
  else{
    junta_no_ini_lista(x, &(*lstAux)); // na minha interpretação juntar no fim de uma fila que não existe é o mesmo que o inserir em primeiro, então caso a lista esteja vazia eu chamo a função de inserir no inicio..
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

void removerN(plista *lst, int n){ //questao h)
  plista ant, atual;
  int v;
  if((v=listavazia(*lst))==0){
    n=n-1; // o anterior vai ficar a apontar para o seguinte endereço da ligação à frente
    atual=*lst;
    for(int i=0; i<n; ++i){ // ciclo para chegar à lista anterior a que queremos eliminar
      ant=atual; //anterior passa a ter endereço do atual
      atual=atual->prox; // atual do que está a frente
    }
    *lst=ant;
    (*lst)->prox=atual->prox; // a lista anterior fica com o seu campo de apontador com o endereço do campo apontador da lista seguinte, esta fica sem ligação na corrente de nós..
  }
  else
    puts("Lista vazia");
}

void removerPrimeiraOcorrencia(plista *lst, float n){ // questao i)
  int v;
  plista ant, atual;
  if((v=listavazia(*lst))==0){
    atual=*lst;
    if(atual->valor == n){
      atual=atual->prox;
      *lst=atual;
    }
    else{
      while(atual != NULL){
        ant=atual;
        atual=atual->prox;
        if(atual->valor == n){ // caso seja igual é só ligar o anterior ao posterior, deixando este valor sem ligação.
          *lst=ant;
          (*lst)->prox = atual->prox;
          break;
        }
      }
      puts("Valor não encontrado");
    }
  }
  else
    puts("Lista encontra-se vazia");
}

void removerOcorrencia(plista *lst, float n){ // questao j
  int v;
  plista ant, atual;
  if((v=listavazia(*lst))==0){
    atual=*lst;
    while(atual->valor == n && atual != NULL){
      atual=atual->prox;
      *lst=atual;
      if(*lst == NULL){ // caso toda a lista tenha valores iguais adaptei apra que fizesse primeiro um ciclo em vez de apenas uma condição
        break;
      }
    }
    while(atual != NULL){
      ant=atual;
      atual=atual->prox;
      if(atual->valor == n){ // caso seja igual é só ligar o anterior ao posterior, deixando este valor sem ligação.
        ant->prox = atual->prox;
        atual=atual->prox;
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
  flush_in();
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
  plista ptr;
    while (listavazia(lst) == 0) {
        ptr = lst;
        lst = lst->prox;
        free (ptr); // a cada vez que o lst para para o proximo o anterior é libertado...
    }
    puts("Lista eliminada");
    return NULL; //retorna null para o lst que é o ponteiro ao qual aponta para o inicio da lista.
}

void mostrarPrimeiro(plista lst){ //questao o
  int v;
  if((v=listavazia(lst)) == 0)
    printf("Valor %f \n", lst->valor);
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
    junta_no_ini_lista(lst->valor, &lst2); //introduzir o primeiro elemento da lista

    lst=lst->prox; //deixar lst já no proximo elemento para que seja copiado
    while(lst != NULL){
      junta_valor(lst->valor, &lst2);
      lst=lst->prox;
    }
    puts("Lista copiada com sucesso!");
    return lst2;
  }
  else{
    puts("A Lista está vazia");
    return lst2;
  }
} //questao s

plista construirLista(plista lst, int n){ //questão m
  int v;
  float valor;
  plista ant, atual;
  if((v=listavazia(lst))!=0){
    puts("Insira o valor a por na lista"); scanf("%f", &valor);
    junta_no_ini_lista(valor, &lst);
    atual=lst;
    n=n-1;
    for(int i=0; i<n; ++i){
      puts("Insira o valor a por na lista"); scanf("%f", &valor);
      junta_valor(valor, &atual);
      atual=atual->prox; // fica a apontar para o proximo que já tem ligação e foi acabado de inserir.
    }
    return lst;
  }
  else{
    atual=lst;
    ant=NULL;
    while(atual != NULL){
      ant=atual;
      atual=atual->prox; // se este for null o anterior esta na lista que tem o ponteiro no null que é o fim ou cauda da lista.
    }
    for(int i=0; i<n; ++i){
      puts("Insira o valor a por na lista"); scanf("%f", &valor);
      junta_valor(valor, &ant);
      ant=ant->prox; // fica a apontar para o proximo que já tem ligação e foi acabado de inserir.
    }
    return lst;
    }
}

void juntarDuasListas(plista * lst, plista * lst2){ //questão r
  int v;
  if((v=listavazia(*lst))==0){
    plista ant, atual;
    ant=NULL;
    atual=*lst; //não necessito de usar o atual aqui mas uso para ser mais facil perceber o que se passa no codigo.

    while(atual != NULL){
      ant=atual;
      atual=atual->prox;
    }
    ant->prox = *lst2;
  }
  else
    *lst=*lst2;
}

plista trocaDois(plista lst, int primeiro, int segundo){ //questão t

  plista ant1, atual1, ant2, atual2, auxiliar;

    atual1=lst;
    atual2=lst;
    ant1=lst;
    ant2=lst;

    for(int i=1; i<primeiro; ++i){
      ant1=atual1; //fica com o local que está a apontar anteriormente para aquele que queremos trocar
      atual1=atual1->prox;
      if(atual1 == NULL){ //o atual está apontar para o local que queremos trocar
        puts("Elemento não existe na lista");
        return lst;
      }
    }

    for(int i=1; i<segundo; ++i){
      ant2=atual2; //fica com o local que está a apontar anteriormente para aquele que queremos trocar
      atual2=atual2->prox;
      if(atual2 == NULL){ //o atual está apontar para o local que queremos trocar
        puts("Elemento não existe na lista");
        return lst;
      }
    }

    if(atual1==lst){ //caso se escolha o extremo esquerdo da lista (primeiro elemento)
      lst=atual2;
      auxiliar=atual2->prox;
      ant2->prox=atual1;
      atual2->prox=atual1->prox;
      atual1->prox=auxiliar;
    }
    else{
      if(atual2==lst){ //caso se escolha o extremo direito da lista
        lst=atual1;
        ant1->prox=atual2;
        auxiliar=atual1->prox; //porque aqui o atual 1 é o que está no extremo direito da lista..
        atual1->prox=atual2->prox;
        atual2->prox=auxiliar;
      }
      else{

        ant1->prox = atual2; //o que esta atras do primeiro elemento aponta para o segundo na linha de nos dando o lugar a ele

        ant2->prox = atual1; // o que está atrás do segundo elemento aponta para o que era o primeiro que o utilizador deu para trocar
        auxiliar = atual2->prox; //esta apenas tomar o valor para depois se fazer a triagulação de ponteiros para trocar para onde apontam..

        atual2->prox = atual1->prox;

        atual1->prox = auxiliar;
    }
  }
    return lst;

}

void trocar(plista *a, plista *b){ //como anteriormente não criei uma função de troca de valores mas sim elementos fiz este pequeno subprograma para ordenar.

    float aux = (*a)->valor;
    (*a)->valor = (*b)->valor;
    (*b)->valor = aux;
}

void ordemCrescente(plista *lst){
    int trocado, v;
    plista atual;
    if((v=listavazia(*lst))==0){
    do{
        trocado = 0;
        atual = *lst;

        while (atual->prox != NULL){
            if(atual->valor > atual->prox->valor){
                trocar(&atual, &atual->prox);
                trocado = 1;
            }
            atual = atual->prox;
        }
    }while(trocado != 0);
    puts("\n\nLista ordenada por ordem crescente");
    }
    else
      puts("Lista Vazia");
}

void ordemDecrescente(plista *lst){
  int trocado, i, v;
  plista atual;
  if((v=listavazia(*lst))==0){
  do{
      trocado = 0; // caso esteja ordenada então sai do do while..
      atual = *lst;

      while (atual->prox != NULL){
          if(atual->valor < atual->prox->valor){
              trocar(&atual, &atual->prox);
              trocado = 1; // como entrou não está completamente ordenada então tem de ser verificada de novo..
          }
          atual = atual->prox;
      }
  }while(trocado != 0);
  puts("\n\nLista ordenada por ordem descrescente");
  }
  else
    puts("Lista Vazia");
}

 int main(){
    int opcao, verifica, v, primeiro, segundo, aux;
    float valor=0;
    plista lst, auxiliar, lst2;
    int n=0;
    lst=crialista(); //simplesmente inicia um ponteiro de lista em NULL
    lst2=crialista();
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
    printf("15 - Mostrar o ultimo elemento de uma lista\n");
    printf("16 - Mostrar a cauda (todos os elementos excepto o primeiro) de uma lista\n");
    printf("17 - Copia uma lista para outra\n"); //faço primeiro a copia para depois as conectar.
    printf("18 - Juntar duas listas numa só\n");
    puts("19 - Trocar dois valores");
    puts("20 - Ordenar por Ordem Crescente");
    puts("21 - Ordenar por Ordem ordemDescrente");
    printf("22 - Sair\n");

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

        case 4: printf("Quer que imprima a lista 1 ou 2\n"); scanf("%d", &v);
                if(v==1)
                  escrevelista(lst);
                if(v==2)
                  escrevelista(lst2);
                else
                  flush_in(); break;

        case 5: lst=removerprimeiro(lst); break;// ele fica a apontar para o segundo e assim indica que o primeiro deixou se ser acessivel.

        case 6: removeUltimo(&lst); break; // remover o que está na ponta da cauda da lista..

        case 7: puts("Insira o numero da lista a eliminar"); scanf("%d", &n);
                removerN(&lst, n); break;

        case 8: puts("Insira o elemento a eliminar na primeira ocorrencia"); scanf("%f", &valor);
                removerPrimeiraOcorrencia(&lst, valor); break;

        case 9: puts("Insira a ocorrencia a apagar da lista"); scanf("%f", &valor);
                removerOcorrencia(&lst, valor); break;

        case 10: tamanhoLista(lst); break;

        case 11: puts("Indique o valor a procurar para devolver"); scanf("%f", &valor);
                 auxiliar=devolvePonteiroValor(lst, valor);
                 if(auxiliar != NULL){
                   printf("Atraves do ponteiro recebido apontamos para a lista mostrando o seu valor que e %f \n", auxiliar->valor);
                 }
                 else{
                   puts("Erro, ou valor nao existente na lista ou lista simplesmente vazia");
                 }break;

        case 12: puts("Indique quantos elementos vai inserir para a lista 2"); scanf("%d", &n);
                 lst2=construirLista(lst2, n); break;

        case 13: lst=limparLista(lst); break;

        case 14: mostrarPrimeiro(lst); break;

        case 15: mostrarUtimo(lst); break;

        case 16: mostraCauda(lst); break;

        case 17: puts("Para copiar a lista 1 para 2 - Selecione 1");
                 puts("Para copiar a lista 2 para 1 - Selecione 2");
                 scanf("%d", &aux);

                 if(aux==1){
                   lst2=limparLista(lst2); //como vai tomar valores assim limpo-a antes
                   lst2 = copiarDuaslistas(lst, lst2);
                 }
                 else{
                   if(aux==2){
                     lst = limparLista(lst);
                     lst = copiarDuaslistas(lst2, lst);
                   }
                   else{
                     puts("Opcao nao aceite");
                   }
                 }
                 break;

        case 18: juntarDuasListas(&lst, &lst2); break;

        case 19: //tentei usar o troca valores para usar o buble sort mas depois topei que não era possivel
        if((v=listavazia(lst))==0){
          puts("Insira o primeiro elemento a trocar"); scanf("%d", &primeiro); //são float porque assim posso usar esta função no bubble sort
          do{
            puts("AVISO: Não insira os mesmos elementos a trocar");
            puts("Insira o primeiro elemento a trocar"); scanf("%d", &segundo);
          }while(segundo == primeiro);
          lst=trocaDois(lst, primeiro, segundo);
        }
        else{
          puts("Lista vazia");
        }
        break;

        case 20: ordemCrescente(&lst); break;

        case 21: ordemDecrescente(&lst); break;

        case 22: break;

        default: printf("\nOpcao nao valida volte a tentar\n\n"); break;
      }


    }while(opcao != 22);


 return 0;
 }
