#include <stdio.h>

void inicializaMatrizA(float *pm) 
{
    int i, j;
    for (i = 0; i < 20; i++)
    {
        for (j = 0; j < 20; j++) 
            {
            *(pm + i*20 + j) = -1;
        }
    }
}

void atribuiValorAij(float *pm, int i, int j, float valor)
{
    *(pm + i*20 + j) = valor;
}

void mostraMatriz(float *pm) 
{
    int i, j;
    for (i = 0; i < 20; i++)
    {
        for (j = 0; j < 20; j++) 
        {
            printf("%.2f ", *(pm + i*20 + j));
        }
        printf("\n");
    }
}

int main()
{
    int i, j;
    float valor;
    float matrizA[20][20];
    inicializaMatrizA(&matrizA[0][0]);

    printf("Informe o valor a ser atribuído:\n");
    scanf("%f", &valor);
    printf("Informe a posição da matriz i e j:\n");
    scanf("%d %d", &i, &j);
    atribuiValorAij(&matrizA[0][0], i, j, valor);

    printf("Matriz resultante:\n");
    mostraMatriz(&matrizA[0][0]);

    return 0;
}