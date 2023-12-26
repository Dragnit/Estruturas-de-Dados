#include <stdio.h>
void MostrarNumeros()
{
	int primeirosnumeross[1000];
	FILE * aleat50;
	FILE * aleat100;
	FILE * aleat500;
	FILE * PrimeirosNumeros;

	aleat50=fopen("aleat100.txt","r");
	aleat100=fopen("aleat500.txt","r");
	aleat500=fopen("aleat1000.txt","r");
	PrimeirosNumeros=fopen("PrimeirosNumeros.txt","w+");

	for(int i=0;i<50;i++)
	{
		fscanf(aleat50,"%d",&primeirosnumeross[i]);
	}
	for(int i=0;i<50;i++)
	{
		fprintf(PrimeirosNumeros,"%d ",primeirosnumeross[i]);
	}

	for(int i=0;i<100;i++)
	{
		fscanf(aleat100,"%d",&primeirosnumeross[i]);
	}
	for(int i=0;i<100;i++)
	{
		fprintf(PrimeirosNumeros,"%d ",primeirosnumeross[i]);
	}

	for(int i=0;i<500;i++)
	{
		fscanf(aleat500,"%d",&primeirosnumeross[i]);
	}

	for(int i=0;i<500;i++)
	{
		fprintf(PrimeirosNumeros,"%d ",primeirosnumeross[i]);
	}
	fclose(aleat50);
	fclose(aleat100);
	fclose(aleat500);
	fclose(PrimeirosNumeros);
}
void ParesImpares()
{
		int Numeros[1000];
		FILE * PrimeirosNumeros;
		FILE * NumerosPares;
		FILE * NumerosImpares;

		PrimeirosNumeros=fopen("PrimeirosNumeros.txt", "r");
		NumerosPares=fopen("Pares.txt", "w+");
		NumerosImpares=fopen("Impares.txt", "w+");
		for(int i=0;i<650;i++)
		{
			fscanf(PrimeirosNumeros, "%d", &Numeros[i]);
		}

		for(int i=0;i<650;i++)
		{
			if(Numeros[i]%2==0)
			{
				fprintf(NumerosPares, "%d ", Numeros[i]);
			}
			else
			fprintf(NumerosImpares, "%d ", Numeros[i]);
		}

}

int main()
{
	MostrarNumeros();
	ParesImpares();
}























































































