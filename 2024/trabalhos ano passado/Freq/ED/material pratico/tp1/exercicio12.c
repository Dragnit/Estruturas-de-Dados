#include <stdio.h>

int removerrepetidos(int arr[],int n) {
  int valor = 0,i,resultado,k,j;

  for (i=0; i < n; i++) {
    for(j=i+1; j < n; j++) {
      if (arr[i] == arr[j]) {
        for(k=j; k < n; k++) {
            arr[k] = arr[k+1];
        }
        n--;
        j--;
      }
    }
  }

  for(i=0; i < n; i++) {
    printf("a[%d] = %d\n",i,arr[i]);
  }
}

int main() {
  int num,value,vec[1000],i;

  printf("Quantos valores pretende inserir no vetor? ");
  scanf("%d",&num);

  for (int i = 0; i < num; i++) {
    printf("Qual e o valor que quer inserir? ");
    scanf("%d",&value);
    vec[i] = value;
  }

  removerrepetidos(vec,num);

}
