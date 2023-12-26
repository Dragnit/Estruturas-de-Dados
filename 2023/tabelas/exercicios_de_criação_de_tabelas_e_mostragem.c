#include <stdio.h>
#define DIM 10

void criaTabela(int vec[])
{
  for(int i = 0; i < DIM; i++)
    vec[i] = i + 1;
}

void escreveArray(int v[], int n)
{
  printf("vetor\n");
  for(int i = 0; i < n; i++)
    printf("elemento %i:\t%i\n", i, v[i]);
}

void main()
{
  int vetor[DIM];
  criaTabela(vetor);
  escreveArray(vetor, DIM);
}
