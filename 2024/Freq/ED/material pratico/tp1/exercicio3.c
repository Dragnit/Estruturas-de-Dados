#include <stdio.h>

int valor;

int deslocarelementos (int valor, int vec[]) {
  int value = vec[0];

  for(int i = 0; i < valor - 1; i++) {
    vec[i] = vec[i+1];
  }
  vec[valor-1] = value;

  printf("Os valores, apos serem trocados sao: ");
  for (int i=0; i<valor; i++) {
    printf("%d ", vec[i]);
  }
}


int main () {
  int v,i;

  printf("Quantos valores deseja inserir no vetor?: ");
  scanf("%d",&valor);

  int vec[valor];

  for (i=0; i<valor; i++) {
    printf("Valor para inserir: ");
    scanf("%d", &vec[i]);
  }
  printf("Os valores, antes de serem trocados eram: ");
    for (i=0; i<valor; i++) {
      printf("%d ", vec[i]);
    }
  printf("\n");

  deslocarelementos(valor,vec);
}
