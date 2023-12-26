#include <stdio.h>

int tamanho_str(char *ps) 
{
    int tamanho = 0;
    while (*ps != '\0')
    {
        tamanho++;
        ps++;
    }
    return tamanho;
}



int main()
{
    char str[] = "hello world";
    printf("Tamanho da string: %d\n", tamanho_str(str));

    printf("insira o numero de caracteres que pretende copiar");

    return 0;
}