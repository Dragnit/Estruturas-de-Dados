
#include <stdio.h>
#include <stdlib.h>
//alínea a

typedef struct lno * plista;
typedef struct lno
{
    float valor;
    struct lno *prox;
}listano;

struct ponteiros
{
    plista head;
    plista tail;
};typedef struct ponteiros pt;


//alínea b

//alínea a ex2

plista CriaLista()
{
    plista p = NULL;
    return p;
}

//alínea b ex2

char ListaVazia(plista lst)
{
    if (lst == NULL)
        return 'y';
    else
        return 'n';
}

void MostraLista(plista lst){
    if(ListaVazia(lst)=='y')
        printf("Lista esta vazia.\n");
    else{
        printf("[");
        do{
            printf(" %.1f,",lst->valor);
            lst = lst->prox;
        }while(lst != NULL);
        printf("\b ]\n");
    }
}

//alínea e ex2

void JuntaFim(float x, plista * head, plista * tail)
{
    char c = ListaVazia(*head);
    plista no = (plista) malloc(sizeof(listano));
    if(no==NULL)
        printf("\nNao ha memoria disponivel!");

    if(c=='n') {

        no->valor = x;
        no->prox = NULL;

        (*tail)->prox = no;
        (*tail) = no;
    } else {
        no->valor = x;
        no->prox = NULL;

        *head = no;
        *tail = *head;
    }
}

//alínea g ex2

void RemoveUltimo(plista * tail, plista * head)
{
    char c = ListaVazia(*head);
    plista paux = NULL;
    plista aux = NULL;
    if(c=='n')
    {
        paux = *head;
        if(paux->prox == NULL)
        {
            *tail = NULL;
            *head = NULL;
        } else
            {
            while(paux->prox != NULL)
            {
                aux = paux;
                paux = paux->prox;
            }
            *tail = aux;
            (*tail)->prox = NULL;
            }
    } else printf("\nLista esta vazia!");
}

//alínea j ex2

void RemoveTodasOcorrencias(plista * tail, plista * head, float x)
{
    char c = ListaVazia(*head);
    plista paux, aux;
    if(c=='n')
    {        paux = *head;
        if(paux->valor == x)
        {
            paux = paux->prox;
            *head = paux;
        }
        else
        {
            while(paux->prox != NULL)
            {
                aux = paux;
                paux = paux->prox;
                if(paux->valor == x)
                {
                    if(paux->prox == NULL)
                    {
                        *tail = aux;
                        aux->prox = paux->prox;
                    } else{
                            aux->prox = paux->prox;
                    }
                }
            }
        }
    }
    else printf("\nO valor nao existe.");
}

//alínea n ex2

void LimpaLista(plista * lst)
{
    plista paux;
    if(ListaVazia(*lst) == 'y')
        printf("\nLista esta vazia.");

    while(*lst != NULL)
    {
        paux = *lst;
        *lst = (*lst)->prox;
        free(paux);
    }
}

//alínea p ex2

float MostraUltimo(plista lst)
{
    if(ListaVazia(lst)=='y')
        printf("\nLista esta vazia.");
    else {
        while (lst->prox != NULL)
            lst = lst->prox;
    }
    return lst->valor;
}

// alínea t ex 2

void TrocaListas(plista * head, float x, float y)
{
    plista paux = *head;
    plista aux = *head;
    printf("\nInsira o valor que quer trocar: ");
    scanf("%f", &x);
    printf("\nInsira o proximo valor a trocar: ");
    scanf("%f", &y);

    if(paux == NULL || aux == NULL)
        printf("\nUma das listas esta vazia!");
    else {
        while (paux != NULL && paux->valor != x)
            paux = paux->prox;

        while (aux != NULL && aux->valor != y)
            aux = aux->prox;

        paux->valor = y;
        aux->valor = x;
    }
}
void main()
{
    pt ptr;
    ptr.head = CriaLista();
    ptr.tail = CriaLista();
    plista lst = CriaLista();
    float x, y;
    int opcao;

    do {
        printf("\n\n\n1.Verificar se a lista e vazia.");
        printf("\n2.Mostrar a lista.");
        printf("\n3.Acrescentar um valor x no fim da lista.");
        printf("\n4.Remover o ultimo elemento da lista.");
        printf("\n5.Limpar uma lista.");
        printf("\n6.Mostrar o ultimo elemento de uma lista");
        printf("\n7.Trocar elementos de listas.");
        printf("\n8.Remover ocorrencias de x valor.");
        printf("\n0.Sair do menu");
        printf("\nEscolha a sua opcao:");
        scanf("%d", &opcao);
        fflush(stdin);

        switch (opcao) {
            case 1:
                if(ListaVazia(ptr.head)=='y')
                    printf("\nA lista esta vazia.");
                else
                    printf("\nA lista nao esta vazia.");
                break;
            case 3:
                printf("\nInsira o valor que deseja inserir no fim da lista: ");
                scanf("%f", &x);
                JuntaFim(x, &ptr.head, &ptr.tail);
                break;
            case 2:
                MostraLista(ptr.head);
                break;
            case 4:
                RemoveUltimo(&ptr.tail, &ptr.head);
                break;
            case 5:
                LimpaLista(&ptr.head);
                break;
            case 6:
                x = MostraUltimo(ptr.head);
                printf("\nO ultimo elemento e %.1f", x);
                break;
            case 7:
                TrocaListas(&ptr.head, x, y);
                break;
            case 8:
                printf("\nInsira o valor que deseja remover: ");
                scanf("%f", &x);
                RemoveTodasOcorrencias(&ptr.tail, &ptr.head, x);
                break;
        }
    }
    while (opcao != 0);
}

