#include <stdio.h>
#include <stdlib.h>


// linked list of accounts datastructure
typedef struct account
{
  char name[30];
  int number;
  float balance;
  struct account *next; // se for NULL, nao tem mais elementos
} account_node, *account_list;


// linked list of users datastructure
typedef struct user
{
  char name[30];
  int age;
  int pin;
  int is_admin;
  int accounts[10];
  struct user *next;
} user_node, *user_list;


account_list accounts = NULL;
user_list users = NULL;

// user_node logged_in;


void create_acc()
{
  int a;
  FILE *ptr;
  ptr=fopen("contas.dat","a+");
  account_no;
  system("clear");

  puts("Insira o seu Nome: ")
  scanf("%s", &add.nome);
  fprintf(ptr, "%s\n", add.nome);
  puts("Insira o seu Telefone: ")
  scanf("%d", &add.telefone);
  fprintf(ptr, "%d\n", add.telefone);
  puts("Insira o seu Numero de Cliente: ")
  scanf("%s", &add.Numero);
  fprintf(ptr, "%d\n", add.Numero);
  puts("Insira o seu Pin: ")
  scanf("%d", &add.pin);
  fprintf(ptr, "%d\n", add.pin);



}


void create_user(user_list *list, char name[30], int age, int pin, int is_admin)
{
  // list -> NULL ou nao NULL (nao interessa caso se adicione a cabeca)
  //  criar novo elemento (primeiro ou nao)
  //  inicializar valores
  //  associar o next do novo elemento a lista (next do novo elemento = *list)
  //  associar a lista ao novo elemento (*list = novo elemento)
}


void depositar(int num)
{
  // argumentos tem que ter algum significado
  //  sobre uma conta?
  //  sobre uma conta de um utilizador?
  //  saldo que queres depositar?
  //  manter alguma forma de infomacao sobre o utilizador ou conta

  int pin = 0;

  puts("insira o seu pin: ");
  scanf("%d", &pin);

  for (int i = 0; i < num; i++)
  {
    // utilizador e um tipo, nao uma variavel
    if (utilizador.pin_user == pin)
    {
      // t nao esta definido
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
    case 1:
      inserirTarefa();
      break;
    case 2:
      estado();
      break;
    case 3:
      menuConsulta();
      break;
    case 4:
      break;
    case 5:
      break;
    default:
      printf("Opcao invalida\n");
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
    case 1:
      inserirTarefa();
      break;
    case 2:
      estado();
      break;
    case 3:
      menuConsulta();
      break;
    case 4:
      break;
    case 5:
      break;
    default:
      printf("Opcao invalida\n");
    }
  }

  fflush(stdin);
  printf("\nOperacao concluida\7");
  system("pause > nul"); // Espera para que se carregue numa tecla para continuar
}
