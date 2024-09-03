#include <stdio.h>
#include <stdlib.h>
//a decrição apenas le uma palavra
//o estado e a importancia estao como numeros
//
int indicador()
{
  int linha = 1;
  int ch;
  FILE * fp;
  fp = fopen("tarefas","r");

  while ((ch = fgetc(fp)) != EOF)
  {
    if(ch == '\n')
    {
      linha++;
    }
  }
  fclose(fp);
  return linha;
}

void resumo() //quarata consulta
{
  char desc[50];
  int estado = 0, dia = 1, mes = 1, anos = 0, i= 0;
  int fazer = 0, concluido = 0, fazer1 = 0, concluido1 = 0, fazer2 = 0, concluido2 = 0;
  int importancia = 0;

  FILE * fp;
  fp = fopen("tarefas","r");

  while(fscanf(fp, "%d %s %d %d %d %d %d", &i, desc, &dia, &mes, &anos, &estado, &importancia) != EOF)
  {
    if(estado == 0 && importancia == 1)
      fazer++;
    if(estado == 1 && importancia == 1)
      concluido++;
    if(estado == 0 && importancia == 2)
      fazer1++;
    if(estado == 1 && importancia == 2)
      concluido1++;
    if(estado == 0 && importancia == 3)
      fazer2++;
    if(estado == 1 && importancia == 3)
      concluido2++;
  }
  puts("importancia fazer concluidas");
  printf("Alta:       %d          %d\n", fazer, concluido);
  printf("Media:      %d          %d\n", fazer1, concluido1);
  printf("Baixa:      %d          %d\n", fazer2, concluido2);

  fclose(fp);
  printf("\nOperacao concluida\a");
  system("pause > nul");
}

void atrasadas() // terceira consulta
{
  char desc[50];
  int estado = 0, dia = 1, mes = 1, anos = 0, i= 0, a = 0, b = 0, c = 0;
  int importancia = 0;

  puts("insira a data(dd-mm-aa): ");
  scanf("%d %d %d", &a, &b, &c);

  FILE * fp;
  fp = fopen("tarefas","r");


  while(fscanf(fp, "%d %s %d%d%d %d %d", &i, desc, &dia, &mes, &anos, &estado, &importancia) != EOF)
  {
    if(a > dia && b >= mes || c >anos)
        printf("%d %s %02d%02d%d %d %d\n", i, desc, dia, mes, anos, estado, importancia);
  }


  printf("\nOperacao concluida\7");
  system("pause > nul");
}

void naoConcluido() //segunda consulta
{
  char desc[50];
  int estado = 0, dia = 1, mes = 1, anos = 0, i= 0, a = 0;
  int importancia = 0;

  FILE * fp;
  fp = fopen("tarefas","r");

  printf("insira a importancia (0-todas; 1-alta; 2-media; 3-baixa): ");
  scanf("%d", &a);

  while(fscanf(fp, "%d %s %d %d %d %d %d", &i, desc, &dia, &mes, &anos, &estado, &importancia) != EOF)
  {
    if(a == 0 && estado == 0)
      printf("%d %s %02d%02d%d %d %d\n", i, desc, dia, mes, anos, estado, importancia);
    if(a == 1 && importancia == a && estado == 0)
      printf("%d %s %02d%02d%d %d %d\n", i, desc, dia, mes, anos, estado, importancia);
    if(a == 2 && importancia == a && estado == 0)
      printf("%d %s %02d%02d%d %d %d\n", i, desc, dia, mes, anos, estado, importancia);
    if(a == 3 && importancia == a && estado == 0)
      printf("%d %s %02d%02d%d %d %d\n", i, desc, dia, mes, anos, estado, importancia);
  }
  printf("\nOperacao concluida\a");
  system("pause > nul");
}

void estado() // altera o estado
{
    char desc[50];
    int estado = 0, dia = 1, mes = 1, anos = 0, i= 0, a = 0, b = 0;
    int importancia = 0;

    FILE * fp;
    FILE *fp1;
    fp = fopen("tarefas","r");
    fp1 = fopen("Estado","wt");
    //uso de ficheiro auxiliara para realizar a ação
    while(fscanf(fp, "%d %s %d %d %d %d %d", &i, desc, &dia, &mes, &anos, &estado, &importancia) != EOF)
    {
      fprintf(fp1, "%d %s %d%d%d %d %d\n", i, desc, dia, mes, anos, estado, importancia);
    }
    fclose(fp);
    fclose(fp1);
    //dados da linha e do novo estado
    puts("Insira o indicador da tarefa: ");
    scanf("%d", &a);
    puts("insira o novo estado(0-fazer 1-concluido)");
    scanf("%d", &b);
    if(b < 0 || b > 1)
    {
      puts("estado invalido");
      system("pause > nul");
    }

    fp1 = fopen("Estado","r");
    fp = fopen("tarefas","wt");
    //escreve o novo estado
    while(fscanf(fp1, "%d %s %d %d %d %d %d", &i, desc, &dia, &mes, &anos, &estado, &importancia) != EOF)
    {
      if(a == i)
        fprintf(fp, "%d %s %d%d%d %d %d\n", i, desc, dia, mes, anos, b, importancia);
      else
        fprintf(fp, "%d %s %d%d%d %d %d\n", i, desc, dia, mes, anos, estado, importancia);
    }

    fclose(fp1);
    fclose(fp);

    printf("\nOperacao concluida\a");
    system("pause > nul");
}

void inserirTarefa() //Funcao que cria tarefas
{
  int i = indicador();

  char desc[50];
  int dia = 1, mes = 1, anos = 0, importancia = 1;
  int estado = 0;
  FILE * fp;

  fp = fopen("tarefas","at");

  printf("Insira a descricao da tarefa: \n");
  gets(desc);
  if(desc[0] == '0')
  {
    puts("Descricao invalida");
    system("pause > nul");
    return;
  }
  printf("Insira o dia: \n");
  scanf("%d", &dia);
  if(dia < 1 || dia > 31)
  {
    printf("data invalida");
    system("pause > nul");
    return;
  }
  printf("Insira o mes: \n");
  scanf("%d", &mes);
  if(mes < 1 || mes > 12)
  {
    printf("data invalida");
    system("pause > nul");
    return;
  }
  printf("Insira o ano: \n");
  scanf("%d", &anos);
    if(anos > 2022 || anos < 2022)
    {
      printf("data invalida");
      system("pause > nul");
      return;
    }
  printf("Insira a importancia(1-alta; 2-media; 3-baixa) \n");
  scanf("%d", &importancia);
  if(importancia < 1 || importancia > 3)
  {
    printf("importancia invalida");
    system("pause > nul");
    return;
  }

  fprintf(fp, "%d ", i);
  fprintf(fp, "%s ", desc);
  fprintf(fp, "%02d-%02d-%d ", dia, mes, anos);
  fprintf(fp, "%d ", estado);
  fprintf(fp,"%d\n", importancia);
  fclose(fp);
  printf("\nOperacao concluida\7");
  system("pause > nul");
}

int consultarTarefa()//primeira consulta
{
  char desc[50];
  int estado = 0, dia = 1, mes = 1, anos = 0, i= 0;
  int importancia = 0;
  int ch = 0;
  FILE *fp;
  fp =  fopen("tarefas","r");

  if (fp == NULL)
    printf("Erro!!");
  else
    printf("Ficheiro aberto com sucesso!!\n");

  while(fscanf(fp, "%d %s %d %d %d %d %d", &i, desc, &dia, &mes, &anos, &estado, &importancia) != EOF)
  {
    if(importancia == 1)
      printf("%d %s %d%02d%d %d alta\n", i, desc, dia, mes, anos, estado);
    if(importancia == 2)
      printf("%d %s %d%02d%d %d media\n", i, desc, dia, mes, anos, estado);
    if(importancia == 3)
      printf("%d %s %d%02d%d %d baixa\n", i, desc, dia, mes, anos, estado);
  }
    fclose(fp);

    printf("\nOperacao concluida\7");
    system("pause > nul"); // Espera para que se carregue numa tecla para continuar
}

void menuConsulta()//Menu das consultas
{
  int a = 0;
  while (a != 5) // Ciclo para que volte sempre ao menu cada vez que se inserir uma opcao diferente
  {

    system("cls"); // Limpa o ecra

    puts("-------------------------------------------------------");
    puts("                         MENU                          ");
    puts("                                                       ");
    puts("     O que pretende realizar?                          ");
    puts("                                                       ");
    puts("1 -- Consultar todas as Tarefas                        ");
    puts("2 -- Consulta de dados das tarefas nao concluidas      ");
    puts("3 -- Consulta de dados das tarefas nao concluidas e atrasadas");
    puts("4 -- Resumo do estado das tarefas                      ");
    puts("5 -- Sair                                              ");
    puts("-------------------------------------------------------");

    printf("Insira a opcao: ");
    scanf("%d", &a);
    fflush(stdin);

    system("cls");

    switch (a)
    {
      case 1: consultarTarefa(); break;
      case 2: naoConcluido(); break;
      case 3: atrasadas(); break;
      case 4: resumo();break;
      case 5: break;
      default: printf("Opcao invalida\n");
    }
  }

  fflush(stdin);
  printf("\nOperacao concluida\7");
  system("pause > nul"); // Espera para que se carregue numa tecla para continuar

}

int main()
{
  int a = 0;
  int indLinha = 0;
  while (a != 4) // Ciclo para que volte sempre ao menu cada vez que se inserir uma opcao diferente
  {

    system("cls"); // Limpa o ecra

    puts("-------------------------------------------------------");
    puts("                         MENU                          ");
    puts("                                                       ");
    puts("     O que pretende realizar?                          ");
    puts("                                                       ");
    puts("1 -- Inserir uma Tarefa                                ");
    puts("2 -- concluir uma tarefa                               ");
    puts("3 -- Menu de consultas                                 ");
    puts("4 -- Sair                                              ");
    puts("-------------------------------------------------------");

    printf("Insira a opcao: ");
    scanf("%d", &a);
    fflush(stdin);

    system("cls");

    switch (a)
    {
      //case 1: indLinha = indicador(); inserirTarefa(i); indLinha++; break;
      case 1: inserirTarefa(); break;
      case 2: estado(); break;
      case 3: menuConsulta(); break;
      case 4: break;
      default: printf("Opcao invalida\n");
    }
  }

  fflush(stdin);
  printf("\nOperacao concluida\7");
  system("pause > nul"); // Espera para que se carregue numa tecla para continuar

}
