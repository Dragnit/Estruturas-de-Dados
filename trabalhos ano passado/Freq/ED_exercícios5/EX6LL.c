
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//alínea a
typedef struct lno * plista;
typedef struct lno
{
    int numero;
    char nome[200];
    char tarefa[200];
    float salario;
    struct lno *prox;
}listano;

//alínea b
//i
void EscreveDados(float x, int nmr, char nome[], char tarefa[], plista * lst) {
        plista no = (plista) malloc(sizeof(listano));
        plista paux = *lst;
        if (no == NULL)
            printf("\nErro, nao ha memoria disponivel.");
        else {
            printf("\nIndique o numero do funcionario: ");
            scanf("%d", &nmr);
            printf("\nInsira o nome do funcionario: ");
            fflush(stdin);
            gets(nome);
            printf("\nInsira a tarefa do funcionario: ");
            fflush(stdin);
            gets(tarefa);
            printf("\nInsira o salario do funcionario: ");
            scanf("%f", &x);
            no->salario = x;
            no->numero = nmr;
            strcpy(no->tarefa, tarefa);
            strcpy(no->nome, nome);
            no->prox = NULL;
            if (*lst == NULL) {
                *lst = no;
            } else {
                while (paux->prox != NULL) {
                    paux = paux->prox;
                }
                paux->prox = no;
            }
        }
}

//ii

void ApresentarDados(plista lst)
{
    if(lst == NULL)
        printf("\nNao existem funcionarios!!");
    else{
        while (lst != NULL)
        {
            printf("\nNome do funcionario: %s", lst->nome);
            printf("\nNumero do funcionario: %d", lst->numero);
            printf("\nTarefa do funcionario: %s", lst->tarefa);
            printf("\nSalario do funcionario: %.1f", lst->salario);
            printf("\n\n");
            lst = lst->prox;
        }
         }
}

//iii

void SalarioAcima500(plista lst)
{
    if(lst == NULL)
        printf("\nNao existem funcionarios!");
    else {
        while (lst != NULL) {
            if (lst->salario > 500) {
                printf("\nNome do funcionario: %s", lst->nome);
                printf("\nNumero do funcionario: %d", lst->numero);
                printf("\nTarefa do funcionario: %s", lst->tarefa);
                printf("\nSalario do funcionario: %.1f", lst->salario);
                printf("\n");
            }
            lst = lst->prox;
        }
    }
}

//iv

plista ProcuraFuncionario(plista lst)
{
    char procurar[200];
    printf("\nInsira o nome do funcionario que deseja encontrar: ");
    fflush(stdin);
    gets(procurar);
            while(lst!=NULL)
            {
                if(strcmp(lst->nome, procurar)==0)
                {
                    return lst;
                    break;
                }
                lst = lst->prox;
            }
            return NULL;
}
void AtualizarDados(plista lst)
{
    int numero, nmr;
    char nome[200], tarefa[200];
    float x;
    printf("\nInsira o numero do funcionario cujos dados pretende atualizar: ");
    scanf("%d", &numero);
    if(lst == NULL)
        printf("\nNao existem funcionarios!");
    else {
        while(lst != NULL)
        {
            if (lst->numero == numero)
            {
                printf("\nIndique o numero do funcionario: ");
                scanf("%d", &nmr);
                printf("\nInsira o nome do funcionario: ");
                fflush(stdin);
                gets(nome);
                printf("\nInsira a tarefa do funcionario: ");
                fflush(stdin);
                gets(tarefa);
                printf("\nInsira o salario do funcionario: ");
                scanf("%f", &x);
                lst->salario = x;
                lst->numero = nmr;
                strcpy(lst->tarefa, tarefa);
                strcpy(lst->nome, nome);
            }
            lst = lst->prox;
        }
    }
}

void OrdenaNomes(plista * lst)
{
    plista paux = NULL;
    char auxiliar[200];
    int flag = 0, aux;
    while(flag == 0)
    {
        flag = -1;
        paux = *lst;
        while(paux->prox != NULL)
        {
            if (strcmp(paux->nome, (paux->prox)->nome)>0)
            {
                strcpy(auxiliar, (paux->prox)->nome);
                strcpy((paux->prox)->nome, paux->nome);
                strcpy(paux->nome, auxiliar);

                aux = (paux->prox)->salario;
                (paux->prox)->salario = paux->salario;
                paux->salario = aux;

                aux = (paux->prox)->numero;
                (paux->prox)->numero = paux->numero;
                paux->numero = aux;

                strcpy(auxiliar, (paux->prox)->tarefa);
                strcpy((paux->prox)->tarefa, paux->tarefa);
                strcpy(paux->tarefa, auxiliar);

                flag = 0;
            }
            paux = paux->prox;
        }
    }
}
void main()
{
    float x;
    int n, nmr;
    char nome[200];
    char tarefa[200];
    plista a = NULL;
    printf("\nInsira o numero de funcionarios: ");
    scanf("%d", &n);
    for(int i=0;i<n;i++)
    EscreveDados(x, nmr, nome, tarefa, &a);
    ApresentarDados(a);
    printf("\n\nFuncionarios com salario acima de 500: \n\n");
    SalarioAcima500(a);
    plista b = ProcuraFuncionario(a);
    if(b!=NULL)
        printf("\nFuncionario %s encontrado(a)!\n", b->nome);
    else printf("\nFuncionario nao encontrado!\n");
    AtualizarDados(a);
    printf("\nLista atualizada de funcionarios: \n");
    ApresentarDados(a);
    OrdenaNomes(&a);
    printf("\nLista apos ordenada alfabeticamente: ");
    ApresentarDados(a);
}