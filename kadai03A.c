#include <stdio.h>

int main(void)
{
	int i;
	int sum = 0 ;
	
	for (i = 0; i <= 10; i++)
	{
		printf("%d ",i);
		
		sum += i;
	}
	
	printf("\n���v:%d\n",sum);
	
	return 0;

}
