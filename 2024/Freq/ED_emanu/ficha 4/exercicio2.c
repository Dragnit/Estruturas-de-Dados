#include<stdio.h>
#include<string.h>

  typedef struct coordenadas_ponto
{
  float x;
  float y;
}ponto;

  typedef struct rectangle
{
  int xmin;
  int xmax;
  int ymin;
  int ymax;
}retangulo;


  void escrever_ponto(ponto a)
{
  printf("O ponto e: (%0.1f,%0.1f)\n",a.x,a.y);
}

  void funcao(ponto a,ponto b)
{
  char h[15],v[15];
  if(a.x<b.x)
    strcpy(h,"esquerda");
  else strcpy(h,"direita");

  if(a.y<b.y)
    strcpy(v,"baixo");
  else strcpy(v,"cima");

  printf("O primeiro ponto esta a %s e em %s de segundo ponto!\n",h,v);
}
  void area(retangulo r)
{
  int i,j,Area;
  i=r.xmax-r.xmin;
  j=r.ymax-r.ymin;
  Area=i*j;
  printf("Area:%d\n",Area);
}

  void esta_dentro(ponto k,retangulo r)
{
  if(k.x>=r.xmin && k.x<=r.xmax && k.y>=r.ymin && k.y<=r.ymax)
    printf("O ponto esta dentro do retangulo.");
  else
    printf("O ponto esta fora do retangulo.");
}
  int main()
{
  ponto p1,p2,k;
  printf("Indique as coordenadas de p1: \n");
  scanf("%f%f",&p1.x,&p1.y);
  printf("Indique as coordenadas de p2: \n");
  scanf("%f%f",&p2.x,&p2.y);

  escrever_ponto(p1);
  escrever_ponto(p2);
  funcao(p1,p2);

  retangulo r;
  printf("\nEscreva os valores do retangulo R: \n");
  scanf("%d%d%d%d",&r.xmin,&r.xmax,&r.ymin,&r.ymax);
  area(r);
  printf("Indique as coordenadas de k: \n");
  scanf("%f%f",&k.x,&k.y);
  esta_dentro(k,r);

  return 0;
}
