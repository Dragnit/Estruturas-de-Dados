#include <stdio.h>
//alinea d
float * soma(float *pm1, float *pm2)
{
    for(int x=0;x<400;x++)
    {
        *pm1 = *pm1 + (*pm2);
        ++pm1;
        ++pm2;
    }
}
//alinea c
void InserirValor(float * pm, int i, int j)
{
    float numeroUtilizador;
    scanf("%f", &numeroUtilizador);
    for(int k=0;k<20*i+j;k++)
    ++pm;
    *pm = numeroUtilizador;
}
//alinea a
void InicializaMatrizA(float * pm)
{
  for(int i=1;i<=400;i++)
  {
    *pm = -1;
    ++pm;
  }
}
//alinea b
void InicializaMatrizB(float * pm)
{
  for(int i=1;i<=400;i++)
  {
    *pm = i;
    ++pm;
  }
}
int main()
{
  int i, j;
  float * pm1;
  float * pm2;
  float matriz1[20][20];
  float matriz2[20][20];
  pm1 = matriz1[0];
  pm2 = matriz2[0];
  InicializaMatrizA(pm1);
  for(int k=0;k<20;k++)
  {
    printf("\n");
    for(int x=0;x<20;x++)
    printf("%.0f ", matriz1[k][x]);
  }
  InicializaMatrizB(pm2);
  for(int k=0;k<20;k++)
  {
      printf("\n");
      for(int j=0;j<20;j++)
      {
          printf("%.0f ", matriz2[k][j]);
      }
  }
  printf("\nEscolha a linha e a coluna respetivamente: \n");
  scanf("%d", &i);
  scanf("%d", &j);
  printf("Insira o numero que pretende inserir: \n");
  InserirValor(pm2, i, j);
  soma(pm1, pm2);
  for(int k=0;k<20;k++)
  {
    printf("\n");
    for(int x=0;x<20;x++)
    printf("%.0f ", matriz1[k][x]);
  }
}