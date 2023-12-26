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

void escrevermatriz (int m3[5][7])
{
  int i,j;

  for(i=0;i<5;i++) {
    for (j=0;j<7;j++) {
      printf("%d\t", m3[i][j]);
    }
    printf("\n");
  }
}
// subprograma que escreve uma matriz
 int main() {
   int mat1[5][7],mat2[5][7];

   matriz_1(mat1);  // escrever matriz mat1
   escrevermatriz(mat1);
   printf("\n");
   matriz_2(mat2);  // escrever matriz mat2
   escrevermatriz(mat2);

  return 0;
}
