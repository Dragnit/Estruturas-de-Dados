#include<stdio.h>

int main()
{
    char *a;
    int *b;
    float *c;
    printf("tipo | tamnho(bytes) | tamanho do ponteiro(bytes) |\n");
    printf("+----+---------------+----------------------------+\n");
    printf("char | %d | %d |\n",sizeof(char),sizeof(a));
    printf("int  | %d | %d |\n",sizeof(int),sizeof(b));
    printf("float| %d | %d |",sizeof(float),sizeof(c));

    return 0;
}
