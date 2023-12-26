#include <stdio.h>

void bubblesort(int vec[], int n)
{
    int i, j, valor;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n-i-1; j++)
        {
            if( vec[j] > vec[j+1])
            {
                valor = vec[j];
                vec[j] = vec[j+1];
                vec[j+1] = valor;
            }
        }
    }

    printf("O vetor organizado (apos o bubbleSort) ficou: ");
    for(i = 0; i < n; i++)
    {
        printf("%d  ", vec[i]);
    }
}

int main()
{
    int vec[100], i, num, value, temp;

    printf("Quantos valores pretende inserir? ");
    scanf("%d",&num);

    for (int i = 0; i < num; i++) {
      printf("Qual e o valor que quer inserir? ");
      scanf("%d",&value);
      vec[i] = value;
  }

    bubblesort(vec, num);

}
