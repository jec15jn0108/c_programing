#include <stdio.h>

/* 15jn0108 Onogaki kaichi*/

int main(void)
{
	int array[8];
	int tmp, i, j;
	
	for( i = 0; i < 8; i++)
	{
		printf("®”[%d]-->",i);
		scanf("%d",&array[i]);
	}
	
	for( i = 0; i < 8 - 1; i++)
	{
		for( j = i; j < 8; j++)
		{
			if( array[i] > array[j])
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
			}
		}
	
	}
	
	printf("\n––ƒ\[ƒgŒã––\n");
	
	for( i = 0; i < 8; i++)
	{
		printf("Œ‹‰Ê[%d]:%d\n",i,array[i]);
	}
	
	return 0;

}
