#include <stdio.h>
void sequencia_Nelementos_Recursivo(int n){
  if(n==1){
    printf("%d",n);
  }else{
    printf("%d",n);
    sequencia_Nelementos_Recursivo(n-1);
    printf("%d",n);
  }
}

void sequencia_Nelementos_Iterativo(int n){
  int aux=n;

  for(n;n>1;n--){
    printf("%d",n);
  }
  for(n;n<=aux;n++){
    printf("%d",n);
  }
}

int main()
{
  int n;
  printf("Insira n para fazer a sequencia:\n");
  scanf("%d",&n);

  sequencia_Nelementos_Recursivo(n);
  printf("\n");
  sequencia_Nelementos_Iterativo(n);
  return 0;
}
