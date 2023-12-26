#include<stdio.h>
/*
struct estrutura_data
{
	int dia, mes, ano;
	// mes poderia ser uma string
};
*/
typedef struct estrutura_data data;


typedef struct estrutura_data
{
	int dia, mes, ano;
} data;

/* le uma data da consola (standard input) na forma dia-mes-ano
	devolve a estrutura que descreve a data */
data le_data()
{
  data d;
  printf("inserir data (dia-mes-ano): ");
  scanf("%i-%i-%i",&d.dia,&d.mes,&d.ano);
  return d;
}

// escreve uma data na consola (standard output) na forma dia-mes-ano
void escreve_data(data d)
{
  printf("%i-%i-%i\n",d.dia,d.mes,d.ano);
}

/* compara duas datas
	se a 1a data e posterior a 2a data devolve '>'
	se a 1a data e anterior a 2a data devolve '<'
	se as duas datas sao iguais devolve '=' */
char compara_datas(data d1, data d2)
{/*...*/}

// determina a "maior" (mais recente) data entre duas datas d1 e d2
data maior_data(data d1, data d2)
{
  if(d1.ano > d2.ano)
    return d1; //return '>';// em compara_datas
  else
    if(d1.ano < d2.ano)
      return d2;
    else //d1.ano = d2.ano
      if(d1.mes > d2.mes)
        return d1;
      else
        if(d1.mes < d2.mes)
          return d2;
        else // d1.ano = d2.ano e d1.mes = d2.mes
          if(d1.dia > d2.dia)
            return d1;
          else
            if(d1.dia < d2.dia)
              return d2;
            else return d1; //d1 = d2
}

int main()
{
  data da1 = le_data(), da2 = le_data();
  escreve_data(maior_data(da1,da2));

  return 1;
}
