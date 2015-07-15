#include	<stdio.h>

int main(void)
{
	int	array[5], i;
	int	*pa;
	
	pa = array;
	
	for(i = 0; i < 5; i++){
		printf("®”[%d]-->", i);
		scanf("%d", pa + i);
	}
	
	
	printf("\n");
	
	for(i = 0; i < 5; i++){
		printf("Œ‹‰Ê[%d]:%d\n", i, *(pa + i));
	}
	
	return 0;
}