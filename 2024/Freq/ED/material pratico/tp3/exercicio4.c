#include <stdio.h>
#include <stdlib.h>

void inicializa_matrizA () {
  int m[20][20];
  int *pm;
  int i,j;

pm = m[0];
*pm = -1;

for (i = 0; i < 20;i++) {
  for (j = 0;j < 20;j++) {
    m[i][j]=*pm;
  }
}

printf("Matriz A:\n");
for (i = 0; i < 20;i++) {
  for (j = 0;j < 20;j++) {
    printf("%d ",m[i][j] );
  }
  printf("\n");
}
}

void inicializa_matrizB () {
  int m[20][20];
  int *pm;
  int i,j;
  int contador = 0;

pm = m[0];
*pm = 1;

for (i = 0; i < 20;i++) {
  for (j = 0;j < 20;j++) {
    m[i][j]=*pm + contador;
    contador++;
  }
}

printf("Matriz B:\n");
for (i = 0; i < 20;i++) {
  for (j = 0;j < 20;j++) {
    printf("%d ",m[i][j]);
  }
  printf("\n");
}
}

void atribui_valor_ij () {
  int m[20][20];
  int *pm;
  int i,j,coluna,linha,valor;

pm = m[0];
*pm = 1;

for (i = 0; i < 20;i++) {
  for (j = 0;j < 20;j++) {
    m[i][j]=*pm;
  }
}

coluna = rand() % 20 + 1;
linha = rand() % 20 + 1;

printf("Qual e o valor que deseja inserir? ");
scanf("%d",&valor);

m[linha][coluna] = valor;

printf("Matriz C:\n");
for (i = 0; i < 20;i++) {
  for (j = 0;j < 20;j++) {
    printf("%d ",m[i][j] );
  }
  printf("\n");
}
}

int main () {
   inicializa_matrizA();
   printf("\n");
   inicializa_matrizB();
   printf("\n");
   atribui_valor_ij();
   printf("\n");
}
