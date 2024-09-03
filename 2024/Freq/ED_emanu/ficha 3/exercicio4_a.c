#include <stdio.h>

int main()
{
  int matriz[20][20];
  int *ptr;
  int coluna=20,linha=20,i,j;
  ptr=matriz[0];
  for(i=0;i<linha;i++)
    {
      for(j=0;j<coluna;j++){
        *ptr=-1;
        printf("%d ",*ptr);
      }
      printf("\n");
    }
return 0;
}
