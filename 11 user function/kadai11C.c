#include	<stdio.h>


int Add(int *pa, int *pb);

int	main(void)
{
	int	a;
	int	b;
	int sum;
	
	printf("変数a入力-->");
	scanf("%d", &a);
	printf("変数b入力-->");
	scanf("%d", &b);
	
	sum = Add(&a, &b);
	
	printf("合計:%d\n", sum);
	
	return 0;
}

int Add(int *pa, int *pb)
{
	return *pa + *pb;
}