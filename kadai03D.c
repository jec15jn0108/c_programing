#include <stdio.h>

int main(void)
{
	int		num		;
	int 	sum = 0	;
	double 	ave 	;
	int 	i		;
	
	for( i = 0; i < 5; i++ )
	{
		printf("®”“ü—Í-->");
		scanf("%d",&num);
		
		sum += num;
		
	}
	
	printf("‡Œv:%d\n",sum);
	
	ave = (double)sum / 5;
	
	printf("•½‹Ï:%.1f\n",ave);
	
	return 0;

}
