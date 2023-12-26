#include <stdio.h>

int descobririndicemaior(int arr[],int n) {
  int maior = arr[0],k = 0;

  for (int i = 0; i < n; i++) {
    if (arr[i] > maior) {
      maior = arr[i];
      k = i;
    }
  }
  printf("O maior valor do vector situa-se no indice %d\n",k);
}

int trocarelementos(int arr[],int n) {
  int ind1, ind2;

  printf("O array esta organizado desta forma ");

  for (int i = 0; i < n; i++) {
    printf("%d ",arr[i]);
  }

  printf("\n");

  while (ind1 > n-1 || ind2 > n-1) {
    printf("Qual e o primeiro indice que pretende mudar? ");
    scanf("%d",&ind1);
    printf("\n");
    printf("Qual e o segundo indice que pretende mudar? ");
    scanf("%d",&ind2);
  }

  printf("\n");

  int y = arr[ind1];
  arr[ind1] = arr[ind2];
  arr[ind2] = y;

  printf("O array (depois da troca) esta organizado desta forma: ");

  for (int i = 0; i < n; i++) {
    printf("%d ",arr[i]);
  }
}

void selecaolinear(int arr[], int n) {
  int i, j, k, min, aux;

  for (i = 0; i < (n-1); i++)
  {
     min = i;
     for (j = (i+1); j < n; j++) {
       if(arr[j] < arr[min])
         min = j;
     }
     if (arr[i] != arr[min]) {
       aux = arr[i];
       arr[i] = arr[min];
       arr[min] = aux;
     }
  }

  printf("\n");

  printf("Usando o algoritmo de Selecao linear o array vai organizar-se da seguinte forma: ");

  for (int k = 0; k < n; k++) {
    printf("%d ",arr[k]);
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

  descobririndicemaior(vec,num);
  printf("\n");
  trocarelementos(vec,num);
  printf("\n");
  selecaolinear(vec,num);
}
