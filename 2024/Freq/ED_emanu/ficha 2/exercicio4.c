#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ARRAY_SIZE 1000

int elementsNum,auxElements;
int array[ARRAY_SIZE];

void insertNumbers(){
  int i;
  printf("Insira o numero de elementos total(100/500/1000): ");
  scanf("%d",&elementsNum);

  for(i=0;i<elementsNum;i++){
    printf("Insira os numeros a introduzir no vetor: ");
    scanf("%d",&auxElements);
    array[i]=auxElements;
    if(auxElements<=0 || auxElements>elementsNum){
      printf("Numeros nao estao dentro do intervalo!!");
      return;
    }
  }
}

void fileAscendingOrder(){
  int i,j,auxNumbers;

  FILE * ascendingOrder;

  if(elementsNum==100){
    ascendingOrder=fopen("ascendingOrder100.txt","w+");
  }

  if(elementsNum==500){
      ascendingOrder=fopen("ascendingOrder500.txt","w+");
  }

  if(elementsNum==1000){
      ascendingOrder=fopen("ascendingOrder1000.txt","w+");
  }

   for(i=0;i<elementsNum;i++){
     for(j=i+1;j<elementsNum;j++){
       if(array[i]>array[j]){
         auxNumbers=array[i];
         array[i]=array[j];
         array[j]=auxNumbers;
       }
     }
   }

   for(i=0;i<elementsNum;i++){
     fprintf(ascendingOrder,"%d ",array[i]);
   }
fclose(ascendingOrder);
}

void fileDescendingOrder(){
  int i,j,auxNumbers;

  FILE * descendingOrder;

  if(elementsNum==100){
    descendingOrder=fopen("descendingOrder100.txt","w+");
  }

  if(elementsNum==500){
      descendingOrder=fopen("descendingOrder500.txt","w+");
  }

  if(elementsNum==1000){
      descendingOrder=fopen("descendingOrder1000.txt","w+");
  }

  for(i=0;i<elementsNum;i++){
    for(j=i+1;j<elementsNum;j++){
      if(array[i]<array[j]){
        auxNumbers=array[i];
        array[i]=array[j];
        array[j]=auxNumbers;
      }
    }
  }

  for(i=0;i<elementsNum;i++){
    fprintf(descendingOrder,"%d ",array[i]);
  }
fclose(descendingOrder);
}

void fileRandomOrder(){
  int i;
  int randomArray[ARRAY_SIZE];
  time_t t;

  srand((unsigned) time(&t));

  FILE * randomOrder;
  if(elementsNum==100){
    randomOrder=fopen("randomOrder100.txt","w+");
  }
  if(elementsNum==500){
    randomOrder=fopen("randomOrder500.txt","w+");
  }
  if(elementsNum==1000){
    randomOrder=fopen("randomOrder1000.txt","w+");
  }

  for(i=0;i<elementsNum;i++){
    randomArray[i]= rand()%elementsNum+1;
  }

  for(i=0;i<elementsNum;i++){
    fprintf(randomOrder,"%d ",randomArray[i]);
  }
  fclose(randomOrder);
}
int main()
{
insertNumbers();
fileAscendingOrder();
fileDescendingOrder();
fileRandomOrder();

	return 0;
}