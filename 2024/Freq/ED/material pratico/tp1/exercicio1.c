#include <stdio.h>

void lerelementosvetor()
{
  int num,v;
  printf("Quantos numeros pretende inserir? ");
  scanf("%d",&num);

  int vec[num];

  printf("\n");

  for (int i = 0; i < num; i++) {
    printf("Insira o valor ");
    scanf("%d",&v );
    vec[i] = v;
  }

  printf("Os valores inseridos no vetor foram: ");
  for (int i = 0; i < num; i++) {
      printf("%d ", vec[i]);
  }
}

int main() {
  lerelementosvetor();
}
