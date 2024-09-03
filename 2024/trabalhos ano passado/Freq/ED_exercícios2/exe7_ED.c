#include <stdio.h>
#include <string.h>
#define MAX_ALUNOS 50
#define MAX_NOME 100
int inserir_nomes(char nomes[][MAX_NOME], int total_alunos)
{
  int numero_alunos;
  printf("Introduza o numero de alunos: ");
  scanf("%d", &numero_alunos);

  for (int i = total_alunos; i < total_alunos + numero_alunos; i++)
  {
    char nome[50];
    printf("Introduza o nome do aluno: ");
    fflush(stdin);
    fgets(nome, 50, stdin);

    strcpy(nomes[i], nome);
    printf("\n");
  }

    return total_alunos + numero_alunos;
}
void gravar_nomes(char nomes[][MAX_NOME],int total_alunos)
{
 FILE *f=fopen("nomes.txt","w");
 for (int i=0; i < total_alunos; i++)
 {
   fputs(nomes[i], f);
   fputs("\n", f);
 }
 fclose(f);
 printf("Nomes guardados com sucesso");

}
int ler_ficheiro_nomes(char nomes[][MAX_NOME], int total_alunos) 
{
   FILE *f=fopen("nomes.txt","r");
   int i = 0;
   while(fgets(nomes[i], MAX_NOME, f) != NULL)
   {
     if(nomes[i][strlen(nomes[i])-1]!='\0')
        nomes[i][strlen(nomes[i])-1]='\0';
    i++;
   }
   fclose(f);
   return i;
}
void apresentar_nomes(char nomes[][MAX_NOME], int total_alunos)
{
  for (int j = 0; j < total_alunos; j++)
  {
    printf("%s", nomes[j]);
    printf("\n");
  }
}
void guardar_tabelanomes_bin(char nomes[][MAX_NOME],int total_alunos)
{
  FILE *fp=fopen("tabelaNomes.dat","wb");
  int i = 0;
  if( fp == NULL)
  {
    printf("Impossivel abrir o ficheiro");
  }
  else
  {
     fwrite(nomes[i], sizeof(nomes[i]),1*total_alunos, fp);
     i++;
  }
  fclose(fp);
  printf("Nomes guardados com sucesso");
}
void ler_tabelanomes_bin(char nomes[][MAX_NOME],int total_alunos)
{
 FILE *fp=fopen("tabelaNomes.dat","rb");
 int i = 0;
 if( fp == NULL)
 {   
   printf("Impossivel abrir o ficheiro");
 }
 else
 {
   while(fread(nomes[i], sizeof(nomes[i]),1, fp)!=0)   
    {
      i++;
    }
   for (int j = 0; j < i; j++)
   {
     printf("%s", nomes[j]);
     printf("\n");
   }
  }
   fclose(fp);
 }
void guardar_nomes_bin(char nomes[][MAX_NOME],int total_alunos)
{
  FILE *fp=fopen("nomesBinario.dat","wb");
  if( fp == NULL)
  {
    printf("Impossivel abrir o ficheiro");
  }
  else
  {
    for(int i = 0; i < total_alunos; i++)
     fwrite(nomes[i], sizeof(nomes[i]),1, fp);
  }
  fclose(fp);
  printf("Nomes guardados com sucesso");
}
void ler_nomes_bin(char nomes[][MAX_NOME])
{
 FILE *fp=fopen("nomesBinario.dat","rb");
 int i = 0;
 if( fp == NULL)
 {   
   printf("Impossivel abrir o ficheiro");
 }
 else
 {
  while(fread(nomes[i], sizeof(nomes[i]),1, fp) != 0)
  {    
   i++;
  }
  for (int j = 0; j < i; j++)
  {
    printf("%s", nomes[j]);
    printf("\n");
  }
  }
  fclose(fp);
}

int main()
{
  int total_alunos = 0;
  int opcao;
  char nomes[MAX_ALUNOS][MAX_NOME];
  ler_nomes_bin(nomes);
  total_alunos = ler_ficheiro_nomes(nomes, total_alunos);
  do
  {
      printf("Menu do Programa\n");
      printf("1. Inserir Nomes\n");
      printf("2. Gravar Nomes\n");
      printf("3. Apresentar Nomes\n");
      printf("4. Guardar um nome de cada vez em binario\n");
      printf("5. Ler tabela de nomes em binario\n");
      printf("6. Guardar tabela de nomes de uma so vez\n");
      printf("0. Sair\n");
      printf("Entre com a opcao: ");
      scanf("%d", &opcao);
      fflush(stdin);
 
      switch(opcao)
      {
       case 1: total_alunos= inserir_nomes(nomes, total_alunos); break; 
       case 2: gravar_nomes(nomes, total_alunos); break;
       case 3: apresentar_nomes(nomes, total_alunos); break;
       case 4: guardar_nomes_bin(nomes,total_alunos); break;
       case 5: ler_tabelanomes_bin(nomes,total_alunos); break;
       case 6: guardar_tabelanomes_bin(nomes, total_alunos); break;
       case 0: printf("opcao Sair selecionada\n"); break;
       default: printf("opcao invalida\n");
      }
      getchar();
   }
    while(opcao != 0);
  }