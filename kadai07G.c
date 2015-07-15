#include <stdio.h>

int main(void)
{
	int	i, dat[10], sum = 0;
	double ave;
	
	
	for(i = 0; i < 10; i++)
	{
		printf("®”[%d]-->",i);
		scanf("%d",&dat[i]);
		
		sum += dat[i];
	}
	
	ave = (double)sum / 10;
	
	printf("\n•½‹Ï(%.1f)ˆÈã‚Ìƒf[ƒ^\n",ave);
	
	for( i = 0; i < 10; i++)
	{
		if(dat[i] >= ave)
		{
			printf("%d:%d\n", i, dat[i]);
		}
	}
		
	return 0;

}
