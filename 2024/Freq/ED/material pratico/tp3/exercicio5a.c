#include <stdio.h>
#define TAM 50

int main(){

  char *q , string[TAM];
  int contadorchar = 0;

  printf("Escreva uma string :");
  gets(string);
  q=string;
  while (*q++ != '\0')
  contadorchar++;
  printf("A string tem %d caracteres",contadorchar);
}
