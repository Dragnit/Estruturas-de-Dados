#include <stdio.h>
int escrever_elementos(int numero[], int num_elementos)
{
  for (int m=0; m < num_elementos; m++ )
  {
    printf("Introduza o numero: ");
    scanf("%d", &numero[m]);
  }
}
int mover_elementos(int numero[], int num_elementos)
{
  int ultima_posicao;
  ultima_posicao = numero[0];
  for (int i= 0; i < num_elementos; i++)
  {
    numero[i]=numero[i+1];
  }
  numero[num_elementos-1]=ultima_posicao;
  for (int i= 0; i < num_elementos; i++)
  {
   printf("elemento %d: %d\n", i, numero[i]);
  }
}
int main()
{
  int num_elementos;
  printf("Introduza o tamanho do vetor: ");
  scanf("%d", &num_elementos);
 int numero[num_elementos];
 escrever_elementos(numero, num_elementos);
 mover_elementos(numero, num_elementos);
	return 0;
}
