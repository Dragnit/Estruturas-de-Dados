#include <stdio.h>

int escrever_elementos(int escrever[], int dim_string)
{
  for (int i = 0; i < dim_string; i++)
  {
    printf("Introduza o elemento: ");
    scanf("%d", &escrever[i]);
  }
}
int ler_string(int ler[], int dim_string)
{
  for (int j = 0; j < dim_string; j++)
  {
    printf("elemento %d: %d \n", j, ler[j]);
  }
}

int main()
{
  int dim_string;
  printf("Introduza quantos elementos quer inserir: ");
  scanf("%d", &dim_string);
  printf("\n");
  int string[dim_string];
  escrever_elementos(string, dim_string);
  printf("\n");
  ler_string(string, dim_string);
	return 0;
}
