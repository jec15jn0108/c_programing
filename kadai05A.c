#include <stdio.h>

int main(void)
{
	int point;
	int sum = 0;
	int i;
	double ave;
	
	for(i = 1; i <= 5; i++)
	{
		do
		{
			printf("%d人目点数入力-->",i);
			scanf("%d",&point);
			
		}while(point < 0 || point > 100);
		
		sum += point;
	}
	
	ave = (double)sum / (i - 1);
	
	printf("\n平均:%.1f\n",ave);
	
	
	return 0;

}
