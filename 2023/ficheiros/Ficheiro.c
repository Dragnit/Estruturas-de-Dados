#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void criaFicheiro()
{
    char ficheiro[50], texto[100];

    printf("Insira o nome do ficheiro que pretende criar: ");
    scanf("%s", ficheiro);
    fflush(stdin);

    FILE * fp = fopen(ficheiro, "w");
    
    printf("Insira uma frase: ");
    fgets(texto, 100, stdin);
    fputs(texto, fp);

    fclose(fp);
}

void acrescentaFicheiro()
{
    char texto[50], ficheiro[50];
    printf("Insira o nome do ficheiro: ");
    scanf("%s", ficheiro);
    fflush(stdin);

    FILE * fp = fopen(ficheiro,"a");

    if(fp == NULL)
    {
        printf("Ficheiro nao existente\n");
        return;
    }
    else
    {
        printf("Ficheiro aberto com sucesso\n");
        
        printf("Insira a frase a acrescentar: ");
        fgets(texto, 100, stdin);
        fprintf(fp, "%s", texto);

        fclose(fp);

    }
}

void contaLinhas()
{
    int linhas = 0;
    char nLinhas [50];
    char ficheiro[50], ch;

    printf("insira o nome do ficheiro: ");
    scanf("%s", ficheiro);

    FILE * fp = fopen(ficheiro, "r");

    if(fp == NULL)
    {
        printf("nao foi possivel abrir o ficheiro ");
        return;
    }

    while(fgets(nLinhas, sizeof(nLinhas), fp) != NULL)
    {   
        linhas++;
    }

    fclose(fp);

    printf("O numero de linhas e: %d", linhas);
}

void contaLetras()
{
    char ficheiro[50];
    int chars = 0;
    char ch;

    printf("insira o nome do ficheiro: ");
    scanf("%s", ficheiro);

    FILE * fp = fopen(ficheiro, "r");

    if(fp == NULL)
    {
        printf("nao foi possivel abrir o ficheiro ");
        return;
    }

    while ((ch = fgetc(fp)) != EOF) {
        chars++;
    }

    printf("%d", chars);
}

void contaPalavras()
{
    char ficheiro[50];
    int palavras = 0;
    char ch;
    int nPalavras = 0;

    printf("insira o nome do ficheiro: ");
    scanf("%s", ficheiro);

    FILE * fp = fopen(ficheiro, "r");

    if(fp == NULL)
    {
        printf("nao foi possivel abrir o ficheiro ");
        return;
    }

    while ((ch = fgetc(fp)) != EOF) {
        if (isspace(ch)) {
            nPalavras = 0;
        } else if (!nPalavras) {
            nPalavras = 1;
            palavras++;
        }
    }

    printf("%d", palavras);
}

int main()
{
    int a = 0;

    printf("Insira a opcao (1 para criar ficheiro, 2 para acrescentar, 3 para contar linhas, 4 para contar letras, 5 para contar palavras): ");
    scanf("%d", &a);

    getchar(); // consome o caractere de nova linha

    switch(a)
    {
    case 1 :criaFicheiro(); break;
    case 2 :acrescentaFicheiro(); break;
    case 3 :contaLinhas(); break;
    case 4 :contaLetras(); break;
    case 5 :contaPalavras(); break;
    default:
        printf("Opcao invalida\n");
        break;
    }

    return 0;
}