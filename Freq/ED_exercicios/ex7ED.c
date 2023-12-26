#include <stdio.h>
#include<stdlib.h>
int vetor[100];
int nmrelementos;
int ocorrencia;
int ocorrenciaa;
int ocorrenciaaa;
int PrimeiraOcorrencia()
{
  int PrimeiraOcorr;
  for(PrimeiraOcorr=0; PrimeiraOcorr<nmrelementos; PrimeiraOcorr++)
  {
    if(vetor[PrimeiraOcorr]==ocorrenciaaa)
    {
      return PrimeiraOcorr;
      break;
    }
  }
  return -1;
}
int UltimaOcorrencia()
{
  int UltimaOcorr;
  for(UltimaOcorr=nmrelementos; UltimaOcorr>0; UltimaOcorr--)
  {
    if(vetor[UltimaOcorr]==ocorrenciaa)
    {
      return UltimaOcorr;
      break;
    }
  }
  return -1;
}
void NmrOcorrencias()
{
  int IncOcorrencia=0;
  printf("\nInsira o numero desejado: ");
  scanf("%d", &ocorrencia);
  for(int i=0;i<nmrelementos;i++)
  {
    if(vetor[i]==ocorrencia)
    {
      IncOcorrencia++;
    }
  }
  printf("\nO numero escolhido aparece %d vezes no vetor", IncOcorrencia);

}
void MostrarVetor()
{
  for(int i=0;i<nmrelementos;i++)
  printf("%d ", vetor[i]);
}
void InserirVetor()
{
  for(int i=0;i<nmrelementos;i++)
  scanf("%d", &vetor[i]);
}
void main()
{
  int opcao;
  int indice;
  for(int i=0;i!=-1;i++) {
    printf("\n\nMenu\n");
    printf("1. Inserir o vetor\n");
    printf("2. Numero de ocorrencias de valor\n");
    printf("3. Procurar a ultima ocorrencia de x valor\n");
    printf("4. Procurar primeira ocorrencia de x valor\n");
    printf("0. Sair do menu\n");
    printf("\nEscolha a sua opcao: ");
    scanf("%d", &opcao);

    switch(opcao) {
      case 1:
      printf("Insira o numero de elementos do vetor: ");
      scanf("%d", &nmrelementos);
      printf("\nPreencha o vetor: ");
      InserirVetor();
      printf("\nO vetor inserido foi o seguinte:\n");
      MostrarVetor();
      break;
      case 2:
      NmrOcorrencias();
      break;
      case 3:
      printf("\nInsira o numero desejado: ");
      scanf("%d", &ocorrenciaa);
      if(UltimaOcorrencia()!=-1)
      printf("\nValor esta presente no vetor, indice %d", UltimaOcorrencia());
      else
      printf("\nValor nao existe no array");
      break;
      case 4:
      printf("\nInsira o numero desejado: ");
      scanf("%d", &ocorrenciaaa);
      if(PrimeiraOcorrencia()!=-1)
      printf("\nValor esta presente no vetor, indice %d", PrimeiraOcorrencia());
      else
      printf("\nValor nao existe no array");
      break;
      case 0 :
      printf("\nDecidiu sair do menu.");
      exit(0);
      default:
      printf ("Opcao invalida, por favor, tente novamente\n");
      scanf("%d", &opcao);
      break;
    }
  }
}
