#include <stdio.h>

void matriz_1(int m1[5][7])
{
int i,j;
for(i=0;i<5;i++)
 for (j=0;j<7;j++)
  m1[i][j]=j;
}
void matriz_2(int m2[][7])
{
int i,j;
for(i=0;i<5;i++)
 for (j=0;j<7;j++)
  m2[i][j]=i;
}

void escrever_matriz(int m[5][7])
{
  for(int i=0;i<5;i++){
    printf("\n");
   for (int j=0;j<7;j++)
    printf("%d ", m[i][j]);
  }
}

int main()
{
int mat1[5][7],mat2[5][7];
matriz_1(mat1);
escrever_matriz(mat1);
printf("\n");
matriz_2(mat2);
escrever_matriz(mat2);
return 0;
}
