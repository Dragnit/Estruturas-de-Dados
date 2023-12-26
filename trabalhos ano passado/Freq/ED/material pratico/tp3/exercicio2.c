#include <stdio.h>

int main() {
  int *iptr;
  float *fptr;
  char *cptr;

    printf("  tipo |  tamanho (bytes)  |  tamanho do ponteiro (bytes)\n");
    printf("+------+-------------------+------------------------------+\n");
    printf("| char |                 %d |                            %d |\n", sizeof(char),sizeof(cptr));
    printf("| int  |                 %d |                            %d |\n", sizeof(int),sizeof(iptr));
    printf("| float|                 %d |                            %d |\n", sizeof(float),sizeof(fptr));

    return 0;
}
