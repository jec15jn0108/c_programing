#include	<stdio.h>


int Add(int *pa, int *pb);

int	main(void)
{
	int	a;
	int	b;
	int sum;
	
	printf("�ϐ�a����-->");
	scanf("%d", &a);
	printf("�ϐ�b����-->");
	scanf("%d", &b);
	
	sum = Add(&a, &b);
	
	printf("���v:%d\n", sum);
	
	return 0;
}

int Add(int *pa, int *pb)
{
	return *pa + *pb;
}