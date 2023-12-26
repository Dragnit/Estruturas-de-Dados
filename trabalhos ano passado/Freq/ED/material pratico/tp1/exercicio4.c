#include <stdio.h>

int main()
{
  int numpar,numimpar,valorpar,valorimpar;
  float media = 0, media1 = 0, soma = 0,soma1 = 0;
  printf("Quantos numeros pares pretende inserir? ");
  scanf("%d",&numpar);
  printf("Quantos numeros impares pretende inserir? ");
  scanf("%d",&numimpar);

  int vecpar[numpar],vecimpar[numimpar];

  printf("\n");

  for (int i = 0; i < numpar; i++) {
    printf("Insira os numeros pares ");
    scanf("%d",&valorpar);
    vecpar[i] = valorpar;
  }

  for (int i = 0; i < numimpar; i++) {
    printf("Insira os numeros impares ");
    scanf("%d",&valorimpar);
    vecimpar[i] = valorimpar;
  }

  printf("Numero de numeros pares inseridos: %d\n", numpar);
  printf("Numero de numeros impares inseridos: %d\n", numimpar);

  printf("Os numeros pares inseridos foram: ");
  for (int i = 0; i < numpar; i++) {
      printf("%d ", vecpar[i]);
  }

  printf("\n");

  printf("Os numeros impares inseridos foram: ");
  for (int i = 0; i < numimpar; i++) {
      printf("%d ", vecimpar[i]);
  }

  for (int i = 0; i < numpar; i++) {
      soma = soma + vecpar[i];
  }
  media = soma / numpar;
  printf("\n");
  printf("A media dos numeros pares e %.2f: ", media);

  for (int i = 0; i < numimpar; i++) {
      soma1 = soma1 + vecimpar[i];
  }
  media1 = soma1 / numimpar;
  printf("\n");
  printf("A media dos numeros pares e %.2f: ", media1);
}
