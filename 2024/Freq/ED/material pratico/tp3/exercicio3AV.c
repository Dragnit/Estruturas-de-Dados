#include <stdio.h>

void troca(int *x, int *y)
{
  int aux;
  aux = *x;
  *x = *y;
  *y = aux;
}
int main(){

  int *a=5, *b=12;
  unsigned long int i=1001, j=1002;
  i = &a;
  j = &b;

  printf("Antes da funcao troca\n");
  printf("Valor de a:%d\n",a);
  printf("Valor de b :%d\n",b);
  printf("Valor de &a:%d\n",&a);
  printf("Valor de &b :%d\n",&b);
  printf("Valor de i:%d\n",i);
  printf("Valor de j:%d\n",j);
  printf("Valor de &i:%d\n",&i);
  printf("Valor de &j:%d\n",&j);
  troca(*a,*b);
  printf("\nDepois da funcao troca\n");
  printf("Valor de a:%d\n",a);
  printf("Valor de b :%d\n",b);
  printf("Valor de &a:%d\n",&a);
  printf("Valor de &b :%d\n",&b);
  printf("Valor de i:%d\n",i);
  printf("Valor de j:%d\n",j);
  printf("Valor de &i:%d\n",&i);
  printf("Valor de &j:%d\n",&j);

}
