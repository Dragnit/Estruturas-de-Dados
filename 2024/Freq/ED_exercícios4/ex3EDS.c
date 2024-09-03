#include <stdio.h>
#include <math.h>
struct fracao
        {
    float numerador;
    float denominador;
};

typedef struct fracao frac;

frac le_fracao()
{
    frac a;
    printf("Insira o numerador: ");
    scanf("%d", &a.numerador);
    printf("\nInsira agora o denominador: ");
    scanf("%d", &a.denominador);
    while(a.denominador == 0)
    {
        printf("\nO denominador nao pode ter 0. Insira novamente: ");
        scanf("%d", &a.denominador);
    }
    return a;
}

void soma_fracao(frac a, frac b)
{
    float soma, fraca, fracb;
    fraca = a.numerador / a.denominador;
    fracb = b.numerador / b.denominador;
    soma = fraca + fracb;
    printf("\nA soma das fracoes e: %.3f", soma);
}
void subtrai_fracao(frac a, frac b)
{
    float subtracao, fraca, fracb;
    fraca = a.numerador / a.denominador;
    fracb = b.numerador / b.denominador;
    subtracao = fraca - fracb;
    printf("\nA subtracao das fracoes e: %.3f", subtracao);
}
void multiplica_fracao(frac a, frac b)
{
    float multiplicacao, fraca, fracb;
    fraca = a.numerador / a.denominador;
    fracb = b.numerador / b.denominador;
    multiplicacao = fraca * fracb;
    printf("\nO produto das fracoes e: %.3f", multiplicacao);
}
void divide_fracao(frac a, frac b)
{
    float divisao, fraca, fracb;
    fraca = a.numerador / a.denominador;
    fracb = b.numerador / b.denominador;
    if(fracb==0)
        printf("\nNao e possivel dividir nenhum valor por 0.");
    divisao = fraca / fracb;
    printf("\nO resultado da divisao das fracoes e: %.3f", divisao);
}
void expoente_fracao(frac a, frac b)
{
    double expoentea, expoenteb, fraca, fracb; 
    int expoente;
    printf("\nInsira o expoente ao qual quer elevar as fracoes: ");
    scanf("%d", &expoente);
    fraca = a.numerador / a.denominador;
    fracb = b.numerador / b.denominador;
    expoentea = pow(fraca, expoente);
    expoenteb = pow(fracb, expoente);
    printf("\nO valor do expoente da fracao a e: %lf", expoentea);
    printf("\nO valor do expoente da fracao b e: %lf", expoenteb);
}
void main()
{
   frac a, b;
   a = le_fracao();
   b = le_fracao();
   soma_fracao(a,b);
   subtrai_fracao(a,b);
   multiplica_fracao(a,b);
   divide_fracao(a,b);
   expoente_fracao(a,b);
}









































































































































































