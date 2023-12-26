#include <stdio.h>

void criaTabela(int vec[], int a)
{
  int b;

  for (int i = 0; i < a; i++)
  {
    printf("Insira o proximo elemento:\t ");
    scanf("%d", &b);
    vec[i] = i + 1;
  }
}

void escreveArray(int v[], int n)
{
  printf("vetor\n");
  for(int i = 0; i < n; i++)
    printf("elemento %i:\t%i\n", i, v[i]);
}

void main()
{
  int a;

  printf("Insira o numero de elementos da tabela\t");
  scanf("%d", &a);

  int vetor[a];
  criaTabela(vetor, a);
  escreveArray(vetor, a);
}
