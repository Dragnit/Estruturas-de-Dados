#include<stdio.h>

  void copia_string(char *final, char *original)
{
    while(*original)
      {
        *final = *original;
        original++;
        final++;
      }
    *final = '\0';
}

  int main()
{
    char original[100], final[100];
    printf("String original:");
    gets(original);
    copia_string(final,original);
    printf("A string e: \"%s\"\n",final);
    return 0;
}
