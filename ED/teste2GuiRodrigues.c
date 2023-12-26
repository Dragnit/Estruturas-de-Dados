#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct servico//estrutura dos servicos
{
  int codigo;
  char data_inicio[];
  char data_inicio[];
  char nome;
  int n_telemovel;
  char servico[50];
} servico, *list;

void mem_error()//funcao de erro
{
    perror("Not enough memory");
    exit(1);
}

void cria_lista(list *lst, float val)//cria uma lista
{
  *lst = (list)malloc(sizeof(node));

  if (*lst == NULL)
  mem_error();

  (*lst)->value = val;
  (*lst)->next = NULL;
  return;
}

void dados()//funcao de insercao de dados
{
  int a;
  time_t ddh;
  time(&ddh);

  puts("Insira o codigo: ")
  scanf("%d", &add.codigo);
  puts("Insira o Nome: ")
  scanf("%s", &add.nome);
  puts("Insira o Numemor de Telemovel: ")
  scanf("%d", &add.n_telemovel);
  puts("Insira o tipo de servico: ")
  scanf("%d", &add.servico);

  printf("%d \n", &add.codigo);
  printf("%s \n", add.nome);
  printf("dia/data/hora: %s \n", ctime(&ddh));
  printf("%d \n", &add.n_telemovel);
  printf("%s", add.servico);

}


void main()
{
  dados();

}
