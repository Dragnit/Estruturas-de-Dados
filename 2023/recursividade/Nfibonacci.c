#include <stdio.h>

int calcularFibonacci(int n) 
{
    if (n <= 1) {
        return n;
    }

    return calcularFibonacci(n - 1) + calcularFibonacci(n - 2);
}

int main()
{
    int n;
    printf("Digite o valor de n: ");
    scanf("%d", &n);

    int fibonacci = calcularFibonacci(n);
    printf("O %d numero de Fibonacci e %d\n", n, fibonacci);

    return 0;
}
