#include <stdio.h>
#include <time.h>
#include <string.h>

// pergunta 1
typedef struct no * ponteiro;
typedef struct no 
{
  int numero;
  char medicao[50];
  char data[50];
  char localizacao[50];
  ponteiro ant;
  ponteiro prox;  
}listano;

typedef struct sensor
{
  char nome[50];
  ponteiro pprox;
}nomesensor;

ponteiro crialista()
{
  ponteiro a = NULL;
  return a; 
}
int contanos(ponteiro lst)
{
  int i=0;
  while (lst != NULL)
  {
    i++;
    lst = lst->prox;
  }
  return i;
}

// pergunta 2

void mostralista(int total_sensor, nomesensor stringSensor[50])
{
  ponteiro aux = NULL;
  
  for(int i=0; i < total_sensor; i++)
  {
    printf("Nome Sensor: %s ", stringSensor[i].nome);
    aux = stringSensor[i].pprox;
    while(aux!=NULL)
    {
      printf("Numero do sensor: %d", aux->numero);
      printf("O que o sensor mede: %s\n", aux->medicao);
      printf("Localizacao do sensor: %s\n", aux->localizacao);
      printf("Data: %s\n", aux->data);
      aux = aux->prox;
    }
    
  }
}

// exercício 3
void eliminaultimo(int total_sensor, nomesensor stringSensor[50], ponteiro * lst)
{
  ponteiro paux = *lst;
  ponteiro aux = NULL;
 for(int i=0; i < total_sensor; i++)
 {
   aux = stringSensor[i].pprox;
  while(aux!= NULL)
  {
    aux = paux;
    paux = paux->prox;
  }
  free(paux);
  if(aux != NULL)
   aux->prox = NULL;
  else
   *lst = NULL;
  }
}

// exercicio4
void gravarcvs(int total_sensor, nomesensor stringSensor[50])
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
          fprintf(f, "%s;",stringSensor[i].nome);
          fprintf(f, "\n\n");
          while (aux != NULL)
          {
              fprintf(f, "Data/Hora;Temperatura;Humidade;CO2 emitido;Energia;Producao;");
              fprintf(f, "\n");
              fprintf(f, "%d;%s;%s;%s", aux->numero, aux->medicao, aux->localizacao, aux->data);
              aux = aux->prox;
          }
      }
  fclose(f);
  return 1;//c
}
}
int main()
{
  int comprimento, total_sensor;  // total_sensor vai ser a variavel que vai guardar quantos senseros foram inseridos
  ponteiro lst = crialista();
  comprimento = contanos(lst);
  nomesensor stringSensor[50];
  mostralista(total_sensor, stringSensor);
  eliminaultimo(total_sensor, stringSensor, &lst);
  gravarcvs(total_sensor, stringSensor);

	return 0;
}