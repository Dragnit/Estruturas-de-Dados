#include <stdio.h>

int main()
{
  int num;
	printf("Introduza quantos numeros quer inserir: ");
  scanf("%d", &num );
  printf("\n");
  int string[num];
  float media_impares, media_pares;
  int soma =0, soma_pares = 0;
  int somou = 0, somou_pares = 0;
  for(int i = 0; i < num; i++)
  {
    printf("Introduza um numero: ");
    scanf("%d", &string[i]);
  }
  for (int j = 0; j < num; j++)
  {
   if(string[j] % 2 != 0)
   {
    soma = soma + string[j];
    somou++;
    media_impares= soma / somou;
   }
   if(string[j] % 2 == 0)
   {
     soma_pares = soma_pares + string[j];
     somou_pares++;
     media_pares= soma_pares / somou_pares;
   }
 }
 printf("media impares: %0.1f\n", media_impares );

 printf("media pares: %0.1f", media_pares);
}
