#include <stdio.h>

int fibonacci_Recursivo(int n){
  if(n<=1){
    return n;
  }else{
    return fibonacci_Recursivo(n-1)+fibonacci_Recursivo(n-2);
  }
}

int fibonacci_Iterativo(int n){
  int auxNumero, numeroAnterior=0,numeroAtual=1;

  for(int i=1;i<n;i++){
    auxNumero=numeroAnterior;
    numeroAnterior=numeroAtual;
    numeroAtual=auxNumero+numeroAnterior;
  }
  return numeroAtual;
}

int main()
{
int n;

printf("Insira o elemento n que pretende calcular na serie de fibonacci:\n");
scanf("%d",&n);

while(n<=0){
  printf("O numero que inseriu e invalido!\nInsira novamente o numero:\n");
  scanf("%d",&n);
}

printf("Elemento %d na serie de Fibonacci(recursivo): %d\n",n,fibonacci_Recursivo(n));
printf("Elemento %d na serie de Fibonacci(iterativo): %d",n,fibonacci_Iterativo(n));
	return 0;
}