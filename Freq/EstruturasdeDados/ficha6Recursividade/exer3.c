#include<stdio.h>
 /*--------------------------------------------------------------
 --------------------------------------------------------------
 Proprietario: Jorge Miguel dos Santos Martins
 Curso: Licenciatura Sistemas Tecnologias de Informacao
 Disciplina: Programacao II / Estruturas Dados Data:
 Programa/Exercicio: Ficha  6/ Exercicio 3
 --------------------------------------------------------------
 --------------------------------------------------------------
 */
void escreve(int tamanho, int vet[5]){
  for(int i=0; i<tamanho; ++i){
    printf(" %d ", vet[i]);
  }
}

void inverteInteractivo(int tamanho, int vet[5]){

  int aux, j=0;

  for(int i=tamanho-1; i>=tamanho/2; --i){
    aux=vet[j];
    vet[j]=vet[i];
    vet[i]=aux;
    j++;
  }
}


  void inverterRecursivo(int vetor[], int a, int b){
    int aux;
  	if(a==b)
      return;
    else{
      aux=vetor[a];
      vetor[a]=vetor[b];
      vetor[b]=aux;
      inverterRecursivo(vetor, a+1, b-1);
    }
  }


 int main(){

int tamanho=5;

int vetor[]={1, 2, 3, 4, 5};

puts("Vetor original");
escreve(tamanho, vetor);

inverteInteractivo(tamanho, vetor);
puts("\nRecursao interativa");
escreve(tamanho, vetor);

inverterRecursivo(vetor, 0, tamanho-1);
puts("\n Recursiva");
escreve(tamanho, vetor);


 return 0;
 }
