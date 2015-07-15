#include <stdio.h>

int main(void)
{
	int array[8];
	int tmp, i, j, min;
	
	for( i = 0; i < 8; i++)
	{
		printf("®”[%d]-->",i);
		scanf("%d",&array[i]);
	}
	
	for( i = 0; i < 8 - 1; i++)
	{
		min = i;
		
		for( j = i + 1; j < 8; j++)
		{
			if (array[j] < array[min]) {
				min = j;
			}
		}
		
		if( i != min )
		{
			tmp = array[i];
			array[i] = array[min];
			array[min] = tmp;
		}
	}
	
	printf("\n––ƒ\[ƒgŒã––\n");
	
	for( i = 0; i < 8; i++)
	{
		printf("Œ‹‰Ê[%d]:%d\n",i,array[i]);
	}
		
	return 0;

}
