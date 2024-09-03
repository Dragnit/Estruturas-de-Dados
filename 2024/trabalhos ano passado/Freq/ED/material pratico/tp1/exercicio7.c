#include <stdio.h>

int vec[1000],num,contador=0;

int lervalores(int num) {
  int value;

  for (int i = 0; i < num; i++) {
    printf("Qual e o valor que quer inserir? ");
    scanf("%d",&value);
    vec[i] = value;
    contador++;
  }
}

int numocorrencias (int num) {
  int valor,contador = 0;

  printf("Qual e o numero que pretende consultar? ");
  scanf("%d", &valor);

  for (int i=0; i<num; i++)
  {
    if (valor == vec[i])
      contador++;
  }

  printf("O numero aparece %d vezes no vetor",contador);
}

int ocorrencias(int num) {
  int primeiro = -1, valor, ultimo = -1;

  printf("Qual e o numero que pretende consultar? ");
  scanf("%d", &valor);

  for (int i=0; i<num; i++)
  {
    if (valor != vec[i])
      continue;
    if (primeiro == -1)
      primeiro = i;
      ultimo = i;
  }
    if (primeiro != -1) {
      printf("A primeira ocorrencia do valor %d ocorre no indice %d do vetor\n",valor,primeiro);
      printf("A ultima ocorrencia do valor %d ocorre no indice %d do vetor\n",valor,ultimo);
    }
    else
      return -1;
}

int main() {

  printf("Quantos valores pretende inserir? ");
  scanf("%d",&num);

  lervalores(num);
  printf("\n");
  numocorrencias(num);
  printf("\n");
  ocorrencias(num);
  printf("\n");
}
