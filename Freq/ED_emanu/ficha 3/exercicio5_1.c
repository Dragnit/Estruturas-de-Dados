#include<stdio.h>

int main()
{

  char str[20], *pt;
  int i = 0;
  printf("Escreva uma string com menos de 20 caracteres: ");
  gets(str);
  pt = str;
  while (*pt != '\0')
    {
      i++;
      pt++;
    }
  printf("Tamanho da string: %d", i);

  return 0;
}
