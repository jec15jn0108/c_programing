#include <stdio.h>

int main(void)
{
	int	num[5]		;
	int i, sum = 0	;
	
	for(i = 0; i < 5; i++)
	{
		printf("数値[%d]-->",i);
		scanf("%d",&num[i]);
		
		sum += num[i];
	}
	
	printf("\n合計:%d\n",sum);
	
	printf("結果:");
	for(i = 0; i < 5; i++)
	{
		printf("%d ",num[i]);
	}
	printf("\n");
	
	
	return 0;

}
