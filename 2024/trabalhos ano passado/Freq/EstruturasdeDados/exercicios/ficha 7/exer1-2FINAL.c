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
 typedef struct data_maquinas * point; //estrutura dos dados de cada maquina
 typedef struct data_maquinas {
 char data[40];
 float temp;
 float humi;
 float co2;
 float EnerC;
 float producao;
 point prox; //liga para a proxima lista..

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
  int existeMaquina(maquinas vet[TAMANHO], char auxNome[100]){ //subprograma para verificar se existem maquinas no vetor com o nome dado.
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

 int insereMaquina(maquinas vet[TAMANHO], int counter){ //subprograma que insere as maquinas no vetor de estruturas
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
   struct tm *tempo;
   time_t dat;
   float valor;
   char aux[100];
   time(&dat);
   point no = (point)malloc(sizeof(dados));
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
    tempo = localtime(&dat); //uso na mesma o localtime e a seguir retiro a info dele para string com o strftime
    strftime(no->data,40,"%d/%m/%Y - %H:%M", tempo); //d para dia m para mes e Y em grande para que o ano seja completo
    no->prox = * lst; // o ponteiro desta estrutura fica com valor null (ficando a ser o ultimo da lista)
     * lst = no; //o valor apontado por lst passa a ser o valor que o no inicializou a lista
   }
 }

 void junta_valor(point * lstAux){ //inserir no fim da fila questao com data automatica
   struct tm *temp;
   time_t dt;
   point atual, ant, novo; //inicio 3 ponteiros
   int v, val;
   float valor;
   char aux[100];
   time(&dt);
   if((v=listavaziamaquinas(*lstAux))==0){
     novo = (point)malloc(sizeof(dados)); // o novo para alocar uma estrutura do tipo dados no determinado local de memoria

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
     temp = localtime (&dt);
     strftime(novo->data,40,"%d/%m/%Y - %H:%M", temp); //formato escolhido porque é melhor para comparaçoes passando partes da string para inteiros com o strtol

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
   struct tm *juntaInicio;
   int ano, mes, dia, hora, min, seg, val;
   time_t dat;
   time (&dat);
   float valor;
   char aux[100];
   point no = (point)malloc(sizeof(dados));
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
    juntaInicio = localtime (&dat);
    puts("Insira dia"); scanf("%d", &dia); flush_in();
    puts("Insira mes"); scanf("%d", &mes); flush_in();
    puts("Insira ano"); scanf("%d", &ano); flush_in();
    puts("Insira hora - Apenas a hora não os minutos"); scanf("%d", &hora); flush_in();
    puts("Insira minutos"); scanf("%d", &min); flush_in();
    puts("Insira segundos"); scanf("%d", &seg); flush_in();
    if(dia ==0 && mes == 0 && ano == 0 && hora == 0 & min == 0 && seg == 0){ //por causa das falhas...
      strcpy(no->data, "0");
      no->prox = * lst; // o ponteiro desta estrutura fica com valor null (ficando a ser o ultimo da lista)
       * lst = no; //o valor apontado por lst passa a ser o valor que o no inicializou a lista
    }
    else{
      juntaInicio->tm_year = (ano - 1900);
      juntaInicio->tm_mon  = (mes -1);
      juntaInicio->tm_mday = dia;
      juntaInicio->tm_hour = hora;
      juntaInicio->tm_min = min;
      juntaInicio->tm_sec = seg;
      val=mktime(juntaInicio); //função que tranforma em time_t, retira os dados existentes e adapta-os para o tempo..
      if( val == -1 ) {
         printf("Erro: impossivel o mktime ter sido usado\n");
         return;
      }
      else{
        strftime(no->data,40,"%d/%m/%Y - %H:%M", juntaInicio); //após ter os dados transformo-os novamente em string
        no->prox = * lst; // o ponteiro desta estrutura fica com valor null (ficando a ser o ultimo da lista)
         * lst = no; //o valor apontado por lst passa a ser o valor que o no inicializou a lista
     }
   }
  }
 }

 void junta_valorManual(point * lstAux){ //inserir no fim da fila questao
   struct tm *juntaManual;
   point atual, ant, novo; //inicio 3 ponteiros
   int v, val, mes, ano, dia, hora, min, seg;
   float valor;
   time_t dat;
   time (&dat);
   char aux[100];
   if((v=listavaziamaquinas(*lstAux))==0){
     novo = (point)malloc(sizeof(dados)); // o novo para alocar uma estrutura do tipo listano no determinado local de memoria

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
     juntaManual = localtime(&dat);
     puts("Insira dia"); scanf("%d", &dia); flush_in();
     puts("Insira mes"); scanf("%d", &mes); flush_in();
     puts("Insira ano"); scanf("%d", &ano); flush_in();
     puts("Insira hora - Apenas a hora não os minutos"); scanf("%d", &hora); flush_in();
     puts("Insira minutos"); scanf("%d", &min); flush_in();
     puts("Insira segundos"); scanf("%d", &seg); flush_in(); //o mktime precisa dos segundos para acertar completamente nos termos da hora, deu alguns erros sem os segundos..
     if(dia ==0 && mes == 0 && ano == 0 && hora == 0 & min == 0 && seg == 0){ //por causa das falhas...
       strcpy(novo->data, "0");
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
       juntaManual->tm_year = (ano - 1900);
       juntaManual->tm_mon  = (mes -1);
       juntaManual->tm_mday = dia;
       juntaManual->tm_hour = hora;
       juntaManual->tm_min = min;
       juntaManual->tm_sec = seg;
       val=mktime(juntaManual);
       if( val == -1 ) {
        printf("Error:impossivel usar o mktime\n");
        return;
       }
       else{
       strftime(novo->data,40,"%d/%m/%Y - %H:%M", juntaManual);
       ant=NULL;
       atual=*lstAux; //o ponteiro atual começa no inicio da fila a apontar e vai seguindo enquanto o ant vai atrás deste

       while(atual != NULL){ //enquanto não chegar à lista que está no fim ele continua
             ant = atual; //a atual passa a ser a lista anterior(damos o valor da anterior)
             atual = atual->prox; // e aqui é quando se dá o proximo passo para a proxima lista
         }
             //*lstAux = novo; caso no main decidir enviar o & (**lst).prox
             ant->prox = novo;
       }
     }
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

 int comparaDatas(char data[40], int dia1, int mes1, int ano1, int dia2, int mes2, int ano2){
   char dataDia[3], dataMes[3], dataAno[5];
   int j=0, t=0, dia, mes, ano;
   for(int i=0; i<10; ++i){ //ciclo que vai retirar caracteres da string data
     if(i>=0 && i<2){
       dataDia[i]=data[i];
     }
     else{
       if(i>2 && i<=4){
         dataMes[j]=data[i];
         j++;
       }
       else{
         if(i>5 && i<=9){
           dataAno[t]=data[i];
           t++;
         }
       }
     }
   }
   dataDia[2]='\0'; //passar de vetor de caracteres para string
   dataMes[2]='\0';
   dataAno[4]='\0';

   dia = strtol(dataDia, NULL, 10); //transforma uma string em um inteiro de base 10
   mes = strtol(dataMes, NULL, 10);
   ano = strtol(dataAno, NULL, 10);
/*
   printf("%s\n", dataDia);
   printf("%s\n", dataMes);
   printf("%s\n", dataAno);

   printf("%d\n", dia);
   printf("%d\n", mes);
   printf("%d\n", ano);
*/
   if(ano >= ano1 && ano <= ano2 ){ //significa que esta dentro do intervalo de anos..
     puts("entra nos anos");
     if(ano == ano1 && ano == ano2){
       if(mes == mes1 && mes == mes2){ //meses iguais no intervalo
         puts("Sera nos meses");
         if(dia >= dia1 && dia <= dia2){
           puts("chega aqui");
           return 1;
         }
       }
       if(mes >= mes1 && mes <= mes2){
         if(mes == mes1){
           if(dia >= dia1){
             return 1;
           }
         }
         if(mes == mes2){
           if(dia <= dia2){
             return 1;
           }
         }
         return 1; //pois como se encontra dentro do intervalo de meses sem ser um dos extremos está no intervalo aceitavel
       }
     }
     else{
        if(ano == ano1 && ano < ano2){ //caso os anos não sejam os mesmos..
          if(mes >= mes1 && dia >= dia1)
            return 1;
      }
      else{
        if(ano > ano1 && ano == ano2){
          if(mes <= mes2 && dia <= dia2)
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
   char auxNome[100];
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
            printf(" %28s  %20.2f  %20.2f  %20.2f  %20.2f %20.2f  \n",atual->data, atual->temp, atual->humi, atual->co2, atual->EnerC, atual->producao);
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
   point atual;
   saveBin=fopen("basedadosMaquinas.dat", "wb");


   if(saveBin==NULL){
     printf("Erro ao abrir ficheiro, clique para sair\n"); getchar();
     fclose(saveBin);
     return;
   }
   else{
     fwrite(&counter, sizeof(int), 1, saveBin);
     fwrite(vetor, sizeof(maquinas)*10, 1, saveBin);
     while(i<counter){
       atual=vetor[i].head;
       lista=contaListas(vetor[i].head);
       fwrite(&lista, sizeof(int), 1, saveBin); //gravar o numero de listas que estão inseridas / contruidas..
       if(lista > 0){
         while(atual != NULL){ //preferi guardar elemento a elemento assim tenho noção que foi tudo gravado.
           fwrite(&(atual->data), sizeof(char)*40, 1, saveBin);
           fwrite(&(atual->temp), sizeof(float), 1, saveBin);
           fwrite(&(atual->humi), sizeof(float), 1, saveBin);
           fwrite(&(atual->co2), sizeof(float), 1, saveBin);
           fwrite(&(atual->EnerC), sizeof(float), 1, saveBin);
           fwrite(&(atual->producao), sizeof(float), 1, saveBin);
           atual=atual->prox;
         }
         i++;
       }
      else{ //o outro i esta dentro do if, isto porque se a maquina não tiver dados o programa rebenta ao gravar
         i++;
      }
    }
   }
   fclose(saveBin);
 }
//apenas envio o counter para que não tenha que estar a iniciar outra variavel aqui dentro mesmo podendo usar o mesmo nome, já tive problemas com isso, assim ao ler o codigo relembro o ponto ancora
int loadDataBase(maquinas vetor[TAMANHO], int counter){ //subprograma que vai fazer a leitura do que está no ficheiro..
 FILE *loadBin;
 int lista=0, i=0;
 point novo, no, atual;

 loadBin=fopen("basedadosMaquinas.dat", "rb");

 if(loadBin==NULL){
   printf("Erro ao abrir ficheiro ou não existente, clique para continuar\n"); getchar();
   fclose(loadBin);
   return 0;
 }
 else{
   fread(&counter, sizeof(int), 1, loadBin);//controle de não sair do vetor o numero de maquinas..
   fread(vetor, sizeof(maquinas)*10, 1, loadBin);
   while(i<counter){
     fread(&lista, sizeof(int), 1, loadBin); //para ir buscar o tamanho das listas que foram gravadas nos dados..

     vetor[i].head=crialistamaquinas(); //deixar o ponteiro a null, para se não houver dados dar lista vazia
     atual=vetor[i].head; //o mesmo que estar a null
     if(lista>0){ //para por no inicio da lista
       no = (point)malloc(sizeof(dados));
       fread(&(no->data), sizeof(char)*40, 1, loadBin);
       fread(&(no->temp), sizeof(float), 1, loadBin);
       fread(&(no->humi), sizeof(float), 1, loadBin);
       fread(&(no->co2), sizeof(float), 1, loadBin);
       fread(&(no->EnerC), sizeof(float), 1, loadBin);
       fread(&(no->producao), sizeof(float), 1, loadBin);

       no->prox = vetor[i].head; //o mesmo que estar igual a NULL
       vetor[i].head = no;
       atual = vetor[i].head; //fica a apontar para o mesmo local que o head..
     }
     lista=(lista-1);
     while(lista > 0){ //caso seja 0 inicialmente -1 não é maior que 0

       novo = (point)malloc(sizeof(dados));
       fread(&(novo->data), sizeof(char)*40, 1, loadBin);
       fread(&(novo->temp), sizeof(float), 1, loadBin);
       fread(&(novo->humi), sizeof(float), 1, loadBin);
       fread(&(novo->co2), sizeof(float), 1, loadBin);
       fread(&(novo->EnerC), sizeof(float), 1, loadBin);
       fread(&(novo->producao), sizeof(float), 1, loadBin);
       novo->prox = NULL;
       atual->prox = novo; //ainda esta no anterior e o seu proximo a apontar para o seguinte
       atual = atual->prox; //agora passar apontar para o que foi criado..
       lista--;
     }
     i++;

  }
   puts("Leitura de dados do ficheiro com sucesso!!\n");
   fclose(loadBin);
   return counter;
 }
}

void retiraMomento(point *lst, char n[40]){ // questao i)
  int v, str;
  point ant, atual;
  if((v=listavaziamaquinas(*lst))==0){
    atual=*lst;
    str=strcmp(atual->data, n);
    if(str==0){
      atual=atual->prox;
      *lst=atual;
    }
    else{
      while(atual != NULL){
        ant=atual;
        atual=atual->prox;
        str=strcmp(atual->data, n);
        if(str==0){ // caso seja igual é só ligar o anterior ao posterior, deixando este valor sem ligação.
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

void inserirMomentoRetirar(maquinas vetor[TAMANHO]){
  int indice;
  char auxNome[100], dataRetirar[40];
  puts("Indique em qual maquina quer retirar alguma inserção de dados");
  fgets(auxNome, 98, stdin);
  auxNome[strlen(auxNome)-1]='\0'; //retirar a linha..
  indice=existeMaquina(vetor, auxNome); //menos um porque ele soma inicialmente ou seja estando no primeiro indice tem de indicar para o indice 0, irei depois fazer isso dentro do if..
  if(indice>0){
    indice--; //deixar o indice no local correcto como foi mencionado em cima.
    puts("Insira a data a retirar, insira com o formato dd/mm/aaaa - HH:mm , caso contrario corre o risco de a data não ser encontrada");
    fgets(dataRetirar, 38, stdin);
    dataRetirar[strlen(dataRetirar)-1]='\0'; //retirar a linha..

    retiraMomento(&vetor[indice].head, dataRetirar);
  }
  else{
    puts("Maquina nao existe");
  }

}

int contaFalhas(point *lst){
  int conta=0, v, dat;
  point atual;
  atual=*lst;
  if((v=listavaziamaquinas(*lst))==0){
    while(atual != NULL){
      dat = strtol(atual->data, NULL, 10);
      if(dat == 0 && atual->temp == 0 && atual->humi == 0 && atual->co2 == 0 && atual->EnerC == 0 && atual->producao == 0)
        conta++;
      atual=atual->prox;
    }
  }
    else
      puts("Lista encontra-se vazia");
  return conta;
}

void retiraFalhas(point *lst){
  int v, datt;
  point ant, atual;
  if((v=listavaziamaquinas(*lst))==0){
    atual=*lst;
    datt=strtol(atual->data, NULL, 10);
    while(datt == 0 && atual->temp == 0 && atual->humi == 0 && atual->co2 == 0 && atual->EnerC == 0 && atual->producao == 0 && atual != NULL){
      atual=atual->prox;
      *lst=atual;
      if(*lst == NULL){ // caso toda a lista tenha valores iguais adaptei apra que fizesse primeiro um ciclo em vez de apenas uma condição
        break;
      }
      datt=strtol(atual->data, NULL, 10); //strtol apenas vai encontrar o 0.
    }
    if((*lst)->prox == NULL){
      puts("Terminado");
    }
    else{
      while(atual != NULL){
        ant=atual;
        atual=atual->prox;
        datt=strtol(atual->data, NULL, 10);
        if(datt == 0 && atual->temp == 0 && atual->humi == 0 && atual->co2 == 0 && atual->EnerC == 0 && atual->producao == 0){ // caso seja igual é só ligar o anterior ao posterior, deixando este valor sem ligação.
          ant->prox = atual->prox;
          atual=atual->prox;
        }
      }
      puts("Terminado");
    }
}
  else
    puts("Lista encontra-se vazia");

}

void inserirMaquinaFalhas(maquinas vetor[TAMANHO]){
  int indice, opcao, recebeNumero;
  char auxNome[100], dataRetirar[40];
  puts("Indique em qual maquina quer verificar se existem falhas");
  fgets(auxNome, 98, stdin);
  auxNome[strlen(auxNome)-1]='\0'; //retirar a linha..
  indice=existeMaquina(vetor, auxNome); //menos um porque ele soma inicialmente ou seja estando no primeiro indice tem de indicar para o indice 0, irei depois fazer isso dentro do if..
  if(indice>0){
      indice--; //deixar o indice no local correcto como foi mencionado em cima.
      do{
        puts("1 - Contar falhas");
        puts("2 - Retirar falhas");
        puts("3 - Sair");
        printf("\nOpcao: "); scanf("%d", &opcao);
        switch (opcao) {
          case 1: recebeNumero=contaFalhas(&vetor[indice].head);
                  if(recebeNumero){
                    printf("Existem %d falhas na lista ligada desta maquina\n", recebeNumero);
                  }
                  else{
                    puts("Nao existem falhas na lista ligada de dados da maquina");
                  }
                  break;

          case 2: retiraFalhas(&vetor[indice].head); break;

          case 3: break;

          default: printf("\nOpcao nao valida volte a tentar\n\n"); break;
        }
     }while(opcao != 3);
  }
  else{
    puts("Maquina nao existe");
  }


}

int comparaDuasDatas(char data1[40], char data2[40]){
  char dataDia1[3], dataDia2[3], dataMes1[3], dataMes2[3], dataAno1[5], dataAno2[5], dataHora1[3], dataMinuto1[3], dataHora2[3], dataMinuto2[3];
  int j=0, t=0, h=0, m=0, dia1, mes1, ano1, dia2, mes2, ano2, hora1, hora2, minuto1, minuto2;
  for(int i=0; i<18; ++i){
    if(i>=0 && i<2){
      dataDia1[i]=data1[i];
      dataDia2[i]=data2[i];
    }
    else{ //os else estão aqui para que umas condições não entrem nas outras.
      if(i>2 && i<=4){
        dataMes1[j]=data1[i];
        dataMes2[j]=data2[i];
        j++;
      }
      else{
        if(i>5 && i<=9){
          dataAno1[t]=data1[i];
          dataAno2[t]=data2[i];
          t++;
        }
        else{
          if(i>12 && i<15){
            dataHora1[h]=data1[i];
            dataHora2[h]=data2[i];
            h++;
          }
          else{
            if(i>15 && i<=17){
              dataMinuto1[m]=data1[i];
              dataMinuto2[m]=data2[i];
            }
          }
        }
      }
    }
  }


  dataDia1[2]='\0'; //deixar eles como string e não vetor de caracteres
  dataDia2[2]='\0';
  dataMes1[2]='\0';
  dataMes2[2]='\0';
  dataAno1[4]='\0';
  dataAno2[4]='\0';
  dataHora1[2]='\0';
  dataHora2[2]='\0';
  dataMinuto1[2]='\0';
  dataMinuto2[2]='\0';

  dia1 = strtol(dataDia1, NULL, 10); //transforma uma string em um inteiro de base 10
  dia2 = strtol(dataDia2, NULL, 10); //transforma uma string em um inteiro de base 10
  mes1 = strtol(dataMes1, NULL, 10);
  mes2 = strtol(dataMes2, NULL, 10);
  ano1 = strtol(dataAno1, NULL, 10);
  ano2 = strtol(dataAno2, NULL, 10);
  hora1 = strtol(dataHora1, NULL, 10);
  hora2 = strtol(dataHora2, NULL, 10);
  minuto1 = strtol(dataMinuto1, NULL, 10);
  minuto2 = strtol(dataMinuto2, NULL, 10);

  if(ano1 == ano2){
    if(mes1 == mes2){
      if(dia1 == dia2){ //caso os dias sejam iguais é que entra a hora
        if(hora1 == hora2 && minuto1 <= minuto2){
          return 0;
        }
        else{
          if(hora1 == hora2 && minuto1 > minuto2){
            return 1;
          }
          if(hora1 > hora2){
            return 1;
          }
          else{
            return 0; //caso a hora não seja maior no final de ter passado e negado todas as condições quer dizer que esta é menor ou igual
          }
        }
      }
      else{
        if(dia1 > dia2){
          return 1;
        }
        return 0; //caso o dia 2 seja maior que o dia 1 então já está por ordem crescente..
      }
    }
    else{
      if(mes1 > mes2){
        return 1;
      }
      else{
        return 0;
      }
    }
  }
  else{
    if(ano1 > ano2){
      return 1;
    }
    return 0;
  }

}

void trocar(point *a, point *b){
    char dataAux[40];
    float tempAux, humiAux, co2Aux, EnerCAux, producaoAux;
    //obter os valores de a para uma auxiliar
    strcpy(dataAux, (*a)->data);
    tempAux = (*a)->temp;
    humiAux = (*a)->humi;
    co2Aux = (*a)->co2;
    EnerCAux = (*a)->EnerC;
    producaoAux = (*a)->producao;

    //copiar os valores de b para a
    strcpy((*a)->data, (*b)->data);
    (*a)->temp = (*b)->temp;
    (*a)->humi = (*b)->humi;
    (*a)->co2 = (*b)->co2;
    (*a)->EnerC = (*b)->EnerC;
    (*a)->producao = (*b)->producao;

    //dar ao b os valores de a
    strcpy((*b)->data, dataAux);
    (*b)->temp = tempAux;
    (*b)->humi = humiAux;
    (*b)->co2 = co2Aux;
    (*b)->EnerC = EnerCAux;
    (*b)->producao = producaoAux;

}

void ordemCrescente(point *lst){
  int fail;
  fail=contaFalhas(&(*lst));
  if(fail){
    puts("Existem falhas nas datas do sistema apagar antes de ordenar");
  }
  else{

    int trocado, i, v, comparador;
    point atual;
    if((v=listavaziamaquinas(*lst))==0){
      do{
          trocado = 0; // caso esteja ordenada então sai do do while..
          atual = *lst;

          while (atual->prox != NULL){
            comparador=comparaDuasDatas(atual->data, atual->prox->data);
              if(comparador){ //caso seja o return 1 e que entra aqui
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
}

void inserirMaquinaOrdem(maquinas vetor[TAMANHO]){ //subprograma que vai escolher a maquina a por em ordem crescente
  int indice;
  char auxNome[100];
  puts("Indique em qual maquina quer ordenar");
  fgets(auxNome, 98, stdin);
  auxNome[strlen(auxNome)-1]='\0'; //retirar a linha..
  indice=existeMaquina(vetor, auxNome); //menos um porque ele soma inicialmente ou seja estando no primeiro indice tem de indicar para o indice 0, irei depois fazer isso dentro do if..
  if(indice>0){
    indice--; //deixar o indice no local correcto como foi mencionado em cima.
    ordemCrescente(&vetor[indice].head);
  }
  else{
    puts("Maquina nao existe");
  }


}

void gravarExcel(maquinas vetor[TAMANHO], int counter){ //subprograma para gravar em excel como a stora ensina na ficha
  FILE *saveEx;
  int i=0;
  point atual;
  saveEx=fopen("basedadosMaquinas.csv", "w");


  if(saveEx==NULL){
    printf("Erro ao abrir ficheiro, clique para sair\n"); getchar();
    fclose(saveEx);
    return;
  }
  else{
    while(i<counter){
      fprintf(saveEx, "\n %s ;", "Maquina: ");
      fprintf(saveEx, "%s \n\n", vetor[i].nome);
      atual=vetor[i].head;
      fprintf(saveEx, "%s ; %s ; %s ; %s ; %s ; %s \n", "Data", "temperatura", "Humidade", "Co2", "Energia Consumida", "Producao");
      while(atual != NULL){
        fprintf(saveEx, "%s ;", atual->data);
        fprintf(saveEx, "%.2f ;", atual->temp);
        fprintf(saveEx, "%.2f ;", atual->humi);
        fprintf(saveEx, "%.2f ;", atual->co2);
        fprintf(saveEx, "%.2f ;", atual->EnerC);
        fprintf(saveEx, "%.2f \n", atual->producao);
        atual=atual->prox;
      }
      i++;
    }
  }
  fclose(saveEx);
}

void filtroSuperior(maquinas vetor[TAMANHO]){ //subprograma que tem as condições para que os valores sejam superiores, ter a noção que a data vai ate a hora na comparação
  float auxpro;
  char dataSup[40], auxNome[100];
  int indice, datasComparadas;
  point atual;
  puts("Indique em qual maquina quer verificar");
  fgets(auxNome, 98, stdin);
  auxNome[strlen(auxNome)-1]='\0'; //retirar a linha..
  indice=existeMaquina(vetor, auxNome); //menos um porque ele soma inicialmente ou seja estando no primeiro indice tem de indicar para o indice 0, irei depois fazer isso dentro do if..
  if(indice>0){
      indice--; //deixar o indice no local correcto como foi mencionado em cima.
      puts("Insira a data no formato (dd/mm/yyyy - HH:MM), nao esquecer de inserir os / nem do - no meio");
      fgets(dataSup, 38, stdin);
      dataSup[strlen(dataSup)-1]='\0'; //retirar a linha a mais..
      puts("Insira a produção superior a procurar"); scanf("%f", &auxpro);
      printf(" %28s  %20s  %20s %20s %20s %20s \n", "Data", "temperatura", "Humidade", "Co2", "Energia Consumida", "Producao");
      atual=vetor[indice].head;

      while(atual != NULL){
        datasComparadas=comparaDuasDatas(atual->data, dataSup);
        printf("%d\n", datasComparadas);
        if(datasComparadas > 0 && auxpro < atual->producao){ //superior mas não igual..
          printf(" %28s %20.2f  %20.2f  %20.2f  %20.2f %20.2f  \n", atual->data, atual->temp, atual->humi, atual->co2, atual->EnerC, atual->producao);
        }
        atual=atual->prox;
      }
   }

}
//decidi deixar este porque acho que para fazer bateria de testes consegue ver na totalidade o que cada maquina tem de dados..
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
       printf(" %28s  %20s  %20s %20s %20s %20s \n", "Data", "temperatura", "Humidade", "Co2", "Energia Consumida", "Producao");
       while(atual != NULL){
         printf(" %28s %20.2f  %20.2f  %20.2f  %20.2f %20.2f  \n", atual->data, atual->temp, atual->humi, atual->co2, atual->EnerC, atual->producao);
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


int main(){
   maquinas vetor[TAMANHO];
   int counter=0, opcao;
   counter=loadDataBase(vetor, counter); //aqui o contador irá receber um valor que é o numero de indices ocupados no vetor de esruturas..
   do{
     puts("1 - Inserir nova maquina");
     puts("2 - Inserir dados");
     puts("3 - Mostrar dados num intervalo de tempo");
     puts("4 - Gravar Dados");
     puts("5 - Inserir dados manualmente");
     puts("6 - Retirar, da lista de uma maquina, os dados de um momento indicado pelo utilizador");
     puts("7 - Contagem e retirar Falhas");
     puts("8 - Ordenação das datas por ordem crescente");
     puts("9 - Lista filtro data superior e nao igual à inserida e produção superior e nao igual à inserida");
     puts("10 - Gravar em ficheiro Excel");
     puts("12 - MostrarLista(Teste Prog)");

     puts("11 - sair");
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

       case 6: inserirMomentoRetirar(vetor); break;

       case 7: inserirMaquinaFalhas(vetor); break;

       case 8: inserirMaquinaOrdem(vetor); break;

       case 9: filtroSuperior(vetor); break;

       case 10: gravarExcel(vetor, counter); break;

       case 11: break;

       case 12: mostrarDados(vetor); break;

       default: printf("\nOpcao nao valida volte a tentar\n\n"); break;
     }



   }while(opcao != 11);

   saveDataBase(vetor, counter);
   puts("Aviso: Os seus dados foram gravados autmaticamente antes do programa terminar.");

 return 0;
 }
