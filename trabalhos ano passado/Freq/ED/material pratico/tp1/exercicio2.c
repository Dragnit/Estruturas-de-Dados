#include <stdio.h>
#include <stdlib.h>

void inserirnumerosaleatorios()
{
  int max = 30;
  int vec[max];

  for (int i = 0; i < max; i++) {
    vec[i] = rand() % 50 + 1;
  }

  for (int i = 0; i < max; i++) {
      printf("O valor inserido foi %d\n", vec[i]);
  }
}

int main() {
  inserirnumerosaleatorios();
}
