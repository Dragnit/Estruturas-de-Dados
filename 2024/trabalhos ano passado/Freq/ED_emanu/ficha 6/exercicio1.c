#include <stdio.h>

int fatorial_Recursivo(int n){
  if(n>=1){
    return n*fatorial_Recursivo(n-1);
  }else{
    return 1;
  }
}

int fatorial_Iterativo(int n){
  float auxMultiplica=1;

  for(int i=1;i<=n;i++){
    auxMultiplica*=i;
  }

  return auxMultiplica;
}

int main()
{
int n;

printf("Introduza um numero inteiro positivo:\n");
scanf("%d",&n);

while(n<=0){
  printf("O numero que inseriu e invalido!\nInsira novamente o numero:\n");
  scanf("%d",&n);
}

printf("Fatorial(versao recursiva) de %d: %d\n",n,fatorial_Recursivo(n));

printf("Fatorial(versao iterativa)de %d: %d",n,fatorial_Iterativo(n));
	return 0;
}
