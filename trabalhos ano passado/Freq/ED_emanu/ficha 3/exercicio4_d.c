#include <stdio.h>

#define LINHAS 3
#define COLUNAS 3

  void EscreveMatriz(int mat[][COLUNAS])
{
    int i, j;


    for (i = 0; i <LINHAS; i++)
    {
        for (j = 0; j <COLUNAS; j++)
        {
            // (*(mat + i) + j) e igual a &mat[i][j]
            scanf("%d", (*(mat + i) + j));
        }
    }
}

  void PrintMatriz(int mat[][COLUNAS])
{
    int i, j;

    for (i = 0; i <LINHAS; i++)
    {
        for (j = 0; j <COLUNAS; j++)
        {
            // *(*(mat + i) + j) e igual a mat[i][j]
            printf("%d ", *(*(mat + i) + j));
        }
        printf("\n");
    }
}

  void SomaMatriz(int mat1[][COLUNAS], int mat2[][COLUNAS], int res[][COLUNAS])
{
    int i, j;
    for (i = 0; i <LINHAS; i++)
    {
        for (j = 0; j <COLUNAS; j++)
        {
            // res[i][j] = mat1[i][j] + mat2[i][j]
            *(*(res + i) + j) = *(*(mat1 + i) + j) + *(*(mat2 + i) + j);
        }
    }
}

void EscreveMatriz(int mat[][COLUNAS]);
void PrintMatriz(int mat[][COLUNAS]);
void SomaMatriz(int mat1[][COLUNAS], int mat2[][COLUNAS], int res[][COLUNAS]);

int main()
{
    int mat1[LINHAS][COLUNAS], mat2[LINHAS][COLUNAS], res[LINHAS][COLUNAS];

    printf("Introduza os elementos da matriz de tamanho de %dx%d: \n",LINHAS,COLUNAS);
    EscreveMatriz(mat1);

    printf("\nIntroduza os elementos da segunda matriz de tamanho %dx%d: \n",LINHAS,COLUNAS);
    EscreveMatriz(mat2);

    SomaMatriz(mat1, mat2, res);

    printf("\nSoma das matrizes: \n");
    PrintMatriz(res);


    return 0;
}
