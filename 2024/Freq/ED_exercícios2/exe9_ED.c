#include <stdio.h>
#define MAX_REGISTOS 1000 
int inserir_registos(long long int data_registo[], float hora_registo[], float temperatura_registo[], int total_registos)
{
  int n_registos;
  printf("Introduza quantos registos pretende fazer: ");
  scanf("%d", &n_registos);
  for (int i = total_registos; i < (total_registos + n_registos) && (i < MAX_REGISTOS); i++)
  {
    printf("Introduza a data: ");
    scanf("%lld", &data_registo[i]);
    printf("Introduza a hora: ");
    scanf("%f", &hora_registo[i]);
    printf("Introduza a temperatura: ");
    scanf("%f", &temperatura_registo[i]);
  }
  return total_registos + n_registos;
}
float calcular_amptermica(long long int data_registo[], float temperatura_registo[], int total_registos)
{
  long long int data_procurar;
  float maior_temp = 0, menor_temp, amplitude_ter;
  int encontrou = 0;
  while(encontrou == 0)
 {  
  printf("Introduza a data para calcular a amplitude termica: ");
  scanf("%lld", &data_procurar);
  for(int i = 0; i < total_registos; i++)
  {  
    if (data_procurar == data_registo[i])
    {
     encontrou = 1;
     if( temperatura_registo[i] > maior_temp)
      maior_temp = temperatura_registo[i];
    }
  }
  menor_temp = maior_temp;
  for(int i = 0; i < total_registos; i++)
  {  
    if (data_procurar == data_registo[i])
    {
     if( temperatura_registo[i] < menor_temp)
      menor_temp = temperatura_registo[i];
    }
  }
}
  amplitude_ter = maior_temp - menor_temp; 
  return amplitude_ter;
}
void calcular_varias_amptermicas(long long int data_registo[], float temperatura_registo[], int total_registos)
{
  int n_amptermica;
  printf("Introduza para quantos dias e que pretende calcular a amplitude termica: ");
  scanf("%d", &n_amptermica);
  for (int j = 0; j < n_amptermica; j++)
  {
    printf("Amplitude Termica: %0.1f\n", calcular_amptermica(data_registo, temperatura_registo, total_registos));
  }
}
float calcular_mediatemp(long long int data_registo[], float temperatura_registo[], int total_registos)
{
  int encontrou = 0;
  int m = 0;
  float soma = 0;
  long long int data_procurar;
  float media_temp;
  while(encontrou == 0)
 {  
  printf("Introduza a data para calcular a amplitude termica: ");
  scanf("%lld", &data_procurar);
  for(int i = 0; i < total_registos; i++)
  {  
    if (data_procurar == data_registo[i])
    {
     encontrou = 1;
     soma = soma + temperatura_registo[i];
     m++;
     media_temp = soma / m;
    }
  }
    
 }
 return media_temp;
}
void calcular_varias_mediastemp(long long int data_registo[], float temperatura_registo[], int total_registos)
{
  int n_mediastemp;
  printf("Introduza para quantos dias e que pretende calcular a amplitude termica: ");
  scanf("%d", &n_mediastemp);
  for (int j = 0; j < n_mediastemp; j++)
  {
    printf("Medias das Temperaturas: %0.1f\n", calcular_mediatemp(data_registo, temperatura_registo, total_registos));
  }
}
void apresentar_registos(long long int data_registo[], float hora_registo[], float temperatura_registo[], int total_registos)
{
  
  for(int i = 0; i < total_registos; i++)
  {
    printf("Registo %d: ", i+1);
    printf("\n\n");
    printf("Data: %lld\n", data_registo[i] );
    printf("Hora: %.2f\n", hora_registo[i]);
    printf("Temperatura: %.1f\n", temperatura_registo[i]);
  }
}
void gravar_registos(long long int data_registo[], float hora_registo[], float temperatura_registo[], int total_registos)
{
  FILE *f=fopen("temperaturas.dat","wb");
  for (int i=0; i < total_registos; i++)
  {
    fwrite(data_registo, sizeof(long long int[MAX_REGISTOS]),1, f);
    fwrite(hora_registo, sizeof(float[MAX_REGISTOS]),1, f);
    fwrite(temperatura_registo, sizeof(float[MAX_REGISTOS]),1, f);
  }
  fclose(f);
  printf("Dados guardados com sucesso\n");
}
int ler_registos(long long int data_registo[], float hora_registo[], float temperatura_registo[], int total_registos) 
{
   FILE *f=fopen("temperaturas.dat","rb");
   int i=0;
   while (fread(data_registo, sizeof(long long int[MAX_REGISTOS]),1, f) != 0)
   {
     fread(hora_registo, sizeof(float[MAX_REGISTOS]),1, f);
     fread(temperatura_registo, sizeof(float[MAX_REGISTOS]),1, f);
     i++;
   }
   
   fclose(f);
   return i;
}
int main()
{
  int total_registos = 0;
  long long int data_registo[MAX_REGISTOS];
  float hora_registo[MAX_REGISTOS];
  float temperatura_registo[MAX_REGISTOS];
  total_registos = ler_registos(data_registo, hora_registo, temperatura_registo, total_registos);
  int opcao;
  do
  {
      printf("Menu do Programa\n");
      printf("1. Inserir Registos\n");
      printf("2. Apresentar Registos\n");
      printf("3. Calcular Amplitude Termica\n");
      printf("4. Calcular Media de Temperaturas de um dia\n");
      printf("5. Gravar dados recolidos\n");
      printf("0. Sair\n");
      printf("Entre com a opcao: ");
      scanf("%d", &opcao);
      fflush(stdin);
 
      switch(opcao)
      {
       case 1: total_registos = inserir_registos(data_registo, hora_registo, temperatura_registo, total_registos);break;
       case 2: apresentar_registos(data_registo, hora_registo, temperatura_registo, total_registos);break;
       case 3: calcular_varias_amptermicas(data_registo, temperatura_registo, total_registos);break;
       case 4: calcular_varias_mediastemp(data_registo, temperatura_registo, total_registos);break;
       case 5: gravar_registos(data_registo, hora_registo, temperatura_registo, total_registos); break;
       case 0: printf("opcao Sair selecionada\n"); break;
       default: printf("opcao invalida\n");
      }
      getchar();
   }
    while(opcao != 0);
  }