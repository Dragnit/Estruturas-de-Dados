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

void media(int v[], int n)
{
  int pares = 0;
  int impares = 0;
  int mediaPares = 0;
  int mediaImpares = 0;

  for(int i = 0; i < n; i++)
    {
      if(v[i]%2 == 0)
        {
          pares++;
          mediaPares = mediaPares + v[i];
        }
      else
      {
        impares++;
        mediaImpares = mediaImpares + v[i];
      }
    }
  printf("media de pares: %f \nmedia de impares: %f", mediaPares*1.0/pares, mediaImpares*1.0/impares);
}

void main()
{
  int a;

  printf("Insira o numero de elementos da tabela\t");
  scanf("%d", &a);

  int vetor[a];
  criaTabela(vetor, a);
  escreveArray(vetor, a);
  media(vetor, a);
}
