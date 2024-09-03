#include<stdio.h>
 /*--------------------------------------------------------------
 --------------------------------------------------------------
 Proprietario: Jorge Miguel dos Santos Martins
 Curso: Licenciatura Sistemas Tecnologias de Informacao
 Disciplina: Programacao II / Estruturas Dados Data:
 Programa/Exercicio: Ficha  4/ Exercicio 3
 --------------------------------------------------------------
 --------------------------------------------------------------
 */
struct numeros_fraccao{ // estrutura onde estão os campos para a fraccao.
  float numerador;
  float denominador;
}; typedef struct numeros_fraccao fraccao;

fraccao read(){ // funcao que le a fraccao dada pelo utilizador
  fraccao f; //variavel local do tipo de estrutura fraccao
  printf("Insira o numerador: "); scanf("%f", &f.numerador);
  do{
    printf("\nAVISO O DENOMINADOR TEM DE SER DIFERENTE DE 0 ");
    printf("\nInsira o denominador: "); scanf("%f", &f.denominador);
  }while(f.denominador==0);
return f;
}

fraccao soma(fraccao frac1, fraccao frac2){ // funcao que faz a soma entre fraccoes
  fraccao f; //variavel local que vai ficar com a soma
  f.denominador=(frac1.denominador * frac2.denominador); //primeiro multiplico os denominadores para saber o denominador final
  f.numerador=((frac1.denominador * frac2.numerador) + (frac2.denominador * frac1.numerador)); //multiplicação cruzada entre denominador e numerador contrario para depois nos resultados os somar..
return f;
}

fraccao subtracao(fraccao frac1, fraccao frac2){
  fraccao f; //variavel local que vai ficar com a soma
  f.denominador=(frac1.denominador * frac2.denominador); //primeiro multiplico os denominadores para saber o denominador final
  f.numerador=((frac2.denominador * frac1.numerador) - (frac1.denominador * frac2.numerador)); //multiplicação cruzada entre denominador e numerador contrario para depois nos resultados os subtrair..
return f;
}

fraccao multiplica(fraccao frac1, fraccao frac2){
  fraccao x; // variavel local de estrutura que vai retornar o resultado da multiplicação
  x.denominador = (frac1.denominador * frac2.denominador); //simples multiplicação entre denominadores
  x.numerador = (frac1.numerador * frac2.numerador);
return x;
}

fraccao div(fraccao frac1, fraccao frac2){
  fraccao x; // variavel local de estrutura como as outras funçoes
  if(frac1.numerador==0) // estava a dar um erro que em vez de devolver 0 devolvia 1#$.&& basicamente lixo.
    x.numerador=0;
  if(frac2.numerador==0)
    x.numerador=0;
  else //o else é só para o numerador, em qualquer caso o denominador nunca é 0 nesta fase.
    x.numerador = (frac1.numerador / frac2.numerador);
  x.denominador = (frac1.denominador / frac2.denominador);
return x;
}

fraccao potencia(fraccao f, int exp){
  float aux;
  fraccao p=f; // caso ele seja elevado a 1 não passa no ciclo for assim retorna a mesma fração.
  if(exp==0){ // qualquer numero com expoente 0 dá 1.
    f.numerador=1;
    f.denominador=1;
  }
  if(exp<0){ // expoente negativo é só trocar as posicoes.
    if(f.numerador==0) // segurança para não ficar com um denominador 0!!
      printf("\nIMPOSSIVEL OPERACAO COM FRACCAO COM NUMERADOR 0 DEVIDO AO DENOMINADOR NAO PUDER FICAR 0\n");
    else{
      aux=f.numerador;
      f.numerador=f.denominador;
      f.denominador=aux;
      exp=(exp * (-1)); // passar o expoente para positivo
    }
  }
  if(exp>0){
    for(int i=exp; i>1; --i){ // i igual ao expoente e o ciclo corre enquanto o i é maior que 1
      p=(multiplica(p, f)); // aproveito a funcao de multiplicar para multiplicar entre si dentro de um ciclo que faz de expoente.
    }
    f=p;
  }
  return f;
}

 int main(){
   fraccao frac1, frac2, somafrac, subfrac, multfrac, divfrac; // fraccao do tipo da estrutura que criei
   int exp;
   printf("Insira a primeira fraccao\n");
   frac1 = read(); // para ler a fracao
   printf("Insira a segunda fraccao\n");
   frac2 = read(); //crio a segunda fraccao para que seja mais facil ter uma para fazer contas e não ser apenas a mesma..
   printf("Fraccao 1 -> %.2f / %.2f\n", frac1.numerador, frac1.denominador);
   printf("Fraccao 2 -> %.2f / %.2f\n", frac2.numerador, frac2.denominador);
   somafrac = soma(frac1, frac2); // nos prints usei o decimal para se perceber quando da numerador 0 o decimal é 0.
   printf("\nResultado da soma de fracoes numerador / denominador -> %.2f / %.2f -> decimal e %.2f\n", somafrac.numerador, somafrac.denominador, (somafrac.numerador/somafrac.denominador));
   subfrac = subtracao(frac1, frac2);
   printf("\nResultado da subtracao de fracoes numerador / denominador -> %.2f / %.2f -> decimal e %.2f\n", subfrac.numerador, subfrac.denominador, (subfrac.numerador/subfrac.denominador));
   multfrac = multiplica(frac1, frac2);
   printf("\nResultado da multiplicao de fracoes numerador / denominador -> %.2f / %.2f -> decimal e %.2f\n", multfrac.numerador, multfrac.denominador, (multfrac.numerador/multfrac.denominador));
   divfrac = div(frac1, frac2);
   printf("\nResultado da divisao de fracoes numerador / denominador -> %.2f / %.2f -> decimal e %.2f\n", divfrac.numerador, divfrac.denominador, (divfrac.numerador/divfrac.denominador));
   printf("Indique a potencia que quer aplicar nas fraccoes: "); scanf("%d", &exp);
   frac1=potencia(frac1, exp);
   frac2=potencia(frac2, exp);
   printf("\nFraccao 1 -> %.2f / %.2f -> decimal %.2f \n Fraccao 2 -> %.2f / %.2f -> decimal  %.2f \n ", frac1.numerador, frac1.denominador, (frac1.numerador/frac1.denominador), frac2.numerador, frac2.denominador, (frac2.numerador/frac2.denominador));
 return 0;
 }
