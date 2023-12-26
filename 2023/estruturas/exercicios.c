#include<stdio.h>
#include<string.h>

typedef struct coordenadas_ponto { 
  float x, y; 
}coordenadas; 

typedef struct retangulo_medidas { 
  float  xmin, xmax, ymin, ymax;
}retangulo; 

void areaRetangulo()
{
    float c, l, area;
    retangulo r;

    puts("insira o xmax, o xmin, o y max e o ymin do retangulo");
    scanf("%f %f %f %f", &r.xmax, &r.xmin, &r.ymax, &r.ymin);

    c = r.xmax - r.xmin;
    l = r.ymax - r.ymin;

    area = c * l;

    printf("a area do retangulo = %.1f", area);
}
 
// subprograma escreve_ponto 
// escreve um ponto com as coordenadas x e y na forma (x,y) 
/*...*/ 
 
// subprograma funcao 
void funcao(coordenadas a, coordenadas b) 
{ 
  char h[15], v[15]; 
   
  if(a.x < b.x) 
   strcpy(h,"esquerda"); 
  else strcpy(h,"direita"); 
   
  if(a.y < b.y) 
   strcpy(v,"baixo"); 
  else strcpy(v,"cima"); 
   
  printf("O primeiro ponto esta a %s e em %s do segundo ponto!\n",h,v); 
} 

void escrevePonto(coordenadas p1)
{
    printf("p(%.1f, %.1f)\n", p1.x, p1.y);
}
 
int main() 
{ 
  // declarar pontos p1 e p2; 
  coordenadas p1, p2;
   
  // pedir ao utilizador e ler as coordenadas dos pontos p1 e p2 
  puts("insira as coordenadas dos pontos p1 e p2");
  scanf("%f %f %f %f", &p1.x, &p1.y, &p2.x, &p2.y);
   
  // chamar o subprograma escreve_ponto para mostrar os pontos lidos  
  escrevePonto(p1);
  escrevePonto(p2);
   
  // chamar o subprograma funcao aplicado aos pontos p1 e p2 
  funcao(p1, p2);

  // chamar a o subprograma retangulo

  areaRetangulo();
   
  return 0; 
}