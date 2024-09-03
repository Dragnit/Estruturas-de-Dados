
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct funcionarios{
    int numero;
    char nome[100];
    char tarefa[100];
    float salario;
};
typedef struct funcionarios func;

void IntroduzirDados(func * pt_func)
{
        printf("\nNome: ");
        fflush(stdin);
        gets(pt_func->nome);
        printf("\nNumero: ");
        scanf("%d", &pt_func->numero);
        printf("\nTarefa: ");
        fflush(stdin);
        gets(pt_func->tarefa);
        printf("\nSalario: ");
        scanf("%f", &pt_func->salario);
}
void ApresentarDados(func * pt_func)
{
        printf("Nome: %s\n", pt_func->nome);
        printf("Numero: %d\n", pt_func->numero);
        printf("Tarefa: %s\n", pt_func->tarefa);
        printf("Salario: %.1f\n\n", pt_func->salario);
}
void ListarAcima500(func * pt_func)
{
        if(pt_func->salario > 500)
        {
            printf("Nome: %s\n", pt_func->nome);
            printf("Numero: %d\n", pt_func->numero);
            printf("Tarefa: %s\n", pt_func->tarefa);
            printf("Salario: %.1f\n\n", pt_func->salario);
        }
}
void ProcurarFuncionario(func * pt_func, char procurar[])
{
        if(strcmp(pt_func->nome, procurar)==0)
        {
            printf("Nome: %s\n", pt_func->nome);
            printf("Numero: %d\n", pt_func->numero);
            printf("Tarefa: %s\n", pt_func->tarefa);
            printf("Salario: %.1f\n\n", pt_func->salario);
        }
}
void AtualizarDados(func * pt_func, int numerofunc)
{

        if (numerofunc == pt_func->numero)
        {
            printf("\nInsira de novo os dados: ");
            printf("\nNome: ");
            fflush(stdin);
            gets(pt_func->nome);
            printf("\nNumero: ");
            scanf("%d", &pt_func->numero);
            printf("\nTarefa: ");
            fflush(stdin);
            gets(pt_func->tarefa);
            printf("\nSalario: ");
            scanf("%f", &pt_func->salario);
        }
    }
void main()
{
    int nmrfunc, numerofunc;
    func * pt_func;
    char procurar[100];

    printf("Introduza o numero de funcionarios: ");
    scanf("%d", &nmrfunc);

    pt_func = (func *)malloc(nmrfunc*sizeof(func));

    for(int i=0;i<nmrfunc;i++)
        IntroduzirDados(&pt_func[i]);

    for(int i=0;i<nmrfunc;i++)
        ApresentarDados(&pt_func[i]);

    printf("\nFuncionarios com salario superior a 500 euros: \n\n");
    for(int i=0;i<nmrfunc;i++)
        ListarAcima500(&pt_func[i]);

    printf("\nIntroduza o nome do funcionario que deseja encontrar: ");
    fflush(stdin);
    gets(procurar);
    for(int i=0;i<nmrfunc;i++)
        ProcurarFuncionario(&pt_func[i], procurar);

    printf("\nInsira o numero do funcionario cujos dados quer atualizar: ");
    scanf("%d", &numerofunc);
        for(int i=0;i<nmrfunc;i++)
            AtualizarDados(&pt_func[i], numerofunc);
        for(int i=0;i<nmrfunc;i++)
            ApresentarDados(&pt_func[i]);
        free(pt_func);
}
