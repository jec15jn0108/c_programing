#include <stdio.h>

/* 15jn0108 Onogaki kaichi*/

int main(void)
{
	int dat[8];
	int i, sum = 0;
	int near, nearest, nearNum;
	double ave;
	
	for( i = 0; i < 8; i++ )
	{
		printf("���l[%d]-->",i);
		scanf("%d",&dat[i]);
		
		sum += dat[i];
	}
	
	ave = (double)sum / 8;
	printf("\n����:%.1f\n",ave);
	
	
	for ( i = 0; i < 8; i++)
	{
		nearNum = (dat[i] > ave) 	?	dat[i] - ave :
										ave - dat[i] ;
		
		if(i = 0)
		{
			nearest = nearNum;
		}
		
		if(nearNum < nearest)
		{
			nearest = nearNum;
			near = i;
		}
		
		
	}
	
	printf("���ʁ@�v�f�ԍ�:%d\n",near);
	printf("�@�@�@�@�f�[�^:%d\n",dat[near]);
	
	return 0;

}
