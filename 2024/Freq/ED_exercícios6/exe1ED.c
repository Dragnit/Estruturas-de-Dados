#include <stdio.h>

int fatorial_recursiva(int n)
{
  if (n <= 0)
   return 1;
  else
   return n * fatorial_recursiva(n-1);
}

int fatorial_iterativa(int n)
{
  int fatorial = 1;
  for(int i=1; i <= n; i++)
   fatorial = fatorial * i;
   return fatorial;
}
void main()
{
 int n;
 printf("Introduza o numero para calcular o fatorial: ");
 scanf("%d", &n );

 printf("O fatorial de %d e: %d\n", n, fatorial_recursiva(n));

  printf("Fatorial: %d\n", fatorial_iterativa(n));
}
