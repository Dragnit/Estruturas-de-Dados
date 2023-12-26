#include<stdio.h>

int main()
{
    int matriz[20][20];
    int *ptr,i,j,linha=20,coluna=20,contagem=0;
    ptr=matriz[0];
    for(i=0;i<linha;i++)
      {
        for(j=0;j<coluna;j++){
          *ptr=1+contagem;
          printf("%d ",*ptr);
          contagem++;
        }
        printf("\n");
      }
}
