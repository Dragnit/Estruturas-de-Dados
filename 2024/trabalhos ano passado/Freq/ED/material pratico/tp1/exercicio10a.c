#include <stdio.h>

int inserirelemento(int vec[], int num) {
  int valor,i;

  printf("\nQual e o valor que pretende inserir no vetor? ");
  scanf("%d",&valor);

  for (i = num - 1; (i >= 0 && vec[i] > valor); i--)
        vec[i + 1] = vec[i];

    vec[i + 1] = valor;

    return (num + 1);
}

int main() {
  int arr[20] = { 10, 20, 30, 40, 50, 60 };
  int n = 6, i;

  printf("\nAntes da insercao o vetor encontra-se ordenado desta forma: ");

  for (i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }

  printf("\n");

  inserirelemento(arr,n);

  printf("\nDepois da insercao o vetor encontra-se ordenado desta forma: ");

  for (i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
}
