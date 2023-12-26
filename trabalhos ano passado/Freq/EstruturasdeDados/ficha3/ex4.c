#include<stdio.h>

 /*--------------------------------------------------------------
 --------------------------------------------------------------
 Proprietário: Jorge Miguel dos Santos Martins
 Curso: Licenciatura Sistemas Tecnologias de Informação
 Disciplina: Programação II / Estruturas Dados
 Data:01 de Abril de 2020
 Programa/Exercicio: Exercicio 4 / Ficha 3
 --------------------------------------------------------------
 --------------------------------------------------------------
 */
 void flush_in(){ // codigo para limpeza de buffer do teclado..
    int ch;
    while( (ch = fgetc(stdin)) != EOF && ch != '\n' ){}
    return;
  }

  void inicializer(int tamanho, float *p){ //alinea a)

    for(int i=0; i<(tamanho*tamanho); ++i){
      *p=-1;
      p++;
    }
  }

  void inicializerCresc(int tamanho, float *p){ //alinea b))

    for(int i=0; i<(tamanho*tamanho); ++i){
      *p=(i+1);
      p++;
    }
  }

  void giveValue(int tamanho, float *p, int i, int j){ //alinea c)

    float val;

    printf("Insira o valor a inserir: "); scanf("%f", &val); printf("\n");
    p=p+(i*tamanho+j); //multiplica a linha desejada pelo total de colunas da matriz e em seguida soma-se a coluna desejada. Em c alocação de matrizes em memoria é unilateral(sempre seguido).
    *p=val;
    flush_in();
  }

  void sum(int tamanho, float * p1, float *p2){

    for(int i=0; i<(tamanho*tamanho); ++i){
      *p1= *p1 + *p2;
      p1++;
      p2++;
    }
  }

  void test(int tamanho, float *p){

    for(int a=0; a<(tamanho*tamanho); ++a){
      if(a%tamanho==0){
        printf("\n");
      }
      printf(" %.1f ", *p);
      p++;
    }
    getchar();
  }

 int main(){

   int tamanho = 20, i, j;

   float array[tamanho][tamanho], array2[tamanho][tamanho];

   printf("\t\tIniciar com -1\n");
   inicializer(tamanho, &array[0][0]);
   test(tamanho, &array[0][0]);
   printf("\n\n\t\t Iniciar uma tabela de forma crescente\n");
   inicializerCresc(tamanho, &array2[0][0]);
   test(tamanho, &array2[0][0]);
   printf("\n\t\tInserir valor dentro da matriz A que tem tudo a -1\n\n");
   printf("Insira em que linha quer inserir o valor: "); scanf("%d", &i);
   printf("\nInsira em que coluna quer inserir o valor: "); scanf("%d", &j); printf("\n");
   giveValue(tamanho, &array[0][0], i, j);
   test(tamanho, &array[0][0]);
   printf("\n\n\t\t\tSoma das duas matrizes\n");
   sum(tamanho, &array[0][0], &array2[0][0]);
   test(tamanho, &array[0][0]);



	return 0;
}
