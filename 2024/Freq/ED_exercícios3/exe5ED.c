#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int tamanho_str(char *ps)
{
    int count = 0;
    while(*ps!='\0')
    {
        ++ps;
        count ++;
    }
    return count;
}
char * copia_substr(char * src, int i, int len)
{
    char ps[200];
    char * aux = malloc(len);
     src = &src[i];
     int x=0;
     while(x<len)
     {
         ps[x] = *src;
         ++src;
         x++;
     }
     ps[x]='\0';
     strcpy(aux, ps);
    return aux;
}

int main()
{
    char ps[200];
    int i, len;
    printf("Insira a palavra que quer contar: ");
    scanf("%s", ps);
    *ps = ps[0]; //inicializar o ponteiro no primeiro elemento da string
    int count = tamanho_str(ps); //igualar a variável count ao valor retornado na função, em cima
    tamanho_str(ps);
    printf("Tamanho da palavra %s: %d", ps, count);
    printf("\nIntroduza o indice por onde quer comecar: ");
    scanf("%d", &i);
    printf("\nIntroduza a quantidade de caracteres que quer copiar: ");
    scanf("%d", &len);
    char * dst = copia_substr(ps,i,len);
    printf("%s", dst);
    free(dst);
}















































































































































