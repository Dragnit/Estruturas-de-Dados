#include<stdio.h>
#include<string.h>
#include<math.h>

typedef struct Funcionario { 
  char Nome[15];
  int numero;
  char tarefa[15];
  float salario;
}funcionario;

int inserirFuncionario(funcionario tabela[], int n)
{
    funcionario f;
    int m=0;

    printf("Quantos funcionarios deseja inserir na tabela? ");
    scanf("%d", &m);

    for (int i = 0; i < m; i++)
    {
        puts("insira o nome do funcionario: ");
        scanf("%s", &f.Nome);

        puts("insira o numero do funcionario: ");
        scanf("%d", &f.numero);

        puts("insira a tarefa do funcionario: ");
        scanf("%s", &f.tarefa);

        puts("insria o salario do funcionario: ");
        scanf("%f", &f.salario);

        tabela[n+i] = f;
    }

    

    return n+m;
}

void listarFuncionarios(funcionario tabela[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Nome: %s\n", tabela[i].Nome);
        printf("Numero: %d\n", tabela[i].numero);
        printf("Tarefa: %s\n", tabela[i].tarefa);
        printf("Salario: %.2f\n\n", tabela[i].salario);
    }
}

void salariosuperior(funcionario tabela[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (tabela[i].salario > 500)
        {
            printf("Nome: %s\n", tabela[i].Nome);
            printf("Numero: %d\n", tabela[i].numero);
            printf("Tarefa: %s\n", tabela[i].tarefa);
            printf("Salario: %.2f\n\n", tabela[i].salario);
        }
    }
}

void procurarNome(funcionario tabela[], int n)
{
    char nome[15];

    puts("Insira o nome que deseja procurar: ");
    scanf("%s", nome);

    int encontrado = 0;
    for (int i = 0; i < n; i++)
    {
        if (strcmp(nome, tabela[i].Nome) == 0)
        {
            printf("Nome: %s\n", tabela[i].Nome);
            printf("Numero: %d\n", tabela[i].numero);
            printf("Tarefa: %s\n", tabela[i].tarefa);
            printf("Salario: %.2f\n\n", tabela[i].salario);
            encontrado = 1;
        }
    }
    if (!encontrado)
        puts("Funcionario nao existe.");
}

int main()
{
    int a, n=0;
    funcionario tabela[100];

    do
    {
                printf("\nMenu:\n");
        printf("1. Inserir funcionarios\n");
        printf("2. Listar funcionarios\n");
        printf("3. Listar funcionarios com salario superior a 500\n");
        printf("4. Pesquisa de funcionarios por nome\n");
        printf("4. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &a);

        switch (a)
        {
        case 1:
            n = inserirFuncionario(tabela, n);
            break;
         case 2:
            listarFuncionarios(tabela, n);
            break;
        case 3:
            salariosuperior(tabela, n);
            break;
        case 4:
            procurarNome(tabela, n);
            break;
        default:
            break;
        }

    }while(a != 4);
    
    return 0;

}