#include <stdio.h>
#include <string.h>
#define MAX_ALUNOS 50
#define MAX_ID 11
#define MAX_NOME 100
int inserir_alunos(char ids_aluno[][MAX_ID], char nomes[][MAX_NOME], int total_alunos)
{
  int numero_alunos;
  printf("Introduza o numero de alunos: ");
  scanf("%d", &numero_alunos);

  for (int i = total_alunos; (i < total_alunos + numero_alunos) && (i < MAX_ALUNOS); i++)
  {
    char nome[50];
    char id_aluno[11];
    printf("Introduza o nome do aluno: ");
    fflush(stdin);
    fgets(nome, 50, stdin);
    printf("numero de aluno: ");
    fflush(stdin);
    scanf("%s", id_aluno);

    strcpy(nomes[i], nome);
    strcpy(ids_aluno[i], id_aluno);
    printf("\n");
  }
  if( total_alunos + numero_alunos > MAX_ALUNOS)
  {
    printf("Nao e possivel inserir porque ultrapassou o numero maximo de alunos\n" );
    return MAX_ALUNOS;
  }
  else
    return total_alunos + numero_alunos;
}
void puxar_alunos_atras(char ids_aluno[][MAX_ID], char nomes[][MAX_NOME], int total_alunos, int posicao_apagar) 
{
  for (int i = posicao_apagar; i < total_alunos; i++)
  {
    strcpy(ids_aluno[i], ids_aluno[i+1]);
    strcpy(nomes[i], nomes[i+1]);
  }
}

int remover_aluno(char ids_aluno[][MAX_ID], char nomes[][MAX_NOME],int total_alunos)
{
  char numero_pesquisar[MAX_ID];
  printf("Introduza o numero de aluno que quer remover: ");
  scanf("%s", numero_pesquisar);
  int posicao_apagar, apagou=0;
  for (int i = 0; i < total_alunos; i++)
  {
    if (strcmp(ids_aluno[i],numero_pesquisar) == 0)
    {
      apagou = 1;
      posicao_apagar = i;
      break;
    }
  }
  if (apagou == 1)
  {
    puxar_alunos_atras(ids_aluno, nomes, total_alunos, posicao_apagar); 
    printf("Aluno Removido com sucesso\n");
    return total_alunos - 1;
  }
  else
  {
    printf("Aluno nao encontrado\n");
    return total_alunos;
  }
}

int remover_varios_alunos (char ids_aluno[][MAX_ID], char nomes[][MAX_NOME],int total_alunos)
{
  int n_alunos_remover;
  printf("Introduza quantos alunos pretende remover: ");
  scanf("%d", &n_alunos_remover);
  for (int i = 0; i < n_alunos_remover; i++){
    total_alunos = remover_aluno( ids_aluno,nomes,total_alunos);
  }
  return total_alunos;
 }

void apresentar_dados(char ids_aluno[][MAX_ID], char nomes[][MAX_NOME], int total_alunos)
{
  for(int i = 0; i < total_alunos; i++)
  {
    printf("Nome: %s", nomes[i]);
    printf("Numero: %s", ids_aluno[i]);
    printf("\n");
  }
}
 void grava_ficheiros(char nomes[][MAX_NOME], char ids_aluno[][MAX_ID],int total_alunos)
 {
  FILE *f=fopen("alunos.txt","w");
  for (int i=0; i < total_alunos; i++)
  {
    fputs(ids_aluno[i], f);
    fputs("\n", f);
    fputs(nomes[i], f);
  }
  fclose(f);

 }
 int ler_ficheiro_alunos(char nomes[][MAX_NOME], char ids_aluno[][MAX_ID]) 
{
    FILE *f=fopen("alunos.txt","r");
    int i=0;
    while (fgets(ids_aluno[i], MAX_ID, f) != NULL)
    {
      if(ids_aluno[i][strlen(ids_aluno[i])-1]!='\0')
        ids_aluno[i][strlen(ids_aluno[i])-1]='\0';
      fgets(nomes[i], MAX_NOME, f);
     i++;
    }
    
    fclose(f);
    return i;
}
int main()
{
 int total_alunos = 0;
 int opcao;
 char ids_aluno[MAX_ALUNOS][MAX_ID];
 char nomes[MAX_ALUNOS][MAX_NOME];
 total_alunos = ler_ficheiro_alunos(nomes, ids_aluno);
 do
 {
     printf("Menu do Programa\n");
     printf("1. Inserir Alunos\n");
     printf("2. Remover Alunos\n");
     printf("3. Apresentar Alunos\n");
     printf("4. Gravar Dados dos Alunos\n");
     printf("0. Sair\n");
     printf("Entre com a opcao: ");
     scanf("%d", &opcao);
     fflush(stdin);

     switch(opcao)
     {
      case 1: total_alunos = inserir_alunos(ids_aluno, nomes, total_alunos);break;
      case 2: total_alunos = remover_varios_alunos(ids_aluno, nomes, total_alunos); break;
      case 3: apresentar_dados(ids_aluno, nomes, total_alunos); break;
      case 4: grava_ficheiros(nomes, ids_aluno, total_alunos); break;
      case 0: printf("opcao Sair selecionada\n"); break;
      default: printf("opcao invalida\n");
     }
     getchar();
  }
   while(opcao != 0);
 }
