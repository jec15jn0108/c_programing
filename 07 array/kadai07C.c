#include <stdio.h>

int main(void)
{
	int	num[5]		;
	int i, sum = 0	;
	
	for(i = 0; i < 5; i++)
	{
		printf("”’l[%d]-->",i);
		scanf("%d",&num[i]);
		
		sum += num[i];
	}
	
	printf("\n‡Œv:%d\n",sum);
	
	printf("Œ‹‰Ê:");
	for(i = 0; i < 5; i++)
	{
		printf("%d ",num[i]);
	}
	printf("\n");
	
	
	return 0;

}
