#include<stdio.h>

 /*--------------------------------------------------------------
 --------------------------------------------------------------
 Proprietário: Jorge Miguel dos Santos Martins
 Curso: Licenciatura Sistemas Tecnologias de Informação
 Disciplina: Programação II / Estruturas Dados
 Data: 27 fevereiro 2020
 Programa/Exercicio: ficha 1 / Exercicio 1
 --------------------------------------------------------------
 --------------------------------------------------------------
 */


int save(int vet[], int read){ // para gravar no vetor os valores.. Exercicio 1
  int maximo;
  scanf("%d", &maximo);

  if(maximo>50){
    printf("Maior que memoria admite...\n");
    printf("Clique numa tecla para terminar\n");
    getchar();
    getchar();
    return -1;
  }
  else{
  for(int i=0; i<maximo; ++i){
    printf("Insira inteiro\n");
    scanf("%d", &read);
    vet[i]=read;
    }
    return maximo;
  }
}

void show(int vet[], int counter){ //para demonstrar os valores Exercicio 1
  if(counter==-1){
    return;
  }
  else{
    printf("Numeros em memoria sao:\n");
    for(int i=0; i<counter; ++i){
      printf("%d\n", vet[i]);
    }
    printf("\nClique numa tecla para terminar..");
    getchar();
    getchar(); //duplo para absorver o enter do teclado
  return;
  }
}

 int main(){
   int vet[51], read, counter;

   printf("Insira o numero de inteiros que quer guardar menor ou igual que 50\n");
   counter = (save(vet, read));
   show(vet, counter);

	return 0;
}
