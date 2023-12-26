#include <stdio.h>
int c, primeiro, ultimo, meio, n, procurar, array[100];
int PesquisaBin()
{
  primeiro = 0;
  ultimo = n - 1;
  meio = (primeiro+ultimo)/2;
  while (primeiro <= ultimo)
  {
    if (array[meio] < procurar)
    primeiro = meio + 1;
    else
    if (array[meio] == procurar)
    {
      return procurar;
      break;
    }
    else
    ultimo = meio - 1;
    meio = (primeiro + ultimo)/2;
  }
  if (primeiro > ultimo)
  return -1;
}
int main()
{
  printf("Insira o numero de elementos do array:\n");
  scanf("%d",&n);
  printf("Preencha o array:\n", n);
  for (c = 0; c < n; c++)
  scanf("%d",&array[c]);
  printf("Insira o numero a procurar:\n");
  scanf("%d", &procurar);
  if(PesquisaBin()==-1)
  {
    printf("\nValor nao encontrado no array!");
  }
  else
  printf("\nValor encontrado na posicao %d!", meio);
}
