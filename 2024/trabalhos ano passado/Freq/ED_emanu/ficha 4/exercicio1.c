#include <stdio.h>

typedef struct estrutura_data{
  int dia;
  int mes;
  int ano;
}data;

data le_data(){
  data estrutura;
  printf("Insira o dia:\n");
  scanf("%d",&estrutura.dia);

  if(estrutura.dia<1 || estrutura.dia>31){
    printf("Dia Invalido!\nInsira novamente o dia:\n");
    scanf("%d",&estrutura.dia);
  }

  printf("Insira o mes:\n");
  scanf("%d",&estrutura.mes);

  if(estrutura.mes<1 || estrutura.mes>12){
    printf("Mes inexistente!\nInsira novamente o mes:\n");
    scanf("%d",&estrutura.mes);
  }
  printf("Insira o ano:\n");
  scanf("%d",&estrutura.ano);

  return estrutura;
}

void escreve_data(data estrutura){
  printf("%d-%d-%d\n",estrutura.dia,estrutura.mes,estrutura.ano);
}

char compara_datas(data d1,data d2){
  if(d1.ano>d2.ano){
    return '>';
  }else{
    if(d1.ano<d2.ano){
      return '<';
    }
}
    if(d1.ano==d2.ano){
      if(d1.mes>d2.mes){
        return '>';
      }else{
        if(d1.mes<d2.mes){
          return '<';
        }
      }
    }

    if(d1.ano==d2.ano){
      if(d1.mes==d2.mes){
        if(d1.dia>d2.dia){
          return '>';
        }else{
          if(d1.dia<d1.dia){
            return '<';
          }
        }
      }
    }

    if(d1.ano==d2.ano){
      if(d1.mes==d2.mes){
        if(d1.dia==d2.dia){
          return '=';
        }
      }
    }
}

data maior_data(data d1,data d2){
  if(d1.ano<d2.ano){
    return d2;
  }else{
    if(d1.ano>d2.ano){
      return d1;
    }
  }

  if(d1.ano==d2.ano){
    if(d1.mes<d2.mes){
      return d2;
    }else{
      if(d1.mes>d2.mes){
        return d1;
      }
    }
  }

  if(d1.ano==d2.ano){
    if(d1.mes==d2.mes){
      if(d1.dia<d2.dia){
        return d2;
      }else{
        return d1;
      }
    }
  }
}
int main()
{
data d1,d2;

d1=le_data();
d2=le_data();
escreve_data(d1);
compara_datas(d1,d2);

if(compara_datas(d1,d2)=='='){
  printf("As datas são iguais\n");
}else{
  if(compara_datas(d1,d2)=='<'){
    printf("Primeira data anterior a segunda data\n");
  }else{
    if(compara_datas(d1,d2)=='>'){
        printf("Primeira data posterior a segunda data\n");
    }
  }
}

escreve_data(maior_data(d1,d2));
	return 0;
}