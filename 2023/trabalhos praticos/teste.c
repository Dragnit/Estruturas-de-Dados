#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct cliente {
    int telefone;
    char nome[20];
    int nif;
    char mail[50];
    int numeroCliente;
    char cartao[20];
    float compras[20];
    int voucher;
    float totalCompras;
    struct cliente* proximo; // Ponteiro para o próximo cliente
} cliente;


void data(char dataformatada[10])
{
  time_t t = time(NULL);
  struct tm *tm = localtime(&t);
  strftime(dataformatada, 11, "%Y%m%d", tm);
}

cliente registaCliente() {
    srand(time(NULL));
    long long numero = rand() % 90000 + 10000;

    cliente cliente;
    printf("Insira o seu nome: \n");
    scanf("%s", cliente.nome);

    printf("Insira o NIF: \n");
    scanf("%d", &cliente.nif);

    printf("Insira o numero de telefone: \n");
    scanf("%d", &cliente.telefone);

    printf("Insira o email: \n");
    scanf("%s", cliente.mail);

    printf("Possui cartao da empresa? \n");
    scanf("%s", cliente.cartao);

    cliente.numeroCliente = numero;
    printf("numero de cliente: %lld\n", numero);
    cliente.voucher = 0;
    for (int i = 0; i < 20; i++)
        cliente.compras[i] = 0;

    return cliente;
}

void criaCSV(cliente c[100], int i, char loja[20])
{
  char nomearquivo[50];
  char dataf[10];
  data(dataf);
  sprintf(nomearquivo, "%s_%s.csv", loja, dataf);
  FILE *fp = fopen(nomearquivo, "a");
  if (fp == NULL)
  {
    perror("Erro ao abrir o arquivo");
    return;;
  }
  // caso esteja vazio acrescenta cabeçalho
  fseek(fp, 0, SEEK_END);
  if (ftell(fp) == 0)
  {
    fputs("Data\tCompra (€)\tN.º Cliente\n", fp);
  }
  for (int j = 0; j < i; j++)
    for (int k = 0; c[j].compras[k] != 0; k++)
      fprintf(fp, "%s\t%f\t%d\n",dataf, c[j].compras[k], c[j].numeroCliente);

  fclose(fp);
}

void removerCliente(cliente c[100], int i)
{
  int numero;
  printf("Insira o numero do cliente: ");
  scanf("%d", &numero);
  int clienteRemovido = 0;
  for (int j = 0; j < i; j++)
  {
    if (numero == c[j].numeroCliente){
      memset(c[j].nome, ' ', sizeof(c[j].nome)); // preenche o array nome com espaços em branco
      memset(c[j].mail, ' ', sizeof(c[j].mail));
      memset(c[j].cartao, ' ', sizeof(c[j].cartao));
      c[j].telefone = 0;
      c[j].nif = 0;
      printf("Cliente removido com sucesso.\n");
      clienteRemovido = 1;
      }
    }
    if (!clienteRemovido)
    {
        printf("Cliente não encontrado.\n");
    }
}

void listarClientes(cliente c[100], int i)
{
  for (int j = 0; j < i; j++)
  {
    if (c[j].nif!=0){
      printf("Nome: %s\n", c[j].nome);
      printf("Numero de Cliente: %d\n", c[j].numeroCliente);
      printf("\n");
    }
  }
}

void editardados_recursivo(cliente c[100], int i)
{
  int num;
  printf("Insira o número de cliente: ");
  scanf("%d", &num);

  // Verificar se o número de cliente existe
  int index = -1;
  for (int j = 0; j < i; j++)
  {
    if (num == c[j].numeroCliente)
    {
      index = j;
      break;
    }
  }

  if (index != -1)
  {
    printf("Nome: ");
    scanf("%s", c[index].nome);

    printf("NIF: ");
    scanf("%d", &c[index].nif);

    printf("Número de telefone: ");
    scanf("%d", &c[index].telefone);

    printf("Email: ");
    scanf("%s", c[index].mail);

    printf("Possui cartão da empresa? ");
    scanf("%s", c[index].cartao);

    printf("Dados do cliente atualizados com sucesso.\n");
  }
  else
  {
    printf("Cliente não encontrado.\n");
  }

  // Perguntar se deseja editar mais clientes
  char resposta;
  printf("Deseja editar mais clientes? (s/n): ");
  scanf(" %c", &resposta);
  if (resposta == 's' || resposta == 'S')
  {
    editardados_recursivo(c, i);
  }
}


void guardarBinario(cliente c[100], int i)
{
    FILE *fp = fopen("binario", "wb");

    if (fp == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    fwrite(c, sizeof(cliente), i, fp);

    fclose(fp);
}

void registar_compra(cliente c[100], int i)
{
    int num;
    char resposta[5];
    float valor;
    char loja[20];
   
    puts("Insira o número de cliente: ");
    scanf("%d", &num);
    for (int j = 0; j < i; j++)
    {
        if (num == c[j].numeroCliente)
        {
            printf("Digite o valor da compra: ");
            scanf("%f", &valor);
            printf("Em que loja: ");
            scanf(" %s", loja);
            if (valor > 50 && strcmp(c[j].cartao, "sim") == 0)
            {
                if (c[j].voucher != 0)
                {
                    printf("Quer usar um voucher? ");
                    scanf("%s", resposta);
                    if (strcmp(resposta, "sim") == 0)
                    {
                        valor = valor * (50 / 100.0);
                        c[j].voucher--;
                        printf("valor: %.2f\n", valor);
                    }
                    else
                    {
                        c[j].voucher++;
                        printf("Voucher adicionado.\n");
                    }
                }
                else
                {
                    c[j].voucher++;
                    printf("Voucher adicionado.\n");
                }
            }
            for (int a = 0; a < 20; a++)
            {
                if (c[j].compras[a] == 0)
                {
                    c[j].compras[a] = valor;
                    printf("Compra registrada: %.2f\n", c[j].compras[a]);
                    break;
                }
            }
        }
    }
    criaCSV(c, i, loja);
}

void mostrar_compras(cliente c[100], int i) {
  printf("compra\t cliente\n");
  for (int j = 0; j < i; j++) {
    for (int k = 0; k < 20; k++) {
      if (c[j].compras[k] != 0) {
        printf("%.2f\t%d\n", c[j].compras[k], c[j].numeroCliente);
      }
    }
  }
}

void visualizar(cliente c[100], int i)
{
  float soma = 0;
  int num, k=0;
  int totalVouchers = 0;
  printf("Insira o numero do cliente: ");
  scanf("%d", &num);

  for (int j = 0; j < i; j++) 
  {
    if (num == c[j].numeroCliente) 
    {
      for (int a = 0; c[j].compras[a]!=0; a++)
      {
        soma += c[j].compras[a];
        k++;
      }
      totalVouchers = c[j].voucher;
      break;  // Interrompe o loop após encontrar o cliente desejado
    }
  }

  printf("Valor total de compras: %.2f\n", soma);
  printf("Media das compras: %.2f\n", soma / k);
  printf("O cliente possui: %d voucher(s)\n", totalVouchers);
}

void ordenar(cliente c[100], int i)
{
    for (int j = 0; j < i; j++)
    {
       c[j].totalCompras = 0; // Redefinir totalCompras para cada cliente
        for (int a = 0; c[j].compras[a] != 0; a++)
            c[j].totalCompras += c[j].compras[a];
    }

    cliente temp;
    for (int j = 0; j < i - 1; j++)
    {
        for (int k = 0; k < i - j - 1; k++)
        {
            if (c[k].totalCompras < c[k + 1].totalCompras)
            {
                temp = c[k];
                c[k] = c[k + 1];
                c[k + 1] = temp;
            }
        }
    }
    printf("\nClientes ordenados por valor total de compras:\n");
    for (int a = 0; a < i; a++)
    {
        printf("Nome: %s, Total de compras: %.2f\n", c[a].nome, c[a].totalCompras);
    }
}

void velesdisponiveis(cliente c[100], int i){
  int num;
  int disp;
   printf("Insira o numero do cliente: ");
  scanf("%d", &num);

  for (int j = 0; j < i; j++) 
  {
    if (num == c[j].numeroCliente) 
    {
      disp = c[j].voucher;
      break;  // Interrompe o loop após encontrar o cliente desejado
    }
  }
  printf("tem ainda %d vouchers disponiveis", disp);
}

int clienteParticular(cliente c[100], int i)
{
  char opcao;

  // system("cls"); // limpa o terminal (Windows)

  puts("******************************************************");
  puts("* A - Editar dados                                   *");
  puts("* B - Mostrar compras registadas                     *");
  puts("* C - Registar nova compra                           *");
  puts("* D - Visualizar a média, o valor total              *");
  puts("*     de compras e o número total de vales usados    *");
  puts("* E - Verificar vales disponíveis                    *");
  puts("* J - Sair do programa                               *");
  puts("******************************************************");
  printf("Opção: ");

  fflush(stdin);
  scanf(" %c", &opcao);

  switch (opcao) {
    case 'A':
      editardados_recursivo(c, i);
      break;
    case 'B':
      mostrar_compras(c, i);
      break;
    case 'C':
      registar_compra(c, i);
      break;
    case 'D':
      visualizar(c, i);
      break;
    case 'E':
      velesdisponiveis(c, i);
      break;
    case 'J':
      printf("Adeus\n");
      return 0;
    default:
      printf("Opção inválida\n");
  }

  printf("\nPressione enter para continuar\n");
  fflush(stdin);
  getchar();

  // Chama recursivamente a função clienteParticular
  clienteParticular(c, i);
}


void ficheiro(cliente c[100], int *i){
    FILE *fp;
    fp = fopen("binario", "rb");
    if (fp == NULL)
    {
      printf("Erro ao abrir o arquivo.\n");
      return;
    }
    int elementos_lidos = fread(c, sizeof(cliente), 100, fp);
    fclose(fp);

    if (elementos_lidos > 0){
      *i = elementos_lidos;
      printf("Dados do arquivo binário lidos com sucesso.\n");
    }
    else
      printf("Arquivo binário vazio ou erro ao ler os dados.\n");
}
int main()
{
  system("chcp 65001");
  char opcao;
  int i = 0;
  cliente c[100]; // Array para armazenar os clientes registrados
  ficheiro(c, &i); // Lê os dados do arquivo binário

  do{
    //system("cls"); // limpa o terminal (Windows)

    puts("************************************************");
    puts("* A - registar cliente                         *");
    puts("* B - remover cliente                          *");
    puts("* C - listar clientes                          *");
    puts("* D - cliente em particular                    *");
    puts("* E - ordenar clientes                         *");
    puts("* J - Sair do programa                         *");
    puts("************************************************");
    printf("Opcao: ");

    fflush(stdin);
    scanf(" %c", &opcao); // Corrigido para evitar problemas com o buffer

    switch (opcao){
      case 'A':
        c[i] = registaCliente();
        i++;
        break;
      case 'B':
        removerCliente(c, i);
      break;
      case 'C': 
        listarClientes(c, i);
        break;
      case 'D': 
        clienteParticular(c,i);
       break;
      case 'E':
        ordenar(c, i);
        break;
      case 'J': 
        printf("bye \n"); 
        guardarBinario(c, i);
      break;
      default:  printf("opcao invalida\n");
    }
    printf("Pressione enter para continuar\n"); fflush(stdin); getchar();
  }
  while(opcao != 'J');

  return 0;
}