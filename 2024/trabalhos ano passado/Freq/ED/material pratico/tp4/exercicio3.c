#include <stdio.h>
#include <math.h>

struct numerador_denominador {
  int num;
  int den;
};

typedef struct numerador_denominador fracao;

fracao somar(fracao a, fracao b)
{
  fracao som;
  ((som.num = (a.num * b.den) + (b.num * a.den))&&(som.den = a.den * b.den));
  printf("SOMA: %d/%d\n",som.num,som.den);
}

fracao subtrair(fracao a, fracao b)
{
  fracao sub;
  ((sub.num = (a.num * b.den) - (b.num * a.den)) && (sub.den = a.den * b.den));
  printf("SUBTRACAO: %d/%d\n",sub.num,sub.den);
}

fracao multiplicacao(fracao a, fracao b)
{
  fracao mult;
  ((mult.num = (a.num * b.num)) && (mult.den = (a.den * b.den)));
  printf("MULTIPLICACAO: %d/%d\n",mult.num,mult.den);

}

fracao dividir(fracao a, fracao b)
{
  fracao div;
  ((div.num = (a.num * b.den)) && (div.den = (a.den * b.num)));
  printf("DIVISAO: %d/%d\n",div.num,div.den);
}

fracao expoente(fracao a)
{
  int exp,na,da,n,d;


  printf("Qual o expoente da primeira fracao:");
  scanf("%d",&exp);

  na=a.num;
  da=a.den;

  n= pow(na,exp);
  d=pow(da,exp);

  printf("(%d/%d)^%d=%d/%d",a.num,a.den,exp,n,d);

}


int main()
{
  fracao f1,f2;
  printf("Primeira fracao(num/den): ");
  scanf("%d/%d",&f1.num,&f1.den);
  printf("Segunda fracao(num/den): ");
  scanf("%d/%d",&f2.num,&f2.den);

  somar(f1,f2);
  subtrair(f1,f2);
  multiplicacao(f1,f2);
  dividir(f1,f2);
  expoente(f1);


  return 0 ;
}
