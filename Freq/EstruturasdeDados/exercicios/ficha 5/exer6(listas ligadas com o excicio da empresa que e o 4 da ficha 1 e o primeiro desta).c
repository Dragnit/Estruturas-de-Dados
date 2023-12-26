#include<stdio.h>
#include<string.h>
#include<ctype.h> //uso esta biblioteca por causa do tolower
#include<malloc.h>
 /*--------------------------------------------------------------
 --------------------------------------------------------------
 Proprietario: Jorge Miguel dos Santos Martins
 Curso: Licenciatura Sistemas Tecnologias de Informacao
 Disciplina: Programacao II / Estruturas Dados Data:
 Programa/Exercicio: Ficha 5 / Exercicio 6
 --------------------------------------------------------------
 --------------------------------------------------------------
 */
 typedef struct dados_funcionario * list;
 typedef struct dados_funcionario{ // estrutura que tem os campos necessários de cada funcionario
   int numero;
   char nome[60];
   char tarefa[50];
   float salario;
   list prox;
 } funcionario;

 void flush_in(){ // codigo para limpeza de buffer do teclado..
    int ch;
    while( (ch = fgetc(stdin)) != EOF && ch != '\n' ){}
    return;
  }

  list crialista() {
     list p = NULL;
     return p;
   }

  int listavazia(list lst) {
      if (lst == NULL)
        return 1;
      else
        return 0;
    }

 //inserirDados

  int verifica(list lst, int n){
    while(lst != NULL){
      if(lst->numero == n){
        return 1;
      }
      lst=lst->prox;
    }
    return 0;
  }

 void inserirDadosInicio(list * lst) {
   int auxNumero;
   float salar;
     list no = (list)malloc(sizeof(funcionario));
     if (no == NULL){
       perror("ERRO!!! Nao ha memoria disponivel...");
       exit(-1);
     }
     else{
       puts("Insira numero de funcionaro");
       scanf("%d", &auxNumero);
       printf("Numero inserido com sucesso\n");
       no->numero=auxNumero; // dou o valor ao devido local na estrutura.
       flush_in();
       printf("Insira o nome do funcionario: "); fgets(no->nome, 58, stdin); // em vez de usar o strcpy inseri directamente na estrtura.
       auxNumero=(strlen(no->nome)-1); // ainda pensei em usar o scanf[] mas devido que uso mais o fgets para ficheiros decidi começar a treinar mais este.
       no->nome[auxNumero]='\0'; // basicamente o \n estava a dar problemas depois para listar, decidi eliminar logo desde inicio
       printf("Funcionario inserido com sucesso\n");

       printf("Insira a tarefa do funcionario: "); fgets(no->tarefa, 48, stdin); // inserir tarefas do funcionario
       auxNumero=(strlen(no->tarefa)-1);
       no->tarefa[auxNumero]='\0'; // basicamente o \n estava a dar problemas depois para listar, decidi eliminar logo desde inicio
       printf("Inserido com sucesso\n");

       printf("Insira o salario do funcionario em euros e coloque apenas o numero: ");
       if(scanf("%f", &salar)){
          no->salario=salar;
          printf("\nSalario inserido com sucesso\n\n");
       }
       no->prox = * lst; // o ponteiro desta estrutura fica com valor null (ficando a ser o ultimo da lista)
       * lst = no; //o valor apontado por lst passa a ser o valor que o no inicializou a lista
     }
   }

 void inserirDados(list * lstAux){ //inserir no fim da fila questao e)
     list atual, ant, novo; //inicio 3 ponteiros
     int auxNumero, v;
     float salar;

       novo = (list)malloc(sizeof(funcionario)); // o novo para alocar uma estrutura do tipo listano no determinado local de memoria

       puts("Insira numero de funcionario");
       scanf("%d", &auxNumero);
       v=verifica(*lstAux, auxNumero);
       if(v==1){
         puts("Numero já existe");
         return;
       }
       else{
       novo->numero = auxNumero;
       printf("Numero inserido com sucesso\n");
       novo->numero=auxNumero; // dou o valor ao devido local na estrutura.
       flush_in();
       printf("Insira o nome do funcionario: "); fgets(novo->nome, 58, stdin); // em vez de usar o strcpy inseri directamente na estrtura.
       auxNumero=(strlen(novo->nome)-1); // ainda pensei em usar o scanf[] mas devido que uso mais o fgets para ficheiros decidi começar a treinar mais este.
       novo->nome[auxNumero]='\0'; // basicamente o \n estava a dar problemas depois para listar, decidi eliminar logo desde inicio
       printf("Funcionario inserido com sucesso\n");

       printf("Insira a tarefa do funcionario: "); fgets(novo->tarefa, 48, stdin); // inserir tarefas do funcionario
       auxNumero=(strlen(novo->tarefa)-1);
       novo->tarefa[auxNumero]='\0'; // basicamente o \n estava a dar problemas depois para listar, decidi eliminar logo desde inicio
       printf("Inserido com sucesso\n");

       printf("Insira o salario do funcionario em euros e coloque apenas o numero: ");
       if(scanf("%f", &salar)){
          novo->salario=salar;
          printf("\nSalario inserido com sucesso\n\n");
       }
       novo->prox = NULL; // porque ele vai ficar no fim da fila..

       ant=NULL;
       atual=*lstAux; //o ponteiro atual começa no inicio da fila a apontar e vai seguindo enquanto o ant vai atrás deste

       while(atual != NULL){ //enquanto não chegar à lista que está no fim ele continua
             ant = atual; //a atual passa a ser a lista anterior(damos o valor da anterior)
             atual = atual->prox; // e aqui é quando se dá o proximo passo para a proxima lista
         }

             ant->prox = novo;
       }
}

 void listaFuncionarios(list lst){ //funcao que vai listas os dados dos funcionarios
   printf("\t\tLista de Funcionarios da Empresa\n\n");
   printf(" %21s  %58s  %48s  %10s  \n", "Numero de Funcionario", "Nome", "Tarefa", "Salario"); //ajeito assim mostrando tudo a esquerda mas fica alinhado com espaços certos
   while(lst != NULL){
     printf(" %21d  %58s  %48s  %10.2f  \n", lst->numero, lst->nome, lst->tarefa, lst->salario);
     lst=lst->prox;
   }
   printf("\nClique enter para voltar ao menu\n"); getchar();
 }


 void lista500Euros(list lst){ // funcao que demonstra funcionarios com salario superior a 500 euros, copia da lista mas com condição
   printf("\t\tLista de Funcionarios da Empresa a receber mais de 500 Euros\n\n");
   printf(" %21s  %58s  %48s  %10s  \n", "Numero de Funcionario", "Nome", "Tarefa", "Salario");
   while(lst != NULL){
     if(lst->salario > 500) // a diferença é que adicionei a condição de mostrar apenas aqueles que tem um salario superior a 500 euros!!
        printf(" %21d  %58s  %48s  %10.2f  \n", lst->numero, lst->nome, lst->tarefa, lst->salario);
     lst=lst->prox;
   }

   printf("\nClique enter para voltar ao menu\n"); getchar();
 }


 void actualizaNum(list *lst){ // actualizar os dados do funcionario
   int auxNumero, opcao, verifica=0;
   float auxSalario; //para verificação se é mesmo numero do salario e não bloquear o programa caso não seja..
   list atual;
   atual= *lst;
   printf("Insira o numero do funcionario a actualizar: "); scanf("%d", &auxNumero);
   while(atual != NULL){
     if(auxNumero==atual->numero){
       verifica++;
       do{ // para não obrigar a ter de passar por todos os pontos quando só quer mudar um por exemplo, criei um submenu de mudança dos dados.
         printf("Opcao 1 -> Mudar nome\n");
         printf("Opcao 2 -> Mudar Tarefa\n");
         printf("Opcao 3 -> Mudar Salario\n");
         printf("Opcao 4 -> Sair\n");
         printf("Opcao: ");scanf("%d", &opcao); flush_in(); // segurança para caso seja diferente de numero não fiquei em loop infinito com o \n
         if(isdigit(opcao)==0){
           switch(opcao){
             case 1: printf("Insira o novo nome: "); fgets(atual->nome, 58, stdin);
             atual->nome[strlen(atual->nome)-1]='\0'; // retirar o \n que vem por defeito para não complicar nas apresentações de dados
             printf("\nNome alterado com sucesso\n"); break;

             case 2: printf("Insira a nova tarefa: "); fgets(atual->tarefa, 48, stdin);

             atual->tarefa[strlen(atual->tarefa)-1]='\0'; // retirar o \n que vem por defeito para não complicar nas apresentações de dados
             printf("\nTarefa alterada com sucesso\n"); break;

             case 3: printf("Insira o novo salario: ");
             if(scanf("%f", &auxSalario)){
                atual->salario=auxSalario;
                printf("\nSalario alterado com sucesso\n");
                flush_in();
             }
             else{
               flush_in();
               printf("Ocorreu um erro na alteracao do valor do salario\n"); break;
              }
             case 4: break;

             default: printf("Opcao nao valida volte a tentar\n\n"); break;
           }
         }
         else{
           flush_in(); // caso não limpe o buffer ele está sempre no scanf a inserir algo diferente de numero e entra em ciclo infinito
           printf("\nOpcao nao valida volte a tentar\n\n");
         }
       }while(opcao != 4);
     }
     atual=atual->prox;
  }
  if(verifica==0)
    printf("Nao existe funcionario com esse numero\n");
 }

 void trocar(list *a, list *b){ //como anteriormente não criei uma função de troca de valores mas sim elementos fiz este pequeno subprograma para ordenar.
     //a recebe de b..
     int auxNumero;
     char auxNome[60];
     char auxTarefa[50];
     float auxSalario;

     auxNumero=(*a)->numero;
     strcpy(auxNome, (*a)->nome);
     strcpy(auxTarefa, (*a)->tarefa);
     auxSalario=(*a)->salario;
     //inserir os valores em a)
     (*a)->numero=(*b)->numero;
     strcpy((*a)->nome, (*b)->nome);
     strcpy((*a)->tarefa, (*b)->tarefa);
     (*a)->salario=(*b)->salario;
     //inserir os valores em b)
     (*b)->numero=auxNumero;
     strcpy((*b)->nome, auxNome);
     strcpy((*b)->tarefa, auxTarefa);
     (*b)->salario=auxSalario;
 }


void ordemAlfa(list *lst){
  int bubble, trocado;
  list atual;

  do{ // uso do bubble sort para comparar dois a dois.
    trocado=0;
    atual=*lst;
    while(atual->prox != NULL){
      bubble=strcmp(atual->nome, atual->prox->nome); // usei aqui e não no if, porque estava a dar erro.
      if(bubble > 0){ //vai fazendo comparação dois a dois até ordenar por completo o vetor.
        trocado=1;
        trocar(&atual, &atual->prox);
      }
      atual=atual->prox;
    }

  }while(trocado != 0);
  printf("\n\nAVISO -> TABELA ORDENADA COM SUCESSO!!\n\n");
}

void escrevefun(list r){ // este subprograma escreve a estrutura que recebe, neste caso foi feito para o subprograma procuraPorNome
    printf(" %21s  %58s  %48s  %10s  \n", "Nome", "Numero de Funcionario", "Tarefa", "Salario");
    printf(" %21d  %58s  %48s  %10.2f  \n", r->numero, r->nome, r->tarefa, r->salario);
    printf("Clique enter para voltar ao menu "); getchar();
}

list procuraPorNome(list lst, char auxNome[60]){
  char auxTolower[60];
  for(int x=0; auxNome[x] != '\0'; ++x){ //passar com o tolower caracter a caracter para pequeno para depois comparar e não haver case sensitive
     auxNome[x]=(tolower(auxNome[x]));
  }
  while(lst != NULL){ // ciclo para transformar uma auxiliar em low case o que esta no vetor de dados da estrutura (uso auxiliar porque nao quero mexer no original)
    for(int j=0; lst->nome[j]; ++j){
      auxTolower[j]=(tolower(lst->nome[j])); // passar caracter a caracter para pequeno para depois comparar sem case sensitives
    }
    if(strncmp(auxNome, auxTolower, strlen(auxNome))==0){ //compara as strings caso a auxNome tenha da sua parte igualdade da dados.nome devolve 0
       return lst;
    }
    for(int a=0; auxTolower[a] != '\0'; ++a){ // aqui serve para limpar a string para não ficar com uma string anterior caso esta seja maior, jogar pelo seguro.
      auxTolower[a]='\0';
    }
  }
    list vacuo = (list) malloc(sizeof(funcionario)); //NULL ou algo vazio?? decidi deixar assim sendo mais facil interpretar..
    vacuo->numero=0;
    strcpy(vacuo->nome, "Sem registo");
    strcpy(vacuo->tarefa, "Sem registo");
    vacuo->salario=0;
    return vacuo;
}

 int main(){
   int opcao=0, v;
   char auxNome[60];
   list head;
   head=crialista();

   do{
     printf("Opcao 1 -> Introduzir funcionario\n");
     printf("Opcao 2 -> Listar todos os funcionarios e respectivos dados\n");
     printf("Opcao 3 -> Listar os funcionarios com salario superior a 500 Euros\n");
     printf("Opcao 4 -> Procurar e listar todos os dados de um funcionario, usando o seu nome! \n");
     printf("Opcao 5 -> Actualizar os dados de um funcionario, usando o seu numero! \n");
     printf("Opcao 6 -> Ordene a tabela por ordem alfabetica dos nomes dos funcionarios\n");
     printf("Opcao 7 -> Sair\n");
     printf("\nOpcao: "); scanf("%d", &opcao); flush_in(); // este flush in esta aqui para limpar o buffer pois caso seja diferente de numero ele entrava em infinito
     if(isdigit(opcao)==0){ // para saber se é número uso a função isdigit que retorna 0 caso o caracter não seja numerico
       switch (opcao) {
         case 1:
                 v=listavazia(head);
                 if(v==0){
                   inserirDados(&head);
                 }
                 else{
                   inserirDadosInicio(&head);
                 }
                 break;

         case 2: listaFuncionarios(head); break; // lista todos os funcionarios inseridos

         case 3: lista500Euros(head); break; //lista todos os funcionarios com salarios superiores a 500 euros

         case 4: printf("Insira o nome do funcionario: "); fgets(auxNome, 58, stdin); auxNome[strlen(auxNome)-1]='\0';
                 escrevefun(procuraPorNome(head, auxNome)); break;

         case 5: actualizaNum(&head); break; //actualiza os dados de um funcionario atraves do numero

         case 6: ordemAlfa(&head); break; //para ver a tabela ordenada basta ir a opcao 2 lista funcionarios

         case 7: break;
         default: printf("\nOpcao nao valida volte a tentar\n\n"); break;
       }
     }
     else{
      flush_in(); // caso não limpe o buffer ele está sempre no scanf a inserir algo diferente de numero e entra em ciclo infinito
      printf("\nOpcao nao valida volte a tentar\n\n");
    }
  }while(opcao!=7);

 return 0;
 }
