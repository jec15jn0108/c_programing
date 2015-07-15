#include <stdio.h>

int main(void)
{
	int 	no, point, cnt, sum = 0;
	int		max = -1, min = 101, maxno, minno;
	double	ave;
	
	cnt = 0;
	
	printf("番号,得点-->");
	while(scanf("%d,%d",&no, &point) != EOF)
	{
		cnt++;
		sum += point;
		
		if(point > max)
		{
			max = point;
			maxno = no;
		}
		
		if(point < min)
		{
			min = point;
			minno = no;
		}
		
		printf("番号,得点-->");
	}
	
	if(cnt != 0)
	{
		ave = (double)sum / cnt;
		printf("\n平均点:%f\n",ave);
		
		printf("最高点  番号:%2d  得点:%d\n",maxno,max);
		printf("最低点  番号:%2d  得点:%d\n",minno,min);
	}
	

	
	
	return 0;

}
