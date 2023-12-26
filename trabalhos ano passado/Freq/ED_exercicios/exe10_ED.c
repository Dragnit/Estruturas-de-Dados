#include <stdio.h>
int vetor[100],i,p,inval, tamanho, min, aux;
void ordenar_vetor()
{
  for(i=0;i<tamanho;i++)
  {
    if(inval<vetor[i])
    {
      p = i;
      break;
    }
  }
  for(i=tamanho;i>=p;i--)
  vetor[i]= vetor[i-1];
  vetor[p]=inval;
  if(inval>vetor[tamanho])
  {
    for(int y=0;y<tamanho;y++)
    vetor[y]=vetor[y+1];
    vetor[tamanho]=inval;
  }
}
void insercao_linear(int num[], int num_elementos)
{
  for(int i = 0; i < num_elementos; i++)
  {
    printf("Introduza o elemento: \n");
    scanf("%d", &num[i]);
  }
  int i, aux, j;
    for (i = 1; i < num_elementos; i++)
    {
        aux = num[i];
        j = i - 1;
        while (j >= 0 && num[j] > aux) {
            num[j + 1] = num[j];
            j = j - 1;
        }
        num[j + 1] = aux;
    }
   for (int m = 0; m < num_elementos; m++)
    printf("vetor por ordem crescente: %d\n", num[m]);
}
void main()
{
  int opcao;
  do
  {
   printf("Menu do Programa\n");
   printf("1. Ordenar Elementos\n");
   printf("2. Insercao Linear\n");
   printf("0. Sair\n");
   printf("Entre com a opcao: ");
   scanf("%d", &opcao);
   fflush(stdin);
   switch(opcao)
   {
    case 1:{
            printf("Introduza o tamanho do vetor: ");
            scanf("%d", &tamanho);
            printf("Insira os elementos por ordem crescente:\n");
            for(i=0;i<tamanho;i++)
            scanf("%d",&vetor[i]);
            printf("Insira o valor novo do array : ");
            scanf("%d",&inval);
            ordenar_vetor();
            printf("\n\nArray depois do elemento selecionado :\n ");
            for(int i=0;i<=tamanho;i++)
            printf("%d ", vetor[i]);
            printf("\n");
            break;
            }
    case 2: {
            int num_elementos;
            printf("Introduza o tamanho do vetor: ");
            scanf("%d", &num_elementos);
            int num[num_elementos];
            insercao_linear(num, num_elementos); break;
           }
    case 0: printf("opcao Sair selecionada\n"); break;
    default: printf("opcao invalida\n");
   }
   getchar();
 }
 while(opcao != 0);
}
