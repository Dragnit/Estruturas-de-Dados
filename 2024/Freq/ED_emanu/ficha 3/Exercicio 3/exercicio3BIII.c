void trocaB(int *x, int *y)
{
int * aux;
aux = x;
x = y;
y = aux;
}

int main()
{
int a=5,b=12,x=1001,z=1002;
unsigned long int i,j;

i=&a;
j=&b;

printf("Antes da Troca:\n");
printf("Valor de x: %d\n",x);
printf("Valor de z: %d\n",z);
printf("Valor de &x: %d\n",&x);
printf("Valor de &z: %d\n",&z);
printf("Valor de a: %d\n",a);
printf("Valor de b: %d\n",b);
printf("Valor de &a: %d\n",&a);
printf("Valor de &b: %d\n",&b);
printf("Valor de i: %d\n",i);
printf("Valor de j: %d\n",j);
printf("Valor de &i: %d\n",&i);
printf("Valor de &j: %d\n",&j);
trocaB(&i,&j);
printf("Depois da Troca:\n");
printf("Valor de x: %d\n",x);
printf("Valor de z: %d\n",z);
printf("Valor de &x: %d\n",&x);
printf("Valor de &z: %d\n",&z);
printf("Valor de a: %d\n",a);
printf("Valor de b: %d\n",b);
printf("Valor de &a: %d\n",&a);
printf("Valor de &b: %d\n",&b);
printf("Valor de i: %d\n",i);
printf("Valor de j: %d\n",j);
printf("Valor de &i: %d\n",&i);
printf("Valor de &j: %d\n",&j);
	return 0;
}