#include <stdio.h>

int main(void)
{
	int		num		;
	int 	sum = 0	;
	double 	ave 	;
	int 	i		;
	
	for( i = 0; i < 5; i++ )
	{
		printf("整数入力-->");
		scanf("%d",&num);
		
		sum += num;
		
	}
	
	printf("合計:%d\n",sum);
	
	ave = (double)sum / 5;
	
	printf("平均:%.1f\n",ave);
	
	return 0;

}
