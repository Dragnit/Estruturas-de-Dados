#include <stdio.h>

int insercaolinear(int vec[], int num) {
  int i, valor, j;
    for (i = 1; i < num; i++) {
        valor = vec[i];
        j = i - 1;
        while (j >= 0 && vec[j] > valor) {
            vec[j + 1] = vec[j];
            j = j - 1;
        }
        vec[j + 1] = valor;
    }
}

int main() {
  int arr[20] = { 11, 17, 9, 30, 21 };
  int n = 5, i;

  insercaolinear(arr,n);

  printf("\nDepois da insercao linear o vetor encontra-se ordenado desta forma: ");

  for (i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
}

/*pseudocodigo: FUNÇÃO INSERTION_SORT (A[], tamanho)
        VARIÁVEIS
                i, j, eleito
        PARA i <- 1 ATÉ (tamanho-1) FAÇA
                eleito <- A[i];
                j <- i-1;
                ENQUANTO ((j>=0) E (eleito < A[j])) FAÇA
                          A[j+1]:= A[j];
# Elemento de lista numerada
                          j:=j-1;
                FIM_ENQUANTO
                A[j+1] <- eleito;
        FIM_PARA
FIM*/
