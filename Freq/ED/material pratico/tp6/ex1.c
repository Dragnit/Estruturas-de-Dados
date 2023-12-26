#include <stdio.h>

int fatr (int n) {

  if ((n==1) || (n==0)) return 1;
  else
  return fatr(n-1)*n;
}


int fati(int n){

  int fat=1,i;

  for(i=n;i>0;i--)
  fat=fat *i;
  return fat;
}


int main () {

  int n;

  printf("Informe o numero que deseja obter o fatorial:\n");
  scanf("%d",&n);
  printf("O fatorial (recursiva) de %d e %d \n",n,fatr (n));
  printf("O fatorial (iterativa) de %d e %d \n",n,fati (n));
}
