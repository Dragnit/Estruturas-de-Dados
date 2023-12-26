#include <stdio.h>

int main()
{
 int *p;
 char *m;
 float *j;
 printf("%d\n",sizeof(*p));
 printf("%d\n",sizeof(*j));
 printf("%d\n\n",sizeof(*m));

 printf("%d\n",sizeof(p));
 printf("%d\n",sizeof(j));
 printf("%d\n",sizeof(m));

}