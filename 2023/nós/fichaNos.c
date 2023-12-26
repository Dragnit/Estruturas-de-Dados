#include <stdio.h>
#include <stdlib.h>

typedef struct lno * plista;
typedef struct lno
{
    float valor; // campo valoré um real
    plista prox; // campo proxé um ponteiro para um nó da lista
} listano;

plista crialista()
{
    plista p = NULL;
    return p;
}

int listavazia(plista lst)
{
    if (lst == NULL)
    {
        puts("vazio");
        return 1;
    }
    else
    {
        puts("tem algo");
        return 0;
    }

}

void escrevelista(plista lst)
{
    if(listavazia(lst))
        printf("a lista e vazia!!!\n");
    else
    {
            printf("[");
        do
        {
            printf(" %.1f,",lst->valor);
            lst = lst->prox;
        }
        while(lst != NULL);
            printf("\b ]\n");
    }
}

void mostrarPrimeiroItem(plista lst)
{
    if (lst != NULL) 
    {
        printf("Primeiro item: %.2f\n", lst->valor);
    } 
    else 
    {
        printf("A lista esta vazia.\n");
    }
}

void mostrarUltimoItem(plista lst) 
{
    if (lst == NULL) 
    {
        printf("A lista esta vazia.\n");
        return;
    }

    // Percorre a lista até o último nó
    while (lst->prox != NULL) 
    {
        lst = lst->prox;
    }

    printf("Ultimo item: %.2f\n", lst->valor);
}

plista acrescentarNoInicio(plista lst, float valor) 
{
    // Cria um novo nó
    plista novoNo = (plista) malloc(sizeof(listano));
    novoNo->valor = valor;
    
    // Define o próximo nó como o nó atual do início da lista
    novoNo->prox = lst;
    
    // Atualiza o início da lista para o novo nó
    lst = novoNo;
    
    // Retorna a lista atualizada
    return lst;
}

plista acrescentarNoFim(plista lst, float valor) {
    // Cria um novo nó
    plista novoNo = (plista) malloc(sizeof(listano));
    novoNo->valor = valor;
    novoNo->prox = NULL; // O novo nó será o último, portanto o próximo é NULL
    
    // Verifica se a lista está vazia
    if (lst == NULL) {
        // Se a lista estiver vazia, o novo nó se torna o primeiro nó
        lst = novoNo;
    } else {
        // Caso contrário, percorre a lista até o último nó
        plista atual = lst;
        while (atual->prox != NULL) {
            atual = atual->prox;
        }
        // Atualiza o ponteiro do último nó para o novo nó
        atual->prox = novoNo;
    }
    
    // Retorna a lista atualizada
    return lst;
}

void mostrarListaExcetoPrimeiro(plista lst) 
{
    if (lst == NULL) 
    {
        printf("Lista vazia.\n");
    } 
    else 
    {
        printf("Elementos da lista (exceto o primeiro): ");
        plista atual = lst->prox;  // Pula o primeiro nó
        while (atual != NULL) {
            printf("%.2f ", atual->valor);
            atual = atual->prox;
        }
        printf("\n");
    }
}

int contarElementosLista(plista lst) 
{
    int contador = 0;
    plista atual = lst;

    while (atual != NULL) 
    {
        contador++;
        atual = atual->prox;
    }

    return contador;
}

int main()
{
    plista plst = crialista();
    int proximo = 0;
    int ult = 0;
    
    // coloca valor 12.3 no início da lista
    plista no = (plista)malloc(sizeof(listano));
    no->valor = 12.3;
    no->prox = plst;
    plst = no;
    
    puts("insira o primeiro elemento e o ultimo");
    scanf("%d %d", &proximo, &ult);
    plst = acrescentarNoInicio(plst, proximo);
    plst = acrescentarNoFim(plst, ult);
    listavazia (plst);
    escrevelista(plst);
    mostrarPrimeiroItem(plst);
    mostrarUltimoItem(plst);
    mostrarListaExcetoPrimeiro(plst);
    int total = contarElementosLista(plst);
    printf("Numero total de elementos: %d", total);
    
    return 0;
}
sdfghooiugfdw