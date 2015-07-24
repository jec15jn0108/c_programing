#include <stdio.h>

int main(void)
{
	int NUM	;
	int i,j	;
	int flag;
	
	flag = 0;
	
	printf("®”n-->");
	scanf("%d",&NUM);
	
	for(i = 2; i <= NUM; i++)
	{
		
		for(j = 2; j < i; j++)
		{
			if( i % j == 0)
			{
				flag = 1;
			}
		}
		
		if(flag == 0)
		{
			printf("%d ",i);
		}
		
		flag = 0;
		
	}
	
	printf("\n");
	
	return 0;

}
