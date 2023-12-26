#include <stdio.h>

int recursivo(int n)
{
    if (n == 0) 
    {
        return 1;
    }
    else
    {
        return n * recursivo(n - 1);
    }
}

int Nrecursivo(int n)
{   
    int result = 1;

    for (int i = 1; i <= n; i++)
    {
        result *= i;
    }

    return result;
}

void calculador()
{
    int num;

    puts("insira um numero inteiro: ");
    scanf("%d", &num);

    if(num < 0)
    {
        puts("nao insira numeros negativos >:L");
    }

    int result = recursivo(num);
    int result2 = Nrecursivo(num);

    printf("%d! = %d \n", num, result);
    printf("%d! = %d", num, result2);
}

int main()
{
    calculador();
    return 0;
}