#include <stdio.h>
#include <string.h>

typedef struct func
{
  int num;
  char nome[20];
  char tarefa[20];
  float salario;
}funcionario;


funcionario lefunc()
{
  funcionario f;
  puts("insira o nome");
  fflush(stdin);
  scanf("%s", &f.nome);
  puts("insira o numero");
  scanf("%d", &f.num);
  puts("insira a tarefa");
  fflush(stdin);
  scanf("%s", &f.tarefa);
  puts("insira o salario");
  scanf("%f", &f.salario);
  return f;
}

int adicionaFunc(funcionario f,funcionario t[], int n)
{
  if(n < 50)
  {
    t[n] = f;
    return n++;
  }
  else
  {
    puts("numero maximo de funcionario atingido");
    return n;
  }
}

void listarFunc(funcionario t[], int numF)
{
  for(int i=0; i<numF; i++)
  {
    printf("%s\n", t[i].nome);
    printf("%d\n", t[i].num);
    printf("%s\n", t[i].tarefa);
    printf("%.2f\n", t[i].salario);

  }
}

void acimaQuinhentos(funcionario t[], int numF)
{
  puts("\nO funcionario que tem um salario superior a 500 e:");
  for(int i=0; i<numF; i++)
  {
    if(t[i].salario > 500)
      printf("%s\n", t[i].nome);
  }
}

void procuraFunc(funcionario t[], int numF)
{
  char nome[20];
  puts("\ninsira o nome do funcionario que pretende procurar:");
  scanf("%s", &nome);
  for(int i=0; i<numF; i++)
  {
    if(strcmp(t[i].nome,nome)==0)
    {
      printf("%s\n", t[i].nome);
      printf("%d\n", t[i].num);
      printf("%s\n", t[i].tarefa);
      printf("%.2f\n", t[i].salario);
    }
    else
    {
      printf("estrutura vazia\n");
    }
  }
}

int main()
{
  funcionario tf[50];
  int numF = 0;

  funcionario f = lefunc();
  adicionaFunc(f,tf,numF);
  numF ++;

  f = lefunc();
  numF = adicionaFunc(f,tf,numF);
  numF++;
  listarFunc(tf,numF);
  acimaQuinhentos(tf,numF);
  procuraFunc(tf,numF);
  return 0;
}
