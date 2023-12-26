#include <stdio.h>
#include <stdlib.h>
#define MAX 30
int main()
{
  int vec[MAX];
	for (int i = 0; i < MAX; i++)
  {
    printf("%d\n", rand() % 50 + 1);
    vec[i] = rand();
    printf("%d\n", vec[i]);
  }
}
