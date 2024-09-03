#include <stdio.h>
#include <string.h>

struct coordenadas_ponto {
  float x;
  float y;
};

typedef struct coordenadas_ponto ponto;


struct retangulo {
  float xmin;
  float xmax;
  float ymin;
  float ymax;
};

typedef struct retangulo pontos;

void escreve_ponto(ponto a, ponto b) {
  printf("Primeiro ponto: p1 = (%d,%d)\n", a);
  printf("Segundo ponto: p2 = (%d,%d)", b);
}

void funcao(ponto a, ponto b) {
  char h[15], v[15];

  if(a.x < b.x)
  strcpy(h,"esquerda");
  else
  strcpy(h,"direita");
  if(a.y < b.y)
  strcpy(v,"baixo");
  else
  strcpy(v,"cima");
  printf("O primeiro ponto esta a %s e em %s do segundo ponto!\n",h,v);
}

/*O subprograma função tem como objetivo mostrar a localizaçao do primeiro ponto (com as coordenadas que o utilizador inseriu)
em relaçao a localizaçao do segundo ponto.
Para isso faz uma comparação entre a coordenada x do primeiro ponto e do segundo ponto. Se a coordenada x do primeiro ponto for
menor do que a coordenada x do segundo ponto significa que o primeiro ponto está à esquerda do segundo ponto, caso contrário, está
à direita.
Depois faz uma comparação entre a coordenada y do primeiro ponto e do segundo ponto. Se a coordenada y do primeiro ponto for menor do a
coordenada y do segundo ponto significa que o primeiro ponto está em baixo do segundo ponto, senão, está em cima.  */

void area(pontos amin, pontos amax, pontos bmin, pontos bmax) {
  float area;

  area = (bmax.ymax - bmin.ymin) * (amax.xmax - amin.xmin) ;

  printf("\nA area e: %.2f",area);
}

void esta_dentro(pontos amin, pontos amax, pontos bmin, pontos bmax, ponto c) {
  float altura, base;

  altura = (amax.xmax - amin.xmin);

  base = (bmax.ymax - bmin.ymin);

  if (c.x > altura)
    printf("\nO ponto situa-se fora do retangulo");
  else
    if (c.y > base)
      printf("\nO ponto situa-se fora do retangulo");
    else
      printf("\nO ponto situa-se dentro do retangulo");
}

int main()
{
  ponto p1,p2,p3;
  pontos amax,amin,bmax,bmin;

  printf("Criacao de dois pontos\n");
  printf("Coordenadas do ponto 1 (p1): ");
  scanf("%d,%d",&p1.x,&p1.y);
  printf("Coordenadas do ponto 2 (p2): ");
  scanf("%d,%d",&p2.x,&p2.y);
  printf("\n");

  escreve_ponto(p1,p2);// chamar o subprograma escreve_ponto para mostrar os pontos lidos

  printf("\n");

  funcao(p1,p2);// chamar o subprograma funcao aplicado aos pontos p1 e p2

  printf("\n");

  printf("Criacao de um retangulo\n");
  printf("Altura minima: ");
  scanf("%f",&amin.xmin);
  printf("\nAltura maxima: ");
  scanf("%f",&amax.xmax);
  printf("\nBase minima: ");
  scanf("%f",&bmin.ymin);
  printf("\nBase maxima: ");
  scanf("%f",&bmax.ymax);

  printf("\nCriacao de um ponto\n");
  printf("Coordenadas do ponto (p3): ");
  scanf("%f,%f",&p3.x,&p3.y);

  area(amin,amax,bmin,bmax);

  esta_dentro(amin,amax,bmin,bmax,p3);

  return 0;
}
