
#include <stdio.h>
#include <stdlib.h>
typedef struct lno * plista;
typedef struct lno
{
    float valor;
    struct lno *prox;
}listano;

//alínea a
plista CriaLista()
{
    plista p = NULL;
    return p;
}
//alínea b
char ListaVazia(plista lst)
{
    if (lst == NULL)
        return 'y';
    else
        return 'n';
}
//alínea c
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
//alínea d
void JuntaInicio(float x, plista * lst)
{
    plista no = (plista)malloc(sizeof(listano));
    if(no == NULL)
        printf("\nErro, nao ha memoria disponivel");
    else
    {
        no->valor = x;
        no->prox = *lst;
        *lst = no;
    }
}
//alínea e
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

//alínea f
void RemovePrimeiro(plista * lst)
{
    plista paux = *lst;
    *lst = (*lst)->prox;
    free(paux);
}
//alínea g
void RemoveUltimo(plista * lst)
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
//alínea h
void RemoveNelemento(plista * lst, int n)
{
    plista paux = *lst;
    plista aux = NULL;
    int count = 1;
    while(paux->prox != NULL && count != n )
    {
        count++;
        aux = paux;
        paux = paux->prox;
    }
    if(count<n)
        printf("\nA lista tem apenas %d elemento(s)", count);
    if(aux!=NULL)
        aux->prox = paux->prox;
    else
        *lst = (*lst)->prox;
    free(paux);
}
//alínea i
void RemovePrimeiraOcorrencia(plista * lst, float v)
{
    plista paux = *lst;
    plista aux = NULL;
    while(paux->valor != v && paux->prox != NULL)
    {
        aux = paux;
        paux = paux->prox;
    }
    if(paux->valor == v)
    {
        if(aux!=NULL)               //caso tenha mais que um valor
            aux->prox = paux->prox;
        else
            *lst = (*lst)->prox;    //caso tenha apenas um valor
        free(paux);
    }
}
//alínea k
int ComprimentoLista(plista lst)
{
    int count = 0;
    while(lst != NULL)
    {
        count++;
        lst = lst->prox;
    }
    return count;
}
//alínea j
void RemoveTodasOcorrencias(plista * lst, float v)
{
    plista paux = *lst;
    int count = 51238;
    int size = 0;
    while(paux!=NULL && count != size) //a partir do momento em que count = size, não há mais nada a remover porque a função
                                       // RemovePrimeiraOcorrencia não removeu nada, logo, o count = size.
    {
      count = ComprimentoLista(*lst);  //count passa a ser o comprimento da lista
      RemovePrimeiraOcorrencia(lst, v); //funcao para remover a ocorrencia do valor
      size = ComprimentoLista(*lst);    // size passa a ser o novo comprimento (total-1)
      paux = *lst;                      //paux passa a ser o proximo elemeto e tudo se repete
    }
}
//alínea l
float ProcuraValor(plista lst, float x)
{
    printf("\nInsira o valor que deseja procurar: ");
    scanf("%f", &x);
    while(lst!=NULL && lst->valor != x)
    {
        lst = lst->prox;
    }
    if(lst == NULL)
        return 0;
    else
    return lst->valor;
}
//alínea m
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
//alínea n
void LimpaLista(plista * lst)
{
    while(*lst!=NULL)
        RemoveUltimo(lst);
}
//alínea o
float MostraPrimeiro(plista lst)
{
    if(ListaVazia(lst)=='y')
        printf("\nLista esta vazia.");
    return lst->valor;
}
//alínea p
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
//alínea q
void MostraCauda(plista lst)
{
    if(ListaVazia(lst)=='y')
        printf("\nLista esta vazia.");
    else
    {
        lst = lst->prox;
        while(lst!=NULL)
        {
            printf("%0.1f, ", lst->valor);
            lst = lst->prox;
          
        }
        
    }
}
//alínea r
void ConcatenaListas(plista * lst1, plista * lst2) {

    plista aux = *lst1;
    if (*lst1 == NULL)
    {
        *lst1 = *lst2;
    } else
        {
        while (aux->prox != NULL){
            aux = aux->prox;
        }
            aux->prox = *lst2;
        }
}
//alínea s
void CopiaLista(plista * lst1, plista * lst2)
{
    plista paux = *lst1;
        while (paux != NULL) {
            JuntaFim(paux->valor, &(*lst2));
            paux = paux->prox;
    }
}
//alínea t
void TrocaElementos(plista * lst, float x, float y)
{
    plista paux = *lst;
    plista aux = *lst;
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
//alínea u
void OrdenaCrescente(plista * lst)
{
    plista paux = NULL;
    float auxiliar;
    int flag = 0;
    while(flag == 0)
    {
        flag = -1;
        paux = *lst;
        while(paux->prox != NULL)
        {
            if (paux->valor > (paux->prox)->valor)
            {
                auxiliar = (paux->prox)->valor;
                (paux->prox)->valor = paux->valor;
                paux->valor = auxiliar;
                flag = 0;
            }
            paux = paux->prox;
        }
    }
}
//alínea v
void OrdenaDecrescente(plista * lst)
{
    plista paux = NULL;
    float auxiliar;
    int flag = 0;
    while(flag == 0)
    {
        flag = -1;
        paux = *lst;
        while(paux->prox != NULL)
        {
            if (paux->valor < (paux->prox)->valor)
            {
                auxiliar = (paux->prox)->valor;
                (paux->prox)->valor = paux->valor;
                paux->valor = auxiliar;
                flag = 0;
            }
            paux = paux->prox;
        }
    }
}
void main() {
    float x, v, procura;
    int n, opcao;
    char verifica;
    plista a = CriaLista();
    plista b = CriaLista();
    int comp = ComprimentoLista(a);
    do {
        printf("\n\n\n1.Verificar se a lista e vazia.");
        printf("\n2.Mostrar a lista.");
        printf("\n3.Acrescentar um valor x no inicio da lista.");
        printf("\n4.Acrescentar um valor x no fim da lista.");
        printf("\n5.Remover o primeiro elemento da lista.");
        printf("\n6.Remover o ultimo elemento da lista.");
        printf("\n7.Remover o n-esimo elemento da lista.");
        printf("\n8.Remover a primeira ocorrencia de x valor.");
        printf("\n9.Remover x valor da lista.");
        printf("\n10.Ver o comprimento da lista.");
        printf("\n11.Procurar certo valor na lista.");
        printf("\n12.Criar lista.");
        printf("\n13.Limpar lista.");
        printf("\n14.Apresentar o primeiro elemento da lista.");
        printf("\n15.Apresentar o ultimo elemento da lista.");
        printf("\n16.Apresentar a cauda da lista.");
        printf("\n17.Juntar duas listas numa so.");
        printf("\n18.Copiar de uma lista para a outra.");
        printf("\n19.Trocar dois elementos de uma lista.");
        printf("\n20.Colocar a lista por ordem crescente.");
        printf("\n21.Colocar a lista por ordem decrescente.");
        printf("\n0.Sair do menu");
        printf("\nEscolha a sua opcao:");
        scanf("%d", &opcao);
        fflush(stdin);

        switch (opcao) {
            case 1:
                verifica = ListaVazia(a);
                if (verifica == 'y')
                    printf("\nA lista esta vazia.");
                else printf("\nA lista nao esta vazia.");
                break;
            case 2:
                MostraLista(a);
                break;
            case 3:
                printf("\nInsira o valor que deseja inserir: ");
                scanf("%f", &x);
                JuntaInicio(x, &a);
                break;
            case 4:
                printf("\nInsira o valor que deseja inserir no fim: ");
                scanf("%f", &x);
                JuntaFim(x, &a);
                break;
            case 5:
                RemovePrimeiro(&a);
                break;
            case 6:
                RemoveUltimo(&a);
                break;
            case 7:
                printf("\nIndique a posicao que deseja remover: ");
                scanf("%d", &n);
                while (n <= 0)
                {
                    printf("\nValor invalido, por favor insira de novo: ");
                    scanf("%d", &n);
                }
                RemoveNelemento(&a, n);
                break;
            case 8:
                printf("\nIndique o valor que deseja remover: ");
                scanf("%f", &v);
                RemovePrimeiraOcorrencia(&a, v);
                break;
            case 9:
                printf("\nIndique o valor que deseja remover da lista: ");
                scanf("%f", &v);
                RemoveTodasOcorrencias(&a, v);
                break;
            case 10:
                printf("\nA lista tem %d elemento(s).", comp);
                break;
            case 11:
                procura = ProcuraValor(a, x);
                if(procura != 0)
                    printf("\nValor %.1f encontrado.", procura);
                else
                    printf("\nO valor nao foi encontrado.");
                break;
            case 12:
                printf("\nInsira o numero de elementos da lista: ");
                scanf("%d", &n);
                MontaLista(&a, n);
                break;
            case 13:
                LimpaLista(&a);
                ListaVazia(a);
                break;
            case 14:
               x = MostraPrimeiro(a);
               printf("\nO primeiro elemento da lista e %.1f", x);
                break;
            case 15:
                x = MostraUltimo(a);
                printf("\nO ultimo elemento da lista e %.1f", x);
                break;
            case 16:
                MostraCauda(a);
                break;
            case 17:
                printf("\nInsira o numero de elementos da segunda lista: ");
                scanf("%d", &n);
                MontaLista(&b, n);
                ConcatenaListas(&a, &b);
                MostraLista(a);
                break;
            case 18:
                b = NULL;
                CopiaLista(&a, &b);
                MostraLista(b);
                MostraLista(a);
                break;
            case 19:
                TrocaElementos(&a, x, v);
                MostraLista(a);
                MostraLista(b);
                break;
            case 20:
                OrdenaCrescente(&a);
                MostraLista(a);
                break;
            case 21:
                OrdenaDecrescente(&a);
                MostraLista(a);
                break;
            case 0:
                printf("\nSaiu do menu.");
                break;
            default:
                printf("\nOpcao invalida.");
                break;
        }
    }
        while (opcao != 0);
}