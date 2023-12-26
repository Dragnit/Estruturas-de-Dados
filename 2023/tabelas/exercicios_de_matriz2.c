#include <stdio.h>

void matriz_A(int l, int c,int m1[][c])
{
 int i,j;

 for(i=0;i<l;i++)
  for (j=0;j<c;j++)
   m1[i][j]=j;
}

void matriz_B(int m2[][7])
{
 int i,j;

 for(i=0;i<5;i++)
  for (j=0;j<7;j++)
   m2[i][j]=i;
}

void escreveMatriz(int l, int c, int m[][c])
{
   int i, j;

   for(i=0; i < l; i++)
   {
      for (j = 0; j < c; j++)
         printf("%d ", m[i][j]);
      printf("\n");
   }
}

void calculaMedia(int l, int c, int m1[][c])
{
  int soma = 0;

  for(int i = 0; i < l; i++)
    {
      for(int j = 0; j < c; j++)
      {
        soma = soma + m1[i][j];
      }
    }

  printf("media de todos os elemesnto: %f", soma*1.0/(l*c));
}

void calculaMediaLinha(int l, int c, int m1[][c])
{
  int somaColunas = 0, linha;

  printf("\n \ninsira a linha que pretende calcular a media: ");
  scanf("%d", &linha);

  for(int j = 0; j < c; j++)
  {
    somaColunas = somaColunas + m1[linha][j];
  }

  printf("\n media da linha escolhida: %f", somaColunas*1.0/c);
}

float calculaMediaColuna(int l, int c, int m1[][c])
{
  int somaLinhas = 0, coluna;

  printf("\n \ninsira a colunha que pretende calcular a media: ");
  scanf("%d", &coluna);

  for(int i = 0; i < l; i++)
    {
      somaLinhas = somaLinhas + m1[i][coluna];
    }

  return somaLinhas*1.0/l;
}

void diagonalEspacial(int l, int c, int m1[][c])
{
  int a = 0;

  if(c != l)
    printf("Nao é possivel encontrar a diagonal da matriz o numero de linhas e colunas deve ser igual");
  else
  {
    for(int i; i < l; i++)
    {
      for(int j; j < c; j++)
        if(j < i)
          a++;
    }
    printf("numero de zeros a cima da diagonal: %d", a);
  }
}

int linhaMaiorSoma(int l, int c, int mat2[][c])
{
  int soma = 0, max = 0, linha = 0;

  for(int i = 0; i < c; i++)
  {
    soma = soma + mat2[0][i];
  }
  max = soma;

  for(int i = 1; i < l; i++)
  {
    soma = 0;
    for(int j = 0; j < c; j++)
    {
      soma = soma + mat2[i][j];
    }
    if(soma > max)
      {
        max = soma;
        linha = i;
      }
  }
  return linha;
}

void trocaColunas(int l, int c, int mat1[][c])
{
  printf("\n");

  int coluna1, coluna2, troca;
  printf("insira as colunas que quer trocar: ");
  scanf("%d %d", &coluna1, &coluna2);

  printf("colunas da matriz trocada: \n");
  for(int i = 0; i <l; i++)
  {   
      troca = mat1[i][coluna1];
      mat1[i][coluna1] = mat1[i][coluna2];
      mat1[i][coluna2] = troca;
  }
  
  for(int i = 0; i < l; i++)
  {
    for (int j = 0; j < c; j++)
    printf("%2d ", mat1[i][j]);
    printf("\r\n");
  }
  printf("\n");
}

void somaMatrizes(int l, int c, int mat1[][c], int mat2[][c])
{
  int somaMatrizes[l][c];
  for(int i = 0; i < l; i++)
  {
    for(int j = 0; j < c; j++)
      somaMatrizes[i][j] = mat1[i][j] + mat2[i][j];
  }
  printf("\n");
  printf("Soma das matrizes: \n");
  for(int i = 0; i < l; i++)
  {
    for(int j = 0; j < c; j++)
    printf("%2d ", somaMatrizes[i][j]);
    printf("\r\n");
  }
  printf("\n");
}

int main()
{
  int c,l;

 printf("insira o numero de linas e o numero de colunas\n");
 scanf("%d %d", &l, &c);

 int mat1[l][c], mat2[5][7];

 matriz_A(l, c, mat1);
 matriz_B(mat2);
 // escrever matriz mat1 e mat2
 escreveMatriz(l, c, mat1);
 printf("\n");
 escreveMatriz(5, 7, mat2);

 printf("\n");

 calculaMedia(l, c, mat1);
 calculaMedia(5, 7, mat2);
 printf("a media da coluna e: %f", calculaMediaColuna(c, l, mat1));
 calculaMediaLinha(c, l, mat1);

 printf("\n");

 diagonalEspacial(c, l, mat1);

 printf("\n");

 printf("a linha com a maior soma e %d", linhaMaiorSoma(5, 7, mat2));

 printf("\n");

 trocaColunas(c, l, mat1);

 printf("\n");

 somaMatrizes(c, l, mat1, mat2);

 // escrever matriz mat2


 return 0;
}
