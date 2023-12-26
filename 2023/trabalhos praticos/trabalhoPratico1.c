#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct cliente
{
	int telefone;
  char nome[20];
  int nif;
  char mail[50];
  int numeroCliente;
  char cartao[20];
  int compras[20];
  int voucher;

} cliente;

void data()
{
  time_t t = time(NULL);
  struct tm *tm = localtime(&t);
  //printf("%d-%02d-%02d\n", tm->tm_year + 1900, tm->tm_mon + 1, tm->tm_mday);
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

/*void criaCSV()
{
  FILE *fp = fopen("csv.csv", "+a");

  fputs();
  
  fclose(fp);
}*/

void removerCliente(cliente c[100], int i)
{
  int numero;
  puts("Insira o numero do cliente: ");
  scanf("%d", &numero);

  FILE* arquivo = fopen("binario", "rb");
  if (arquivo == NULL) 
  {
    printf("Erro ao abrir o arquivo.\n");
    return;
  }

  FILE* arquivoTemp = fopen("temp.bin", "wb");
  if (arquivoTemp == NULL) 
  {
    printf("Erro ao criar arquivo temporário.\n");
    fclose(arquivo);
    return;
  }

  cliente cliente;

  while (fread(&cliente, sizeof(cliente), 1, arquivo) == 1) 
  {
    if (cliente.numeroCliente != numero) 
    {
      fwrite(&cliente, sizeof(cliente), 1, arquivoTemp);
    }
  }

  fclose(arquivo);
  fclose(arquivoTemp);

  remove("binario");
  rename("temp.bin", "binario");

  printf("Cliente removido com sucesso.\n");
}

void listarClientes(cliente c[100], int i)
{
  FILE* arquivo = fopen("binario", "rb");
  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo.\n");
    return;
  }

  cliente cliente;

  while (1) 
  {
    // Lê um cliente do arquivo
    size_t leitura = fread(&cliente, sizeof(cliente), 1, arquivo);

    // Verifica se a leitura foi bem-sucedida
    if (leitura != 1) 
    {
      if (feof(arquivo)) 
      {
        // Alcançou o final do arquivo, sair do loop
        break;
      } 
      else
      {
        // Erro ao ler do arquivo, exibir mensagem e sair do loop
        printf("Erro ao ler do arquivo.\n");
        break;
      }
    }

    // Imprime os dados do cliente
    printf("Nome: %s\n", cliente.nome);
    printf("Numero de Cliente: %d\n", cliente.numeroCliente);
    printf("\n");
  }

    fclose(arquivo);

  for (int j = 0; j < i; j++)
  {
    printf("Nome: %s\n", c[j].nome);
    printf("NIF: %d\n", c[j].nif);
    printf("\n");
  }

}

void editardados(cliente c[100], int i)
{
  int num;
  puts("Insira o numeo de cliente: ");
  scanf("%d", &num);
  for (int j = 0; j < i; j++)
  {
    if (num == c[j].numeroCliente)
    {
      printf("nome: \n");
      scanf("%s", c[j].nome);

      printf("NIF: \n");
      scanf("%d", &c[j].nif);

      printf("numero de telefone: \n");
      scanf("%d", &c[j].telefone);

      printf("email: \n");
      scanf("%s", c[j].mail);

      printf("Possui cartao da empresa? \n");
      scanf("%s", c[j].cartao);
    }
    
  }
}

void guardarBinario(cliente c[100], int i)
{
    FILE* fp = fopen("binario", "ab+");
  
    if (fp == NULL) 
    {
      printf("Erro ao abrir o arquivo.\n");
      return;
    }
  
    fwrite(c, sizeof(cliente), i, fp);
  
    fclose(fp);
}

void regitar_compra(cliente c[100], int i) {
    int num;
    char resposta[5];
    int valor;
    puts("Insira o número de cliente: ");
    scanf("%d", &num);
    for (int j = 0; j < i; j++) {
        if (num == c[j].numeroCliente) {
            printf("Digite o valor da compra: ");
            scanf("%d", &valor); // guardar compra juntamente com o cliente
            
            if (valor > 50 && strcmp(c[j].cartao, "sim") == 0) {
                if (c[j].voucher != 0) {
                    printf("Quer usar um voucher? ");
                    scanf("%s", resposta);
                    if (strcmp(resposta, "sim") == 0){
                        valor=valor*(50/100);
                        c[j].voucher--;
                    }else {
                        c[j].voucher++;
                        printf("Voucher adicionado.\n");
                    }
                } 
                else {
                    c[j].voucher++;
                    printf("Voucher adicionado.\n");
                }
            }
            for (int a = 0; a < 20; a++)
            {
              if (c[j].compras[a] == 0) { // Check for the next available position (where value is 0)
                c[j].compras[a] = valor;
                break;
              }
            }
            printf("Compra registrada.\n");
        }
    }
    
}

void mostrar_compras(cliente c[100], int i){
  printf("compra\t cliente\n");
  for (int j = 0; j < i; j++)
  {
    printf("%d", c[j].compras[j]);
    printf("\t%d\n", c[j].numeroCliente);
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
  do{
    //system("cls"); // limpa o terminal (Windows)
    
    puts("******************************************************");
    puts("* A - Editar dados                                   *");
    puts("* B - Mostrar compras registadas                     *");
    puts("* C - Registar nova compra                           *");
    puts("* D - visualizar a media, o valor total              *");
    puts("*     de compras e o numero total de vales usados    *");
    puts("* E - verificar vales disponiveis                    *");
    puts("* J - Sair do programa                               *");
    puts("******************************************************");
    printf("Opcao: ");

    fflush(stdin);
    scanf("%c", &opcao);
    

    switch(opcao){
      case 'A': 
        editardados(c,i);
        break;
      case 'B':
        mostrar_compras(c,i);
        break;
      case 'C': 
        regitar_compra(c,i);
        break;
      case 'D': 
        visualizar(c,i);
       break;
      case 'E': 
        velesdisponiveis(c,i);
        break;
      case 'J': 
        printf("Adeus\n"); 
        
      break;
      default:  printf("opcao invalida\n");
    }
    printf("\nPressione enter para continuar\n"); fflush(stdin); getchar();
  }
  while(opcao != 'J');

  return 0;
}

int main(){
  char opcao;
  int i = 0;
  cliente c[100]; // Array para armazenar os clientes registrados

  do{
    //system("cls"); // limpa o terminal (Windows)
    
    puts("************************************************");
    puts("* A - registar cliente                         *");
    puts("* B - remover cliente                          *");
    puts("* C - listar clientes                          *");
    puts("* D - cliente em particular                    *");
    puts("* E - ordenar clientes                         *");
    puts("* F - criar um ficheir csv para uma loja       *");
    puts("* J - Sair do programa                         *");
    puts("************************************************");
    printf("Opcao: ");

    fflush(stdin);
    scanf("%c", &opcao);
    

    switch(opcao){
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
  
        break;
      case 'F': 
 
        break;
      case 'J': 
        printf("Siga comer um binario de ficheiro? \n"); 
        guardarBinario(c, i);
      break;
      default:  printf("opcao invalida\n");
    }
    printf("Pressione enter para continuar\n"); fflush(stdin); getchar();
  }
  while(opcao != 'J');

  return 0;
}