
#include <stdio.h>
#include <stdlib.h>
typedef struct lno * ppilha;
typedef struct lno
{
    float valor;
    struct lno *prox;
}pilha;

//alínea a
ppilha CriaPilha()
{
    ppilha p = NULL;
    return p;
}
//alínea b
char PilhaVazia(ppilha lst)
{
    if(lst == NULL)
        return 'y';
    else
        return 'n';
}

//alínea c
void AcrescentaPilha(float x, ppilha * lst)
{
    ppilha no = (ppilha)malloc(sizeof(pilha));
    if(no == NULL)
        printf("\nErro, nao ha memoria disponivel");
    else
    {
        no->valor = x;
        no->prox = *lst;
        *lst = no;
    }
}
//alínea d
void RemovePilha(ppilha * lst)
{
    ppilha paux = *lst;
    (*lst) = (*lst)->prox;
    free(paux);
}

//alínea e
void MostraPrimeiro(ppilha lst)
{
    if(PilhaVazia(lst)=='y')
        printf("\nPilha esta vazia!");
    else
    printf("\nO primeiro elemento e: %.1f", lst->valor);
}
void main()
{
    ppilha a = CriaPilha();
    int opcao;
    float x;

    do {
        printf("\n\n\n1.Verificar se a pilha e vazia.");
        printf("\n2.Mostrar o primeiro elemento da pilha.");
        printf("\n3.Acrescentar um valor na pilha.");
        printf("\n4.Remover elemento da pilha.");
        printf("\n0.Sair do menu");
        printf("\nEscolha a sua opcao:");
        scanf("%d", &opcao);
        fflush(stdin);

        switch (opcao) {
            case 1:
                if(PilhaVazia(a)=='y')
                    printf("\nA pilha esta vazia.");
                else
                    printf("\nA pilha nao esta vazia.");
                break;
            case 3:
                printf("\nInsira o valor que deseja inserir na pilha: ");
                scanf("%f", &x);
                AcrescentaPilha(x, &a);
                break;
            case 2:
                MostraPrimeiro(a);
                break;
            case 4:
                RemovePilha(&a);
                break;
            case 0:
                break;
        }
    }
    while (opcao != 0);
}