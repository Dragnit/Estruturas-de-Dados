#include <stdio.h>

int contarAlgarismosRecursivo(int n) 
{
    if (n < 10) {
        // Caso base: quando n tem apenas um algarismo
        return 1;
    } else {
        // Chamada recursiva: remove o último algarismo e soma 1 ao resultado
        return 1 + contarAlgarismosRecursivo(n / 10);
    }
}

int main() 
{
    int n;
    printf("Digite um numero inteiro nao negativo: ");
    scanf("%d", &n);
    
    int numAlgarismos = contarAlgarismosRecursivo(n);
    printf("O numero de algarismos em %d eh: %d\n", n, numAlgarismos);
    
    return 0;
}
