#include<stdio.h>
#include<string.h>
#include<ctype.h> //uso esta biblioteca por causa do tolower
#include<malloc.h>
 /*--------------------------------------------------------------
 --------------------------------------------------------------
 Proprietario: Jorge Miguel dos Santos Martins
 Curso: Licenciatura Sistemas Tecnologias de Informacao
 Disciplina: Programacao II / Estruturas Dados Data:
 Programa/Exercicio: Ficha 5 / Exercicio 1
 --------------------------------------------------------------
 --------------------------------------------------------------
 */

 struct dados_funcionario{ // estrutura que tem os campos necessários de cada funcionario
   int numero;
   char nome[60];
   char tarefa[50];
   float salario;
   struct dados_funcionario *proximo;
 }; typedef struct dados_funcionario funcionario;

 void flush_in(){ // codigo para limpeza de buffer do teclado..
    int ch;
    while( (ch = fgetc(stdin)) != EOF && ch != '\n' ){}
    return;
  }

 int inserirDados(int conta, int tamanho, funcionario *dados){
   funcionario *pontAux;
   int auxNumero;
   float salar;
   if(conta>=tamanho){
     printf("Numero maximo de funcionarios preenchido\n");
     return conta; // nao preciso de else porque com este return ele sai da funcao.
   }
   printf("Insira numero de funcionario: ");
   pontAux=dados;
   if(scanf("%d", &auxNumero)){
     for(int i=0; i<conta; ++i){ //(*pontAux).numero = pontAux->numero
       if(auxNumero==pontAux->numero){ //basicamente penso que não devem existir numa firma funcionarios com os mesmos numeros mecanograficos
         printf("\nNumero de funcionario já existe\n");
         return conta;
       }
       else
          pontAux++; //ele acaba sempre no indice que não tem nada escrito
     }
     printf("Numero inserido com sucesso\n");
     pontAux->numero=auxNumero; // dou o valor ao devido local na estrutura.
     flush_in();
     printf("Insira o nome do funcionario: "); fgets(pontAux->nome, 58, stdin); // em vez de usar o strcpy inseri directamente na estrtura.
     auxNumero=(strlen(pontAux->nome)-1); // ainda pensei em usar o scanf[] mas devido que uso mais o fgets para ficheiros decidi começar a treinar mais este.
     pontAux->nome[auxNumero]='\0'; // basicamente o \n estava a dar problemas depois para listar, decidi eliminar logo desde inicio
     printf("Funcionario inserido com sucesso\n");

     printf("Insira a tarefa do funcionario: "); fgets(pontAux->tarefa, 48, stdin); // inserir tarefas do funcionario
     auxNumero=(strlen(pontAux->tarefa)-1);
     pontAux->tarefa[auxNumero]='\0'; // basicamente o \n estava a dar problemas depois para listar, decidi eliminar logo desde inicio
     printf("Inserido com sucesso\n");

     printf("Insira o salario do funcionario em euros e coloque apenas o numero: ");
     if(scanf("%f", &salar)){
        pontAux->salario=salar;
        printf("\nSalario inserido com sucesso\n\n");
        conta++;
     }
     else{
       flush_in();
       printf("Ocorreu um erro carregue numa tecla para voltar ao menu\n");
       getchar();
       return conta;
     }
   }
   else{ // resultado se o numero inserido for algo diferente de numeros assim o programa não para.
     flush_in();
     printf("\nErro, numero de funcionario algo diferente de digitos\n");
     printf("Clique enter para voltar ao menu..\n");
     getchar();
   }
   return conta;
 }

 void listaFuncionarios(int conta, int tamanho, funcionario *dados){ //funcao que vai listas os dados dos funcionarios
   funcionario *dados1;
   dados1= dados; //para que o ponteiro que esta inicial nunca se perca..
   printf("\t\tLista de Funcionarios da Empresa\n\n");
   printf(" %21s  %58s  %48s  %10s  \n", "Numero de Funcionario", "Nome", "Tarefa", "Salario"); //ajeito assim mostrando tudo a esquerda mas fica alinhado com espaços certos
   for(int i=0; i<conta; ++i){
     printf(" %21d  %58s  %48s  %10.2f  \n", dados1->numero, dados1->nome, dados1->tarefa, dados1->salario);
     dados1++;
   }
   printf("\nClique enter para voltar ao menu\n"); getchar();
 }

 void lista500Euros(int conta, int tamanho, funcionario *dados){ // funcao que demonstra funcionarios com salario superior a 500 euros, copia da lista mas com condição
   funcionario *dados1;
   dados1=dados;
   printf("\t\tLista de Funcionarios da Empresa a receber mais de 500 Euros\n\n");
   printf(" %21s  %58s  %48s  %10s  \n", "Numero de Funcionario", "Nome", "Tarefa", "Salario");
   for(int i=0; i<conta; ++i){
     if(dados1->salario > 500) // a diferença é que adicionei a condição de mostrar apenas aqueles que tem um salario superior a 500 euros!!
        printf(" %21d  %58s  %48s  %10.2f  \n", dados1->numero, dados1->nome, dados1->tarefa, dados1->salario);
     dados1++;
   }

   printf("\nClique enter para voltar ao menu\n"); getchar();
 }

 void listaPorNome(int conta, int tamanho, funcionario *dados){ // funcao que demonstra a lista dos funcionarios que existem com o nome dado pelo utilizador
   funcionario *dados1=dados;
   char auxNome[60], auxTolower[60];
   int contador=0;
   flush_in();
   printf("Insira o nome do funcionario/s a procurar: "); fgets(auxNome, 58, stdin);
   auxNome[(strlen(auxNome)-1)]='\0'; //retirar a mudança de linha
   printf("\t\tLista de Funcionarios da Empresa com nome %s \n\n", auxNome);
   printf(" %21s  %58s  %48s  %10s  \n", "Nome", "Numero de Funcionario", "Tarefa", "Salario");
   for(int x=0; auxNome[x] != '\0'; ++x){ //passar com o tolower caracter a caracter para pequeno para depois comparar e não haver case sensitive
      auxNome[x]=(tolower(auxNome[x]));
   }
   for(int i=0; i<conta; ++i){ // ciclo para transformar uma auxiliar em low case o que esta no vetor de dados da estrutura (uso auxiliar porque nao quero mexer no original)
     for(int j=0; dados1->nome[j]; ++j){
       auxTolower[j]=(tolower(dados1->nome[j])); // passar caracter a caracter para pequeno para depois comparar sem case sensitives
     }
     if(strncmp(auxNome, auxTolower, strlen(auxNome))==0){ //compara as strings caso a auxNome tenha da sua parte igualdade da dados.nome devolve 0
        printf(" %21d  %58s  %48s  %10.2f  \n", dados1->numero, dados1->nome, dados1->tarefa, dados1->salario);
        contador++;
     }
     for(int a=0; auxTolower[a] != '\0'; ++a){ // aqui serve para limpar a string para não ficar com uma string anterior caso esta seja maior, jogar pelo seguro.
       auxTolower[a]='\0';
     }
     dados1++; //incremento do ponteiro para passar ao proximo local de memoria da tabela "dinamica"
   }
   if(contador==0){
     funcionario vazio={0, "Sem Registo", "Sem Registo", 0}; //inicialização automatica de struct
     //strcpy(vazio.nome, "0")
     printf(" %21d  %58s  %48s  %10.2f  \n", vazio.numero, vazio.nome, vazio.tarefa, vazio.salario); //"estrutura vazia caso não existam funcionarios"
   }
   printf("\nClique enter para voltar ao menu\n"); getchar();
 }

 void actualizaNum(int conta, int tamanho, funcionario *dados){ // actualizar os dados do funcionario
   int auxNumero, opcao, verifica=0;
   funcionario * pontAux=dados;
   float auxSalario; //para verificação se é mesmo numero do salario e não bloquear o programa caso não seja..
   printf("Insira o numero do funcionario a actualizar: "); scanf("%d", &auxNumero);
   for(int i=0; i<conta; ++i){
     if(auxNumero==pontAux->numero){
       verifica++;
       do{ // para não obrigar a ter de passar por todos os pontos quando só quer mudar um por exemplo, criei um submenu de mudança dos dados.
         printf("Opcao 1 -> Mudar nome\n");
         printf("Opcao 2 -> Mudar Tarefa\n");
         printf("Opcao 3 -> Mudar Salario\n");
         printf("Opcao 4 -> Sair\n");
         printf("Opcao: ");scanf("%d", &opcao); flush_in(); // segurança para caso seja diferente de numero não fiquei em loop infinito com o \n
         if(isdigit(opcao)==0){
           switch(opcao){
             case 1: printf("Insira o novo nome: "); fgets(dados[i].nome, 58, stdin);
             flush_in();
             pontAux->nome[strlen(pontAux->nome)-1]='\0'; // retirar o \n que vem por defeito para não complicar nas apresentações de dados
             printf("\nNome alterado com sucesso\n"); break;

             case 2: printf("Insira a nova tarefa: "); fgets(dados[i].tarefa, 48, stdin);
             flush_in();
             pontAux->tarefa[strlen(pontAux->tarefa)-1]='\0'; // retirar o \n que vem por defeito para não complicar nas apresentações de dados
             printf("\nTarefa alterada com sucesso\n"); break;

             case 3: printf("Insira o novo salario: ");
             if(scanf("%f", &auxSalario)){
                pontAux->salario=auxSalario;
                printf("\nSalario alterado com sucesso\n");
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
     pontAux++; //para que o ponteiro ande na memoria alocada de estruturas.
  }
  if(verifica==0)
    printf("Nao existe funcionario com esse numero\n");
 }
//ficquei por aqui AVISO!!
 void ordemCrescente(int conta, int tamanho, funcionario *dados){ // peguei no exericio 10 da ficha 1, e usei o Insert Seletion
   int a; //eu inicio aqui o a para depois puder usar o valor dele fora do vetor..
   funcionario *aux= (funcionario*) malloc(1*sizeof(funcionario)), *dados1=dados, *dados2, *dados3;
   for(int i=1; i<tamanho; ++i){ // o i começa com 1 para que o a depois não seja -1 e depois em baixo começamos logo com um numero de ancora sendo este o 1.
     aux=dados1;
     dados2=dados1;
     for(a=(i-1); a>=0 && dados2->numero > aux->numero; --a){ //a é igual a i-1 assim é sempre o valor que está a esquerda
       dados3=
       *(dados2 + 1) =*dados2; //valor apontado por dados 1 mais uma casa do tamanho funcionario é igual ao valor apontado por dados1
       dados2--;
     }
      dados2++;
      dados2=aux; //o mesmo que em cima..
      dados1++;
   }
   printf("\n\nAVISO -> TABELA ORDENADA COM SUCESSO!!\n\n");
 }

void ordemAlfa(int conta, int tamanho, funcionario dados[tamanho]){
  int bubble;
  funcionario *aux=(funcionario*)malloc(1*sizeof(funcionario)), *dados1=dados; // auxiliar de estrutura para apenas reter temporariamente valores..

  for(int a=0; a<tamanho; ++a){ // uso do bubble sort para comparar dois a dois.
    for(int b=0; b<(tamanho-1); ++b){
      bubble=strcmp(dados->nome, (dados1+1)->nome); // usei aqui e não no if, porque estava a dar erro.
      if(bubble > 0){ //vai fazendo comparação dois a dois até ordenar por completo o vetor.
        *aux=*dados1;
        *dados1=*(dados+1);
        *(dados1+1)=*aux;
      }
    }
  }
  printf("\n\nAVISO -> TABELA ORDENADA COM SUCESSO!!\n\n");
}

void escrevefun(funcionario r){ // este subprograma escreve a estrutura que recebe, neste caso foi feito para o subprograma procuraPorNome
    printf(" %21s  %58s  %48s  %10s  \n", "Nome", "Numero de Funcionario", "Tarefa", "Salario");
    printf(" %21d  %58s  %48s  %10.2f  \n", r.numero, r.nome, r.tarefa, r.salario);
    printf("Clique enter para voltar ao menu "); getchar();
}

funcionario procuraPorNome(int conta, int tamanho, funcionario dados[tamanho], char auxNome[60]){
  char auxTolower[60];
  for(int x=0; auxNome[x] != '\0'; ++x){ //passar com o tolower caracter a caracter para pequeno para depois comparar e não haver case sensitive
     auxNome[x]=(tolower(auxNome[x]));
  }
  for(int i=0; i<conta; ++i){ // ciclo para transformar uma auxiliar em low case o que esta no vetor de dados da estrutura (uso auxiliar porque nao quero mexer no original)
    for(int j=0; dados[i].nome[j]; ++j){
      auxTolower[j]=(tolower(dados[i].nome[j])); // passar caracter a caracter para pequeno para depois comparar sem case sensitives
    }
    if(strncmp(auxNome, auxTolower, strlen(auxNome))==0){ //compara as strings caso a auxNome tenha da sua parte igualdade da dados.nome devolve 0
       return dados[i];
    }
    for(int a=0; auxTolower[a] != '\0'; ++a){ // aqui serve para limpar a string para não ficar com uma string anterior caso esta seja maior, jogar pelo seguro.
      auxTolower[a]='\0';
    }
  }
    funcionario vazio={0, "Sem Registo", "Sem Registo", 0}; //inicialização automatica de struct
    return vazio;
}

 int main(){
   int tamanho, opcao=0, conta=0;
   char auxNome[60];
   printf("Indique quantos funcionarios quer listar?\n"); scanf("%d", &tamanho);
   funcionario * dados = (funcionario*) malloc(tamanho*sizeof(funcionario)); // tabela de dados dos funcionarios da empresa.
   do{
     printf("Opcao 1 -> Introduzir funcionario\n");
     printf("Opcao 2 -> Listar todos os funcionarios e respectivos dados\n");
     printf("Opcao 3 -> Listar os funcionarios com salario superior a 500 Euros\n");
     printf("Opcao 4 -> Procurar e listar todos os dados de um funcionario, usando o seu nome! \n");
     printf("Opcao 5 -> Actualizar os dados de um funcionario, usando o seu numero! \n");
     printf("Opcao 6 -> Ordene a tabela por ordem crescente dos numeros dos funcionarios \n");
     printf("Opcao 7 -> Ordene a tabela por ordem alfabetica dos nomes dos funcionarios\n");
     printf("Opcao 8 -> Procurar e listar todos os dados de um funcionario, usando o seu nome!(Como eu tinha feito) \n");
     printf("Opcao 9 -> Sair\n");
     printf("\nOpcao: "); scanf("%d", &opcao); flush_in(); // este flush in esta aqui para limpar o buffer pois caso seja diferente de numero ele entrava em infinito
     if(isdigit(opcao)==0){ // para saber se é número uso a função isdigit que retorna 0 caso o caracter não seja numerico
       switch (opcao) {
         case 1: conta=inserirDados(conta, tamanho, dados); break; // usar uma variavel de contagem para que o tamanho não seja ultrapassado.
         case 2: listaFuncionarios(conta, tamanho, dados); break; // lista todos os funcionarios inseridos
         case 3: lista500Euros(conta, tamanho, dados); break; //lista todos os funcionarios com salarios superiores a 500 euros
         case 4: printf("Insira o nome do funcionario: "); fgets(auxNome, 58, stdin); auxNome[strlen(auxNome)-1]='\0';
                 escrevefun(procuraPorNome(conta, tamanho, dados, auxNome)); break;
         case 5: actualizaNum(conta, tamanho, dados); break; //actualiza os dados de um funcionario atraves do numero
         case 6: ordemCrescente(conta, tamanho, dados); break; //para ver a tabela ordenada basta ir a opcao 2 lista funcionarios
         case 7: ordemAlfa(conta, tamanho, dados); break; //para ver a tabela ordenada basta ir a opcao 2 lista funcionarios
         case 8: listaPorNome(conta, tamanho, dados); break; //lista todos os funcionarios com nome dado pelo utilizador
         case 9: break;
         default: printf("\nOpcao nao valida volte a tentar\n\n"); break;
       }
     }
     else{
      flush_in(); // caso não limpe o buffer ele está sempre no scanf a inserir algo diferente de numero e entra em ciclo infinito
      printf("\nOpcao nao valida volte a tentar\n\n");
    }
   }while(opcao!=9);

 return 0;
 }
