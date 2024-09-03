#include <stdio.h>
void ler_elementos_matriz(int linhas_matriz, int colunas_matriz, int matriz[][colunas_matriz])
{
  printf("Introduza os elementos da matriz: \n");
  for(int i = 0; i <linhas_matriz; i++)
   for(int j = 0; j <colunas_matriz; j++)
    scanf("%d", &matriz[i][j]);
}
void escrever_matriz(int linhas_matriz, int colunas_matriz, int matriz[][colunas_matriz])
{
  for(int i=0;i<linhas_matriz;i++){
   for (int j=0;j<colunas_matriz;j++)
    printf("%2d ", matriz[i][j]);
      printf("\r\n");
 }
}
void calcular_media_matriz(int linhas_matriz, int colunas_matriz, int matriz[][colunas_matriz])
{
  float soma = 0;
  float media;
  for(int i = 0; i <linhas_matriz; i++)
   for(int j = 0; j <colunas_matriz; j++)
   {
    soma= soma + matriz[i][j];
    media = soma / (linhas_matriz * colunas_matriz);
   }
  printf("Media da Matriz: %0.1f", media);
}
void calcular_media_colunas(int linhas_matriz, int colunas_matriz, int matriz[][colunas_matriz])
{
  float media;
  int coluna;
  float somou = 0, soma = 0;
  printf("Introduza a coluna para fazer a media: ");
  scanf("%d", &coluna);
  while (coluna < 0 || coluna >= colunas_matriz)
  {
    printf("Numero da coluna inserido invalido, introduza novamente: ");
    scanf("%d", &coluna);
  }
  for (int i = 0; i < linhas_matriz; i++)
   for(int j = coluna; j <= coluna ; j++)
   {
      soma = soma + matriz[i][coluna];
      somou ++;
      media = soma / somou;
   }
   printf("media coluna: %0.1f\n", media);

}
void calcular_media_linhas(int linhas_matriz, int colunas_matriz, int matriz[][colunas_matriz])
{
  float media_linhas;
  int linha;
  float somou = 0, soma_linhas = 0;
  printf("Introduza a linha para fazer a media: ");
  scanf("%d", &linha);
  while (linha < 0 || linha >= linhas_matriz)
  {
    printf("Numero da linha inserida invalida, introduza novamente: ");
    scanf("%d", &linha);
  }
  for (int i = linha; i <= linhas_matriz; i++)
   for(int j = 0; j < colunas_matriz ; j++)
   {
      soma_linhas = soma_linhas + matriz[linha][j];
      somou ++;
      media_linhas = soma_linhas / somou;
   }
   printf("media coluna: %0.1f\n", media_linhas);
}
void zeros_diagonal_matriz(int linhas_matriz, int colunas_matriz, int matriz[][colunas_matriz])
{
  int existe = 0;
  if (linhas_matriz != colunas_matriz)
   printf("Nao e possivel contar o numero de zeros acima da diagonal principal\n");
  else
  {
    for(int i = 0; i <linhas_matriz; i++)
    {
     for(int j = 0; j <colunas_matriz; j++)
      if(j > i)
       if(matriz[i][j] == 0)
       {
        existe ++;
       }
     }
      printf("numero de zeros acima da diagonal principal: %d\n", existe);
   }
}
void soma_maxima_linha_matriz(int linhas_matriz, int colunas_matriz, int matriz[][colunas_matriz])
{
  int soma_linha = 0, maior = 0, linha;
  int string[linhas_matriz];
  for(int i = 0; i <linhas_matriz; i++)
  {
   for(int j = 0; j <colunas_matriz; j++)
   {
    soma_linha = soma_linha + matriz[i][j];
    string[i] = soma_linha;
   }
   printf(" a soma da linha %d e : %d\n", i ,string[i]);
   soma_linha = 0;
  }
  for(int i = 0; i <linhas_matriz; i++)
  {
    if (string[i] > maior)
    {
      maior = string[i];
      linha = i;
    }
  }
  printf(" a linha que tem a soma dos elementos maxima e: %d\n", linha);
}
void trocar_colunas_matriz(int linhas_matriz, int colunas_matriz, int matriz[][colunas_matriz])
{
  int coluna1, coluna2, troca;
  printf("Introduza as colunas que quer trocar: \n");
  scanf("%d%d", &coluna1, &coluna2);
  while ((coluna1 >= colunas_matriz || coluna2 >= colunas_matriz) || (coluna1 < 0 || coluna2 < 0))
  {
   printf("nao foi possivel encontrar a coluna, por favor introduza novamente: \n");
   scanf("%d%d", &coluna1, &coluna2);
  }
  printf("colunas da matriz trocada: \n");
  for(int i = 0; i <linhas_matriz; i++)
  {
   for(int j = 0; j <colunas_matriz; j++)
    troca = matriz[i][coluna1];
    matriz[i][coluna1] = matriz[i][coluna2];
    matriz[i][coluna2] = troca;
  }
    for(int i=0;i<linhas_matriz;i++)
    {
     for (int j=0;j<colunas_matriz;j++)
      printf("%2d ", matriz[i][j]);
     printf("\r\n");
    }
    printf("\n");
}
void somar_matrizes(int linhas_matriz, int colunas_matriz, int matriz[][colunas_matriz])
{
  int matriz_2[linhas_matriz][colunas_matriz], soma_matrizes[linhas_matriz][colunas_matriz];
  ler_elementos_matriz(linhas_matriz, colunas_matriz, matriz_2);
  printf("Segunda Matriz:\n");
  escrever_matriz(linhas_matriz, colunas_matriz, matriz_2);
  for(int i = 0; i <linhas_matriz; i++)
  {
   for(int j = 0; j <colunas_matriz; j++)
   soma_matrizes[i][j] = matriz[i][j] + matriz_2[i][j];
  }
  printf("\n");
  printf("Soma das matrizes: \n");
  for(int i = 0; i <linhas_matriz; i++)
  {
   for(int j = 0; j <colunas_matriz; j++)
    printf("%2d ", soma_matrizes[i][j]);
   printf("\r\n");
  }
  printf("\n");
}
int main()
{
  int opcao, linhas_matriz, colunas_matriz;
  printf("Introduza o numero de linhas da matriz: ");
  scanf("%d", &linhas_matriz);
  printf("Introduza o numero de colunas da matriz: ");
  scanf("%d", &colunas_matriz);
  int matriz[linhas_matriz][colunas_matriz];
  do
  {
    printf("Menu do Programa\n");
    printf("1. Ler Matriz\n");
    printf("2. Escrever Matriz\n");
    printf("3. Media dos elmentos da matriz\n");
    printf("4. Media dos elementos da coluna da matriz\n");
    printf("5. Media dos elementos da linha da matriz\n");
    printf("6. Zeros acima da diagonal principal da matriz\n");
    printf("7. Determinar a linha que tem a soma dos seus elementos maxima\n");
    printf("8. Trocar Colunas\n");
    printf("9. Somar Matrizes\n");
    printf("0. Sair\n");
    printf("Entre com a opcao: ");
    scanf("%d", &opcao);
    fflush(stdin);

    switch(opcao)
    {
     case 1: ler_elementos_matriz(linhas_matriz, colunas_matriz, matriz); break;
     case 2: escrever_matriz(linhas_matriz, colunas_matriz, matriz); break;
     case 3: calcular_media_matriz(linhas_matriz, colunas_matriz, matriz); break;
     case 4: calcular_media_colunas(linhas_matriz, colunas_matriz, matriz); break;
     case 5: calcular_media_linhas(linhas_matriz, colunas_matriz, matriz); break;
     case 6: zeros_diagonal_matriz(linhas_matriz, colunas_matriz, matriz); break;
     case 7: soma_maxima_linha_matriz(linhas_matriz, colunas_matriz, matriz); break;
     case 8: trocar_colunas_matriz(linhas_matriz, colunas_matriz, matriz); break;
     case 9: somar_matrizes(linhas_matriz, colunas_matriz, matriz); break;
     case 0: printf("opcao Sair selecionada\n"); break;
     default: printf("opcao invalida\n");
    }
    getchar();
  }
  while(opcao != 0);
}
