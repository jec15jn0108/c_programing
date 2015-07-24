#include <stdio.h>

int main(void)
{
	int		num;
	int		sum = 0, cnt = 0;
	double	ave;
	
	printf("®”“ü—Í-->");
	scanf("%d",&num);
	
	while(num > -1)
	{

		
		if(num > -1)
		{
			cnt++;
			sum += num;
		}
		
		printf("®”“ü—Í-->");
		scanf("%d",&num);
	}
	
	if( cnt != 0)
	{
		ave = (double)sum / cnt;
		
		printf("‡Œv:%d",sum);
		printf("  Œ”:%d",cnt);
		printf("  •½‹Ï:%.1f\n",ave);
	}
	
	return 0;

}
