#include<stdio.h>

int main(){

  int a = 2, b = 3;
  int *p, *q;
  p = &a;
  q = &b;
  //Alinea 1a
  printf("Valor da alinea i: %d\n",p == &a);
  printf("Valor da alinea ii: %d\n",*p - *q);
  printf("Valor da alinea iii: %d\n",**&p);
  printf("Valor da alinea iv: %d\n",*p+1);
  printf("Valor da alinea v: %d\n",*(q-2));

  //Alinea 1b
  printf("\n%p %u %u %d %d %d %d\n",p,p,&p,*p+4,**&p,5**p,**&p+6);

}
