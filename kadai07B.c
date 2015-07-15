#include <stdio.h>

int main(void)
{
	int	num[5];
	int i;
	
	for(i = 0; i < 5; i++)
	{
		printf("”’l[%d]-->",i);
		scanf("%d",&num[i]);
	}
	
	printf("\n");
	
	for(i = 4; i >= 0; i--)
	{
		printf("”’l[%d]:%d\n",i,num[i]);
	}
	
	
	return 0;

}
