#include <stdio.h>
#include <stdlib.h>
typedef struct lno * plista;
typedef struct lno
{
    float valor;
    struct lno *prox;
}listano;

plista CriaLista()
{
    plista p = NULL;
    return p;
}

char ListaVazia(plista lst)
{
    if (lst == NULL)
        return 'y';
    else
        return 'n';
}

void MostraLista(plista lst) {
    if (ListaVazia(lst)=='y')
        printf("\nA lista esta vazia.");
    else
    {
        printf("\n");
    printf("[");
    do {
        printf("%.1f, ", lst->valor);
        lst = lst->prox;
    } while (lst != NULL);
    printf("\b ]\n");
  }
}

void JuntaFim(float x, plista * lst)
{
    plista no = (plista) malloc(sizeof(listano));
    plista paux = *lst;
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

void MontaLista(plista * lst, int max)
{
        float valor;
        for(int i=1;i<=max;i++)
        {
            printf("\nInsira o valor que deseja inserir na posicao %d da lista: ", i);
        scanf("%f", &valor);
        JuntaFim(valor, lst);
    }
}

// Versão Recursiva
void RemoveUltimo_Ite(plista * lst)
{
    plista paux = *lst;
    plista aux = NULL;
    while(paux->prox!=NULL)
    {
        aux = paux;
        paux = paux->prox;
    }
    free(paux);
    if(aux!=NULL)
        aux->prox = NULL;
    else
        *lst = NULL;
}

// Versão Iterativa
void LimpaLista_Rec(plista * lst)
{
  plista paux = *lst;
  while(*lst != NULL)
  {
   *lst = (*lst)->prox;
   free(paux);
   LimpaLista_Rec(lst);
  }
}

void LimpaLista_Ite(plista * lst)
{
    while(*lst!=NULL)
        RemoveUltimo_Ite(lst);
}
int main()
{
 float x;
 int n;
 char verifica;
 plista a = CriaLista();
 
 verifica = ListaVazia(a);
 if (verifica == 'y')
   printf("\nA lista esta vazia.");
 else 
   printf("\nA lista nao esta vazia.");
 // Versão recursiva            
 printf("\nInsira o numero de elementos da lista: ");
 scanf("%d", &n);
 MontaLista(&a, n);
 MostraLista(a);
 LimpaLista_Rec(&a);
 MostraLista(a);
 
// Versão Iterativa
 printf("\nInsira o numero de elementos da lista: ");
 scanf("%d", &n);
 MontaLista(&a, n);
 MostraLista(a);
 LimpaLista_Ite(&a);
 MostraLista(a);
}