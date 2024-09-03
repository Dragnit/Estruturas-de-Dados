#include <stdio.h>

int main()
{
 int a = 2, b = 3;
 int *p, *q;
 
 p = &a;
 q = &b;
 p == &a;
 printf("%d\n", p);
 printf("%d\n", *p - *q);
 printf("%d\n", **&p);
 printf("%d\n", *p+1);
 printf("%d\n", *(q-2));
 
 printf("%p %u %u %d %d %d %d\n",p, p, &p, *p+4, **&p, 5**p, **&p+6);
 
}