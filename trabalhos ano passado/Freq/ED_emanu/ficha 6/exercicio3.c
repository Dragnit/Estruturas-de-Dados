#include <stdio.h>

void insere_Array(int array[],int tamanho){
  for(int i=0;i<tamanho;i++){
    printf("Insira os elementos no array:\n");
    scanf("%d",&array[i]);
  }
}

void escreve_Array(int array[],int tamanho){
  for(int i=0;i<tamanho;i++){
    printf("%d ",array[i]);
  }
}

void inverte_Array_Iterativo(int array[],int tamanho,int auxInicio,int auxFim){
  int auxCopia;
  auxInicio=0;
  auxFim=tamanho-1;

  for(int i=0;i<tamanho;i++){
    if(auxInicio<auxFim){
      auxCopia=array[auxInicio];
      array[auxInicio]=array[auxFim];
      array[auxFim]=auxCopia;
      auxInicio++;
      auxFim--;
    }
  }
}

void inverte_Array_Recursivo(int array[],int tamanho,int auxInicio,int auxFim){
  int auxCopia;
  auxInicio=0;
  auxFim=tamanho-1;

  if(tamanho<=1){
    return;
  }else{
    auxCopia=array[auxInicio];
    array[auxInicio]=array[auxFim];
    array[auxFim]=auxCopia;
  }
  return inverte_Array_Recursivo(array+1,tamanho-2,auxInicio,auxFim);
}

int main()
{
int tamanho;
int array[tamanho];
int auxInicio;
int auxFim;

printf("Insira o tamanho que pretende dar ao array:\n");
scanf("%d",&tamanho);

insere_Array(array,tamanho);

printf("Array antes da inversao:\n");
escreve_Array(array,tamanho);

inverte_Array_Iterativo(array,tamanho,auxInicio,auxFim);
inverte_Array_Recursivo(array,tamanho,auxInicio,auxFim);

printf("\nArray depois da inversao:\n");
escreve_Array(array,tamanho);
	return 0;
}