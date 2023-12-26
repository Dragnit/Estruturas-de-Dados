#include <stdio.h>

int pesquisabinaria () {
  int n = 0, value, valor, vec[1000],num;

  printf("Quantos valores pretende inserir? ");
  scanf("%d",&num);

  for (int i = 0; i < num; i++) {
    printf("Qual e o valor que quer inserir? ");
    scanf("%d",&value);
    vec[i] = value;
}

  printf("Qual e o valor que deseja consultar? ");
  scanf("%d",&valor);

  while (n <= num-1) {
    int meio = n + (num - n) / 2;

    if (vec[meio] == valor)
      return meio;
    else
      if (vec[meio] < valor)
        n = meio + 1;
      else
        n = meio - 1;
  }

  return -1;
}

int main() {
  int resultado;

  resultado = pesquisabinaria();

  if (resultado != -1)
    printf("O elemento esta presente no indice %d",resultado);
  else
    printf("O elemento nao esta presente");
}
