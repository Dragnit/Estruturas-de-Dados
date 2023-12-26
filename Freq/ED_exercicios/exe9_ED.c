#include <stdio.h>
void indicar_indice_elementos(int num[], int num_elementos)
{
 for (int i = 0; i < num_elementos; i++)
 {
  printf("Introduza um numero: ");
  scanf("%d", &num[i]);
 }
 int indice ,maior =0;
 for (int i = 0; i < num_elementos; i++)
 {
   if(num[i] > maior)
   {
     maior = num[i];
     indice = i;
   }
 }
 printf("o indice do maior elemento e: %d\n", indice);
}
void trocar_elementos(int num[], int num_elementos )
{
  int indice1, indice2, troca;
  printf("introduza os dois indices para trocar os elementos desses indices: \n");
  scanf("%d%d", &indice1, &indice2);
  while((indice1 >= num_elementos || indice2 >= num_elementos) || (indice1 < 0 || indice2 < 0))
  {
    printf("Nao foi possivel encontrar o indice introduzido, por favor introduza novamente: \n");
      scanf("%d%d", &indice1, &indice2);
  }
  for (int j = 0; j <num_elementos; j++)
  {
    troca = num[indice1];
    num[indice1] = num[indice2];
    num[indice2] = troca;
  }
  for (int i = 0;i < num_elementos; i++)
  {
    printf("elemento na posicao %d e: %d\n", i, num[i]);
  }
}
void selecao_linear(int num[], int num_elementos)
{
  int i, j, min, ordenar;
  for (i = 0; i < (num_elementos-1); i++)
  {
     min = i;
     for (j = (i+1); j < num_elementos; j++) {
       if(num[j] < num[min])
         min = j;
     }
     if (num[i] != num[min])
     {
       ordenar = num[i];
       num[i] = num[min];
       num[min] = ordenar;
     }
  }
  for (int m = 0; m < num_elementos; m++)
  {
    printf("elementos ordenados: %d\n", num[m]);
  }
}
int main()
{
 int num_elementos, opcao;
 printf("Introduza quantos elementos quer inserir: ");
 scanf("%d", &num_elementos);
 int num[num_elementos];
 do
 {
   printf("Menu do Programa\n");
   printf("1. Escrever Elementos e Indicar maior indice\n");
   printf("2. Trocar elementos\n");
   printf("3. Ordenar vetor\n");
   printf("0. Sair\n");
   printf("Entre com a opcao: ");
   scanf("%d", &opcao);
   fflush(stdin);

   switch(opcao)
   {
    case 1: indicar_indice_elementos(num, num_elementos); break;
    case 2: trocar_elementos(num, num_elementos); break;
    case 3: selecao_linear(num, num_elementos); break;
    case 0: printf("opcao Sair selecionada\n"); break;
    default: printf("opcao invalida\n");
   }
   getchar();
 }
 while(opcao != 0);
}
