#include	<stdio.h>

int main(void)
{
	int a = 10, b = 5, g;
	int *pa, *pd;
	
	pa = &a;
	pd = &b;
	
	g = *pa	+ *pd;
	
	printf("g:%d\n", g);
	
	return 0;
}