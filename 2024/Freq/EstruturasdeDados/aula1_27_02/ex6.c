#include<stdio.h>

 /*--------------------------------------------------------------
 --------------------------------------------------------------
 Proprietário: Jorge Miguel dos Santos Martins
 Curso: Licenciatura Sistemas Tecnologias de Informação
 Disciplina: Programação II / Estruturas Dados
 Data:25 Fevereiro 2020
 Programa/Exercicio:ficha 1 / Exercicio 6
 --------------------------------------------------------------
 --------------------------------------------------------------
 */

//Infelizmente não arrisquei usar o system clear o que pode deixar confuso o desenrolar do programa não sendo tão limpo
//mesmo assim tentei usar os getchar para quando se usar o programa se ir conseguindo seguir o que se está a passar passo a passo
//o uso de condições para não fugir ao que se está a pedir (numeros inteiros, maiores que 0 e afins) foram de minha intençao pessoal pois tento ter atençao ao pormenor..


 void readerMatriz(int linhas, int colunas, float matrizA[linhas][colunas]){ //funcao que insere valores na matriz..
   float valor;
   for(int a=0; a<linhas; ++a){
     for(int b=0; b<colunas; ++b){
       printf("\nInsira valor para linha %d e coluna %d : ", (a+1), (b+1)); //utilizador pode não saber que array começa em zero, usei a matriz comum conhecida
       scanf("%f", &valor);
       matrizA[a][b]=valor;
     }
   }
   getchar();
   return ;
 }

 void writterMatriz(int linhas, int colunas, float matrizA[linhas][colunas]){ //funcao que escreve a matriz
   printf("\n\tValores tabelados na matriz\n\n");
   for(int a=0; a<linhas; ++a){
     for(int b=0; b<colunas; ++b){
       printf("%.2f ", matrizA[a][b]);
     }
     printf("\n");
   }
  printf("\nPrima uma tecla para continuar..\n");
  getchar();
  return;
 }

 void medias(int linhas, int colunas, float matrizA[linhas][colunas]){
   int valorColuna=0, valorLinha=0; // assim no teste if sei que só podem por números positivos
   float divisor=0, sum=0, med;
   printf("Media de todos os elementos da Matriz: ");
   for(int a=0; a<linhas; ++a){
     for(int b=0; b<colunas; ++b){
       sum=(matrizA[a][b]+sum);
       divisor++;
     }
   }
   med=(sum/divisor);
   printf("%.2f \n", med);
   printf("\nPrima uma tecla para continuar..\n");
   getchar();
   do{
     printf("Valores da coluna começam em 1\n");
     printf("Insira o numero de uma coluna para calcular a sua media: ");
     if(scanf("%d", &valorColuna)){
       if(((valorColuna-1)<=(colunas-1) && (valorColuna-1) >=0)){ // uso a subtração para estar a dar a entender ao utilizador quando é por exemplo coluna 1 que ele quer mas na verdade esta na coluna 0 da matriz..
         printf("Valor de coluna aceite\n");
       }
       else{
         printf("Valor inserido incorrecto volte a tentar..\n");
       }
     }
   }while((valorColuna-1)>(colunas-1) || (valorColuna-1)<0);
   
   sum=0; divisor=0; med=0; //reutilizar variaveis..
     for(int b=0; b<linhas; ++b){
       sum=(matrizA[b][valorColuna-1]+sum);
       divisor++;
     }
     med=(sum/divisor);
     printf("Media da coluna %d é %.2f\n", valorColuna, med);
   printf("Prima uma tecla para continuar..\n");
   getchar();
   getchar();
   do{
     printf("Valores da linha começam em 1\n");
     printf("Insira o numero de uma linha para calcular a sua media: ");
     if(scanf("%d", &valorLinha)){
       if(((valorLinha-1)<=(linhas-1) && (valorLinha-1)>=0 )){ // uso a subtração para estar a dar a entender ao utilizador quando é por exemplo linha 1 que ele quer mas na verdade esta na linha 0 da matriz..
         printf("Valor de linha aceite\n");
       }
       else{
         printf("Valor inserido incorrecto volte a tentar..\n");
       }
     }
   }while((valorLinha-1)>(linhas-1) || (valorLinha-1)<0);
   sum=0; divisor=0; med=0; //reutilizar variaveis..
     for(int b=0; b<colunas; ++b){
       sum=(matrizA[valorLinha-1][b]+sum);
       divisor++;
     }
     med=(sum/divisor);
     printf("Media da linha %d é %.2f\n", valorLinha, med);

   printf("Prima uma tecla para continuar..\n");
   getchar();
   getchar();
 return;
 }

 void find0(int linhas, int colunas, float matrizA[linhas][colunas]){
   int ocorrencia=0;
   float auxiliar;
   for(int i=0; i<linhas; ++i){
     for(int b=i; b<colunas; ++b){ //igualo ao i para seguir sempre a iniciar como diagonal (0,0)(1,1)(2,2)(3,3) por ai diante..
       auxiliar=matrizA[i][b];
       if(auxiliar!=0.00){ //devido ao mostrar com apenas duas casas decimais dou a entender que a partir da terceira casa considero como 0 (o que matematicamente não é verdade)..
         continue;
       }
       else{
         ++ocorrencia;
       }
     }
   }
   printf("Foram encontrados %d de zeros acima da diagonal\n", ocorrencia);
   printf("Clique numa tecla para continuar...");
   getchar();
 return;
 }

   void maxSumLine(int linhas, int colunas, float matrizA[linhas][colunas]){ //funcao descobrir linha com maior soma
     float sum=0, valor=0, maxLine=0;
     int line=0; //para o utilizador ver a linha 0 como 1 (não lhe fazer confusao);
     for(int a=0; a<linhas; ++a){
       for(int b=0; b<colunas; ++b){
         sum=(matrizA[a][b]+sum);
       }
       if(sum>maxLine){
         maxLine=sum;
         line=a+1; //para ficar igual ao que o utilizador esta habituado a ver..
         sum=0; //voltar a iniciar a variavel para o proximo ciclo de outra linha
       }
       else{
         sum=0;
       }
     }
     printf("A linha com maior soma e a linha %d com o valor de %.2f \n", line, maxLine);
     printf("Prime tecla para continuar..\n");
     getchar();
   return;
   }

   void change(int linhas, int colunas, float matrizA[linhas][colunas]){

     int col1=0, col2=0;
     float vetAux[colunas];

       printf("Indique as colunas a trocar, começa na coluna 1..\n");
       do{
         printf("Coluna: ");
         if(scanf("%d", &col1)){
           if((col1-1)<=(colunas-1)&&(col1-1)>=0){
             printf("Valor de coluna aceite\n");
           }
           else{
             printf("Valor não aceite volte a inserir.\n");
           }
         }
       }while((col1-1)>(colunas-1) || (col1-1)<0);

       do{
         printf("Coluna: ");
         if(scanf("%d", &col2)){
           if((col2-1)<=(colunas-1)&&(col2-1)>=0){
             printf("Valor de coluna aceite\n");
           }
           else{
             printf("Valor não aceite volte a inserir.\n");
           }
         }
       }while((col2-1)>(colunas-1) || (col2-1)<0);

       col1=(col1-1); col2=(col2-1); //retira-las do numero usado em abstraçao ao utilizador..
       printf("\tMatriz Antes\n");
       writterMatriz(linhas, colunas, matrizA);
       getchar();
       printf("\t Matriz Depois\n");
       for(int a=0; a<colunas; ++a){
         vetAux[a]=matrizA[a][col1];
         matrizA[a][col1]=matrizA[a][col2];
         matrizA[a][col2]=vetAux[a];
       }
       writterMatriz(linhas, colunas, matrizA); //aproveitei usar já a subfuncao..
     return;
   }

   void SumMatriz(int linhas, int colunas, float matrizA[linhas][colunas], float matrizB[linhas][colunas]){

     printf("\nSoma de Matrizes\n");

     float valor=0.0;

     for(int i=0; i<linhas; i++){
       for(int c=0; c<colunas; c++){
         matrizB[i][c]=matrizA[i][c];
       }
     }

     printf("\tMatrizes antes\n");
     printf("Matriz A\n");
     writterMatriz(linhas, colunas, matrizA);
     printf("Matriz B que é copia da A\n");
     writterMatriz(linhas, colunas, matrizB);

     printf("\t Soma das matrizes \n");

     for(int i=0; i<linhas; i++){
       for(int c=0; c<colunas; c++){
         valor=matrizA[i][c];
         matrizB[i][c]=(matrizB[i][c]+valor);
       }
     }
     writterMatriz(linhas, colunas, matrizB);

     return;
   }


 int main(){
   int linhas=0, colunas=0;
   printf("\n\n\tAVISO: LINHAS E COLUNAS COMEÇAM EM 1 NÃO UTILIZE 0 OU NUMEROS NEGATIVOS\n\n\n");
   printf("Nota: Use apenas inteiros para o numero de linhas e colunas..\n\n");
   printf("\n\nClique numa tecla para iniciar o programa\n");
   getchar();
   printf("Insira o numero de linhas: ");
   scanf("%d", &linhas);
   if(linhas>0){
     printf("Valor aceite\n");
   }
   else{
     return 0;
   }
   printf("\nInsira o numero de colunas: ");
   scanf("%d", &colunas);
   if(colunas>0){
     printf("Valor aceite\n");
   }
   else{
     return 0;
   }
   float matrizA[linhas][colunas];
   readerMatriz(linhas, colunas, matrizA);
   writterMatriz(linhas, colunas, matrizA);
   medias(linhas, colunas, matrizA);
   find0(linhas, colunas, matrizA);
   maxSumLine(linhas, colunas, matrizA);
   change(linhas, colunas, matrizA);
   float matrizB[linhas][colunas];
   SumMatriz(linhas, colunas, matrizA, matrizB);

	return 0;
}
