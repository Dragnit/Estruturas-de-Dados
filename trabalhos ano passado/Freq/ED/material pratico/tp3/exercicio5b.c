#include <stdio.h>
#define TAM 100

void copiar(char *stringoriginal ,char*stringcopia){

  while(*stringoriginal != '\0'){
    *stringcopia=*stringoriginal;
    ++stringoriginal;
    ++stringcopia;
  }
  *stringcopia='\0';
}

int main(){

char stringoriginal[TAM],stringcopia[TAM];

printf ("Introduza conteudo para a string original:");
gets(stringoriginal);
copiar(stringoriginal,stringcopia);
printf("Apos copiado- Conteudo da string copia: %s\n",stringcopia);

}
