#include <stdio.h>

int main(void)
{
	int num	;
	int	i,j	;
	
	printf("®”“ü—Í-->");
	scanf("%d",&num);
	
	for( i = 1; i <= num; i++)
	{
		
		for( j = 0; j < num - i; j++)
		{
			printf(" ");
		}
		
		for( j = 0; j < i * 2 - 1; j++)
		{
			printf("*");
		}
		
		printf("\n");
		
	}
	
	return 0;

}
