#include<stdio.h>
#include<string.h>
 /*--------------------------------------------------------------
 --------------------------------------------------------------
 Proprietario: Jorge Miguel dos Santos Martins
 Curso: Licenciatura Sistemas Tecnologias de Informacao
 Disciplina: Programacao II / Estruturas Dados Data:
 Programa/Exercicio: Ficha 4 / Exercicio 2
 --------------------------------------------------------------
 --------------------------------------------------------------
 */
struct coordenadas_ponto{ // estrutura do ponto já dada
  float x;
  float y;
}; typedef struct coordenadas_ponto ponto;


struct coordenadas_rectangulo{ // estrutura do rectangulo
  int xmin;
  int xmax;
  int ymin;
  int ymax;
}; typedef struct coordenadas_rectangulo rectangulo;

ponto read(){
  ponto p;
  printf("\nInsira o coordenada x: "); scanf("%f", &p.x);
  printf("\nInsira o coordenada y: "); scanf("%f", &p.y);
  printf("Coordenadas inseridas com sucesso\n");
  return p;
}

void escreve_ponto(ponto p){
  printf(" (%.2f , %.2f)\n", p.x, p.y);
}

void funcao(ponto a, ponto b) { // problema é que se o ponto estiver um em cima do outro ele não indica essa info
   char h[15], v[15];
   if(a.x < b.x) // verifica no eixo onde se encontra os pontos, se o 1 for menor está na esquerda do segundo e vice versa
   strcpy(h,"esquerda");
      else strcpy(h,"direita");
   if(a.y < b.y)   strcpy(v,"baixo"); // aqui faz o mesmo que em cima mas como o y é o eixo que demonstra a aula então caso o primeiro ponto seja menor que o segundo significa
      else strcpy(v,"cima"); // que este se encontra abaixo do segundo.
   printf("O primeiro ponto esta a %s e em %s do segundo ponto!\n",h,v);
}

rectangulo readRectangulo(){ // funcao que o utilizador insere o xmin, xmax, ymin e ymax
    rectangulo r; //variavel local
    printf("\nInsira o xmin: "); scanf("%d", &r.xmin);
    printf("\nInsira o xmax: ");
    do{
      scanf("%d", &r.xmax);
      if(r.xmax < r.xmin)
        printf("\nMaximo tem de ser maior ou igual a minimo: "); // para que não haja maximos menores que minimos, podem ser iguais..
  }while(r.xmax < r.xmin);
    printf("\nInsira o ymin: "); scanf("%d", &r.ymin);
    printf("\nInsira o ymax: ");
    do{
      scanf("%d", &r.ymax);
      if(r.ymax < r.ymin)
        printf("\nMaximo tem de ser maior ou igual a minimo: "); // o mesmo que em cima..
    }while(r.ymax < r.ymin);
return r;
}

int areaRectangulo(rectangulo r){
    int base, altura, area;
    base=(r.xmax-r.xmin); //a base é o x maximo menos o x minimo para dar a distancia da recta
    altura=(r.ymax-r.ymin); // mesma logica usada na base..
    area=(base*altura);
return area;
}

void esta_dentro(rectangulo r, ponto p){
    if(p.x >= r.xmin && p.x <= r.xmax && p.y >= r.ymin && p.y <= r.ymax) // faço uma condição para verificar se esta fora dos seus limites..
      printf("O ponto encontra-se dentro da area do rectangulo\n");
    else
      printf("O ponto esta fora da area do rectangulo\n");
}

int main(){
  ponto p1, p2, p3;// declarar pontos p1 e p2; aqui declarei também p3 para depois ver se o ponto que o utilizador der esta dentro ou não..
  rectangulo rect; //declarada a variavel do tipo rectangulo que faz parte da estrutura desse tipo
  int area;
  p1 = read();
  p2 = read();// pedir ao utilizador e ler as coordenadas dos pontos p1 e p2  /*...*/
  printf("O ponto 1 tem coordenadas "); escreve_ponto(p1);// chamar o subprograma escreve_ponto para mostrar os pontos lidos   /*...*/
  printf("O ponto 2 tem coordenadas "); escreve_ponto(p2);
  funcao(p1, p2);// chamar o subprograma funcao aplicado aos pontos p1 e p2  /*...*/
  rect=readRectangulo();
  area=areaRectangulo(rect);
  printf("A area do rectangulo e %d ", area);
  printf("\nIndique o ponto a verificar se esta dentro do rectangulo anterior: ");
  p3 = read();
  esta_dentro(rect, p3);
return 0;
}
