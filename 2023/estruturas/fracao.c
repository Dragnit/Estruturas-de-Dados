#include<stdio.h>
#include<string.h>
#include<math.h>

typedef struct fracao_dados { 
  int d, n; 
}fracao;

fracao lerFracao()
{
    fracao f;

    puts("insira o numerador e o denominador: ");
    scanf("%d %d", &f.n, &f.d);

    while(f.d == 0)
    {
        puts("o denominador nao pode ser 0");
        scanf("%d", &f.d);
    }
    
    printf("a sua fracao e: %d/%d \n\n", f.n, f.d);

    return f;
}

void escrevefracao(fracao f)
{
    printf("%d/%d\n", f.n, f.d);
}

fracao somaFracao(fracao f1, fracao f2)
{
    fracao f;

    printf("a soma das duas fracoes e: %d/%d\n\n", f.n=(f1.n*f2.d + f2.n*f1.d), f.d=(f1.d*f2.d));

    return f;
}

fracao subtracaoFracao(fracao f1, fracao f2)
{
    fracao f;
    printf("a subtracao das duas fracoes e: %d/%d\n\n", f.n=(f1.n*f2.d - f2.n*f1.d), f.d=(f1.d*f2.d));
    return f;
}

fracao multiplicacaoFracao(fracao f1, fracao f2)
{
    fracao f;
    printf("a multiplicacao das duas fracoes e: %d/%d\n\n", f.n=(f1.n*f2.n), f.d=(f1.d*f2.d));
    return f;
}

fracao divisaoFracao(fracao f1, fracao f2)
{
    fracao f;
    printf("a divisao das duas fracoes e: %d/%d\n\n", f.n=(f1.n*f2.d), f.d=(f1.d*f2.n));
    return f;
}

float realFracao(fracao f)
{
    printf("o valor real da fracao : %.1f\n\n", 1.0*f.n/f.d);
    return 1.0*f.n/f.d;
}

float expoenteFracao(fracao f)
{
    pow(f.d, f.n);
}

int main()
{
    float a = 0;
    fracao f1, f2, f3, f4, f5, f6, f7;

    f1 = lerFracao();
    f2 = lerFracao();
    f3 = somaFracao(f1, f2);
    f4 = subtracaoFracao(f1, f2);
    f5 = multiplicacaoFracao(f1, f2);
    f6 = divisaoFracao(f1, f2);
    a = realFracao(f1);

    return 0;
}

