#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int Cresc(int quantidade)
{
	FILE * fp;
	char ficheiro[100]="cresc";
	snprintf(ficheiro, sizeof ficheiro, "%s%d", ficheiro, quantidade);
	strcat(ficheiro, ".txt");
	fp = fopen(ficheiro, "w");
	if (fp == NULL)
	{
		printf("Erro ao abrir o ficheiro\n");
	}
	else
	{
		for(int i=1;i<quantidade+1;i++)
		fprintf(fp, "%d ", i);
	}
	fclose(fp);
}

int Decrescente(int quantidade)
{
	FILE * fp;
	char ficheiro[100]="decr";
	snprintf(ficheiro, sizeof ficheiro, "%s%d", ficheiro, quantidade);
	strcat(ficheiro, ".txt");
	fp = fopen(ficheiro, "w");
	if (fp == NULL)
	{
		printf("Erro ao abrir o ficheiro\n");
	}
	else
	{
		for(int i=quantidade ;i>0; i--)
		fprintf(fp, "%d ", i);
	}
	fclose(fp);
}

int aleat(int quantidade)
{
	FILE * fp;
	int c;
	char ficheiro[100]="aleat";
	snprintf(ficheiro, sizeof ficheiro, "%s%d.txt", ficheiro, quantidade);
	fp = fopen(ficheiro, "w+");
	if (fp == NULL)
	{
		printf("Erro ao abrir o ficheiro\n");
	}
	else
	{
		for(int i=1; i<quantidade; i++)
		{
			fprintf(fp, "%d ", rand() % quantidade+1);
		}
	}
	fclose(fp);
}
int main(int argc , char * argv[])
{
	int quantidade;
	printf("Quantos numeros pretende ter nos seus ficheiros?\n");
	scanf("%d", &quantidade);
	Cresc(quantidade);
	Decrescente(quantidade);
	aleat(quantidade);
}

























































































































