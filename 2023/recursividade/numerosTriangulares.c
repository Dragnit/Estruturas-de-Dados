#include <stdio.h>

int calcularNumeroTriangular(int n) 
{
    return n * (n + 1) / 2;
}

int main() 
{
    int n;
    printf("Digite o valor de n: ");
    scanf("%d", &n);

    int numeroTriangular = calcularNumeroTriangular(n);
    printf("O %d numero triangular e %d\n", n, numeroTriangular);

    return 0;
}
