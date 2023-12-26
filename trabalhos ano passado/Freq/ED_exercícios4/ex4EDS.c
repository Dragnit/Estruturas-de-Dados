
#include <stdio.h>
#include <string.h>
struct funcionarios{
    int numero;
    char nome[100];
    char tarefa[100];
    float salario;
};
typedef struct funcionarios func;

void IntroduzirDados(int nmrfunc, func dados[nmrfunc])
{
    for(int i=0;i<nmrfunc;i++)
    {
        printf("\nNome: ");
        fflush(stdin);
        gets(dados[i].nome);
        printf("\nNumero: ");
        scanf("%d", &dados[i].numero);
        printf("\nTarefa: ");
        fflush(stdin);
        gets(dados[i].tarefa);
        printf("\nSalario: ");
        scanf("%f", &dados[i].salario);
    }
}
void ApresentarDados(int nmrfunc, func dados[nmrfunc])
{
    for(int i=0;i<nmrfunc;i++)
    {
        printf("Nome: %s\n", dados[i].nome);
        printf("Numero: %d\n", dados[i].numero);
        printf("Tarefa: %s\n", dados[i].tarefa);
        printf("Salario: %.1f\n\n", dados[i].salario);
    }
}
void ListarAcima500(int nmrfunc, func dados[nmrfunc])
{
    for(int i=0;i<nmrfunc;i++)
    {
        if(dados[i].salario > 500)
        {
            printf("Nome: %s\n", dados[i].nome);
            printf("Numero: %d\n", dados[i].numero);
            printf("Tarefa: %s\n", dados[i].tarefa);
            printf("Salario: %.1f\n\n", dados[i].salario);
        }
    }
}
func ProcurarFuncionario(int nmrfunc, func dados[nmrfunc])
{
    char procurar[100];
    func b;
    strcpy(b.nome, "");
    strcpy(b.tarefa, "");
    b.numero = 0;
    b.salario = 0;
    printf("\nIntroduza o nome do funcionario que deseja encontrar: ");
    fflush(stdin);
    gets(procurar);
    for(int i=0;i<nmrfunc;i++)
    {
        if(strcmp(dados[i].nome, procurar)==0)
            return dados[i];
    }
    return b;
}
void AtualizarDados(int nmrfunc, func dados[nmrfunc])
{
    int numerofunc;
    printf("\nInsira o numero do funcionario cujos dados quer atualizar: ");
    scanf("%d", &numerofunc);
    for(int i=0;i<nmrfunc;i++) {
        if (numerofunc == dados[i].numero) {
            printf("\nInsira de novo os dados: ");
            printf("\nNome: ");
            fflush(stdin);
            gets(dados[i].nome);
            printf("\nNumero: ");
            scanf("%d", &dados[i].numero);
            printf("\nTarefa: ");
            fflush(stdin);
            gets(dados[i].tarefa);
            printf("\nSalario: ");
            scanf("%f", &dados[i].salario);
        }
    }
}
void OrdemNumero(int nmrfunc, func dados[nmrfunc])
{
    func aux;
    for(int i=0;i<nmrfunc;i++)
    {
        for(int x=0;x<nmrfunc;x++)
            if (dados[x + 1].numero < dados[x].numero)
            {
                aux = dados[x];
                dados[x] = dados[x + 1];
                dados[x + 1] = aux;
            }
    }
}
void OrdemNome(int nmrfunc, func dados[nmrfunc])
{
    func aux;
    for(int i=0;i<nmrfunc;i++)
    {
        for(int x=0;x<nmrfunc;x++)
            if (strcmp(dados[x].nome, dados[x+1].nome)>0)
            {
                aux = dados[x];
                dados[x] = dados[x + 1];
                dados[x + 1] = aux;
            }
    }
}
void main()
{
    int nmrfunc;
    func f;
    int opcao;
    printf("\nInsira o numero de funcionarios: ");
    scanf("%d", &nmrfunc);
    func dados[nmrfunc];
    do {
        printf("\n\n--------MENU--------\n\n");
        printf("1. Introduzir dados\n");
        printf("2. Listar funcionarios\n");
        printf("3. Listar funcionarios com salario superior a 500\n");
        printf("4. Procurar funcionarios\n");
        printf("5. Atualizar dados\n");
        printf("6. Ordenar funcionarios por numero (ordem crescente)\n");
        printf("7. Ordenar funcionarios por nome (ordem alfabetica)\n");
        printf("0. Sair");
        printf("\nInsira a sua opcao: ");
        scanf("%d", &opcao);
        switch (opcao)
        {
            case 1:
                IntroduzirDados(nmrfunc, dados);
                break;
            case 2:
                ApresentarDados(nmrfunc, dados);
                break;
            case 3:
                printf("\n\nFuncionarios com salario acima de 500 euros: \n\n");
                ListarAcima500(nmrfunc, dados);
                break;
            case 4:
                f = ProcurarFuncionario(nmrfunc, dados);
                printf("Nome: %s\n", f.nome);
                printf("Numero: %d\n", f.numero);
                printf("Tarefa: %s\n", f.tarefa);
                printf("Salario: %.1f\n\n", f.salario);
                break;
            case 5:
                AtualizarDados(nmrfunc, dados);
                break;
            case 6:
                OrdemNumero(nmrfunc, dados);
                printf("\nNumeros ordenados: \n");
                ApresentarDados(nmrfunc, dados);
                break;
            case 7:
                OrdemNome(nmrfunc, dados);
                printf("\nNomes ordenados: \n");
                ApresentarDados(nmrfunc, dados);
                break;
            case 0:
                printf("\nDecidiu sair.");
                break;
            default:
                printf("\nOpcao invalida.");
                break;
        }
        getchar();
    }
        while (opcao != 0);
}