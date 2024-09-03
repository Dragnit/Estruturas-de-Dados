#include <stdio.h>
#include <stdlib.h>
#include <stdbool>

typedef struct utilizadores //definiçao da estrutura dos dados do utilizador
{
  char nome_user [20];
  int idade_user;
  int pin_user;
  bool is_admin;
  conta accounts[5];
} utilizador;

typedef struct conta //definiçao da estrutura dos dados da conta
{
  char nome_conta [30];
  int numero_conta;
  float saldo_conta;
} conta;


Void deposito(int num)
{
  int pin = 0;

  puts("insira o seu pin: ");
  scanf("%d", &pin);

  for(int i=0; i<num; i++)
  {
    if(strcmp(utilizador.pin_user,pin)==0)
    {
      printf("%s\n", t[i].nome);
    }
  }
}

void Administrador()
{
  int a = 0;
  int indLinha = 0;
  while (a != 5) // Ciclo para que volte sempre ao menu cada vez que se inserir uma opcao diferente
  {

    system("cls"); // Limpa o ecra

    puts("-------------------------------------------------------");
    puts("                         MENU                          ");
    puts("                                                       ");
    puts("     O que pretende realizar?                          ");
    puts("                                                       ");
    puts("1 -- Ver clientes                                      ");
    puts("2 -- Inserir nova conta                                ");
    puts("3 -- Realizar uma transferencia                        ");
    puts("4 -- Consulta de contas                                ");
    puts("5 -- Sair                                              ");
    puts("-------------------------------------------------------");

    printf("Insira a opcao: ");
    scanf("%d", &a);
    fflush(stdin);

    system("cls");

    switch (a)
    {
      case 1: inserirTarefa(); break;
      case 2: estado(); break;
      case 3: menuConsulta(); break;
      case 4: break;
      case 5: break;
      default: printf("Opcao invalida\n");
    }
  }

  fflush(stdin);
  printf("\nOperacao concluida\7");
  system("pause > nul"); // Espera para que se carregue numa tecla para continuar

}

void Utilizadores()
{
  int a = 0;
  int indLinha = 0;
  while (a != 7) // Ciclo para que volte sempre ao menu cada vez que se inserir uma opcao diferente
  {

    system("cls"); // Limpa o ecra

    puts("-------------------------------------------------------");
    puts("                         MENU                          ");
    puts("                                                       ");
    puts("     O que pretende realizar?                          ");
    puts("                                                       ");
    puts("1 -- Realizar um deposito                              ");
    puts("2 -- Realizar um levantamento                          ");
    puts("3 -- Realizar uma transsferencia                       ");
    puts("4 -- Consultar Movimentos                              ");
    puts("5 -- Consultar saldo da conta                          ");
    puts("6 -- Pedir um extrato bancario                         ");
    puts("7 -- Sair                                              ");
    puts("-------------------------------------------------------");

    printf("Insira a opcao: ");
    scanf("%d", &a);
    fflush(stdin);

    system("cls");

    switch (a)
    {
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

int Main()
{
  int a

  printf("Insira o seu pin: ");
  scanf("%d", &a);

  if(a = )
}
