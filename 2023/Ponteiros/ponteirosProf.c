#include <stdio.h>

#define DIM 20

void inicializaMatrizA(float *m)
{
    for (int i = 0; i <= DIM*DIM; i++)
    {
        *m = -1;
        m++;
    }

}

void atribuiValorAij(float *pm, int i, int j, float valor)
{
    *(pm + i*DIM + j) = valor;
}

void mostraMatriz (float *m)
{
    for (int i = 1; i <= DIM*DIM; i++)
    {
        printf("elemento %i = %.2f\n",i,*m);
        m++;
    }
}

int main()
{
    int i, j;
    float valor;
    float matrizA[20][20];
    inicializaMatrizA(&matrizA[0][0]);

    printf("Informe o valor a ser atribuido:\n");
    scanf("%f", &valor);
    printf("Informe a posicao da matriz i e j:\n");
    scanf("%d %d", &i, &j);
    atribuiValorAij(&matrizA[0][0], i, j, valor);

    printf("Matriz resultante:\n");
    mostraMatriz(&matrizA[0][0]);

    return 0;
}