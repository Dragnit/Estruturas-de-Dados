#include <stdio.h>
#include <stdlib.h>

void criaTabela(int vec[], int a)
{
  for (int i = 0; i < a; i++)
  {
    vec[i] = rand()%50 + 1;
  }
}

void escreveArray(int v[], int n)
{
  printf("vetor original\n");
  for(int i = 0; i < n; i++)
    printf("%i\t", v[i]);
}

void moveElementos(int elementos[], int numeroElementos)
{
  int ultimaPosicao;
  ultimaPosicao = elementos[0];
  for (int i= 0; i < numeroElementos - 1; i++)
  {
    elementos[i] = elementos[i+1];
  }
  elementos[numeroElementos - 1] = ultimaPosicao;
  printf("\nvetor alterado\n");
  for (int i= 0; i < numeroElementos; i++)
  {
   printf("%d\t", elementos[i]);
  }

}

void main()
{
  int a;

  printf("Insira o numero de elementos da tabela\t");
  scanf("%d", &a);

  int vetor[a];
  criaTabela(vetor, a);
  escreveArray(vetor, a);
  moveElementos(vetor, a);
}
