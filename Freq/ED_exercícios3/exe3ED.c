#include <stdio.h>

void trocaA(int *x, int *y)
{
int aux;
aux = *x;
*x = *y;
*y = aux;
printf("%d\n",*x);
printf("%d", *y);
}
void trocaB(int *x, int *y)
{
int * aux;
aux = x;
x = y;
y = aux;
printf("%d\n",x);
printf("%d", y);
}
void trocaC(int *x, int *y)
{
int aux;
aux = *x;
x = *y;
*y = aux;
printf("%d\n",x);
printf("%d", *y);
}
int main()
{
 int *a=5, *b=12;
 unsigned long int i, j;
 i = &a;
 j = &b;
 
 //Chamada da função 2
 trocaA(a,b);
 printf("\n");
 trocaB(a,b);
 printf("\n");
 trocaC(a,b);
 printf("\n\n");
}
