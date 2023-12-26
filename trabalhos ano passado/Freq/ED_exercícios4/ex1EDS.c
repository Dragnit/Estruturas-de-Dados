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
    data dat;
    printf("Insira a data: ");
    scanf("%d", &dat.dia);
    while(dat.dia>31 || dat.dia<=0)
    {
        printf("\ndia invalido, tente novamente: ");
        scanf("%d", &dat.dia);
    }

    scanf("%d", &dat.mes);
    while(dat.mes<=0 || dat.mes>12)
    {
        printf("\nmes invalido, tente novamente: ");
        scanf("%d", &dat.mes);
    }

    scanf("%d", &dat.ano);
    return dat;
}
void escreve_data(data d)
{
    printf("Data: %d-%d-%d", d.dia, d.mes, d.ano);
}
char compara_datas(data dat, data datt)
{
    if(dat.ano>datt.ano)
        return '>';
    else
        if(dat.ano == datt.ano)
        {
            if(dat.mes>datt.mes)
                return '>';
            else
                if(dat.mes == datt.mes)
                {
                    if(dat.dia>datt.dia)
                        return '>';
                    else
                        return '=';
                }
        }
    else
        return '<';
}

data maior_data(data dat, data datt)
{
    if(dat.ano>datt.ano)
        return dat;
    else
    if(dat.ano == datt.ano)
    {
        if(dat.mes>datt.mes)
            return dat;
        else
        if(dat.mes == datt.mes)
        {
            if(dat.dia>datt.dia)
                return dat;
            else
                return dat;
        }
    }
    else
        return datt;
}

void main()
{
    data dat, datt;
    dat = le_data();
    datt = le_data();
    escreve_data(dat);
    printf("\n");
    escreve_data(datt);
    compara_datas(dat, datt);
    if(compara_datas(dat, datt) == '>')
    printf("\nPrimeira data e maior");
    else
        if(compara_datas(dat, datt)=='=')
        printf("\nDatas iguais");
    else
        printf("\nSegunda data e maior");

    printf("\nO resultado da funcao \"maior_data\" e: ");
    printf("\n");
    escreve_data(maior_data(dat, datt));
}