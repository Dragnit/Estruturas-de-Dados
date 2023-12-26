#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
#include<time.h> //devido as datas em tempo real
#define TAMANHO 10 //variavel global do tamanho do vetor de estruturas..

 /*--------------------------------------------------------------
 --------------------------------------------------------------
 Proprietario: Jorge Miguel dos Santos Martins
 Curso: Licenciatura Sistemas Tecnologias de Informacao
 Disciplina: Programacao II / Estruturas Dados Data:
 Programa/Exercicio: Ficha 7 / Exercicio 1 e 2
 --------------------------------------------------------------
 --------------------------------------------------------------
 */
 typedef struct data_maquinas * point;
 typedef struct data_maquinas {
 struct tm *data; //ponteiro para a estrutura struct da biblioteca time.h ESTA ESTRUTURA TEM ELEMENTOS DE INTEIROS
 float temp;
 float humi;
 float co2;
 float EnerC;
 float producao;
 point prox;

} dados;


typedef struct estrutura_maquinas { //estrutura que tem os apontadores para cada maquina**
  char nome[100]; //nome da maquina
  point head; //vai apontar para cada inicio de lista de uma maquina
} maquinas;

void flush_in(){ // codigo para limpeza de buffer do teclado..
   int ch;
   while( (ch = fgetc(stdin)) != EOF && ch != '\n' ){}
   return;
 }

 point crialistamaquinas() { //função que retorna null aos ponteiros de "head" ou do tipo point..
    point p = NULL;
    return p;
  }

  int listavaziamaquinas(point head) { //verificar se a lista de uma maquina está vazia ou com elementos.
      if (head == NULL)
        return 1;
      else
        return 0;
    }
  int existeMaquina(maquinas vet[TAMANHO], char auxNome[100]){
    int v, contador=0;
    for(int i=0; i<TAMANHO; ++i){
      v=strcmp(vet[i].nome, auxNome);
      contador++;
      if(v==0){
        return contador; //assim no inserir dados não preciso de criar novo codigo para procurar..
      }
    }
    return 0;
  }

 int insereMaquina(maquinas vet[TAMANHO], int counter){
   char auxNome[100];
   int v;
   puts("Indique o nome da maquina a inserir"); fgets(auxNome, 98, stdin);
   auxNome[strlen(auxNome)-1]='\0'; //eliminar o enter que o fgets come..
   v=existeMaquina(vet, auxNome);
   if(v==0){
     strcpy(vet[counter].nome, auxNome);
     vet[counter].head=crialistamaquinas();
     puts("Maquina inserida com sucesso");
     counter++;
   }
   else{
     puts("Maquina já existe\n");
   }

   return counter;

 }

 void junta_no_ini_lista(point * lst) { //inserir dados com data automatica..
   time_t dat;
   float valor;
   char aux[100];
   time(&dat);
   point no = (point)malloc(sizeof(maquinas));
   if (no == NULL){
     perror("ERRO!!! Nao ha memoria disponivel...");
     exit(-1);
   }
   else{
    puts("Insira temperatura"); scanf("%f", &valor); flush_in();
    no->temp=valor;
    puts("Insira humidade"); scanf("%f", &valor); flush_in();
    no->humi=valor;
    puts("Insira co2"); scanf("%f", &valor); flush_in();
    no->co2=valor;
    puts("Insira energia consumida"); scanf("%f", &valor); flush_in();
    no->EnerC=valor;
    puts("Insira produção da maquina"); scanf("%f", &valor); flush_in();
    no->producao=valor;
    no->data = localtime(&dat);
    no->prox = * lst; // o ponteiro desta estrutura fica com valor null (ficando a ser o ultimo da lista)
     * lst = no; //o valor apontado por lst passa a ser o valor que o no inicializou a lista
   }
 }

 void junta_valor(point * lstAux){ //inserir no fim da fila questao com data automatica
   time_t dt;
   point atual, ant, novo; //inicio 3 ponteiros
   int v, val;
   float valor;
   char aux[100];
   time(&dt);
   if((v=listavaziamaquinas(*lstAux))==0){
     novo = (point)malloc(sizeof(maquinas)); // o novo para alocar uma estrutura do tipo listano no determinado local de memoria

     puts("Insira temperatura"); scanf("%f", &valor); flush_in();
     novo->temp=valor;
     puts("Insira humidade"); scanf("%f", &valor); flush_in();
     novo->humi=valor;
     puts("Insira co2"); scanf("%f", &valor); flush_in();
     novo->co2=valor;
     puts("Insira energia consumida"); scanf("%f", &valor); flush_in();
     novo->EnerC=valor;
     puts("Insira produção da maquina"); scanf("%f", &valor); flush_in();
     novo->producao=valor;
     novo->data = localtime(&dt);

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
     junta_no_ini_lista(&(*lstAux)); // na minha interpretação juntar no fim de uma fila que não existe é o mesmo que o inserir em primeiro, então caso a lista esteja vazia eu chamo a função de inserir no inicio..
   }
 }

 void inserirDados(maquinas vetor[TAMANHO]){
   char auxNome[100];
   int indice;
   puts("Indique o nome da maquina a inserir dados");
   fgets(auxNome, 98, stdin);
   auxNome[strlen(auxNome)-1]='\0'; //retirar a linha..
   indice=existeMaquina(vetor, auxNome); //menos um porque ele soma inicialmente ou seja estando no primeiro indice tem de indicar para o indice 0, irei depois fazer isso dentro do if..
   if(indice>0){
     indice--; //deixar o indice no local correcto como foi mencionado em cima.

     junta_valor(&vetor[indice].head);
   }
   else{
     puts("Maquina nao existe");
   }
 }
 void junta_no_ini_listaManual(point * lst) { //INSERÇÃO MANUAL DOS DADOS
   int ano, mes, dia, hora, min, seg;
   time_t dat;
   float valor;
   char aux[100];
   point no = (point)malloc(sizeof(maquinas));
   if (no == NULL){
     perror("ERRO!!! Nao ha memoria disponivel...");
     exit(-1);
   }
   else{
    puts("Insira temperatura"); scanf("%f", &valor); flush_in();
    no->temp=valor;
    puts("Insira humidade"); scanf("%f", &valor); flush_in();
    no->humi=valor;
    puts("Insira co2"); scanf("%f", &valor); flush_in();
    no->co2=valor;
    puts("Insira energia consumida"); scanf("%f", &valor); flush_in();
    no->EnerC=valor;
    puts("Insira produção da maquina"); scanf("%f", &valor); flush_in();
    no->producao=valor;
    puts("Insira dia"); scanf("%d", &dia); flush_in();
    puts("Insira mes"); scanf("%d", &mes); flush_in();
    puts("Insira ano"); scanf("%d", &ano); flush_in();
    puts("Insira hora - Apenas a hora não os minutos"); scanf("%d", &hora); flush_in();
    puts("Insira minutos"); scanf("%d", &min); flush_in();
    puts("Insira segundos"); scanf("%d", &seg); flush_in();
    no->data->tm_year = (ano - 1900);
    no->data->tm_mon  = (mes -1);
    no->data->tm_mday = dia;
    no->data->tm_hour = hora;
    no->data->tm_min = min;
    no->data->tm_sec = seg;

    no->prox = * lst; // o ponteiro desta estrutura fica com valor null (ficando a ser o ultimo da lista)
     * lst = no; //o valor apontado por lst passa a ser o valor que o no inicializou a lista
   }
 }

 void junta_valorManual(point * lstAux){ //inserir no fim da fila questao
   point atual, ant, novo; //inicio 3 ponteiros
   int v, val, mes, ano, dia, hora, min, seg;
   float valor;
   char aux[100];
   if((v=listavaziamaquinas(*lstAux))==0){
     novo = (point)malloc(sizeof(maquinas)); // o novo para alocar uma estrutura do tipo listano no determinado local de memoria

     puts("Insira temperatura"); scanf("%f", &valor); flush_in();
     novo->temp=valor;
     puts("Insira humidade"); scanf("%f", &valor); flush_in();
     novo->humi=valor;
     puts("Insira co2"); scanf("%f", &valor); flush_in();
     novo->co2=valor;
     puts("Insira energia consumida"); scanf("%f", &valor); flush_in();
     novo->EnerC=valor;
     puts("Insira produção da maquina"); scanf("%f", &valor); flush_in();
     novo->producao=valor;
     puts("Insira dia"); scanf("%d", &dia); flush_in();
     puts("Insira mes"); scanf("%d", &mes); flush_in();
     puts("Insira ano"); scanf("%d", &ano); flush_in();
     puts("Insira hora - Apenas a hora não os minutos"); scanf("%d", &hora); flush_in();
     puts("Insira minutos"); scanf("%d", &min); flush_in();
     puts("Insira segundos"); scanf("%d", &seg); flush_in();
     novo->data->tm_year = (ano - 1900);
     novo->data->tm_mon  = (mes -1);
     novo->data->tm_mday = dia;
     novo->data->tm_hour = hora;
     novo->data->tm_min = min;
     novo->data->tm_sec = seg;

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
     junta_no_ini_listaManual(&(*lstAux)); // na minha interpretação juntar no fim de uma fila que não existe é o mesmo que o inserir em primeiro, então caso a lista esteja vazia eu chamo a função de inserir no inicio..
   }
 }

 void inserirdadosManuais(maquinas vetor[TAMANHO]){ //exactamente igual ao codigo do inserir mas por causa de ser manual tive de mudar para outro subprograma
   char auxNome[100];
   int indice;
   puts("Indique o nome da maquina a inserir dados");
   fgets(auxNome, 98, stdin);
   auxNome[strlen(auxNome)-1]='\0'; //retirar a linha..
   indice=existeMaquina(vetor, auxNome); //menos um porque ele soma inicialmente ou seja estando no primeiro indice tem de indicar para o indice 0, irei depois fazer isso dentro do if..
   if(indice>0){
     indice--; //deixar o indice no local correcto como foi mencionado em cima.

     junta_valorManual(&vetor[indice].head);
   }
   else{
     puts("Maquina nao existe");
   }
 }

 int comparaDatas(struct tm *data, int dia1, int mes1, int ano1, int dia2, int mes2, int ano2){ //aplicação do difftime da biblioteca time.h para comparar as datas será para a ordem crescente..
   if(data->tm_year+1900 >= ano1 && data->tm_year+1900 <= ano2 ){ //significa que esta dentro do intervalo de anos..
     if(data->tm_year+1900 == ano1 && data->tm_year+1900 == ano2){
       if(data->tm_mon+1 == mes1 && data->tm_mon+1 == mes2){ //meses iguais no intervalo
         if(data->tm_mday >= dia1 && data->tm_mday <= dia2){
           return 1;
         }
       }
       if(data->tm_mon+1 >= mes1 && data->tm_mon+1 <= mes2){
         if(data->tm_mon+1 == mes1){
           if(data->tm_mday >= dia1){
             return 1;
           }
         }
         if(data->tm_mon+1 == mes2){
           if(data->tm_mday <= dia2){
             return 1;
           }
         }
         return 1; //pois como se encontra dentro do intervalo de meses sem ser um dos extremos está no intervalo aceitavel
       }
     }
     else{
        if(data->tm_year+1900 == ano1 && data->tm_year+1900 < ano2){ //caso os anos não sejam os mesmos..
          if(data->tm_mon+1 >= mes1 && data->tm_mday >= dia1)
            return 1;
      }
      else{
        if(data->tm_year+1900 > ano1 && data->tm_year+1900 == ano2){
          if(data->tm_mon+1 <= mes2 && data->tm_mday <= dia2)
            return 1;
           }//fim do ultimo se ano1 menor e ano2 igual
           return 0;
         }
       }
   }
   else
    return 0;
}


void dadosIntervaloTempo(maquinas vetor[TAMANHO]){
  char auxNome[100], auxData[100], auxData2[100]; //*result ->ponteiro que era..
  int indice, v, result, dia1, dia2, mes1, mes2, ano1, ano2;
  point atual;
  puts("Indique o nome da maquina a procurar dados");
  fgets(auxNome, 98, stdin);
  auxNome[strlen(auxNome)-1]='\0'; //retirar a linha..
  indice=existeMaquina(vetor, auxNome); //menos um porque ele soma inicialmente ou seja estando no primeiro indice tem de indicar para o indice 0, irei depois fazer isso dentro do if..
  if(indice>0){
    indice--; //deixar o indice no local correcto como foi mencionado em cima.
    atual=vetor[indice].head;
    if(v=listavaziamaquinas(vetor[indice].head)==0){
       puts("Insira a o momento de tempo que quer procurar"); puts("De"); printf("Dia: "); scanf("%d", &dia1); flush_in(); printf("\nMes: "); scanf("%d", &mes1); flush_in(); printf("\nAno: "); scanf("%d", &ano1); flush_in();
       puts("\nAte"); printf("Dia: "); scanf("%d", &dia2); flush_in(); printf("\nMes: "); scanf("%d", &mes2); flush_in(); printf("\nAno: ", &ano2); flush_in();
       printf(" %28s  %20s  %20s  %20s %20s %20s %20s \n", "Data", "Hora", "temperatura", "Humidade", "Co2", "Energia Consumida", "Producao");
       while(atual != NULL){
         result=comparaDatas(atual->data, dia1, mes1, ano1, dia2, mes2, ano2);
         if(result){ //a funcao devolve 1 caso esteja dentro dos parametros
           printf(" %20d/%d/%d %16d:%2.d:%2.d  %20.2f  %20.2f  %20.2f  %20.2f %20.2f  \n", atual->data->tm_mday, atual->data->tm_mon+1, atual->data->tm_year+1900, atual->data->tm_hour, atual->data->tm_min, atual->data->tm_sec, atual->temp, atual->humi, atual->co2, atual->EnerC, atual->producao);
           //data temperatura humidade c02, energia consumida, producao
         }
         atual=atual->prox;
       }
       printf("\n Clique para voltar ao menu"); getchar();
    }
    else{
      puts("Lista vazia");
    }
  }
  else{
    puts("Maquina nao existe");
  }
}

int contaListas(point head){
  int contas=0;
  point atual;
  atual=head;
  while(atual != NULL){
    contas++;
    atual=atual->prox;
  }
  return contas;
}


void saveDataBase(maquinas vetor[TAMANHO], int counter){
  FILE *saveBin;
  int lista=0, i=0;
  while(vetor[i].head != NULL){
    lista=contaListas(vetor[i].head)+lista; //ira receber o contas do subprograma contalistas..
    ++i;
    if(i==10) //segurança para que não saia do vetor..
      break;
  }
  printf("%d\n", lista);
  saveBin=fopen("basedadosMaquinas.dat", "wb");

  if(saveBin==NULL){
    printf("Erro ao abrir ficheiro, clique para sair\n"); getchar();
    fclose(saveBin);
    return;
  }
  else{
    fwrite(&counter, sizeof(int), 1, saveBin);
    fwrite(&lista, sizeof(int), 1, saveBin); //gravar o numero de listas que estão inseridas / contruidas..
    fwrite(vetor, sizeof(maquinas[10]) + (lista * sizeof(dados)), 1, saveBin);
  }
  fclose(saveBin);
}

void mostrarDados(maquinas vetor[TAMANHO]){ //mostrar dados num momento escolhido pelo utilizador.. TESTE DO PROGRAMADOR T.T.T.T.T.T.T
  char auxNome[100], auxData[100], auxData2[100]; //*result ->ponteiro que era..
  int indice, v, result;
  point atual;
  puts("Indique o nome da maquina a procurar dados");
  fgets(auxNome, 98, stdin);
  auxNome[strlen(auxNome)-1]='\0'; //retirar a linha..
  indice=existeMaquina(vetor, auxNome); //menos um porque ele soma inicialmente ou seja estando no primeiro indice tem de indicar para o indice 0, irei depois fazer isso dentro do if..
  if(indice>0){
    indice--; //deixar o indice no local correcto como foi mencionado em cima.
    atual=vetor[indice].head;
    if(v=listavaziamaquinas(vetor[indice].head)==0){
       printf(" %28s  %20s  %20s  %20s %20s %20s %20s \n", "Data", "Hora", "temperatura", "Humidade", "Co2", "Energia Consumida", "Producao");
       while(atual != NULL){
         printf(" %20d/%d/%d %16d:%2.d:%2.d  %20.2f  %20.2f  %20.2f  %20.2f %20.2f  \n", atual->data->tm_mday, atual->data->tm_mon+1, atual->data->tm_year+1900, atual->data->tm_hour, atual->data->tm_min, atual->data->tm_sec, atual->temp, atual->humi, atual->co2, atual->EnerC, atual->producao);
           //data temperatura humidade c02, energia consumida, producao
         atual=atual->prox;
       }
       printf("\n Clique para voltar ao menu"); getchar();
    }
    else{
      puts("Lista vazia");
    }
  }
  else{
    puts("Maquina nao existe");
  }
}

int loadDataBase(maquinas vetor[TAMANHO], int counter){ //subprograma que vai fazer a leitura do que está no ficheiro..
  FILE *loadBin;
  int lista=0;

  loadBin=fopen("basedadosMaquinas.dat", "rb");

  if(loadBin==NULL){
    printf("Erro ao abrir ficheiro ou não existente, clique para continuar\n"); getchar();
    fclose(loadBin);
    return 0;
  }
  else{
    fread(&counter, sizeof(int), 1, loadBin);//controle de não sair do vetor o numero de maquinas..
    printf("%d\n", counter);
    fread(&lista, sizeof(int), 1, loadBin); //para ir buscar o tamanho das listas que foram gravadas nos dados..
    printf("%d\n", lista);
    fread(vetor, sizeof(maquinas[10]) + (lista * sizeof(dados)), 1, loadBin);
    puts("Leitura de dados do ficheiro com sucesso!!\n");
    fclose(loadBin);
    return counter;
  }
}

 int main(){
   maquinas vetor[TAMANHO];
   //iniciarVetor(vetor); //vetor de estruturas iniciado com os seus head a null
   int counter=0, opcao;
   //counter=loadDataBase(vetor, counter); //aqui o contador irá receber um valor que é o numero de indices ocupados no vetor de esruturas..
   do{
     puts("1 - Inserir nova maquina");
     puts("2 - Inserir dados");
     puts("3 - Mostrar dados num intervalo de tempo");
     puts("4 - Gravar Dados");
     puts("5 - Inserir dados manualmente");
     puts("6 - ");
     puts("10 - MostrarLista(Teste Prog)");

     puts("9 - sair");
     scanf("%d", &opcao);
     flush_in();
     switch (opcao) {
       case 1: if (counter >= 10) {
                  puts("Limite de memoria para maquinas atingido");
               }
               else{
                 counter=insereMaquina(vetor, counter);
             }
             break;
       case 2: inserirDados(vetor); break;

       case 3: dadosIntervaloTempo(vetor); break;

       case 4: saveDataBase(vetor, counter); break;

       case 5: inserirdadosManuais(vetor); break;

       case 6:

       case 10: mostrarDados(vetor); break;

       case 9: break; //inserir gravação ao sair**
     }



   }while(opcao != 9);


 return 0;
 }
