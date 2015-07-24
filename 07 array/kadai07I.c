#include <stdio.h>

int main(void)
{
	int dat[10], err[10];
	int i, j, sum = 0, cnt = 0;
	double ave;
	
	for(i = 0; i < 10; i++)
	{
		printf("データ[%d]入力-->",i);
		scanf("%d",&dat[i]);
		sum += dat[i];
	}
	
	ave = (double)sum / 10;
	
	printf("平均:%.1f\n",ave);
	
	for(i = 0; i < 10; i++)
	{
		if(dat[i] < ave - 50 || dat[i] > ave + 50)
		{
			err[cnt] = i;
			cnt++;
		}
	}
	
	printf("エラー件数:%d\n",cnt);
	
	for(i = 0; i < cnt; i++)
	{
		printf("%d:%d\n",err[i],dat[err[i]]);
	}
	
	return 0;

}
