#include <stdio.h>
void bubble_sort(int vetor[], int tamanho)
{
  int aux;
  for (int i = 0; i < tamanho; i++)
  {
    printf("Introduza o elemento: ");
    scanf("%d", &vetor[i]);
  }
for (int j = 0; j < tamanho; j++)
{
  for (int i = 0; i < tamanho-j-1; i++)
    if(vetor[i] < vetor[i+1])
    {
     aux = vetor[i];
     vetor[i] = vetor[i+1];
     vetor[i+1] = aux;
    }
 }
   printf("Vetor ordenado por ordem decrescente: ");
   for (int i = 0; i < tamanho; i++)
    printf("%d ", vetor[i]);
}
int main()
{
 int tamanho;
 printf("Introduza o tamanho do vetor: ");
 scanf("%d", &tamanho);
 int vetor[tamanho];
 bubble_sort(vetor, tamanho);
	return 0;
}
