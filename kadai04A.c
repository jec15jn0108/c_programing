#include <stdio.h>

int main(void)
{
	int		num;
	int		sum = 0, cnt = 0;
	double	ave;
	
	printf("��������-->");
	scanf("%d",&num);
	
	while(num > -1)
	{

		
		if(num > -1)
		{
			cnt++;
			sum += num;
		}
		
		printf("��������-->");
		scanf("%d",&num);
	}
	
	if( cnt != 0)
	{
		ave = (double)sum / cnt;
		
		printf("���v:%d",sum);
		printf("  ����:%d",cnt);
		printf("  ����:%.1f\n",ave);
	}
	
	return 0;

}
