#include <stdio.h>
#define TAMANHO 5000

void firstXNumbers(){
	int i;
	int xNumbersArray[TAMANHO];
	FILE * random50Numbers;
	FILE * random100Numbers;
	FILE * random500Numbers;
	FILE * firstXNumbers;

	random50Numbers=fopen("randomOrder100.txt","r");
	random100Numbers=fopen("randomOrder500.txt","r");
	random500Numbers=fopen("randomOrder1000.txt","r");
	firstXNumbers=fopen("firstXNumbers.txt","w+");

	for(i=0;i<50;i++){
		fscanf(random50Numbers,"%d ",&xNumbersArray[i]);
	}

	for(i=0;i<50;i++){
		fprintf(firstXNumbers,"%d ",xNumbersArray[i]);
	}

	for(i=0;i<100;i++){
		fscanf(random100Numbers,"%d ",&xNumbersArray[i]);
	}

	for(i=0;i<100;i++){
		fprintf(firstXNumbers,"%d ",xNumbersArray[i]);
	}

	for(i=0;i<500;i++){
		fscanf(random500Numbers,"%d ",&xNumbersArray[i]);
	}

	for(i=0;i<500;i++){
		fprintf(firstXNumbers,"%d ",xNumbersArray[i]);
	}
	fclose(random50Numbers);
	fclose(random100Numbers);
	fclose(random500Numbers);
	fclose(firstXNumbers);
}

void oddNumbers(){
	int i;
	int oddNumbersArray[TAMANHO];
	FILE * firstXNumbers;
	FILE * oddNumbers;
	firstXNumbers=fopen("firstXNumbers.txt","r");
	oddNumbers=fopen("Pares.txt","w+");

	for(i=0;i<650;i++){
		fscanf(firstXNumbers,"%d ",&oddNumbersArray[i]);
	}

	for(i=0;i<650;i++){
		if(oddNumbersArray[i]%2==0){
			fprintf(oddNumbers,"%d ",oddNumbersArray[i]);
		}
	}
	fclose(oddNumbers);
	fclose(firstXNumbers);
}

void evenNumbers(){
	int i;
	int evenNumbersArray[TAMANHO];
	FILE * firstXNumbers;
	FILE * evenNumbers;
	firstXNumbers=fopen("firstXNumbers.txt","r");
	evenNumbers=fopen("Impares.txt","w+");

	for(i=0;i<650;i++){
		fscanf(firstXNumbers,"%d ",&evenNumbersArray[i]);
	}

	for(i=0;i<650;i++){
		if(evenNumbersArray[i]%2 != 0){
			fprintf(evenNumbers,"%d ",evenNumbersArray[i]);
		}
	}
	fclose(evenNumbers);
	fclose(firstXNumbers);
}
int main()
{
firstXNumbers();
printf("Numeros inseridos com sucesso no ficheiro firstXNumbers\n");
oddNumbers();
printf("Numeros Pares inseridos com sucesso no ficheiro Pares\n");
evenNumbers();
printf("Numero Impares inseridos com sucesso no ficheiro Impares");

	return 0;
}