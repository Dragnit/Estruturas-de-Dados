#include <stdio.h>

int lin,col;
int matA[100][100];

void lerelementos() {
  int i, j;

  printf("Quantas linhas deseja na matriz? ");
  scanf("%d",&lin);
  printf("\n");
  printf("Quantas colunas deseja na matriz? ");
  scanf("%d",&col);

  printf("Insira os valores para a matriz:\n");
  for(int i = 0; i < lin; i++) {
    for(int j = 0; j < col; j++) {
      scanf("%d",&matA[i][j]);
    }
  }
}

void escrevermatriz () {
  int i, j;

  for(int i = 0; i < lin; i++) {
    for(int j = 0; j < col; j++) {
     printf("%d ", matA[i][j]);
   }
   printf("\n");
  }
}

void calcularmediamatriz () {
  int i, j;
  float media, soma = 0;

  for(int i = 0; i < lin; i++) {
    for(int j = 0; j < col; j++) {
     soma = soma + matA[i][j];
    }
  }
  media = soma / (lin*col);
  printf("A media de todos os elementos da matriz e: %0.2f\n",media);
}

void calcularmediacoluna () {
  int i, j, c;
  float media, soma = 0;

  printf("Qual e a coluna que deseja selecionar? ");
  scanf("%d",&c);

  for(int j = 0; j < col; j++) {
    for(int i = 0; i < lin; i++) {
      if (c == j)
        soma = soma + matA[i][j];
    }
  }
  media = soma / col;
  printf("A media da coluna %d e: %0.2f\n",c,media);
}

void calcularmedialinha () {
  int i, j, l;
  float media, soma = 0;

  printf("Qual e a linha que deseja selecionar? ");
  scanf("%d",&l);

  for(int i = 0; i < lin; i++) {
    for(int j = 0; j < col; j++) {
      if (l == i)
        soma = soma + matA[i][j];
    }
  }
  media = soma / lin;
  printf("A media da linha %d e: %0.2f\n",lin,media);
}

void contarzeros(){
  int i,j,contador=0;

  for(i=0;i<lin;i++){
    for(j=0;j<col;j++){
      if(matA[i][j] == 0 && j>i){
        contador++;
      }
    }
  }
  printf("O numero de zeros acima da diagonal principal sao: %d\n",contador);
}

void trocarcolunas() {
  int col1, col2, resultado, i;

  printf("Introduza a primeira coluna que deseja ser trocada: ");
  scanf("%d",&col1);
  printf("Introduza a segunda coluna que deseja ser trocada: ");
  scanf("%d",&col2);

   for (i = 0; i < col; ++i)
   {
       resultado = matA[i][col1 - 1];
       matA[i][col1 - 1] = matA[i][col2 - 1];
       matA[i][col2 - 1] = resultado;
    }

    printf("A matriz depois de duas colunas trocadas fica: ");
    for(int i = 0; i < lin; i++)
      for(int j = 0; j < col; j++)
       printf("%d ", matA[i][j]);

}
int main () {
  int op = 1;

  while (op != 0) {

  printf("\nMenu\n");
  printf("1. Ler os elementos da matriz\n");
  printf("2. Escrever a matriz\n");
  printf("3. Calcular a media de todos os elementos da matriz\n");
  printf("4. Calcular a media de todos os elementos da coluna da matriz\n");
  printf("5. Calcular a media de todos os elementos da linha da matriz\n");
  printf("6. Contar numero de zeros que se encontram acima da diagonal principal da matriz\n");
  printf("7. Determinar a linha de uma matriz que tem a soma dos seus elementos máxima\n");
  printf("8. Trocar as colunas j e k de uma matriz\n");
  printf("9. Somar duas matrizes\n");
  printf("0. Sair\n");
  printf("O que deseja fazer? Escolha a opcao correspondente:");
  scanf("%d",&op);

  switch (op) {
    case 1:lerelementos();
    break;
    case 2:escrevermatriz();
    break;
    case 3:calcularmediamatriz();
    break;
    case 4:calcularmediacoluna();
    break;
    case 5:calcularmedialinha();
    break;
    case 6:contarzeros();
    break;
    case 7:printf("Nao fizemos");
    break;
    case 8:trocarcolunas();
    break;
    case 9:printf("Não fizemos");
    break;
  }
}

}
