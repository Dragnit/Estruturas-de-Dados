#include <stdio.h>

int inserir_numeros(int tam, int string[tam])
{
  for(int i = 0; i < tam;i++)
  {
    printf("Introduza o numero: ");
    scanf("%d", &string[i]);
  }
}
int inverternum_rec(int tam, int string[tam])
{
  int i=0, aux, j;
  j=tam-1;
  if(tam <= 1)
   return 1;
  else
  {
    aux = string[i];
		string[i] = string[j];
		string[j] = aux;
  }
   return inverternum_rec(tam-2, string+1);
}
void inverternum_ite(int tam, int string[tam])
{

  printf("Vetor invertido: \n");
  for(int m = tam-1; m >= 0; m--)
  {
    printf("%d\n", string[m]);
  }
}
void main()
{
  int tam;
  printf("Introduza quantos numeros quer inserir: ");
  scanf("%d", &tam);
  int string[tam];
  inserir_numeros(tam, string);

  inverternum_ite(tam, string);
  printf("\n");
  string[tam]= inverternum_rec(tam, string);
  printf("Vetor Invertido: \n");
  for(int i = 0; i < tam; i++)
  {
    printf("%d\n", string[i]);
  }
}
