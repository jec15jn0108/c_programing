#include <stdio.h>

int main(void)
{
	int		num		;
	int 	sum = 0	;
	double 	ave 	;
	int 	i		;
	
	for( i = 0; i < 5; i++ )
	{
		printf("��������-->");
		scanf("%d",&num);
		
		sum += num;
		
	}
	
	printf("���v:%d\n",sum);
	
	ave = (double)sum / 5;
	
	printf("����:%.1f\n",ave);
	
	return 0;

}
