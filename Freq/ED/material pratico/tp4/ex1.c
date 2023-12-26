#include <stdio.h>

struct estrutura_data
{
  int dia;
  int mes;
  int ano;
};
typedef struct estrutura_data data;

data le_data()
{
  data d;

  printf("\nDia: ");
  scanf("%d",&d.dia);
  printf("\nMes: ");
  scanf("%d",&d.mes);
  printf("\nAno: ");
  scanf("%d",&d.ano);

  return d;

}

void escreve_data(data d)
{
  printf("\n%d-%d-%d\n",d.dia,d.mes,d.ano);
}

char compara_datas(data d1, data d2)
{
  if(d1.ano < d2.ano){
    printf("\n1a data e anterior a 2a\n");
    return '<';}
    else
    if (d1.ano > d2.ano){
      printf("\n1a data e posterior a 2a\n");
      return '>';}

      if (d1.ano == d2.ano)
      {
        if (d1.mes<d2.mes){
          printf("\n1a data e anterior a 2a\n");
          return '<';}
          else
          if (d1.mes>d2.mes){
            printf("\n1a data e posterior a 2a\n");
            return '>';}
            else
            if (d1.dia<d2.dia){
              printf("\n1a data e anterior a 2a\n");
              return '<';}
              else
              if(d1.dia>d2.dia){
                printf("\n1a data e posterior a 2a\n");
                return '>';}
                else
                printf("\nas duas datas sao iguais\n");
                return '=';
              }
            }

            data maior_data(data d1, data d2)
            {
              if(d1.ano < d2.ano){
                printf("\n2a data e maior\n");
              }
              else
              if (d1.ano > d2.ano){
                printf("\n1a data e maior\n");
              }

              if (d1.ano == d2.ano)
              {
                if (d1.mes<d2.mes){
                  printf("\n2a data e maior\n");
                }
                else
                if (d1.mes>d2.mes){
                  printf("\n1a data e maior\n");
                }
                else
                if (d1.dia<d2.dia){
                  printf("\n2a data e maior\n");
                }
                else
                if(d1.dia>d2.dia){
                  printf("\n1a data e maior\n");
                }
                else
                printf("\nas duas datas sao iguais\n");
                ;
              }
            }
            // testa as funcoes anteriores
            int main()
            {
              data dat1, dat2;
              dat1 = le_data();
              dat2 = le_data();
              escreve_data(dat1);
              escreve_data(dat2);
              compara_datas(dat1,dat2);
              maior_data(dat1,dat2);

              return 0;
            }
