#include <stdio.h>
void presentMatrix(int line,int column,float matrix[line][column]){
  int i,j;

  for(i=0;i<line;i++){
    for(j=0;j<column;j++){
      printf("%0.0f ",matrix[i][j]);
    }
    printf("\n");
  }
}

void atribui_valor_ij(float *pm,int i,int j) {
    float number;

    printf("Introduza o numero a colocar na matriz: ");
    scanf("%f", &number);

    for (int y = 0; y < 20 * i + j; y++)
      ++pm;
      *pm = number;

}

void insertMatrix(float *pm){
  for(int i=0;i<400;i++)
  {
      *pm=-1;
      pm++;
  }
}

int main()
{
float matrix[20][20];
float *pm;
pm=matrix[0];
int i, j;

insertMatrix(pm);

presentMatrix(20,20,matrix);

printf("Insira a linha em que pretende colocar o valor: ");
scanf("%d",&i);

printf("Insira a coluna em pretende colocar o valor: ");
scanf("%d",&j);

atribui_valor_ij(pm, i,j);

printf("Matriz apos insercao:\n");
presentMatrix(20,20,matrix);
	return 0;
}