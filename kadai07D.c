#include <stdio.h>

int main(void)
{
	int	num[10]		;
	int i	;
	
	for(i = 0; i < 10; i++)
	{
		printf("”’l[%d]-->",i);
		scanf("%d",&num[i]);
	}
	
	printf("\n•‰‚Ì’l‚Ìˆê——\n");
	
	for(i = 0; i < 10; i++)
	{
		if(num[i] < 0)
		{
			printf("%d ",num[i]);
		}
	}
	printf("\n");
	
	
	return 0;

}
