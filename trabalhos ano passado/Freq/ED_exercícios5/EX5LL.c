
#include    <stdio.h>
#include <stdlib.h>
typedef struct lno * pfila;
typedef struct lno
{
    float valor;
    struct lno *prox;
}fila;

//alínea a
pfila CriaFila()
{
    pfila p = NULL;
    return p;
}
//alínea b
char FilaVazia(pfila lst)
{
    if(lst == NULL)
        return 'y';
    else
        return 'n';
}

//alínea c
void AcrescentaFila(float x, pfila * lst)
{
    pfila no = (pfila) malloc(sizeof(fila));
    pfila paux = *lst;
    if (no == NULL)
        printf("\nErro, nao ha memoria disponivel.");
    else {
        no->valor = x;
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
//alínea d
void RemoveFila(pfila * lst)
{
    pfila paux = *lst;
    (*lst) = (*lst)->prox;
    free(paux);
}

//alínea e
void MostraInicio(pfila lst)
{
    if(FilaVazia(lst)=='y')
        printf("\nPilha esta vazia!");
    else
        printf("\nO primeiro elemento e: %.1f", lst->valor);
}
void main()
{
    pfila a = CriaFila();
    int opcao;
    float x;

    do {
        printf("\n\n\n1.Verificar se a fila e vazia.");
        printf("\n2.Mostrar o primeiro elemento da fila.");
        printf("\n3.Acrescentar um valor na fila.");
        printf("\n4.Remover elemento da fila.");
        printf("\n0.Sair do menu");
        printf("\nEscolha a sua opcao:");
        scanf("%d", &opcao);
        fflush(stdin);

        switch (opcao) {
            case 1:
                if(FilaVazia(a)=='y')
                    printf("\nA fila esta vazia.");
                else
                    printf("\nA fila nao esta vazia.");
                break;
            case 3:
                printf("\nInsira o valor que deseja inserir na fila: ");
                scanf("%f", &x);
                AcrescentaFila(x, &a);
                break;
            case 2:
                MostraInicio(a);
                break;
            case 4:
                RemoveFila(&a);
                break;
            case 0:
                break;
        }
    }
    while (opcao != 0);
}