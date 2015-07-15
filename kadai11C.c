#include	<stdio.h>


int Add(int *pa, int *pb);

int	main(void)
{
	int	a;
	int	b;
	int sum;
	
	printf("•Ï”a“ü—Í-->");
	scanf("%d", &a);
	printf("•Ï”b“ü—Í-->");
	scanf("%d", &b);
	
	sum = Add(&a, &b);
	
	printf("‡Œv:%d\n", sum);
	
	return 0;
}

int Add(int *pa, int *pb)
{
	return *pa + *pb;
}