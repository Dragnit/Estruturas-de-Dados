

#include <stdio.h>

struct coordenadas_ponto{
    float x;
    float y;
};
typedef struct coordenadas_ponto ponto;
void funcao(ponto a, ponto b)
{
    char h[100], v[100];
    if(a.x < b.x)
        strcpy(h,"esquerda");
    else
        strcpy(h,"direita/sobre");
    if(a.y < b.y)
        strcpy(v,"baixo");
    else
        strcpy(v,"cima/sobre");
    printf("\nO primeiro ponto esta a %s e em %s do segundo ponto!\n",h,v);
}
void escreve_ponto(ponto a, ponto b)
{
    printf("Ponto a: (%.1f; %.1f)", a.x, a.y);
    printf("\nPonto b: (%.1f; %.1f)", b.x, b.y);
}
void main()
{
    ponto a, b;
    printf("\nInsira as coordenadas do ponto a: ");
    scanf("%f", &a.x);
    scanf("%f", &a.y);
    printf("\nInsira agora as coordenadas do ponto b: ");
    scanf("%f", &b.x);
    scanf("%f", &b.y);
    escreve_ponto(a,b);
    funcao(a,b);
}