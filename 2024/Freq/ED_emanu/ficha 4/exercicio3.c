#include <stdio.h>
#include <math.h>

typedef struct estrutura_frac{
  int numerador;
  int denominador;
}fracao;

fracao le_fracao(){
  fracao frac;
  printf("Introduza uma fracao:\n");
  scanf("%d/%d",&frac.numerador,&frac.denominador);

  if(frac.denominador==0){
    printf("Denominador invalido!\nInsira novamente a fracao:\n");
    scanf("%d/%d",&frac.numerador,&frac.denominador);
  }
  return frac;
}

void escreve_fracao(fracao frac){
  printf("Fracao:%d/%d\n",frac.numerador,frac.denominador);
}

fracao soma_fracao(fracao frac1,fracao frac2){
  int auxDenominador,auxNumerador,maximoDivComum;
  fracao resultado;

  auxNumerador=(frac1.numerador*frac2.denominador)+(frac2.numerador*frac1.denominador);
  auxDenominador=frac1.denominador*frac2.denominador;

  for(int i=1;i<=auxNumerador && i<=auxDenominador;i++){
    if(auxNumerador%i==0 && auxDenominador%i==0){
      maximoDivComum=i;
    }
  }
  resultado.numerador=auxNumerador/maximoDivComum;
  resultado.denominador=auxDenominador/maximoDivComum;

  return resultado;
}

fracao sub_fracao(fracao frac1,fracao frac2){
  int auxDenominador,auxNumerador,maximoDivComum;
  fracao resultado;
  auxNumerador=(frac1.numerador*frac2.denominador)-(frac2.numerador*frac1.denominador);
  auxDenominador=frac1.denominador*frac2.denominador;

  for(int i=1;i<=auxNumerador && i<=auxDenominador;i++){
    if(auxNumerador%i==0 && auxDenominador%i==0){
      maximoDivComum=i;
    }
  }
  resultado.numerador=auxNumerador/maximoDivComum;
  resultado.denominador=auxDenominador/maximoDivComum;

  return resultado;
}
fracao mult_fracao(fracao frac1,fracao frac2){
  int auxDenominador,auxNumerador,maximoDivComum;
  fracao resultado;

  auxNumerador=(frac1.numerador*frac2.numerador);
  auxDenominador=(frac1.denominador*frac2.denominador);

  for(int i=1;i<=auxNumerador && i<=auxDenominador;i++){
    if(auxNumerador%i==0 && auxDenominador%i==0){
      maximoDivComum=i;
    }
  }

  resultado.numerador=auxNumerador/maximoDivComum;
  resultado.denominador=auxDenominador/maximoDivComum;

  return resultado;
}

fracao div_fracao(fracao frac1,fracao frac2){
  int auxDenominador,auxNumerador,maximoDivComum;
  fracao resultado;

  auxNumerador=(frac1.numerador*frac2.denominador);
  auxDenominador=(frac1.denominador*frac2.numerador);

  for(int i=1;i<=auxNumerador && i<=auxDenominador;i++){
    if(auxNumerador%i==0 && auxDenominador%i==0){
      maximoDivComum=i;
    }
  }

  resultado.numerador=auxNumerador/maximoDivComum;
  resultado.denominador=auxDenominador/maximoDivComum;

  return resultado;
}

fracao potencia_fracao(fracao frac1,int expoente){
  int auxDenominador,auxNumerador,maximoDivComum;
  fracao resultado;

  auxNumerador=pow(frac1.numerador,expoente);
  auxDenominador=pow(frac1.denominador,expoente);

  for(int i=1;i<=auxNumerador && i<=auxDenominador;i++){
    if(auxNumerador%i==0 && auxDenominador%i==0){
      maximoDivComum=i;
    }
  }

  resultado.numerador=auxNumerador/maximoDivComum;
  resultado.denominador=auxDenominador/maximoDivComum;

  return resultado;
}

int main()
{
fracao frac1,frac2,resultado;
int expoente;

frac1=le_fracao();
frac2=le_fracao();

resultado=soma_fracao(frac1,frac2);
escreve_fracao(soma_fracao(frac1,frac2));
resultado=sub_fracao(frac1,frac2);
escreve_fracao(resultado);
resultado=mult_fracao(frac1,frac2);
escreve_fracao(resultado);
resultado=div_fracao(frac1,frac2);
escreve_fracao(resultado);

printf("Insira o expoente da fracao:\n");
scanf("%d",&expoente);

if(expoente<0){
  printf("Expoente invalido!Insira um expoente positivo:\n");
  scanf("%d",&expoente);
}

resultado=potencia_fracao(frac1,expoente);
escreve_fracao(resultado);
	return 0;
}