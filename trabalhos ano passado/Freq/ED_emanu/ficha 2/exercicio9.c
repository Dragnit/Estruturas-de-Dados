#include <stdio.h>
#include <stdlib.h>
#define ARRAY_SIZE 100

int thermometerInfo(int date[ARRAY_SIZE],float hour[ARRAY_SIZE],float temperature[ARRAY_SIZE]){
  int i,records=0;
  printf("Quantos registos pretende fazer ?");
  scanf("%d",&records);

  for(i=0;i<records;i++){
    printf("Introduza a data do tipo long long int: ");
    scanf("%d",&date[i]);
    printf("Introduza a hora: ");
    scanf("%f",&hour[i]);
    printf("Introduza a temperatura: ");
    scanf("%f",&temperature[i]);
  }
  return records;
}

int addInfo(int date[ARRAY_SIZE],float hour[ARRAY_SIZE],float temperature[ARRAY_SIZE],int records,int addicionalRecords,int totalRecords){
  int i;
  printf("Insira o numero de registos adicionais que pretende fazer: ");
  scanf("%d",&addicionalRecords);
  totalRecords=records+addicionalRecords;

  for(i=records;i<totalRecords;i++){
    printf("Introduza a data do tipo long long int: ");
    scanf("%d",&date[i]);
    printf("Introduza a hora: ");
    scanf("%f",&hour[i]);
    printf("Introduza a temperatura: ");
    scanf("%f",&temperature[i]);
  }
  return totalRecords;
}

int thermalAmplitude(int date[ARRAY_SIZE],float temperature[ARRAY_SIZE],int totalRecords){
  int searchDate,dateEncounter,highestTemperature=-100,lowestTemperature=100,i,amplitude;

  printf("Introduza a data que pretende pesquisar: ");
  fflush(stdin);
  scanf("%d",&searchDate);

  for(i=0;i<totalRecords;i++){
    if(searchDate==date[i]){
      if(highestTemperature<temperature[i]){
        highestTemperature=temperature[i];
      }
      if(lowestTemperature>temperature[i]){
        lowestTemperature=temperature[i];
      }
    }
  }

 amplitude=highestTemperature-lowestTemperature;
 printf("Amplitude: %d\n",amplitude);
 return amplitude;
}

void averageTemperature(int date[ARRAY_SIZE],float temperature[ARRAY_SIZE],int totalRecords){
  int i,searchDate,dateEncounter;
  float sum=0,average=0;

  printf("Introduza a data que pretende pesquisar: ");
  fflush(stdin);
  scanf("%d",&searchDate);

  for(i=0;i<totalRecords;i++){
    if(searchDate==date[i]){
      sum=sum+temperature[i];
    }
  }
  average=sum/totalRecords;
  printf("Media: %f\n",average);
}

void saveInfo(int date[ARRAY_SIZE],float hour[ARRAY_SIZE],float temperature[ARRAY_SIZE]){
  FILE * info;
  info=fopen("temperaturas.dat","w+b");

  fwrite(date,sizeof(int[ARRAY_SIZE]),1,info);
  fwrite(hour,sizeof(float[ARRAY_SIZE]),1,info);
  fwrite(temperature,sizeof(float[ARRAY_SIZE]),1,info);

  fclose(info);
}

void loadInfo(int date[ARRAY_SIZE],float hour[ARRAY_SIZE],float temperature[ARRAY_SIZE]){
  FILE * load;
  load=fopen("temperaturas.dat","rb");

  fread(date,sizeof(int[ARRAY_SIZE]),1,load);
  fread(hour,sizeof(float[ARRAY_SIZE]),1,load);
  fread(temperature,sizeof(float[ARRAY_SIZE]),1,load);

  fclose(load);
}

int main()
{
char opcao;
int date[ARRAY_SIZE],i;
float hour[ARRAY_SIZE],temperature[ARRAY_SIZE];
int records=0,addicionalRecords=0,totalRecords=0;
loadInfo(date,hour,temperature);

do{
  printf("Menu:\n");
  printf("1-Inserir dados\n");
  printf("2-Acrescentar mais dados\n");
  printf("3-Calculo da Amplitude Termica\n");
  printf("4-Calculo da Media de um determinado dia\n");
  printf("5-Sair\n");
  printf("Introduza a opcao que pretende escolher:");
  fflush(stdin);
  scanf("%c",&opcao);

  switch(opcao){
    case '1':records=thermometerInfo(date,hour,temperature);break;
    case '2':totalRecords=addInfo(date,hour,temperature,records,addicionalRecords,totalRecords);break;
    case '3':thermalAmplitude(date,temperature,totalRecords);break;
    case '4':averageTemperature(date,temperature,totalRecords);break;
    case '5':saveInfo(date,hour,temperature);break;
  }
}while(opcao!='5');

	return 0;
}