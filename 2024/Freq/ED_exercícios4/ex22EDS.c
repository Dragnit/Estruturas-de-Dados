
#include <stdio.h>
struct retangulo{
    int xmin;
    int xmax;
    int ymin;
    int ymax;
};

typedef struct retangulo ret;

int area(ret a)
{
    int areaa;
    int x, y;
    x = (a.xmax - a.xmin);
    y = (a.ymax - a.ymin);
    areaa = x * y;
    return areaa;
}
void esta_dentro(ret a, ret b)
{
  {
    if (b.xmin >= a.xmin && b.xmin <= a.xmax && b.ymin >= a.ymin && b.ymin <= a.ymax)
      printf("\nO ponto pertence!");
    else
      printf("\nO ponto nao pertence!");
  }
}

void main()
{
    ret a, ponto;
    printf("Insira o x minimo: ");
    scanf("%d", &a.xmin);
    printf("\nInsira o x maximo: ");
    scanf("%d", &a.xmax);
    printf("\nInsira o y minimo: ");
    scanf("%d", &a.ymin);
    printf("\nInsira o y maximo: ");
    scanf("%d", &a.ymax);
    int valorarea = area(a);
    printf("\nA area do retangulo e: %d", valorarea);
    printf("\nInsira o x do ponto: ");
    scanf("%d", &ponto.xmin);
    printf("\nInsira o y do ponto: ");
    scanf("%d", &ponto.ymin);
    esta_dentro(a, ponto);
}
