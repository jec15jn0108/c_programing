#include <stdio.h>

int main(void)
{
	int 	no, point, cnt, sum = 0;
	int		max = -1, min = 101, maxno, minno;
	double	ave;
	
	cnt = 0;
	
	printf("�ԍ�,���_-->");
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
		
		printf("�ԍ�,���_-->");
	}
	
	if(cnt != 0)
	{
		ave = (double)sum / cnt;
		printf("\n���ϓ_:%f\n",ave);
		
		printf("�ō��_  �ԍ�:%2d  ���_:%d\n",maxno,max);
		printf("�Œ�_  �ԍ�:%2d  ���_:%d\n",minno,min);
	}
	

	
	
	return 0;

}
