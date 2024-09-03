#include <stdio.h>
void sequencia_rec(int n)
{
 if(n == 1)
  printf("%d", n);
 else
 {
   printf("%d",n);
   sequencia_rec(n-1);
   printf("%d",n);
 }
 
}
 void sequencia_ite(int n)
 {
   int m = n;
   while(n > 1)
   {
    printf("%d", n);
    n--;
   }
   while(n <= m)
  {
    printf("%d", n);
    n++;
  }
 }
void main()
{
  int n;
  printf("Introduza um numero para fazer a sequencia: ");
  scanf("%d", &n);
  sequencia_rec(n);
  printf("\n");
  sequencia_ite(n);
}