#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
//Exercício 1 (criar as estruturas)
typedef struct dataa *plista;
typedef struct dataa{
    char data[200];
    float Co2;
    float humidade;
    float producao;
    float temperatura;
    float energia;
    plista prox;
}dados;

typedef struct maquina{
    char nome[200];
    plista pprox;
}nomesmaquinas;

int ContaLista(plista lst)
{
    int count = 0;
    while(lst!=NULL)
    {
        count++;
        lst = lst->prox;
    }
    return count;
}

//Exercício 2

//alínea a
int InsereMaquinas(nomesmaquinas ArrayNomes[200], int count)
{
    int qnt;

    printf("\nInsira o numero de maquinas que pretende:");
    scanf("%d", &qnt);
    for(int i=0;i<qnt;i++)
    {
        printf("\nInsira o nome da %d maquina:\n", i+1);
        fflush(stdin);
        gets(ArrayNomes[count].nome);
        ArrayNomes[count].pprox = NULL;
        count++;
    }
    return count;
}

void InsereDados(int count, nomesmaquinas ArrayNomes[200])
{
    char maquina[100];
    time_t data;
    char DataAux[200];
    plista no = (plista)malloc(sizeof(dados));
    time(&data);
    printf("\nInsira o nome da maquina onde quer colocar os dados: ");
    fflush(stdin);
    gets(maquina);
    if(no==NULL)
        printf("\nNao ha memoria disponivel!");
    else {
        for (int i = 0; i < count; i++)
        {
            if(strcmp(ArrayNomes[i].nome, maquina)==0)
            {
                printf("\nInsira a quantidade de Co2 da maquina: ");
                scanf("%f", &no->Co2);
                printf("\nInsira a quantidade de energia produzida pela maquina: ");
                scanf("%f", &no->energia);
                printf("\nInsira a temperatura da maquina: ");
                scanf("%f", &no->temperatura);
                printf("\nInsira a quantidade produzida pela maquina: ");
                scanf("%f", &no->producao);
                printf("\nInsira a humidade da maquina atualmente: ");
                scanf("%f", &no->humidade);
                strcpy(DataAux, ctime(&data));
                DataAux[24] = '\0';
                strcpy(no->data, DataAux);
                no->prox = ArrayNomes[i].pprox;
                ArrayNomes[i].pprox = no;
            }
        }
    }
}

//alínea b
void ApresentaDados(int count, nomesmaquinas ArrayNomes[200])
{
    plista aux = NULL;
    for(int i=0;i<count;i++)
    {
        printf("\n\nNome da maquina: %s", ArrayNomes[i].nome);
        aux = ArrayNomes[i].pprox;
        while(aux!=NULL)
        {
            printf("\nQuantidade de Co2 libertada pela maquina: %.1f", aux->Co2);
            printf("\nQuantidade de energia produzida pela maquina: %.1f", aux->energia);
            printf("\nQuantidade de humidade da maquina: %.1f", aux->humidade);
            printf("\nIndices de producao da maquina: %.1f", aux->producao);
            printf("\nTemperatura atual da maquina: %.1f", aux->temperatura);
            printf("\nData: %s\n", aux->data);
            aux = aux->prox;
        }
    }
}

//alínea c
void GuardarDados(int count, nomesmaquinas ArrayNomes[200]){
    FILE * gravardados;
    plista aux = NULL;
    int n = 0;

    gravardados = fopen("dados.dat","wb");

    fwrite(&count,sizeof(int),1,gravardados);
    for(int i=0;i<count;i++){

        fwrite(&ArrayNomes[i].nome, sizeof(char)*20 , 1 , gravardados);
        n = ContaLista(ArrayNomes[i].pprox);
        fwrite(&n, sizeof(int), 1, gravardados);
        aux = ArrayNomes[i].pprox;
        while(aux != NULL){
            fwrite(aux, sizeof(dados) , 1 , gravardados);
            aux = aux->prox;
        }
    }
    fclose(gravardados);
}

//alínea d
int CarregarDados(nomesmaquinas ArrayNomes[200])
{
    FILE * carregardados;
    carregardados = fopen("dados.dat", "rb");
    if(carregardados == NULL) {
        printf("\nFicheiro nao existe!");
        fclose(carregardados);
        return 0;
    }
    else {
        plista no;
        int AuxCount;
        int n = 0;
        fread(&AuxCount,sizeof(int),1,carregardados);
        for (int i = 0; i < AuxCount; i++) {

            fread(&ArrayNomes[i].nome, sizeof(char) * 20, 1, carregardados);
            fread(&n, sizeof(int), 1, carregardados);
            ArrayNomes[i].pprox = NULL;

            for (int j = 0; j < n; j++) {
                no = (plista) malloc(sizeof(dados));
                fread(no, sizeof(dados), 1, carregardados);
                no->prox = ArrayNomes[i].pprox;
                ArrayNomes[i].pprox = no;
            }
        }

        fclose(carregardados);
        return AuxCount;
    }
}

//alínea e
void RetiraMomento(int count, nomesmaquinas ArrayNomes[200])
{
    char stringdata[200];

    printf("\nInsira o momento cujos dados pretende retirar (ex: Fri Jun 26 18:47:47 2020):");
    fflush(stdin);
    gets(stringdata);

    plista aux = NULL;
    plista paux = NULL;
    for(int i=0;i<count;i++)
    {
        aux = ArrayNomes[i].pprox;
        while(aux!=NULL)
        {
            if(strcmp(aux->data, stringdata) == 0)
            {
                if(paux!=NULL)
                    paux->prox = aux->prox;
                else {
                    ArrayNomes[i].pprox = aux->prox;
                }
                free(aux);
            }
            paux = aux;
            aux = aux->prox;
        }
    }
}

//alínea f
void ContaFalhas(int count, nomesmaquinas ArrayNomes[200])
{
    int contador = 0;
    plista aux = NULL;
    for(int i=0;i<count;i++)
    {
        aux = ArrayNomes[i].pprox;
        while(aux!=NULL) {

            if (aux->energia == 0 && aux->producao == 0 && aux->humidade == 0 && aux->Co2 == 0 && aux->temperatura == 0) {
                strcpy(aux->data, "0");
                contador++;
            }
            aux = aux->prox;
        }
        printf("\nMaquina %s: ", ArrayNomes[i].nome);
        printf("\nNumero de erros desta maquina: %d", contador);
        contador = 0;
    }
}

//alínea g
void RetiraFalhas(int count, nomesmaquinas ArrayNomes[200])
{
    plista aux = NULL;
    plista paux = NULL;
    for(int i=0;i<count;i++)
    {
        aux = ArrayNomes[i].pprox;
        while(aux!=NULL)
        {
            if(aux->energia == 0 && aux->producao == 0 && aux->humidade == 0 && aux->Co2 == 0 && aux->temperatura == 0 && (strcmp(aux->data, "0") == 0))
            {
                if(paux!=NULL)
                    paux->prox = aux->prox;
                else {
                    ArrayNomes[i].pprox = aux->prox;
                }
                free(aux);
            }
            paux = aux;
            aux = aux->prox;
        }
    }
}

//alínea h
void ProcuraCriterios(int count, nomesmaquinas ArrayNomes[200])
{
    plista aux = NULL;
    for(int i = 0;i<count;i++)
    {
        aux = ArrayNomes[i].pprox;
        while(aux!=NULL) {
            if (aux->temperatura > 40 && aux->producao > 200) {
                printf("\n\nMaquina com os criterios encontrada! Nome: %s", ArrayNomes[i].nome);
                printf("\nQuantidade de Co2 libertada pela maquina: %.1f", aux->Co2);
                printf("\nQuantidade de energia produzida pela maquina: %.1f", aux->energia);
                printf("\nQuantidade de humidade da maquina: %.1f", aux->humidade);
                printf("\nIndices de producao da maquina: %.1f", aux->producao);
                printf("\nTemperatura atual da maquina: %.1f", aux->temperatura);
                printf("\nData: %s", aux->data);
            }
            else
                printf("\nNao ha maquinas com esses criterios!");
            aux = aux->prox;
        }
    }
}


//funções auxiliares para a alínea i
void DaValor(char *inicial, char *hora, char *dia, char *mes, char *ano) {

    char aux[30];
    strcpy(aux, inicial);
    strtok(aux, " ");//DS
    strcpy(mes, strtok(NULL, " "));
    strcpy(dia, strtok(NULL, " "));
    strcpy(hora, strtok(NULL, " "));
    strcpy(ano, strtok(NULL, " "));
}

void Switch(plista * lst1, plista * lst2)//c: coloquei *
{
    plista aux = (plista)malloc(sizeof(dados));

    strcpy(aux->data, (*lst1)->data);
    aux->producao = (*lst1)->producao;
    aux->energia = (*lst1)->energia;
    aux->Co2 = (*lst1)->Co2;
    aux->humidade = (*lst1)->humidade;
    aux->temperatura = (*lst1)->temperatura;
    aux->prox=(*lst1)->prox;

    strcpy((*lst1)->data, (*lst2)->data);
    (*lst1)->producao = (*lst2)->producao;
    (*lst1)->energia = (*lst2)->energia;
    (*lst1)->Co2 = (*lst2)->Co2;
    (*lst1)->humidade = (*lst2)->humidade;
    (*lst1)->temperatura = (*lst2)->temperatura;
    (*lst1)->prox=(*lst2)->prox;

    strcpy((*lst2)->data, aux->data);
    (*lst2)->producao = aux->producao;
    (*lst2)->energia = aux->energia;
    (*lst2)->Co2 = aux->Co2;
    (*lst2)->humidade = aux->humidade;
    (*lst2)->temperatura= aux->temperatura;
    (*lst2)->prox=aux->prox;
    free(aux);
}
//alínea i
void OrdenaDataCrescente(int count, nomesmaquinas ArrayNomes[200])
{
    plista aux = NULL, aux1 = NULL;
    char hora1[15], hora2[15], dia1[6], mes1[6], ano1[6], dia2[6], mes2[6], ano2[6];
    for(int i=0;i<count;i++)
    {
        aux = ArrayNomes[i].pprox;
        aux1=aux->prox;
        while(aux != NULL && aux1!= NULL)
        {
            DaValor(aux->data, hora1, dia1, mes1, ano1);
            DaValor(aux1->data, hora2, dia2, mes2, ano2);

            if(strcmp(ano1, ano2)>0)
                Switch(&aux, &aux1);//c:&
            else
            if(strcmp(ano1, ano2) == 0)
            {
                if(strcmp(mes1, mes2) > 0)
                    Switch(&aux, &aux1);//c:&
            }
            else
            if(strcmp(ano1, ano2) == 0 && strcmp(mes1, mes2) == 0)
            {
                if(strcmp(dia1, dia2)>0)
                    Switch(&aux,&aux1);//c:&
                else if(strcmp(hora1, hora2)>0)
                    Switch(&aux, &aux1);//c:&
            }
            aux = aux->prox;
            aux1 = aux1->prox;

        }
    }
}


//alínea j
int GravaCsv(int count, nomesmaquinas ArrayNomes[200])
{
    FILE *f = fopen("data.csv", "w");
    plista aux = NULL;
    if(f == NULL)
        return -1;
    else
        for(int i=0;i<count;i++)
        {
            aux = ArrayNomes[i].pprox;

            fprintf(f, "\nMaquina:; ");
            fprintf(f, "%s;", ArrayNomes[i].nome);
            fprintf(f, "\n\n");
            while (aux != NULL)
            {
                fprintf(f, "Data/Hora;Temperatura;Humidade;CO2 emitido;Energia;Producao;");
                fprintf(f, "\n");
                fprintf(f, "%s;%.1f;%.1f;%.1f;%.1f;%.1f", aux->data, aux->temperatura, aux->humidade, aux->Co2, aux->energia, aux->producao);
                aux = aux->prox;
            }
        }
    fclose(f);
    return 1;//c
}
void main()
{
    int count = 0;
    int opcao = -1, AuxCount;
    nomesmaquinas ArrayNomes[200];
    AuxCount = CarregarDados(ArrayNomes);

    while(opcao!=0) {
        fflush(stdin);
        printf("\n\n1.Inserir maquinas.");
        printf("\n2.Inserir dados.");
        printf("\n3.Apresentar dados das maquinas.");
        printf("\n4.Guardar os dados num ficheiro binario.");
        printf("\n5.Eliminar os dados num momento pedido pelo utilizador.");
        printf("\n6.Contar as falhas das maquinas.");
        printf("\n7.Retirar registos de falhas.");
        printf("\n8.Procurar consoante dois criterios (Temperatura maior que 40 e producao acima de 200).");
        printf("\n9.Ordenar a lista por ordem crescente das datas.");
        printf("\n10.Guardar em ficheiros csv.");
        printf("\n0.Sair do programa");
        printf("\nEscolha a opcao que pretende: ");
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                AuxCount = InsereMaquinas(ArrayNomes, count);
                break;
            case 2:
                InsereDados(AuxCount, ArrayNomes);
                break;
            case 3:
                ApresentaDados(AuxCount, ArrayNomes);
                break;
            case 4:
                GuardarDados(AuxCount, ArrayNomes);
                printf("\nDados guardados com sucesso!");
                break;
            case 5:
                RetiraMomento(AuxCount, ArrayNomes);
                break;
            case 6:
                ContaFalhas(AuxCount, ArrayNomes);
                break;
            case 7:
                RetiraFalhas(AuxCount, ArrayNomes);
                printf("\nFalhas retiradas!");
                break;
            case 8:
                ProcuraCriterios(AuxCount, ArrayNomes);
                break;
            case 9:
                OrdenaDataCrescente(AuxCount, ArrayNomes);
                break;
            case 10:
                GravaCsv(AuxCount, ArrayNomes);
                break;
            case 0:
                break;
            default:
                printf("\nOpcao invalida!");
        }
    }
}