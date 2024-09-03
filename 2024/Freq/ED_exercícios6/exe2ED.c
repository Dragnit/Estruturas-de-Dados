#include <stdio.h>

int fibonacci_rec(int n)
{
  if (n == 2 || n == 1)
   return 1;
  else
   return fibonacci_rec(n-1) + fibonacci_rec(n-2);
}

int fibonacci_ite(int n)
{
  int a = 0;
  int b = 1;
  int soma =0;
  for(int i=1; i < n; i++)
  {
    soma= a + b;
    a=b;
    b = soma;
  }
   return b;
}

void main()
{
 int n;
 printf("Introduza o numero para calcular a serie de Fibonacci: ");
 scanf("%d", &n);

 printf("O numero de Fibonacci de %d e: %d\n", n, fibonacci_rec(n));
 printf("O numero de Fibonacci de %d e: %d\n", n, fibonacci_ite(n));

}
