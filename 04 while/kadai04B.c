#include <stdio.h>

int main(void)
{
	int		num;
	int		max = 0;

	printf("整数入力-->");
	scanf("%d",&num);
	
	while(num > -1)
	{
		
		if(num > max)
		{
			max = num;
		}
		
		printf("整数入力-->");
		scanf("%d",&num);
		
	}
	
	printf("最大値:%d\n",max);
	
	return 0;

}
