#include<stdio.h>
 /*--------------------------------------------------------------
 --------------------------------------------------------------
 Proprietario: Jorge Miguel dos Santos Martins
 Curso: Licenciatura Sistemas Tecnologias de Informacao
 Disciplina: Programacao II / Estruturas Dados Data:
 Programa/Exercicio: Ficha 4 / Exercicio 1
 --------------------------------------------------------------
 --------------------------------------------------------------
 */
 struct estrutura_data {
   int dia;
   int mes; // tambem poderia ser uma string
   int ano;
 };
typedef struct estrutura_data data;


 /* le uma data da consola (standard input) na forma dia-mes-ano  devolve a estrutura que descreve a data */
 data le_data() {
   data dat;
   int comp=0;
   do{ // condição para que a data seja bem inserida
   printf("\nEscreva data: "); scanf("%d-%d-%d", &dat.dia, &dat.mes, &dat.ano); // para ler com os - - -
   if(dat.dia>0 && dat.dia < 32)
     printf("Dia inserido correctamente\n");
     else{
       comp++;
       printf("Erro no dia\n");
     }
   if(dat.mes>0 && dat.mes<=12)
     printf("Mes inserido correctamente\n");
     else{
       comp++; // se ele é incrementado não se sai do ciclo
       printf("Erro no mes\n");
     }
   if(dat.ano>0)
     printf("Ano inserido correctamente\n");
     else{
       comp++;
       printf("Erro no ano\n");
     }
  }while(comp!=0);

  printf("\nData inserida com sucesso\n");
  return dat;
}

//escreve uma data na consola (standard output) na forma dia-mes-ano
void escreve_data(data d){
  printf("Escrever as datas\n");
  printf("%d - %d - %d \n", d.dia, d.mes, d.ano);
}

/* compara duas datas  se a 1a data e posterior a 2a data devolve '>'
se a 1a data e anterior a 2a data devolve '<'  se as duas datas sao iguais devolve '=' */
char compara_datas(data d1, data d2) {

  if(d1.ano == d2.ano && d1.mes == d2.mes && d1.dia == d2.dia) // comecei pelas igualdades dos anos e foi reduzindo as diferenças..
    return '=';
  if(d1.ano == d2.ano && d1.mes == d2.mes && d1.dia > d2.dia)
    return '>';
  if(d1.ano == d2.ano && d1.mes == d2.mes && d1.dia < d2.dia)
    return '<';
  if(d1.ano == d2.ano && d1.mes > d2.mes)
    return '>';
  if(d1.ano == d2.ano && d1.mes < d2.mes)
    return '<';
  if(d1.ano > d2.ano)
    return '>';
  else
    return '<';
}

/* determina a "maior" data entre duas datas d1 e d2 */

data maior_data(data d1, data d2) {
  char big;
  big=compara_datas(d1, d2); // uso da função para saber qual a maior..
  if(big=='>')
    return d1;
  if(big=='<')
    return d2;
  else
    return d1;
}

 int main(){
   char comp;
   data dat1, dat2, dat3;
   dat1 = le_data();
   dat2 = le_data();
   escreve_data(dat1);
   escreve_data(dat2);

   comp=compara_datas(dat1, dat2);// usar compara_datas para obter a data mais recente entre dat1 e dat2  /*...*/
   if(comp== '=')
      printf("As datas sao iguais\n");
   if(comp=='>')
      printf("A data 1 e posterior\n");
   else
      printf("A data 2 e posterior\n");

  dat3 = maior_data(dat1, dat2); // usar maior_data para encontrar a “maior” data entre dat1 e dat2  /*...*/
  printf("A maior data e %d-%d-%d\n", dat3.dia, dat3.mes, dat3.ano);

 return 0;
 }
