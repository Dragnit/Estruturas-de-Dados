#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define TAMANHO 5
#define TAMANHO_DATA 30

typedef struct dados *plista;

typedef struct dados{
	char data[TAMANHO_DATA];
	float humidade;
	float qtdCO2;
	float qtdProduzida;
	float energiaConsumida;
	float temperatura;
	plista prox;
}dadosMaquina;

typedef struct maquina{
	char nomeMaquina[TAMANHO_DATA];
	plista auxProx;
}auxMaquina;

int insere_Maquina(auxMaquina array_nome_Maquinas[TAMANHO],int contador){
	for(int i=0;i<TAMANHO;i++){
		printf("Insira o nome da maquina:\n");
		fflush(stdin);
		gets(array_nome_Maquinas[contador].nomeMaquina);
		array_nome_Maquinas[contador].auxProx=NULL;
		contador++;
	}
	return contador;
}

void insere_Dados_Maquina(int contador,auxMaquina array_nome_Maquinas[TAMANHO]){
	char auxNome[TAMANHO_DATA];
	time_t auxData;
	char dataTemp[TAMANHO_DATA];
	float auxDados;
	plista no=(plista)malloc(sizeof(dadosMaquina));
	time(&auxData);

	printf("Insira o nome da maquina em que pretende inserir os dados:\n");
	fflush(stdin);
	gets(auxNome);

	if(no==NULL){
		printf("Erro!!!Memoria indisponivel...");
	}else{
		for(int i=0;i<contador;i++){
			if(strcmp(array_nome_Maquinas[i].nomeMaquina,auxNome)==0){
				printf("Insira a temperatura da maquina:\n");
				scanf("%f",&auxDados);
				no->temperatura=auxDados;
				printf("Insira a humidade da maquina:\n");
				scanf("%f",&auxDados);
				no->humidade=auxDados;
				printf("Insira a quantidade de CO2:\n");
				scanf("%f",&auxDados);
				no->qtdCO2=auxDados;
				printf("Insira a quantidade Produzida:\n");
				scanf("%f",&auxDados);
				no->qtdProduzida=auxDados;
				printf("Insira a energia consumida pela maquina:\n");
				scanf("%f",&auxDados);
				no->energiaConsumida=auxDados;
				strcpy(dataTemp,ctime(&auxData));
				dataTemp[24]='\0';
				strcpy(no->data,dataTemp);
				no->prox=array_nome_Maquinas[i].auxProx;
				array_nome_Maquinas[i].auxProx=no;
			}
		}
	}
}

void escreve_Dados(int contador,auxMaquina array_nome_Maquinas[TAMANHO]){
	plista auxPonteiro=NULL;
	for(int i=0;i<contador;i++){
		printf("Nome da maquina:%s\n",array_nome_Maquinas[i].nomeMaquina);
		auxPonteiro=array_nome_Maquinas[i].auxProx;
		while(auxPonteiro !=NULL){
			printf("Temperatura da maquina:%0.1f\n",auxPonteiro->temperatura);
			printf("Humidade da maquina:%0.1f\n",auxPonteiro->humidade);
			printf("Quantidade de CO2:%0.1f\n",auxPonteiro->qtdCO2);
			printf("Quantidade Produzida:%0.1f\n",auxPonteiro->qtdProduzida);
			printf("Quantidade de energia consumida:%0.1f\n",auxPonteiro->energiaConsumida);
			printf("Data:%s\n",auxPonteiro->data);
			auxPonteiro=auxPonteiro->prox;
		}
	}
}

void conta_Falhas(int contador,auxMaquina array_nome_Maquinas[TAMANHO]){
	char auxFalha[TAMANHO_DATA]="0";
	int auxContaFalhas=0;
	plista auxPonteiro=NULL;
	for(int i=0;i<contador;i++){
		printf("Nome da maquina:%s\n",array_nome_Maquinas[i].nomeMaquina);
		auxPonteiro=array_nome_Maquinas[i].auxProx;
		while(auxPonteiro !=NULL){
			if(auxPonteiro->temperatura==0 && auxPonteiro->humidade==0 && auxPonteiro->qtdCO2==0 && auxPonteiro->qtdProduzida==0 && auxPonteiro->energiaConsumida==0){
				strcpy(auxPonteiro->data,auxFalha);
				printf("Falha detetada!\n");
				auxContaFalhas++;
			}
			printf("Numero de falhas: %d\n",auxContaFalhas);
			auxPonteiro=auxPonteiro->prox;
		}
	}
}

void grava_dados(int contador,auxMaquina array_nome_Maquinas[TAMANHO]){
	FILE * gravaD;
	plista auxPonteiro=NULL;

	gravaD=fopen("Dados.dat","wb");

	fwrite(&contador,sizeof(int),1,gravaD);
	for(int i=0;i<contador;i++){
		fwrite(&array_nome_Maquinas[i].nomeMaquina,sizeof(char)*TAMANHO_DATA,1,gravaD);
		auxPonteiro=array_nome_Maquinas[i].auxProx;
		while(auxPonteiro!=NULL){
			fwrite(auxPonteiro,sizeof(dadosMaquina),1,gravaD);
			auxPonteiro=auxPonteiro->prox;
		}
	}
	fclose(gravaD);
}

int carrega_Dados(auxMaquina array_nome_Maquinas[TAMANHO]){
	FILE * carregaD;
	plista auxPonteiro=NULL,no;
	carregaD=fopen("Dados.dat","rb");
	if(carregaD==NULL){
		printf("Ficheiro nao existe!\n");
		fclose(carregaD);
		return 0;
	}else{
		int auxContador;
		fread(&auxContador,sizeof(int),1,carregaD);
		printf("%d",auxContador);
		for(int i=0;i<auxContador;i++){
			fread(&array_nome_Maquinas[i].nomeMaquina,sizeof(char)*TAMANHO_DATA,1,carregaD);
			array_nome_Maquinas[i].auxProx=NULL;
			printf("%s",array_nome_Maquinas[i].nomeMaquina);
			auxPonteiro=array_nome_Maquinas[i].auxProx;
			while(auxPonteiro != NULL){
				no=(plista)malloc(sizeof(dadosMaquina));
				fread(no,sizeof(dadosMaquina),1,carregaD);
				printf("%0.1f",no->temperatura);
				no->prox=array_nome_Maquinas[i].auxProx;
				array_nome_Maquinas[i].auxProx=no;
				auxPonteiro=auxPonteiro->prox;
			}
		}
		fclose(carregaD);
		return auxContador;
	}
}

void pesquisa_Dados(int contador,auxMaquina array_nome_Maquinas[TAMANHO]){
	plista auxPonteiro=NULL;
	for(int i=0;i<contador;i++){
		auxPonteiro=array_nome_Maquinas[i].auxProx;
		while(auxPonteiro!=NULL){
			if(auxPonteiro->temperatura>40 && auxPonteiro->qtdProduzida>200){
				printf("Maquinas que verificam os dois criterios:\n");
				printf("Nome da maquina:%s\n",array_nome_Maquinas[i].nomeMaquina);
				printf("Temperatura da maquina:%0.1f\n",auxPonteiro->temperatura);
				printf("Humidade da maquina:%0.1f\n",auxPonteiro->humidade);
				printf("Quantidade de CO2:%0.1f\n",auxPonteiro->qtdCO2);
				printf("Quantidade Produzida:%0.1f\n",auxPonteiro->qtdProduzida);
				printf("Quantidade de energia consumida:%0.1f\n",auxPonteiro->energiaConsumida);
				printf("Data: %s\n",auxPonteiro->data);
			}
			auxPonteiro=auxPonteiro->prox;
		}
	}
}

void remove_Falhas(int contador,auxMaquina array_nome_Maquinas[TAMANHO]){
	plista auxPonteiro=NULL;
	plista auxRemove=NULL;
	for(int i=0;i<contador;i++){
		auxPonteiro=array_nome_Maquinas[i].auxProx;
		while(auxPonteiro !=NULL){
			if(auxPonteiro->temperatura==0 && auxPonteiro->humidade==0 && auxPonteiro->qtdCO2==0 && auxPonteiro->qtdProduzida==0 && auxPonteiro->energiaConsumida==0 && strcmp(auxPonteiro->data,"0")==0){
				if(auxRemove!=NULL){
					auxRemove->prox=auxPonteiro->prox;
				}else{
					array_nome_Maquinas[i].auxProx=auxPonteiro->prox;
				}
				free(auxPonteiro);
			}
			auxRemove=auxPonteiro;
			auxPonteiro=auxPonteiro->prox;
		}
	}
}

void remove_Dados(int contador,char pesquisaData[TAMANHO],auxMaquina array_nome_Maquinas[TAMANHO]){
	plista auxPonteiro=NULL;
	plista auxRemove=NULL;
	for(int i=0;i<contador;i++){
		auxPonteiro=array_nome_Maquinas[i].auxProx;
		while(auxPonteiro!=NULL){
			if(strcmp(auxPonteiro->data,pesquisaData)==0){
				if(auxRemove!=NULL){
					auxRemove->prox=auxPonteiro->prox;
				}else{
					array_nome_Maquinas[i].auxProx=auxPonteiro->prox;
				}
				free(auxPonteiro);
			}
			auxRemove=auxPonteiro;
			auxPonteiro=auxPonteiro->prox;
		}
	}
}

void grava_Dados_csv(int contador, auxMaquina array_nome_Maquinas[TAMANHO]){
	plista auxPonteiro=NULL;
	FILE * gravaD;
	gravaD=fopen("DadosExcel.csv","w+");

	for(int i=0;i<contador;i++){
		fprintf(gravaD,"Maquina:;%s\n",array_nome_Maquinas[i].nomeMaquina);
		auxPonteiro=array_nome_Maquinas[i].auxProx;
		while(auxPonteiro!=NULL){
			fprintf(gravaD,"Data/hora;Temperatura;Humidade;CO2 Emitido;Energia;Producao\n");
			fprintf(gravaD,"%s;%0.1f;%0.1f;%0.1f;%0.1f;%0.1f\n",auxPonteiro->data,auxPonteiro->temperatura,auxPonteiro->humidade,auxPonteiro->qtdCO2,auxPonteiro->energiaConsumida,auxPonteiro->qtdProduzida);
			auxPonteiro=auxPonteiro->prox;
		}
	}
	fclose(gravaD);
}

int main()
{
	int contador=0;
	int auxContador;
	char opcao;
	char pesquisaData[TAMANHO_DATA];
	auxMaquina array_nome_Maquinas[TAMANHO];
	int contaFalhas=0;

	auxContador=carrega_Dados(array_nome_Maquinas); //nao funciona como devido
	do{
		printf("Menu das Maquinas\n");
		printf("1.Inserir Maquinas\n");
		printf("2.Inserir Dados Das Maquinas\n");
		printf("3.Escrever Dados Das Maquinas\n");
		printf("4.Escrever numero de falhas em cada maquina\n");
		printf("5.Pesquisa Dados\n");
		printf("6.Remove Falhas\n");
		printf("7.Remove dados num certo momento\n");
		printf("8.Sair\n");
		printf("Insira a opcao que deseja executar\n");
		fflush(stdin);
		scanf("%c",&opcao);

		switch(opcao){
			case '1':
			auxContador=insere_Maquina(array_nome_Maquinas,contador);break;
			case '2':
			insere_Dados_Maquina(auxContador,array_nome_Maquinas);break;
			case '3':
			escreve_Dados(auxContador,array_nome_Maquinas);break;
			case '4':
			conta_Falhas(auxContador,array_nome_Maquinas);break;
			case '5':
			pesquisa_Dados(auxContador,array_nome_Maquinas);break;
			case '6':
			remove_Falhas(auxContador,array_nome_Maquinas);break;
			case '7':
			printf("Insira o momento em que pretende remover os dados:\n");
			fflush(stdin);
			gets(pesquisaData);
			remove_Dados(auxContador,pesquisaData,array_nome_Maquinas);break;
			case '8':
			printf("Bye Bye!!");
			escreve_Dados(auxContador,array_nome_Maquinas);
			grava_dados(auxContador,array_nome_Maquinas);
			grava_Dados_csv(auxContador,array_nome_Maquinas);break;
			default:
			printf("Opcao Invalida!!!\n");
		}
	}while(opcao!='8');

	return 0;
}