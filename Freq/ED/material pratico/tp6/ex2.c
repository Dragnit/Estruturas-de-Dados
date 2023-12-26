#include <stdio.h>

int fibonaccir(int n)
{
  if(n==1 || n==2)
  return 1;
  else
  return fibonaccir(n-1) + fibonaccir(n-2);
}

int fibonaccii(int n) {
  int i, fib1 = 1, fib2 = 1, soma;
  for (i = 3; i <= n; i = i + 1){
    soma = fib1 + fib2;
    fib1 = fib2;
    fib2 = soma;
  }
  return fib2;
}

int main(){

  int n,i;

  printf("Digite o termo da sequencia de Fibonacci: ");
  scanf("%d", &n);
  printf("\nO termo %d da sequencia de Fibonacci (recursiva):",n);
  printf("%d ", fibonaccir(n));
  printf("\nO termo %d da sequencia de Fibonacci (iterativa):",n);
  printf("%d\n", fibonaccii(n));

}
